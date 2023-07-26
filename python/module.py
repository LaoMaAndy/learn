#!/usr/bin/env python3
r'''
# 模块
# 关键字 keywords
    脚本，模块，导入，主模块
        script, module, import, main
    区别：module /ˈmɑːdʒuːl/ ; model/ˈmɑːdl/

# 概念
    模块是包含 Python 定义和语句的文件，其文件名是模块名加后缀名 .py 
    __name__ 可以获取模块名

# 详解
    模块包含可执行的语句和函数定义，用于初始化模块
    仅在导入语句中第一次遇到模块名时执行
  使用模块中的变量：
    模块名. 变量名
  通常但不要求将所有 import 语句放在模块（或脚本）的开头
  import 语句
    将名称导入到当前命名空间中：
        from fibo import fib, fib2
    此语句不会导入模块名称：
        上例中，fibo 为未定义
    导入模块中的所有名称
        from fibo import *
        这种导入方式导入所有不以下划线_开头的名称
        通常不建议从模块或包内导入 *
    格式：
        import ... as ...
        from ... import ... as ...
    每次解释器会话只导入一次模块。如果更改了模块内容，必须重启解释器；
        仅交互测试一个模块时，也可以使用 importlib.reload():
        import importlib;
        importlib.reload(modulename)。
    执行模块
        方式：python module_name.py <arguments>
        执行时，将 __name__ 赋值为 "__main__"，不同于导入
        如需要使用参数，需：
            import sys
            fib(int(sys.argv[1]))
# 模块搜索路径
    内置模块：解释器首先搜索具有该名称的内置模块。
        这些模块的名字被列在 sys.builtin_module_names 中
    如果没有找到，它就在变量 sys.path 给出的目录列表中搜索。
    sys.path 从这些位置初始化:


    
'''


import sys

from pprint import pprint
from share import prn_title, prn_list

def test_import():
    print('test_import()')
    print('Current __name__ is: ')
    pprint(__name__)
    print('sys.path: ')
    prn_list(sys.path)
    print('sys.builtin_module_names: ')
    prn_list(sys.builtin_module_names)

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('module.py')
        test_import()
    test()
