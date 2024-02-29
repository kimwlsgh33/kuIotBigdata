USE madangdb;
SELECT * FROM Book;


INSERT INTO Book(bookid, bookname, publisher, price)
	VALUES (11, "스포츠 의학", "한솔의학서적", 90000);    

INSERT INTO Book
	VALUES (12, "스포츠 의학", "한솔의학서적", 90000);
    
INSERT INTO Book(bookid, bookname, price, publisher)
	VALUES (13, "스포츠 의학", 90000, "한솔의학서적");
    
INSERT INTO Book(bookid, bookname, publisher)
	VALUES (14, "스포츠 의학", "한솔의학서적");

CREATE TABLE imported_book2 (
	bookid		INTEGER PRIMARY KEY,
    bookname	VARCHAR(40),
    publisher	VARCHAR(40),
    price		INTEGER
);
    
SELECT * FROM imported_book;
DROP TABLE imported_book2;

-- practice
INSERT INTO imported_book(bookid, bookname, price, publisher)
	SELECT	bookid, bookname, price, publisher
    FROM	Book;
    
INSERT INTO imported_book2
	SELECT	bookid, bookname, publisher, price
    FROM	Book;
    

-- update
/* Safe Updates 옵션 해제 - PRIMARY KEY외의 것으로 수정 가능 */
SET SQL_SAFE_UPDATES=0; 

SELECT * FROM Customer;

UPDATE	Customer
SET		address = '대한민국 부산'
WHERE	`name`	= '박세리';
-- WHERE custid = 5;

-- 3-48
SELECT * FROM Book;
UPDATE	Book
SET		publisher = (
	SELECT	publisher
    FROM	imported_book
    WHERE	bookid = 10
)
WHERE	bookid = 14;

-- 3-49
DELETE FROM Book WHERE bookid = 11;

DELETE FROM Customer;
DELETE FROM Orders;