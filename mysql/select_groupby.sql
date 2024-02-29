use madangdb;

-- sum
select sum(saleprice) 총판매액 from Orders;

select custid
from Customer   
where name="김연아";

select sum(saleprice)
from Orders
where custid=2;

select sum(saleprice) 판매액
from Orders
where Orders.custid=2;

-- nested query
select sum(saleprice)
from Orders
where custid=(
	select custid
	from Customer   
	where name="김연아"
);

-- 3-17
select sum(saleprice) Total,
	avg(saleprice) Average,
	min(saleprice) Min,
	max(saleprice) Max
from Orders;

-- JOIN => Product result 
-- Customer: 5, Orders: 10 => 5 * 10
select * from Customer, Orders;

-- Customer: 5, Orders: 10 => 10 (max)
select *
from Customer, Orders
where Customer.custid=Orders.custid;

select *
from Customer, Orders
where Customer.custid=Orders.custid
order by Customer.custid;

select *
from Orders, Customer
where Customer.custid=Orders.custid
order by Customer.custid;

-- you need to choose one between two tables
select Customer.custid, name, saleprice
from Customer, Orders
where Customer.custid=Orders.custid;

-- 3-24
select name, sum(saleprice)
from Customer, Orders
where Customer.custid=Orders.custid
group by name
order by name;

-- 3-25 ("books" "ordered" by "customer")
select Customer.name, Book.bookname
from Customer, Orders, Book
where Customer.custid=Orders.custid and Orders.bookid=Book.bookid;

-- 3-26
select Customer.name, Book.bookname, Book.price
from Customer, Orders, Book
where Customer.custid=Orders.custid and Orders.bookid=Book.bookid
and Book.price >= 20000;

-- on : condition
/* left:
retrieves all records from the `left` table
rows of right table that doesn't matched are setted as NULL
*/

/* outer:
include all rows in target table
*/
select Customer.name, Orders.saleprice
from Customer left join Orders on Customer.custid=Orders.custid;

/* inner:
returns only the rows where there is a match in both tables
based `on` the join condition
*/
select Customer.name, Orders.saleprice
from Customer inner join Orders on Customer.custid=Orders.custid;
--

/* full:
returns all the rows
 */
 

-- 3-27
SELECT Customer.`name`, saleprice
FROM Customer LEFT OUTER JOIN Orders ON
   Customer.custid=Orders.custid;

-- 3-28
SELECT bookname, price
FROM Book
WHERE price = (
  SELECT MAX(price) FROM Book
);

-- 3-29
SELECT `name` from Customer
WHERE custid in (
  SELECT custid FROM Orders
);

-- 3-30
SELECT `name`
FROM Customer
WHERE custid IN (
  SELECT custid
  FROM Orders
  WHERE bookid IN (
    SELECT bookid
    FROM Book
    WHERE publisher='대한미디어'
 )
);

-- 3-31 (remove cartesian product between two table)
SELECT bookname
FROM Book b1
WHERE price > (
  SELECT AVG(b2.price) 
  FROM Book b2 
  WHERE b2.publisher = b1.publisher
);

-- 3-32 (UNION - vertical expansion)
SELECT `name` FROM Customer WHERE address LIKE '대한민국%'
UNION ALL
SELECT `name` FROM Customer WHERE custid IN (SELECT custid FROM Orders);

-- 3-33
SELECT `name`, address
FROM Customer cs
WHERE EXISTS (
  SELECT * FROM Orders od WHERE cs.custid=od.custid
);
