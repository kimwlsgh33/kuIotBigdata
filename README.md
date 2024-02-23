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
        - grant all privileges on *.* to 'root'@'localhost' identified by '1234';
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
        - Linux -> Grant all privileges on *.* to a user

        - Windows -> Connect Linux MySQL Server
        - Windows -> Grant all privileges on *.* to a user

    - Firewall
        - Windows Inbound strategy -> allow 3306 port for MySQL
        - Linux Inbound strategy -> allow 3306 port for MySQL
            - config MySQL Server
                - `sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf`
                - replace `127.0.0.1` with `0.0.0.0` for allow all outbound network
        - confirm MySQL configs
            - `sudo ufw allow mysql`
