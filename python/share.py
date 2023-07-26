#!/usr/bin/env python3
r'''自己编写的一些公用函数

'''

#import sys
#sys.path.append('./public')
#sys.path.append('../public') 

import math
from keyword import iskeyword

def prn_list(list_item, row = 4, width = 0):
    '''打印列表，分多个栏
    默认打印4栏，每栏宽度默认20
    '''
    if width == 0:
        width = int(80 // row) - 1
    try:
        for i in range(0, len(list_item), row):
            # 每行先打印两个空格
            print('  ', end='')
            # 此处有可能超出 列表 索引范围，做异常处理
            for j in range(row):
                # 实现方法使用 'string'.format()。不用。
                #print(f'{s:{w}}'.format(s=list_item[i+j], w=width), end='')
                # 使用f'...' 效果更佳
                print(f'{list_item[i+j]:{width}.{width}}', end='')
                # 每栏结尾打印一个空格，确保栏之间分开
                print(' ', end = '')
            print()
    except IndexError:
        return
    finally:
        print()

def test_prn_list():
    prn_title('test_prn_list()')
    t = dir(int)
    prn_list(t)
    prn_list(t, 3)
    prn_list(['aaa','bbb','ccc'])
    prn_list('uvwxyz')

def prn_title(s, width=40, frame=''):
    '''打印标题
    在标题外侧添加边框，并居中打印标题
        width: 整数。标题宽度，默认40字符
        frame: 字符串。标题边框
    frame边框字符串长度可以为1，2，3，4
        默认打印边框：'_||‾'
    '''
    l = len(frame)
    if l == 0:
        frame = '_||‾'
    top = 0
    if l == 1:
        left = right = bottom = 0
    elif l == 2:
        left = right = 1
        bottom = 0
    elif l == 3:
        left = 1
        right = 2
        bottom = 0
    else:
        left = 1
        right = 2
        bottom = 3
    print(frame[top] * width)
    print(frame[left] + s.center(width - 2) + frame[right])
    print(frame[bottom] * width)

def test_prn_title():
    prn_title("test_prn_title()")
    prn_title("test_prn_title()", frame = '*')
    prn_title("test_prn_title()", 40, '=|')
    prn_title("test_prn_title()", frame='*|-')
    prn_title("test_prn_title()", 10, frame='*|-')

def prn_express(exp, width=None, title=None):
    '''打印：表达式，表达式结果，结果类型，备注信息
    默认打印 4 栏，
        栏标题默认为：'express', 'result', 'result type', 'comment'
    参数：
        exp: 列表。列表单数项目为表达式，偶数项目为注释信息。
            项目类型都为字符串。表达式将使用 eval() 求值。
        width: 宽度。列表。包含4个宽度值
        title: 标题。列表。包含4个标题字符串

    '''
    if width == None: 
        width=[20, 20, 20, 20]
    if title == None: 
        title = ['express', 'result', 'result type', 'comment']
    if len(exp) < 1:
        print('exp: ["express", "comment", ...]')
        return
    
    sep_line =  '-' * (width[0]-1) + '|' + \
                '-' * (width[1]-1) + '|' + \
                '-' * (width[2]-1) + '|' + \
                '-' * (width[3]) 
    title = f'{title[0]:^{width[0]}}' \
            f'{title[1]:^{width[1]}}' \
            f'{title[2]:^{width[2]}}' \
            f'{title[3]:^{width[3]}}'
    print(sep_line)
    print(title)
    print(sep_line)

    for i in range(0, len(exp), 2):
        # 用eval() 求表达式的值，用type() 求值的类型
        try:
             # 表达式：允许错误的表达式。如果表达式错误，设定一个默认值
            result = eval(exp[i])
            result_type = type(result)
        except (NameError, SyntaxError, TypeError, ValueError):
            result = 'Error'
            result_type = '---'
        # 每行有四个部分，分别生成f格式字符串
        part_exp = f'{exp[i]:{width[0]-1}.{width[0]-1}}'
        if result_type == type(float()):
            # 对于浮点数，单独设定格式
            part_result = f'{result:>{width[1]-1}.3f}'    
        else:
            part_result = f'{repr(result):>{width[1]-1}.{width[1]-1}}'
        part_type = f'{repr(result_type):^{width[2]+1}.{width[2]+1}}'
        try:
            # 如果没有最后的注释项，exp[i+1]会引发异常。
            print(' ', part_exp, part_result, 
                        part_type, exp[i+1], sep = '')
        except IndexError:
            return
    # 以下实现使用 'str'.format()
    """
    fmt_list = ['{:' + str(x) + '}' for x in width]
    fmt = ' ' + ' '.join(fmt_list)
    sep_list = ['|' + '-' * x for x in width]
    sep = ''.join(sep_list)
    print(sep)
    print(fmt.format(*title))
    print(sep)
    for i in range(0, len(exp), 2):
        # 表达式：可以为错误的表达式。如果表达式错误，设定一个默认值
        try:
            result = eval(exp[i])
            result_type = type(result)
        except (NameError, SyntaxError, TypeError, ValueError):
            result = 'Error'
            result_type = '---'
        try:
            # 如果没有最后的注释项，则会引发异常。
            print(fmt.format(exp[i], repr(result), repr(result_type), exp[i+1]))
        except IndexError:
            return
    """


# make an alias
print_exp = prn_express

def test_print_exp():
    exp_list = ['3 + 4 - 9 + 4*5', '整数运算结果类型为整数',
        '3.1 + 2 - 3.1' , '浮点数表达式结果为浮点数',
        '17 // 6' , '整数的下整除，结果为整数',
        '343.4 // 4.5' , '浮点数的下整除，结果为浮点数',
        '5.3 % 4.1' , '浮点数求余，结果为浮点数',
        '5 % 4' , '整数求余，结果为整数',
        '2 ** 3' , '整数的幂运算，结果为整数',
        '2 ** 3.0' , '浮点数的幂运算，结果为浮点数',
        '3E1', '科学计数法表示的数字都是浮点数',
        '(3 + 4j)','复数可以看作实部和虚部的加法运算',
        '"-------"' , '--------',
        '"abcde"[3]' , '字符串索引，下标不能超范围',
        '"abcdef"[::]' , '字符串切片',
        '"abcdef"[-12:21]' , '起始和终止位置任意',
        '"abcdef"[21:-42]' , '起始和终止位置任意',
        'fdsaewaf+fdjew432', '错误表达式',
    ]
    print_exp(exp_list)

if __name__ == '__main__':
    print(__doc__)
    def test():
        test_prn_title()
        test_prn_list()
        test_print_exp()
    test()
