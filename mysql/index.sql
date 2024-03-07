USE madangdb;
CREATE INDEX ix_book_1 ON Book(bookname);
CREATE INDEX ix_book_2 ON Book(publisher, price);

SELECT * FROM Book WHERE publisher='대한미디어' AND price >= 30000;
SELECT * FROM Book WHERE bookname LIKE "%축구%";

DROP INDEX ix_book_1 ON Book;

-- 주소를 알맞게 바꿔서, 연결 조각모음?
ANALYZE TABLE Book;