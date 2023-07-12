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
    将一个目标值与多个字面值比较
    格式 match ... case  ... _
      其中，下划线 _ 必定匹配成功
    多个值组合 ｜ 或 or : 
      case 401 | 402 | 404
    match 捕获变量：
    case 中可以组合变量和字面值：
      case (x, y):
    对象绑定：
      case Point(x=x_val, y=y_val):
    match语句赋值规则：
      只有独立名称被赋值，
      带点号的名称foo.bar，属性名称x=和y=不被赋值
      类名称不被赋值
    守卫子句：
      case Point(x, y) if x == y:
    as子句：
      case (Point(x1, y1), Point(x2, y2) as p2):
    文档：
    docs.python.org/3/tutorial/controlflow.html
## 循环的技巧
    enumerate()
    docs.python.org/zh-cn/3/tutorial/datastructures.html#tut-loopidioms

''' 
import math
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
def where_is(p):
    '''match 的变量绑定到类对象
    有些地方还不是太明白。

    '''
    match p:
        case Point(x=0, y=0):
            print("Origin")
        case Point(x=0, y=y_val):
            print(f"Y={y_val}")
        case Point(x=x_val, y=0):
            print(f"X={x_val}")
        case Point(x=x_val, y=y_val):
            print('Somewhere:', f"x={x_val}, y={y_val}")
        case _:
            print('Not a Point')

def test_where_is():
    a = Point(0, 100)
    b = Point(200, 0)
    c = Point(123, 456)
    where_is(a)
    where_is(b)
    where_is(c)


def is_prime(n):
    max_factor = int(math.sqrt(n)) + 1 
    # max_factor = n
    for i in range(2, max_factor):
        if n % i == 0:
            # print(n, '=', i , '*', n//i)
            return False
    # print(n, 'is a prime.')
    return True

def list_prime(i):
    ret = []
    for n in range(2, i):
        if is_prime(n):
            ret.append(n)
    return ret

def test_list_prime():
    print(list_prime(100))


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
        test_list_prime()
        test_where_is()
        pass
    test()