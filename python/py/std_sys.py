#!/usr/bin/env python3
r'''
# sys --- 系统相关的参数和函数 System-specific parameters and functions
# argv 一个列表，其中包含了被传递给 Python 脚本的命令行参数。

'''
import sys
from pprint import pprint

def test_sys_flags():
    ''' sys 变量 '''
    flags = ['sys.byteorder'
             ,'sys.builtin_module_names'
             ,'sys.copyright'
             ,'sys.dont_write_bytecode'
             ,'sys.pycache_prefix'
             ,'sys.exec_prefix'
             ,'sys.executable'
             ,'sys.flags'
             ,'sys.float_info'
             ,'sys.platform'
             ,'sys.int_info'
            ]
    for s in flags:
        if s:
            print(s, '=', end = ' ')
            pprint(eval(s))
    print()

def test_argv():
    print(f'{sys.orig_argv = }')
    n = len(sys.argv)
    print(f'{n = }')
    for i in range(n):
        print(i, ':', sys.argv[i])

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('std_sys.py')
        test_argv()
        test_sys_flags()
    test()