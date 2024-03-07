USE madangdb;

CREATE VIEW vw_Book
AS	SELECT *
	FROM Book
    WHERE bookname LIKE "%축구%";
    
SELECT * FROM vw_Book;

-- 4-20
CREATE VIEW vw_Customer
AS	SELECT *
	FROM Customer
    WHERE address LIKE "%대한민국%";
    
SELECT * FROM vw_Customer;

-- 4-21
CREATE VIEW vw_Orders (orderid, custid, name, bookid, bookname, saleprice, orderdate)
AS SELECT	od.orderid, od.custid, cs.name, od.bookid, bk.bookname, od.saleprice, od.orderdate
FROM		Orders od, Customer cs, Book bk
WHERE		od.custid=cs.custid AND od.bookid=bk.bookid;

SELECT orderid, bookname, saleprice 
FROM vw_Orders 
WHERE name='김연아';


CREATE OR REPLACE VIEW vw_Customer (custid, name, address)
AS	SELECT custid, name, address
	FROM Customer
    WHERE address LIKE "%영국%";

DROP VIEW vw_Customer;

-- phone is missing!! - (field list)
INSERT INTO vw_Customer VALUE (6, "김진호", "영국 리즈");
INSERT INTO vw_Customer(custid, name, address) VALUE (6, "김진호", "영국 리즈");
INSERT INTO Customer VALUE (7, "박정석", "영국 런던", "010-1234-5678");
SELECT * FROM vw_Customer;


SELECT * FROM INFORMATION_SCHEMA.TABLES
WHERE table_schema LIKE 'madangdb';

/*
USE INFORMATION_SCHEMA;
SHOW DATABASES;
SHOW TABLES;
*/