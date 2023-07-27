#!/usr/bin/env python3
r''' 成语 / 特殊写法 / 习惯写法
# 目录：
    将参数默认值设为可变类型的潜在问题： 
        def share_arg(i, arg=[])
    自制的range()类
        实现了 __iter__(), __next()__
    自定义类，继承str，并增加__index__()
        MyStr
'''
import sys
from share import prn_title

def return_a_number(self):
    # print('')
    return 77

def test_return_a_number():
    prn_title('test_return_a_number()')
    print(f"{return_a_number('a') = }")

class MyStr(str):
    def __init__(self, arg):
        str.__init__(arg)

def test_MyStr():
    prn_title('test_MyStr()')
    m = MyStr('abcdefghijk')
    print(f'{m = }')
    MyStr.__index__ = return_a_number
    print(f"{int(m) = }")

class MyRange():
    '''自制的range()类:
    基本功能与range()相同
    '''
    def __init__(self, *arg):
        self.start = self.end = 0
        self.step = 1
        s = len(arg)
        if s == 1:
            self.end = arg[0]
        elif s == 2:
            self.start = arg[0]
            self.end = arg[1]
        elif s >= 3:
            self.start = arg[0]
            self.end = arg[1]
            self.step = arg[2]

        if self.step == 0:
            raise ValueError('step cannt be 0')
        self.current = self.start

    def __iter__(self):
        return self

    def __next__(self):
        if self.step > 0 and self.current < self.end:
            self.current += self.step
            return self.current - self.step
        if self.step < 0 and self.current > self.end:
            self.current += self.step
            return self.current - self.step
        raise StopIteration

def test_myrange():
    prn_title('test_myrange()')
    print(f'{list(MyRange(10)) = }')
    print(f'{list(MyRange(2, 5)) = }')
    print(f'{list(MyRange(0, 10, 2)) = }')
    #print(list(MyRange(0, 10, 1, 4)))
    #print(list(MyRange(0, 10, 0)))
    print(f'{list(MyRange(10, 9, -2)) = }')
    print(f'{list(MyRange(10, 0, -1)) = }')


## 函数定义相关 ##
def share_arg(i, arg=[]):
    '''特殊写法
    函数参数默认值为空列表，
    当该列表的值改变后，所有函数调用，该参数默认值都改变。
    可理解为：编译器创建了一个匿名变量，将引用赋值给参数
    若避免该情况，需 arg=None
    然后在函数内部 arg=[]
    
    '''
    arg.append(i)
    return arg

def test_share_arg():
    print('Function share an argument:')
    print(share_arg(100))
    print(share_arg('share'))
    print(share_arg(222))
    print(share_arg(None))

def dont_share_list_arg(i, arg=None):
    '''成语写法：
    避免函数参数共享可变类型：
    若避免该情况，需 arg=None
    然后在函数内部 arg=[]
    '''
    if arg is None:
        arg = []
    arg.append(i)
    return arg

def test_dont_share_list_arg():
    print('Function dont share an argument:')
    print(dont_share_list_arg(100))
    print(dont_share_list_arg('share'))


if __name__ == '__main__':
    print(__doc__)
    def test():
        test_share_arg()
        test_dont_share_list_arg()
        test_myrange()
        test_return_a_number()
        test_MyStr()
    test()


