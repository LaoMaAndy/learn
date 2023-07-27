#!/usr/bin/env python3
r'''
Python 语言参考手册
本参考手册介绍了 Python 句法与“核心语义”。在力求简明扼要的同时，我们也尽量做到准确、完整。
    有关内置对象类型、内置函数、模块的语义在 Python 标准库 中介绍。
    有关本语言的非正式介绍，请参阅 Python 教程 。
    对于 C 或 C++ 程序员，我们还提供了两个手册：
        扩展和嵌入 Python 解释器介绍了如何编写 Python 扩展模块，
        Python/C API 参考手册 则详细介绍了 C/C++ 的可用接口。

1. 概述       Introduction
1.1. 其他实现   Alternate Implementations
1.2. 标注     Notation

2. 词法分析     Lexical analysis
2.1. 行结构    Line structure
2.2. 其他形符  Other tokens
2.3. 标识符和关键字    Identifiers and keywords
2.4. 字面值    Literals
2.5. 运算符    Operators
2.6. 分隔符    Delimiters

3. 数据模型     Data model
3.1. 对象、值与类型    Objects, values and types
3.2. 标准类型层级结构   The standard type hierarchy
3.3. 特殊方法名称     Special method names
3.4. 协程         Coroutines

3. 数据模型     Data model
中文：
https://docs.python.org/zh-cn/3/reference/datamodel.html
英文：
https://docs.python.org/3/reference/datamodel.html


4. 执行模型     Execution model
4.1. 程序的结构  Structure of a program
4.2. 命名与绑定  Naming and binding
4.3. 异常     Exceptions

5. 导入系统     The import system
5.1. importlib  importlib
5.2. 包      Packages
5.3. 搜索     Searching
5.4. 加载     Loading
5.5. 基于路径的查找器   The Path Based Finder
5.6. 替换标准导入系统   Replacing the standard import system
5.7. 包相对导入      Package Relative Imports
5.8. 有关 __main__ 的特殊事项  Special considerations for __main__
5.9. 参考文献   References

6. 表达式  Expressions
6.1. 算术转换   Arithmetic conversions
6.2. 原子     Atoms
6.3. 原型     Primaries
6.4. await 表达式  Await expression
6.5. 幂运算符   The power operator
6.6. 一元算术和位运算   Unary arithmetic and bitwise operations
6.7. 二元算术运算符    Binary arithmetic operations
6.8. 移位运算   Shifting operations
6.9. 二元位运算  Binary bitwise operations
6.10. 比较运算  Comparisons
6.11. 布尔运算  Boolean operations
6.12. 赋值表达式     Assignment expressions
6.13. 条件表达式     Conditional expressions
6.14. lambda 表达式    Lambdas
6.15. 表达式列表     Expression lists
6.16. 求值顺序  Evaluation order
6.17. 运算符优先级    Operator precedence

7. 简单语句     Simple statements
7.1. 表达式语句  Expression statements
7.2. 赋值语句   Assignment statements
7.3. assert 语句  The assert statement
7.4. pass 语句    The pass statement
7.5. del 语句     The del statement
7.6. return 语句  The return statement
7.7. yield 语句   The yield statement
7.8. raise 语句   The raise statement
7.9. break 语句   The break statement
7.10. continue 语句   The continue statement
7.11. import 语句     The import statement
7.12. global 语句     The global statement
7.13. nonlocal 语句   The nonlocal statement

8. 复合语句     Compound statements
8.1. if 语句  The if statement
8.2. while 语句   The while statement
8.3. for 语句     The for statement
8.4. try 语句     The try statement
8.5. with 语句    The with statement
8.6. match 语句   The match statement
8.7. 函数定义   Function definitions
8.8. 类定义    Class definitions
8.9. 协程     Coroutines

9. 顶级组件     Top-level components
9.1. 完整的 Python 程序  Complete Python programs
9.2. 文件输入   File input
9.3. 交互式输入  Interactive input
9.4. 表达式输入  Expression input
10. 完整的语法规范     Full Grammar specification


''' 


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('Reference.py')
    test()