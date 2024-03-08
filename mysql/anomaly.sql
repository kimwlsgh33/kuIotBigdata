USE madangdb;
CREATE TABLE Summer(
	sid		INT PRIMARY KEY,
    class	VARCHAR(40),
    price	INT
);

INSERT INTO Summer VALUES(100, "JAVA", 20000);
INSERT INTO Summer VALUES(150, "PYTHON", 15000);
INSERT INTO Summer VALUES(200, "C", 10000);
INSERT INTO Summer VALUES(250, "JAVA", 20000);

SELECT * FROM Summer;

-- 7-1
SELECT sid, class FROM Summer;
SELECT price, class FROM Summer WHERE class="C";
SELECT DISTINCT class
FROM Summer WHERE price = (
	SELECT MAX(price)
    FROM Summer
);

SELECT COUNT(*), SUM(price) FROM Summer;

SELECT price 'C 수강료'
FROM Summer
WHERE class LIKE 'C';

SET SQL_SAFE_UPDATES=0;
DELETE FROM Summer WHERE sid=200;

-- 7-2
ALTER TABLE `madangdb`.`Summer`
CHANGE COLUMN `sid` `sid` INT NULL ,
DROP PRIMARY KEY;

INSERT INTO Summer VALUES(NULL, "C++", 25000);
SELECT * FROM Summer;
SELECT COUNT(*) FROM Summer WHERE sid IS NOT NULL;

DELETE FROM Summer WHERE class = "C++";

-- 7-3
UPDATE Summer
SET		price = 15000
WHERE	class = "JAVA";

SELECT * FROM Summer;

SELECT	DISTINCT price "JAVA 수강료"
FROM	Summer
WHERE	class LIKE "JAVA";

UPDATE Summer
SET		price = 20000
WHERE	class LIKE "JAVA";

UPDATE Summer
SET		price = 15000
WHERE	class LIKE "JAVA" AND sid = 100;
SELECT * FROM Summer;

SELECT	price "JAVA 수강료"
FROM	Summer
WHERE	class LIKE "JAVA";

UPDATE Summer
SET		price = 20000
WHERE	class LIKE "JAVA";

--
-- SOLUTION
--
DROP TABLE IF EXISTS SummerPrice;
DROP TABLE IF EXISTS SummerEnroll;

-- create table 1
CREATE TABLE SummerPrice (
	class VARCHAR(20),
    price INTEGER
);

INSERT INTO SummerPrice VALUES ("JAVA", 20000);
INSERT INTO SummerPrice VALUES ("PYTHON", 15000);
INSERT INTO SummerPrice VALUES ("C", 10000);

SELECT * FROM SummerPrice;

-- create table2
CREATE TABLE SummerEnroll (
	sid INTEGER,
    class VARCHAR(20)
);

INSERT INTO SummerEnroll VALUES (100, "JAVA");
INSERT INTO SummerEnroll VALUES (150, "PYTHON");
INSERT INTO SummerEnroll VALUES (200, "C");
INSERT INTO SummerEnroll VALUES (250, "JAVA");

SELECT * FROM SummerEnroll;

-- test
SELECT sid, class FROM SummerEnroll;
SELECT price FROM SummerPrice WHERE class LIKE "C";
SELECT DISTINCT class FROM SummerPrice WHERE price = (
	SELECT MAX(price) FROM Summer
);
SELECT COUNT(*) 강습생수, SUM(price) 수익 FROM SummerEnroll, SummerPrice
WHERE SummerPrice.class = SummerEnroll.class;

-- 7-4
DELETE FROM SummerEnroll WHERE sid=200;

-- 7-5
INSERT INTO SummerPrice VALUES ("C++", 25000);

SELECT COUNT(*) FROM SummerPrice;
DELETE FROM SummerPrice WHERE class LIKE "C++";

-- 7-6
UPDATE SummerPrice SET price=15000 WHERE class LIKE "JAVA";
SELECT price "JAVA 수강료" FROM SummerPrice WHERE class LIKE "JAVA";
UPDATE SummerPrice SET price=20000 WHERE class LIKE "JAVA";

