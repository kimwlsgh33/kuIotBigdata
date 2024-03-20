# kuIotBigdata

C/C++ database arduino respberrypi Iot

---

## 2024-02-22

---

- Instruction.
- Sharing google slide share link
- gitHub sign up
- create gitHub repository
- setting ubuntu hangul
- VSCode install

```shell
sudo apt install code_1.86.2-1707854558_amd64.deb
```

- git install

```shell
sudo apt install git
git clone https://github.com/kimwlsgh33/kuIotBigdata.git
```

- Install MySQL workbench (windows, ubuntu)
- Install MySQL DBMS (windows, ubuntu)
- Install VSCode MySQL extension
- Chapter01 데이터베이스 개론
- Chapter03 데이터베이스 기초
  - DB 만들기 create database;
  - DB table 3개 만들기 create table (book, order, customer)
  - DB data 넣기 insert into ... values (...)
  - 유저 만들기, 권한 설정하기
    - grant all privileges on _._ to 'root'@'localhost' identified by '1234';
  - Windows cli 에서 testDB 생성하기

---

## 2024-02-23

---

- Instruction
- Altering user's `mysql_native_password` to use mysql without sudoers
  - `ALTER USER 'user'@'localhost' IDENTIFIED WITH mysql_native_password by 'password';`
  - Setting default password to mysql_native_password if we create a new user
- Connecting MySQL Server to VSCode 'MySQL' plugin
- Write SQL in MySQL workbench and store in project's mysql directory
  - Added:
    - create_user.sql
    - create_table.sql
    - insert_data.sql
    - select_data.sql
- Proceding Chapter 3, p144 ~ p158
  - How to use `SELELCT`
  - Aggregation function
- Proceding Chapter 2, Database Model
  - Integrity Constraints (Having strong normal principle)
  - Relation Structure (relation, tuple, attribute)
  - Relation Algebra (How to write demands into symbols)
- Cross DB connection with Linux & Windows

  - Linux/MySQL
  - Windows/MySQL
  - Connect another DBMS

    - Linux -> Connect Windows MySQL Server
    - Linux -> Grant all privileges on _._ to a user

    - Windows -> Connect Linux MySQL Server
    - Windows -> Grant all privileges on _._ to a user

  - Firewall
    - Windows Inbound strategy -> allow 3306 port for MySQL
    - Linux Inbound strategy -> allow 3306 port for MySQL
      - config MySQL Server
        - `sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf`
        - replace `127.0.0.1` with `0.0.0.0` for allow all outbound network
    - confirm MySQL configs
      - `sudo ufw allow mysql`

---

## 2024-02-25

[C : The basic types of C](c_src/notes/20240225_types.md)

---

## 2024-02-26

[C : Operator in C](c_src/notes/20240226.md)

---

## 2024-02-27

[C : Control Flow in C](c_src/notes/20240227.md)

---

## 2024-02-28

[C : Loop and Redirection in C](c_src/notes/20240228.md)

---

## 2024-02-29

---

- Instruction
- What is a `Makefile`?

  - You can custom command for cli generally to compiling C files
    - `command: example.c`
  - You can create variable in Makefile
    - `variable = value`
  - You can obmit a explicit compiling c file
    - `cfile with out extension: $@`
  - You can execute a `Makefile`
    - Makefile's all command
      - `make`
    - Makefile's other commands
      - `make command`

- What are advantages of `Makefile`
  - `make` will watch the source file and skip few step if it already exists.
  - `make` can use **variable**
- SQL languages

  - aggregation `sum, avg, min, max`
  - combine many tables
    - You need to take care of cartesian product
      - `where table1.columnid = table2=columnid`
    - `FROM table1, table2`
    - OUTER vs. INNER
      - OUTER is UNION
        - `FROM table1 LEFT OUTER JOIN table2`
        - `FROM table1 LEFT JOIN table2`
      - INNER is intersection
        - `FROM table1 INNER JOIN table2`
    - UNION
      - `SELECT ... UNION SELECT ...`
  - DDL
    - **CREATE** structure of database
    - **ALTER** structure of database
    - **DROP** structure of database
  - DCL

    - **INSERT** data into database
    - **UPDATE SET** data in database
    - **DELETE** data from database

  - built-in functions
    - functions such like Math, Date

---

## 2024-03-04

[C : Array](c_src/notes/20240304.md)

---

## 2024-03-05

[C : Pointer](c_src/notes/20240305.md)

---

## 2024-03-06

[C : Pointer as a function argument](c_src/notes/20240306.md)

---

## 2024-03-07

[DB : View and Index](mysql/notes/20240307.md)

---

## 2024-03-08

[DB : MySQL in C and Python & Nomalization](/mysql/notes/20240308.md)

---

## 2024-03-11

[C : ](/c_src/notes/20240311.md)

---

## 2024-03-12
## 2024-03-13
## 2024-03-14
## 2024-03-15

## 2024-03-19

[C : Project](/c_src/notes/project.md)
