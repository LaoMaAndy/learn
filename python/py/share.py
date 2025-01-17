#!/usr/bin/env python3
r'''自己编写的一些公用函数

'''

#import sys
#sys.path.append('./public')
#sys.path.append('../public') 

import math
from keyword import iskeyword
from pprint import pprint

def test_prn_dict():
    pprint(globals())

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
        exp: 列表。列表单数项为表达式，偶数项为注释信息。类型都为字符串。
             将使用 eval() 对表达式求值。允许错误的表达式。
        width: 栏宽度。列表。包含4个宽度值
        title: 标题。列表。包含4个标题字符串
    '''
    if width == None: 
        width=[20, 20, 20, 20]
    if title == None: 
        title = ['express', 'result', 'result type', 'comment']
    if len(exp) < 1:
        print('exp: ["express", "comment", ...]')
        return

    w = width
    t = title
    sep_line =  '-' * (w[0]-1) + '|' + \
                '-' * (w[1]-1) + '|' + \
                '-' * (w[2]-1) + '|' + \
                '-' * (w[3]) 
    title_line = t[0].center(w[0]) + t[1].center(w[1]) + \
                 t[2].center(w[2]) + t[3].center(w[3])

    # title_line = '{t[0]:^{w[0]}}{t[1]:^{w[1]}}{t[2]:^{w[2]}}'\
    #             '{t[3]:^{w[3]}}'.format(t=title, w=width)
    print(sep_line)
    print(title_line)
    print(sep_line)

    for i in range(0, len(exp), 2):
        try:
            # 用eval() 求表达式的值，用type() 求值的类型
            # 允许错误的表达式。如果表达式错误，设定一个默认值
            result = eval(exp[i])
        except (NameError, SyntaxError, TypeError, ValueError):
            result = 'Error'
        result_type = type(result)
        # 每行有四个部分，分别生成格式字符串
        w = width[0] - 1
        # 此处使用 字符串对齐函数，使用切片做裁切
        part_1 = ' ' + exp[i][:w].ljust(w)
        # 以下使用str.format() 两种方法比较，字符串对齐函数更清晰直接
        #part_1 = ' {a:{b}.{b}}'.format(a=exp[i], b=width[0]-1)

        if result_type == type(float()):
            # 对于浮点数，单独设定格式
            part_2 = '{a:>{b}.3f}'.format(a=result, b=width[1]-1)    
        else:
            w = width[1] - 1
            part_2 = repr(result)[:w].rjust(w)
            #part_2 = '{a:>{b}.{b}}'.format(a=repr(result), b=width[1]-1)
        w = width[2] + 1
        part_3 = repr(result_type)[:w].center(w)
        #part_3 = '{a:^{b}.{b}}'.format(a=repr(result_type), b=width[2]+1)
        try:
            # 打印。如果没有最后的注释项，exp[i+1]会引发异常。
            print(part_1, part_2, part_3, exp[i+1], sep = '')
        except IndexError:
            return
    # 以下使用 列表推导 和 'str'.format()
    # 不够清晰也未处理 浮点数
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
        test_prn_dict()
    test()
