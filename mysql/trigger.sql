USE madangdb;
-- This must be used by `root` user
SET global log_bin_trust_function_creators=ON;
CREATE TABLE Book_log(
	bookid_l INTEGER,
    bookname_l VARCHAR(40),
    publisher_l VARCHAR(40),
    price_l INTEGER
);

-- book after insert trigger registration
DROP TRIGGER IF EXISTS `madangdb`.`Book_AFTER_INSERT`;

DELIMITER $$
USE `madangdb`$$
CREATE DEFINER = CURRENT_USER TRIGGER `madangdb`.`Book_AFTER_INSERT` AFTER INSERT ON `Book` FOR EACH ROW
BEGIN
	-- create log by trigger!
    INSERT INTO Book_log
    -- new : this mean to access to income data
    VALUES(new.bookid, new.bookname, new.publisher, new.price);
END$$
DELIMITER ;
-- book after insert trigger registration end
SELECT * FROM Book;
SELECT * FROM Book_log;
INSERT INTO Book VALUES(14, "스포츠 과학 1", "이상 미디어", 25000);

-- 사용자 정의 함수
USE `madangdb`;
DROP function IF EXISTS `fnc_interest`;

DELIMITER $$
USE `madangdb`$$
CREATE FUNCTION `fnc_interest` (
	price INTEGER
)
RETURNS INTEGER
BEGIN
	DECLARE myInterest INTEGER;
    -- 
    IF price >= 30000 THEN
		SET myInterest = price * 0.1;
    ELSE
		SET myInterest = price * 0.05;
    END IF;
RETURN 1;
END$$

DELIMITER ;
-- ------------------------------
SELECT custid, orderid, saleprice, fnc_interest(saleprice) interest FROM Orders;





