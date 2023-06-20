#!/usr/bin/env python3
file_string = '''python函数知识要点：
定义函数 def
文档字符串 docstring
    * 模块开始处
    * 函数名之后
    * 可以给变量赋值
符号表：
    * 局部，外层，全局
    * nonlocal, global
    * vars(), locals(), globals()
参数：
    * 值传递，引用传递
函数名与函数对象, 例如：
    f = fib
    f100 = fib(100)
返回值:
    * 无返回值时，为None
函数参数：
    * 参数默认值
    * 默认值可以使用变量，但只求值一次
'''
a_number = 10
def print_int(i = a_number):
    ''' 此处函数默认值等于一个全局变量，
    该默认值只赋值一次，当全局变量变化后，
    函数默认值仍保持不变'''
    print(i)
def test_print_int():
    print('function default argument value: 20')
    print_int()
    print('change default var: 20')
    a_number = 20
    print_int()
    
def feb_prn(max):
    '''打印斐波那契数列'''
    a, b = 0, 1
    print('不大于', max, '的斐波那契数列:', sep='')
    while a <= max:
        print(a, end=', ')
        a, b = b, a+b
    print('')

def feb(count=0, limit=0, start=0):
    ''' 返回斐波那契数列, 列表。
        列表从0，1开始
        count: 数列元素个数
        limit: 不超过最大值
        start: 开始值
        无参数时返回空列表
    '''
    # print('count:', count, "limit:", limit)
    # 处理参数特殊情况
    if (count<=0 and limit<=0):
        return []
    a, b = start, start+1
    result = [start]
    i = 1       # 已经添加了一个值，计数从1开始
    while True:
        a, b = b, a + b
        if count!=0 and i>=count:
            break
        if limit!=0 and a>limit:
            break
        result.append(a)
        i += 1
    return result

def test_feb():
    print("feb(0):", feb(0))
    print("feb(1):", feb(1))
    print("feb(2):", feb(2))
    print("feb(5):", feb(5))
    print("feb(limit=30):", feb(limit=30))
    print("feb(count=3, limit=1000):", feb(count=3, limit=1000))
    print("feb(count=10, limit=30):", feb(count=10, limit=30))
    print("feb(count=5, start=1000):", feb(count=5, start=1000))

def test_feb_prn():
    feb_prn(1)
    feb_prn(20)

def test_ref_func():
    '''函数名和函数对象:
        * 定义一个变量，引用另一个函数对象
        * 定义一个变量，引用函数对象，附带变量列表
    '''
    f = feb_prn
    f(30)
    f50 = f(50)
    
def no_return(i):
    ''' 函数返回值默认返回None，即使没有return'''
    i += 1

def test_no_return():
    print(no_return(1))

def demo():
    print(file_string)
    test_feb_prn()
    test_no_return()
    test_ref_func()
    test_print_int()
    test_feb()
    
if __name__ == '__main__':
    demo()

    
