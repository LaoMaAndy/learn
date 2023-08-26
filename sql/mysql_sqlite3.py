#!/usr/bin/env python3
r'''
# SQL 语言规范
# 基本概念
    RDBMS: Relational Database Management System
    原子: Atom, 原子数据: Atomic data, 原子性: Atomic
    规范化: normalization
    规范表: normal table
    原子性的步骤：
        同一个列中，没有多个类型相同的值
        同一张表中，没有多个同类数据的列
    第一范式 First Normal Form, 1NF
        每行必须包含原子值
        每行数据必须包含一个独一无二的识别项，成为主键
    第二范式
    第三范式
    主键 Primary Key
        插入数据必须指定主键
        主键不可修改
        合成 synthetic 还是 自然 natural

# 常量
    null(is null, is not null)

# NULL / NOT NULL 未定义
    create table 
# DEFAULT 默认值

# 字面值
    字符串
        单引号，双引号
        反引号
        转义字符 ''  \'
    数字

# 数据类型
    不同的数据库系统使用的名称不完全相同
    CHAR(m)   : m 指定长度
    VARCHAR   : 长度可变，最大长度255
    DEC(m, n) : m 总长度， n 小数点长度
    INT:
    DATE:
    DATATIME:
    TIMESTAMP:
    TIME:
    BLOB:

# 操作符 operator
    sqlite3 不支持：
    创建 create database,  use,  

    sqlite3 支持
    创建 create,  
    
    插入
        insert into...value/values...
    删除
        delete from ... where ...
    选择
        select,  from,  
    条件
        where,  where not
    比较：=  <>  >  <  >=  <=  is  is not
        between...and... (相当于a<=x<=b) 
        in (... , ...)  not in 
        like 通配符（% 任意内容  _ 一个字符）
    逻辑：and,  or,  not 

# 数字函数
# 字符串函数
    大小写：UPPER(), LOWER()

# 日期函数


# 创建数据库
    CREATE DATABASE data_base_name
    USE data_base_name

    sqlite3 db_file_name
    .open --new 
    .open 

# 创建表，指定field名称和类型：
    CREATE TABLE my_contacts
    (
        last_name VARCHAR(30), 
        first_name VARCHAR(20), 
        email VARCHAR(50), 
        gender CHAR(1), 
        birthday DATE, 
        profession VARCHAR(50), 
        location VARCHAR(50), 
        status VARCHAR(20), 
        interests VARCHAR(100), 
        seeking VARCHAR(100)
    );

# 创建带有主键PK的表
   CREATE TABLE your_table
    (
        contact_id INT NOT NULL AUTO_INCREMENT,
        last_name VARCHAR(30), 
        first_name VARCHAR(20), 
        email VARCHAR(50), 
        gender CHAR(1), 
        birthday DATE, 
        profession VARCHAR(50), 
        location VARCHAR(50), 
        status VARCHAR(20), 
        interests VARCHAR(100), 
        seeking VARCHAR(100),
        PRIMARY KEY (contact_id)
    );
    主键自动递增: AUTO_INCREMENT,
    * sqlite3中不兼容
    CREATE TABLE other_contacts
    (
        contact_id INT NOT NULL AUTO_INCREMENT,
    ...)
    * 在MS SQL中，自动递增为 INDEX
    * sqllite 举例
    CREATE TABLE company(
        id INTEGER PRIMARY KEY   AUTOINCREMENT,
        name           TEXT      NOT NULL,
        age            INT       NOT NULL,
        address        CHAR(50),
        salary         REAL
        );


# 核对表结构
    DESC my_contacts;
    .schema my_contacts

# 删除表
    DROP TABLE my_contacts;
    
# 插入一条记录：
    INSERT INTO ... (...) VALUES (...)
    INSERT INTO my_contacts
        (last_name, first_name, email, gender, 
        birthday, profession,
        location, status, interests, seeking )
    VALUES
        ('Anderson', 'Jillian', 'jill_anderson@ breakneckpizza.net', 'F', 
        '1980-09-05', 'Technical Writer',
        'Palo Alto, CA', 'Single', 'Kayaking, Reptiles', 'Relationship, Friends'
        );

# 选择记录 / 条件选择
    SELECT * FROM my_contacts;
    SELECT * FROM my_contacts WHERE first_name = "Li";
    SELECT data_fields FROM table_name WHERE express 
    SELECT drink_name FROM easy_drinks WHERE main = 'soda' AND amount1 > 1;

# 记录的顺序/重复记录
    最后一条记录不一定是最新纪录
    表中不应有重复纪录

# 删除记录
    可以删除 行/多行， 不可以删除 列
    DELETE FROM my_contacts WHERE seeking = 'Friends';
    删除全部行：
        DELETE FROM your_table
# 修改纪录
    UPDATE ... SET ... WHERE ...
    UPDATE table_name SET column_name = newvalue ... WHERE ...
    UPDATE my_contacts SET seeking = 'friend' WHERE seeking = 'friends';
    使用field 字段名作为变量：
    UPDATE drink_info SET cost = cost + 1 WHERE drink_name='Blue Moon'

# 显示表创建的方式 SHOW
    sqlite 不可用
    SHOW CREATE DATABASE databasename; 
    SHOW CREATE TABLE my_contacts; 显示表的创建信息：
    SHOW COLUMNS FROM tablename; 显示列信息
    SHOW INDEX FROM tablename;
    SHOW WARNINGS;

# 
'''


if __name__ == "__main__":
    print(__doc__)
    def test():
        print("mysql_sqlite3.py")
    test()
