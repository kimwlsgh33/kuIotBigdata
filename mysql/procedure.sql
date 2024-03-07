USE madangdb;

DROP procedure IF EXISTS `dorepeat`;

-- change delimiter to //
delimiter //
CREATE procedure `dorepeat`(p1 INT)
BEGIN
	SET @x = 0;
	REPEAT SET
		@x = @x + 1; UNTIL @x > p1
	END REPEAT;
END
//

-- change delimiter to ;
delimiter ;
-- call the procedure
CALL dorepeat(1000);
SELECT @x;

-- Insertbook procedure registration
USE `madangdb`;
DROP procedure IF EXISTS `InsertBook`;

DELIMITER $$
USE `madangdb`$$
CREATE PROCEDURE `InsertBook` (
	In mybookid		INTEGER,
    IN mybookname	VARCHAR(40),
    IN mypublisher	VARCHAR(40),
    IN myprice		INTEGER
)
BEGIN
	INSERT INTO Book(bookid, bookname, publisher, price)
    VALUES(mybookid, mybookname, mypublisher, myprice);
END$$

DELIMITER ;
-- registration end

CALL InsertBook(13, '스포츠과학', '마당과학서적', 25000);
SELECT * FROM Book;


-- BookInsertOrUpdate procedure registration
USE `madangdb`;
DROP procedure IF EXISTS `BookInsertOrUpdate`;

DELIMITER $$
USE `madangdb`$$
CREATE PROCEDURE `BookInsertOrUpdate` (
	mybookid	INTEGER,
    mybookname	VARCHAR(40),
    mypublisher	VARCHAR(40),
    myprice		INT
)
BEGIN
	DECLARE mycount INTEGER;
    SELECT count(*) INTO mycount FROM Book
		WHERE bookname LIKE mybookname;
    IF mycount != 0 THEN
		SET sql_safe_updates=0;
        UPDATE Book SET price = myprice
			WHERE bookname LIKE mybookname;
    ELSE
		INSERT INTO Book(bookid, bookname, publisher, price)
		VALUES(mybookid, mybookname, mypublisher, myprice);
    END IF;
END$$

DELIMITER ;
-- BookInsertOrUpdate procedure registration end
SELECT * FROM Book;
CALL BookInsertOrUpdate(15, '스포츠 즐거움', '마당과학서적', 25000);
CALL BookInsertOrUpdate(16, '스포츠 즐거움', '마당과학서적', 30000); -- 중복데이터 피하기!

-- AveragePrice procedure registration
USE `madangdb`;
DROP procedure IF EXISTS `AveragePrice`;

DELIMITER $$
USE `madangdb`$$
CREATE PROCEDURE `AveragePrice` (
	OUT AverageVal INTEGER
)
BEGIN
	SELECT AVG(price) INTO AverageVal
    FROM Book WHERE price IS NOT NULL;
END$$

DELIMITER ;
-- AveragePrice procedure registration end
CALL AveragePrice(@myprice);
SELECT @myprice;


-- Interest procedure registration
USE `madangdb`;
DROP procedure IF EXISTS `Interest`;

DELIMITER $$
USE `madangdb`$$
CREATE PROCEDURE `Interest` ()
BEGIN
DECLARE myInterest INTEGER DEFAULT 0.0;
    DECLARE price INTEGER;
    DECLARE endOfRow BOOLEAN DEFAULT FALSE;
    DECLARE InterestCursor CURSOR FOR
		SELECT saleprice FROM Orders;
	DECLARE CONTINUE handler FOR
		NOT FOUND SET endOfRow=TRUE;
	OPEN InterestCursor;
    
    cursor_loop: LOOP
		FETCH InterestCursor INTO price;
        IF endOfRow THEN
			LEAVE cursor_loop;
		END IF;
        IF price >= 30000 THEN
			SET myInterest = myInterest + price * 0.1;
		ELSE
			SET myInterest = myInterest + price * 0.05;
		END IF;
	END LOOP cursor_loop;
    
    CLOSE InterestCursor;
    SELECT CONCAT("전체 이익 금액 =", myInterest);
END$$

DELIMITER ;
-- Interest procedure registration end
CALL Interest();