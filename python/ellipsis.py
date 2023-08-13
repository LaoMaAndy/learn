#!/usr/bin/env python3
r'''
When Do You Use an Ellipsis in Python?
https://realpython.com/python-ellipsis/

# Ellipsis是内置ellipsis类的唯一对象
    与省略号字面值 "..." 相同。 该特殊值主要是与用户定义的容器数据类型的扩展切片语法结合使用。 

# 在 Python 中使用省略号作为占位符
    def do_nothing(): ...
    此处 ... 等同 pass
    类中的虚函数常用此写法



'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ellipsis.py')
    test()