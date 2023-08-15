#!/usr/bin/env python3
r'''
# 以下内容以 PostgreSQL 为准
    http://www.postgres.cn/docs/12/

# 数据库内容分类：
    Data Type 数据类型：数字、字符、时间、其余
    KeyWord 关键字：各种指令及组合
    Function 函数: 
        string 字符串函数、
        numeric/math 数字/数学 函数
        advance 高级函数


# SQL指令 不区分大小写。习惯上将指令部分大写，将用户名称小写
    指令文件扩展名 .sql 
    注释行： /*  */
    在交互环境，指令结束使用分号 ;

# 数据类型
    基本约定：
        M   最大长度
        D   小数点后的位数
        fsp 适用于时间，表示秒之后小数部分的精度0～6位
## 数字类型
    精确的数值数据类型（ 
        INTEGER
        SMALLINT
        DECIMAL
        NUMERIC
    近似数值数据类型
        FLOAT
        REAL
        DOUBLE
        PRECISION
    关键字 INT 是 INTEGER 的同义词，
    关键字 DEC 和 FIXED 是 DECIMAL 的同义词。 

## 日期类型
## 字符串类型
## JSON数据类型
## 默认值
## 存储要求
## 选择正确类型

# 创建数据库
    CREATE DATABASE data_base_name

# 选择当前数据库
    USE data_base_name

# 创建表，指定field名称和类型：
    CREATE TABLE my_contacts (
        last_name VARCHAR(30), 
        first_name VARCHAR(20), 
        email VARCHAR(50), 
        birthday DATE, 
        profession VARCHAR(50), 
        location VARCHAR(50), 
        status VARCHAR(20), 
        interests VARCHAR(100), 
        seeking VARCHAR(100)
    );

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

'''


if __name__ == "__main__":
    print(__doc__)  