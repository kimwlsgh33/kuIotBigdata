SHOW TABLES;

DELETE FROM Customer;

SET SQL_SAFE_UPDATES=0;
SET FOREIGN_KEY_CHECKS=0;

-- !!TEST!!
DELETE FROM Customer;
SELECT * FROM Customer;

-- 2
SELECT * FROM information_schema.table_constraints
WHERE TABLE_NAME LIKE "Orders";

-- FOREIGN KEY sat automatically TABLE_ibfk_no
ALTER TABLE Orders DROP FOREIGN KEY Orders_ibfk_1;