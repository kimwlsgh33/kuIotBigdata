USE madangdb;

SELECT ABS(-78), ABS(+78);
SELECT ROUND(3.141592, 4);
SELECT 		custid '고객번호', ROUND(SUM(saleprice)/COUNT(*), -2) '평균금액'
FROM		Orders
GROUP BY	custid;

SELECT ASCII('A');
SELECT LENGTH('군중'); -- byte length
SELECT CHAR_LENGTH('군중');

SELECT bookid, REPLACE(bookname, '야구', '농구') bookname, publisher, price FROM Book;

-- 4-5
SELECT	bookname '제목', CHAR_LENGTH(bookname) '문자수', LENGTH(bookname) '바이트수'
FROM	Book
WHERE	publisher = '굿스포츠';

SELECT		SUBSTR(`name`, 1, 1) '성', COUNT(*) '인원'
FROM		Customer 
GROUP BY	SUBSTR(`name`, 1, 1);

-- 4-7
SELECT orderid '주문번호', orderdate '주문일', ADDDATE(orderdate, INTERVAL 10 DAY) '확정일'
FROM Orders;


SELECT	orderid '주문번호', DATE_FORMAT(orderdate, '%Y-%M-%d') '주문일', custid '고객번호', bookid '도서번호'
FROM	Orders
WHERE	orderdate = STR_TO_DATE('20240707', '%Y%m%d');


USE madangdb;
CREATE TABLE MyBook(
	bookid		INTEGER,
    bookname	VARCHAR(20),
    publisher	VARCHAR(20),
    price		INTEGER,
    PRIMARY KEY (bookid)
);

INSERT INTO MyBook(bookid, bookname, publisher, price) VALUE (1, "1", "1", 10000);
INSERT INTO MyBook(bookid, bookname, publisher, price) VALUE (2, "2", "3", 20000);
INSERT INTO MyBook(bookid, bookname, publisher, price) VALUE (3, "3", "3", NULL);

SELECT price+100
FROM MyBook
WHERE bookid=3;

-- SELECT SUM(price), 
SELECT name, phone
FROM Customer;

SELECT name 이름, IFNULL(phone, '연락처없음') 전화번호
FROM Customer;

-- variable
SET @seq:=0;

SELECT (@seq:=@seq+1) 순번, custid, name, phone
FROM Customer
WHERE @seq < 2;

-- 4-12 example
SELECT orderid, saleprice, (SELECT AVG(saleprice) FROM Orders) 평균값
FROM Orders
WHERE saleprice <= (
	SELECT AVG(saleprice)
    FROM Orders
);

-- subquery can conflict! => use alias
SELECT orderid, custid, saleprice, (SELECT AVG(saleprice) FROM Orders) 평균값
FROM Orders od1
WHERE saleprice > (
	SELECT AVG(saleprice)
    FROM Orders od2
    WHERE od1.custid=od2.custid
);

-- 4-14
SELECT SUM(saleprice) total
FROM Orders
WHERE custid IN (
	-- Result has many rows
	SELECT custid
	FROM Customer
	WHERE address LIKE "%대한민국%"
);

-- 4-15

SELECT orderid, saleprice
FROM Orders
WHERE saleprice > ALL (
	-- Result has many rows
	SELECT saleprice
	FROM Orders
	WHERE custid=3
);

SELECT orderid, saleprice
FROM Orders
WHERE saleprice > (
	-- Result has many rows
	SELECT MAX(saleprice)
	FROM Orders
	WHERE custid=3
);

-- 4-16
SELECT SUM(saleprice)
FROM Orders od
WHERE EXISTS (
	SELECT *
	FROM Customer cs
	WHERE address LIKE "%대한민국%" AND od.custid = cs.custid
);

-- 4-17
SELECT (SELECT name FROM Customer cs WHERE cs.custid=od.custid) name, SUM(saleprice) 'total'
FROM Orders od
GROUP BY od.custid;

-- 4-18
ALTER TABLE Orders ADD bname VARCHAR(40);

UPDATE Orders
SET bname = (
	SELECT bookname
    FROM Book
    WHERE Book.bookid=Orders.bookid
);

SELECT bname FROM Orders;

-- 4-19
SELECT cs.name, SUM(od.saleprice) 'total'
FROM (
	SELECT custid, name
	FROM Customer
	WHERE custid <= 2
) cs, Orders od
WHERE cs.custid=od.custid
GROUP BY cs.name;