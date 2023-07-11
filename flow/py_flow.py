#!/usr/bin/env python3
r'''
Python流程控制 statements
## while 语句：循环
    代码举例：
    i = 0
    while i < 10:
        print(i)
        i += 1

## if 语句：分支
    if ... elif ... else
    代码举例：
    if x < 0:
        print('...')
    elif x == 0:
        print('...')
    else:
        print('...')
    多个elif 相当于 switch case 语句
    python 中使用 match 语句 switch...case

## for 语句：迭代
    迭代顺序：
      对于列表、字符串等序列，顺序相同
      对于集合，顺序不确定
      对于集合，不可迭代同时修改，方法是：
        1) 重建副本进行迭代，或
        2) 创建一个新集合，将修改后的值放入
## range()
    range(0, 10)
      返回一个可迭代对象
    内置函数，可生成级数
      range(n):       0...n-1
      range(a, b)     a...b-1
      range(a, b, s)  a...b-1, 步长s, s可为负数
    组合用法：list() 和 range()
      list(range(0, 100, 2))
    组合用法：range() 和 len()
      for i in range(len(a))
    组合用法：sum() 和 range()
      sum(range(1, 101))

## 循环中的 break, continue, else子句(clause)
    break
      跳出最近的 for 或 while 循环 
    else 子句：
      while条件为假时，for循环完毕后，执行else子句
      break终止循环时，不执行
## pass语句
    占位符，不执行任何操作
    最小的类：
      class MyEmptyClass:
        pass
    空函数：
      def a_function():
        pass
    空循环：
      while True:
        pass
## match 语句
    
## 循环的技巧
    enumerate()
    https://docs.python.org/zh-cn/3/tutorial/datastructures.html#tut-loopidioms

''' 
import math

def is_prime(i, prn='no_print'):
    y_str = 'yYyesYESYesTrueTRUE'
    if y_str.find(prn) == -1:
        prn_or_not = False
    else:
        prn_or_not = True

    l = []
    for n in range(2, i):
        max_factor = int(math.sqrt(n))
        # max_factor = n
        for x in range(2, max_factor):
            if n % x == 0:
                if prn_or_not:
                    print(n, '=', x, '*', n // x)
                break
        else:
            if prn_or_not:
                print(n, ': prime')
            l.append(n)
    return l
def test_is_prime():
    print(is_prime(1_000_000, prn='Y'))


def else_clause():
    for i in range(10):
        print(i, end = ',')
    else:
        print()
        print('all done.')

def iter_col():
    '''迭代字典类型
        修改字典的 key 或 value，可采用如下方法：
    '''
    users = {'andy': 'active', 
             'alice': 'deactive', 
             'laoma': 'active', 
             'leo': 'deactive',
             'kite': 'active'
             }
    # 修改集合，方法一
    for k, v in users.copy().items():
        if v == 'deactive':
            del users[k]
    print(users)
    # 修改集合，方法二
    new_collect = {}
    for k, v in users.items():
        new_collect[k.capitalize()] = v
    print(new_collect)

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('here is test:')
        iter_col()
        else_clause()
        test_is_prime()
        pass
    test()