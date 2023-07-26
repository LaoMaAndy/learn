#!/usr/bin/env python3
r'''
# 数据结构，包含：
    列表、元组、列表推导、del 语句、序列解包/打包、
    集合，字典，循环的技巧，深入条件控制

# 列表详解
    list.append(x) 
      在列表末尾添加一个元素，相当于 a[len(a):] = [x] 。
    list.extend(iterable)
      用可迭代对象的元素扩展列表。相当于 a[len(a):] = iterable 。
    list.insert(i, x)
      在指定位置插入元素。第一个参数是插入元素的索引，
      因此，a.insert(0, x) 在列表开头插入元素， 
      a.insert(len(a), x) 等同于 a.append(x) 。
    list.remove(x)
      从列表中删除第一个值为 x 的元素。未找到指定元素时，
      触发 ValueError 异常。
    list.pop(i)
      删除列表中指定位置的元素，并返回被删除的元素。未指定位置时，a.pop() 
      删除并返回列表的最后一个元素。如果i值错误，则触发IndexError异常
    list.clear()
      删除列表里的所有元素，相当于 del a[:] 。
    list.index(x[, start[, end]])
      返回列表中第一个值为 x 的元素的零基索引。未找到指定元素时，
      触发 ValueError 异常。
    list.count(x)
      返回列表中元素 x 出现的次数。
    list.sort(*, key=None, reverse=False)
      就地排序列表中的元素（要了解自定义排序参数，详见 sorted()）。
    list.reverse()
      翻转列表中的元素。
    list.copy()
      返回列表的浅拷贝。相当于 a[:] 。
  注意：
    insert, remove, sort 等仅修改列表的方法没有打印返回值，返回默认的 None 
    不同类型的数据无法排序。None 无法比较大小。复数之间也无法比较大小。

# 用列表实现堆栈
    堆栈，最后插入的最先取出（“后进先出”）
    添加：append()
    取出：pop()
    是否为空：len()
    空堆栈pop()引发异常：IndexError

# 用列表实现队列
    队列，最先加入的元素，最先取出（“先进先出”）
    然而，列表作为队列的效率很低。因为，在列表末尾添加和删除元素非常快，
      但在列表开头插入或移除元素却很慢（因为所有其他元素都必须移动一位）。
    实现队列最好用 collections.deque
      from collections import deque
      queue.append("Terry") 
      queue.popleft() 

# 列表推导 List Comprehensions
    列表推导式创建列表的方式更简洁。
    以下使用了 map() 内置函数和 lambda 表达式
      squares = list(map(lambda x: x**2, range(10)))
    或使用推导：
      squares = [x**2 for x in range(10)]
    推导的语法：
      [表达式 : 一个或多个 for / if 字句]
    举例：
      x 不等于 y时，组合成的元组构成的list:
        [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]
      等价于：
        combs = []
        for x in [1,2,3]:
            for y in [3,1,4]:
                if x != y:
                    combs.append((x, y))
# 嵌套的列表推导式
    列表推导式中的初始表达式可以是任何表达式，甚至可以是另一个列表推导式。
    矩阵转置：
        matrix = [
            [1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12],
        ]
        [[row[i] for row in matrix] for i in range(4)]
      得到：
        [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]
    相当于：
        transposed = []
        for i in range(4):
            transposed.append([row[i] for row in matrix])
    用内置函数zip()也可实现
        list(zip(*matrix))

# del 语句  The del statement
    无需加括号
    del 语句按索引，而不是值从列表中移除元素。
    del 语句也可以从列表中移除切片，或清空整个列表（之前是将空列表赋值给切片）
    del 也可以用来删除整个变量：
  举例
    a = [-1, 1, 66.25, 333, 333, 1234.5]
    del a[0]
    del a[2:4]
    del a[:]

# 元组 和 序列  Tuples and Sequences
    元组由多个用逗号隔开的值组成，
    举例：
        t = 12345, 54321, 'hello!'
        # Tuples may be nested:
        u = t, (1, 2, 3, 4, 5)
        # but they can contain mutable objects:
        v = ([1, 2, 3], [3, 2, 1])
    输出时，元组都要由圆括号标注，这样才能正确地解释嵌套元组。
    输入时，圆括号可有可无，不过经常是必须的
    元组是 immutable （不可变的）,
      通过解包（见本节下文）或索引访问（如果是 namedtuples，可以属性访问）
    列表是 mutable （可变的），列表元素一般为同质类型，可迭代访问。
    空元组： empty = ()
    1个元素的元组：singleton = 'hello',  

# 元组的打包和解包
    打包： t = 12345, 54321, 'hello!'
    解包：x, y, z = t
        其中，左侧变量和右侧元素的数量应恰好相等。
    序列解包 equence unpacking 
        右侧可以为任何序列
    多重赋值：x, y = y, x
        是元组打包和解包的组合

# 集合 set
    集合是由不重复元素组成的无序容器。
    基本用法包括：
        成员检测、消除重复元素。集合对象支持合集、交集、差集、对称差分等数学运算。
    创建集合：
        使用{} 或 set()
    空集合：
        只能使用set()，不能用{}, {}创建的是空字典
    操作举例：
        basket = {'apple', 'orange', 'apple'}
        'orange' in basket 
        'crabgrass' in basket

        # Demonstrate set operations on unique letters from two words
        a = set('abracadabra')
        b = set('alacazam')
        a - b
        a | b
        a & b
        a ^ b
    集合推导式：
        a = {x for x in 'abracadabra' if x not in 'abc'}
# 字典
    字典是目前唯一的映射类型：Mapping Types 
    字典以 关键字 为索引，关键字通常是字符串或数字，也可以是其他任意不可变类型。
        元组直接或间接地包含了可变对象，就不能用作关键字。列表不能当关键字。
    字典可看做键值对的集合：a set of key: value pairs
        字典的键必须是唯一的。
    空字典 {}
    字典的主要用途:
        通过关键字存储、提取值。
        用 del 可以删除键值对。
        用已存在的关键字存储值，与该关键字关联的旧值会被取代。
        通过不存在的键提取值，则会报错。
    list(d)操作：
        返回该字典中所有键的列表，按插入次序排列
    主要操作：
        in / not in
        d[索引] = 值
        list(d)
    使用dict()创建
        dict() 构造函数可以直接用键值对序列创建字典
    字典推导式
        {x: x**2 for x in (2, 4, 6)}
    用关键字参数指定键值对更便捷：
        dict(sape=4139, guido=4127, jack=4098)

# 循环技术 
    字典中的循环，使用items()：
        for k, v in d.items(): print(k, v)
    序列中循环，使用enumerate()，同时去除索引和值：
        for i, v in enumerate(l): print(i, v)
    zip() 两个序列进行匹配，并循环:
        questions = ['name', 'quest', 'favorite color']
        answers = ['lancelot', 'the holy grail', 'blue']
        for q, a in zip(questions, answers):
            print('What is your {0}?  It is {1}.'.format(q, a))
    reversed() 翻转，然后循环
        for i in reversed(range(1, 10, 2)):
            print(i)
    sorted() 函数，在不改动原序列的基础上，返回一个重新的序列：
        basket = ['apple', 'orange', 'apple']
        for i in sorted(basket):
            print(i)
    set() 去除重复元素：
        basket = ['apple', 'orange', 'apple']
        for f in sorted(set(basket)):
            print(f)
    在循环中修改列表的内容时，需要创建新列表：
    注：'NaN' : not a number
        import math
        raw_data = [56.2, float('NaN'), 51.7,float('NaN'), 47.8]
        filtered_data = []
        for value in raw_data:
            if not math.isnan(value):
                filtered_data.append(value)

# 序列和其他类型的比较
    序列对象的相互比较。使用 字典式 顺序。
    (1, 2, 3)              < (1, 2, 4)
    [1, 2, 3]              < [1, 2, 4]
    'ABC' < 'C' < 'Pascal' < 'Python'
    (1, 2, 3, 4)           < (1, 2, 4)
    (1, 2)                 < (1, 2, -1)
    (1, 2, 3)             == (1.0, 2.0, 3.0)
    (1, 2, ('aa', 'ab'))   < (1, 2, ('abc', 'a'), 4)

'''
from share import prn_title, prn_list

def test_loop_zip():
    prn_title('test_loop_zip()')

    questions = ['name', 'quest', 'favorite color']
    answers = ['lancelot', 'the holy grail', 'blue']
    for q, a in zip(questions, answers):
        print(f'What is your {q}?  It is {a}.')

def test_loop_dict():
    prn_title('test_loop_dict()')
    l = list('This is a test string')
    for i, v in enumerate(l):
        print(i, '-->', v)

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('data_tutorial.py')
        test_loop_dict()
        test_loop_zip()
    test()