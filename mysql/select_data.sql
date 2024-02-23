-- Example 3-1
select bookname, price from Book;

-- Example 2
select price, bookname from Book;

-- Example 3-2
select bookid, bookname, publisher, price from Book;

select * from Book;

-- Example 3-3 (ALL|DISTINCT)
select publisher from Book;
select distinct publisher from Book;

-- Example 3-4
select * from Book where price <= 20000;
select bookname, price from Book where price <= 20000;

-- Example 3-5
select * from Book where price between 10000 and 20000;
select * from Book where price >= 10000 and price <= 20000;

-- Example 3-6
select * from Book where publisher in ('대한미디어', '굿스포츠');
select * from Book where publisher not in ('굿스포츠', '대한미디어');

-- Example 3-7, 3-8
select publisher, bookname from Book where bookname like '축구의 역사';
select publisher, bookname from Book where bookname like '%축구%';
-- Using `as`
select publisher 출판사, bookname 책이름 from Book where bookname like '축구의 역사';
select publisher as 출판사, bookname as 책이름 from Book where bookname like '축구의 역사';

-- Example 3-9
select bookname from Book where bookname like '_구%';
select bookname from Book where bookname like '__의%';

-- Example 3-10
select bookname, price from Book where bookname like '%축구%' and price >= 20000;
select bookname, price from Book where (bookname like '%축구%') and (price >= 20000);

-- Example 3-11
select * from Book where publisher like '굿스포츠' or publisher like '대한미디어';
select * from Book where publisher in ('굿스포츠', '대한미디어');
select * from Book where (publisher like '굿스포츠') and (price < 8000);

-- Example 3-12 (ORDER BY-ASC|DESC)
select * from Book order by bookname;
select * from Book order by bookname desc;

-- Example 3-13
select * from Book order by price, bookname desc;
select * from Book order by price desc, bookname desc;

-- Example 3-14
select * from Book order by price, publisher desc;


-- 
select * from R1 where (A = 'a1') or (A = 'a2');


-- Example 3-15
desc Orders;
select sum(saleprice) from Orders;
select sum(saleprice) "총 판매액" from Orders;


-- Example 3-16
select sum(saleprice) from Orders where custid = 2;


-- Example 3-17
select sum(saleprice) as "총 판매액",
		avg(saleprice) as "평균",
        min(saleprice) as "최소값",
        max(saleprice) as "최대값"
from Orders;


-- Example 3-18 (COUNT, NOT NULL)
select count(*) from Orders;
select count(orderid) from Orders;
select * from Orders;

select count(*) from Customer;
select count(phone) from Customer;

-- Example 3-19
select sum(saleprice), count(*) 
from Orders 
group by custid;

select custid, count(*) as 도서수량
from Orders
where saleprice >= 8000
group by custid
having count(*) >= 2;