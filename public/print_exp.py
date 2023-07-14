#!/usr/bin/env python3
r'''打印表达式 / 值 / 值类型 / 备注信息
    此处：
    字段列表、宽度值 
    -> 使用‘推导’，生成格式化，列表
    -> 将列表join格式化字符串
    -> print(格式串.format(*字段列表))
'''
import math

def print_exp(exp, width=None, title=None):
    if width == None:
        width=[20, 15, 20, 20]
    if title == None:
        title = ['express', 'result', 'result type', 'comment']
    #if exp == None:
    #    exp = []

    fmt_list = ['{:' + str(x) + '}' for x in width]
    fmt = ' ' + ' '.join(fmt_list)
    print('type(width[0]): ', type(width[0]))
    sep_list = ['|' + '-' * x for x in width]
    sep = ''.join(sep_list)
    print(sep)
    print(fmt.format(*title))
    print(sep)
    for i in range(0, len(exp), 2):
        v = eval(exp[i])
        print(fmt.format(exp[i], 
                         str(v)[:10],
                         str(type(v)),
                         exp[i + 1]))


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
    ]
    print_exp(exp_list)

if __name__ == '__main__':
    print(__doc__)
    def test():
        test_print_exp()
    test()
