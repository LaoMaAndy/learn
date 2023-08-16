#!/usr/bin/env python3
r'''

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

# NULL / NOT NULL 未定义
    create table 
# DEFAULT 默认值

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

# 字面值
    字符串
        单引号
        转义字符
    数字

# 核对表结构
    DESC my_contacts;
    .schema my_contacts

# 删除表
    DROP TABLE my_contacts;
    
# 插入一条记录：
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




'''


if __name__ == "__main__":
    print(__doc__)
    def test():
        print("mysql_sqlite3.py")
    test()
