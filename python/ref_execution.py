#!/usr/bin/env python3
r'''
# 执行模型 Execution model
    代码块 code blocks
    以下几个都属于代码块：   
        模块、函数体和类定义。
        交互式输入的每条命令都是代码块。
        一个脚本文件（作为标准输入发送给解释器或是作为命令行参数发送给解释器的文件）也是代码块。
        一条脚本命令（通过 -c 选项在解释器命令行中指定的命令）也是代码块。
        通过在命令行中使用 -m 参数作为最高层级脚本（即 __main__ 模块）运行的模块也是代码块。
        传递给内置函数 eval() 和 exec() 的字符串参数也是代码块。
    代码块在 执行帧 中被执行。 execution frame
    
# 名称的绑定  Naming and binding


'''
class MyClass:
    j = 10
    def foo(self):
        print(f'{self.j =}')

def test_scope():
    m = MyClass()
    m.foo()

def test_nonlocal():
    j = 10
    def inner_func():
        for i in range(10):
            pass
        nonlocal j
        j += 1 
    inner_func()
    print(f'{j = }')

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ref_data.py')
        test_nonlocal()
        test_scope()
    test()
