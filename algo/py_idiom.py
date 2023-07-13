#!/usr/bin/env python3
file_string='''\
Idiom of python language.
Python的一些习惯写法，成语以及一些容易出问题的片段。\
## 函数默认参数问题：
    def share_arg(i, arg=[])

'''

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
    def demo():
        test_share_arg()
        test_dont_share_list_arg()
        pass
    print(file_string)
    demo()


