USE madangdb;

-- CHAR : 나머지 공간을 공백으로 채운다 (비교시, 공백까지 포함됨)
CREATE TABLE NewBook(
	bookid		INTEGER,
    bookname	VARCHAR(20),
    publisher	VARCHAR(20),
    price		INTEGER
);

DROP TABLE NewBook;

CREATE TABLE NewBook(
	bookid		INTEGER,
    bookname	VARCHAR(20),
    publisher	VARCHAR(20),
    price		INTEGER,
    PRIMARY KEY (bookid)
);

CREATE TABLE NewBook(
	bookid		INTEGER PRIMARY KEY,
    bookname	VARCHAR(20) NOT NULL,
    publisher	VARCHAR(20) UNIQUE,
    price		INTEGER DEFAULT 1000 CHECK(price >= 1000)
);

-- A PRIMANRY KEY with two of colume
CREATE TABLE NewBook(
    bookname	VARCHAR(20) NOT NULL,
    publisher	VARCHAR(20) UNIQUE,
    price		INTEGER DEFAULT 1000 CHECK(price >= 1000),
    PRIMARY KEY	(bookname, publisher)
);

CREATE TABLE NewCustomer (
	custid	INTEGER	PRIMARY KEY,
    `name`	VARCHAR(40),
    address	VARCHAR(40),
    phone	VARCHAR(30)
);

-- ON DELETE CASCADE, SET NULL, NO ACTION
CREATE TABLE NewOrders (
	orderid		INTEGER,
    custid		INTEGER	NOT NULL,
    bookid		INTEGER NOT NULL,
    saleprice	INTEGER,
    orderdate	DATE,
    PRIMARY KEY(orderid),
    FOREIGN KEY(custid) REFERENCES NewCustomer(custid) ON DELETE CASCADE
);

ALTER TABLE NewBook ADD isbn VARCHAR(13);
ALTER TABLE NewBook MODIFY isbn INTEGER;
ALTER TABLE NewBook DROP COLUMN isbn;
ALTER TABLE NewBook MODIFY bookname VARCHAR(20) NOT NULL;
ALTER TABLE NewBook ADD PRIMARY KEY(bookid);

DROP TABLE NewBook;
DROP TABLE NewCustomer;
DROP TABLE NewOrders;