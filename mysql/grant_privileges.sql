create user 'root'@'%' identified by '0000';
grant all privileges on *.* to 'root'@'%';
flush privileges;

use mysql;
select user, host from user;