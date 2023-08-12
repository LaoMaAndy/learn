#!/usr/bin/env python3
r'''
# 复合语句 Compound statement
    复合语句是包含其它语句（语句组）的语句；它们会以某种方式影响或控制所包含其它语句的执行。 
        通常，复合语句会跨越多行，虽然在某些简单形式下整个复合语句也可能包含于一行之内。
    if, while 和 for 语句用来实现传统的控制流程构造。 
    try 语句为一组语句指定异常处理和/和清理代码，而 
    with 语句允许在一个代码块周围执行初始化和终结化代码。 
    函数和类定义在语法上也属于复合语句。

    一条复合语句由一个或多个‘子句’组成。 一个子句则包含一个句头和一个‘句体’。 
        特定复合语句的子句头都处于相同的缩进层级。 每个子句头以一个作为唯一标识的关键字开始并以一个冒号结束。 
        子句体是由一个子句控制的一组语句。 
        子句体可以是在子句头的冒号之后与其同处一行的一条或由分号分隔的多条简单语句，
        或者也可以是在其之后缩进的一行或多行语句。 只有后一种形式的子句体才能包含嵌套的复合语句；
    还要注意的是在这种情形下分号的绑定比冒号更紧密，因此在以下示例中，所有 print() 调用或者都不执行，或者都执行:
        if x < y < z: print(x); print(y); print(z)
    概述：
    compound_stmt ::=  if_stmt
                       | while_stmt
                       | for_stmt
                       | try_stmt
                       | with_stmt
                       | match_stmt
                       | funcdef
                       | classdef
                       | async_with_stmt
                       | async_for_stmt
                       | async_funcdef
    suite         ::=  stmt_list NEWLINE | NEWLINE INDENT statement+ DEDENT
    statement     ::=  stmt_list NEWLINE | compound_stmt
    stmt_list     ::=  simple_stmt (";" simple_stmt)* [";"]

    请注意语句总是以 NEWLINE 结束，之后可能跟随一个 DEDENT。 
        还要注意可选的后续子句总是以一个不能作为语句开头的关键字作为开头， 因此不会产生歧义
        （‘悬空的 else’问题(‘dangling else’ problem)在 Python 中是通过要求嵌套的 if 语句必须缩进来解决的)。

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ref_compound_statements.py')
    test()