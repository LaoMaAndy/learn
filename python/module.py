#!/usr/bin/env python3
r'''
# 模块
# 关键字 keywords
    脚本，模块，导入，主模块
        script, module, imported, main

  模块是包含 Python 定义和语句的文件，其文件名是模块名加后缀名 .py 
  __name__ 可以获取模块名

'''

from share import prn_title

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('module.py')
    test()
