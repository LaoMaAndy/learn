#!/usr/bin/env python3
r'''
Python运算符

## 逻辑值检测
    被 if 或 while 测试条件为假的情况：
      * __bool__() 返回 False
      * __len__() 返回 0
      * 常量 False, None
      * 任何数值的 0
      * 空的序列，空的多项集'', (), [], {}, range(0)
    测试为真：
      * 不为 False 的情况均为真
    布尔运算的结果返回 0 或 False, 1 或 True
    布尔运算 or 和 and 总是返回其中一个操作数

## 数学运算
    + - * / 
       整数类型的 + - * 运算结果，仍为整数
       整数 / 运算结果为浮点数
       表达式中只要含有浮点数，结果就是浮点数
    // 向下取整运算，支持浮点数
       整数运算返回整数，浮点数返回浮点数
    %  求余数。支持浮点数运算。
    ** 指数运算

## 数学运算补充
    -x 求复数
    +x 不变
    abs(x)   绝对值
    int(x)   转化为整数
    float(x) 转化为浮点数
    complex(r, i)  转化为复数
    c.conjugate()  共轭复数
    divmod(x, y)   (x // y, x % y)
    pow(x, y)  幂运算
    // 的舍入方向为负无穷
     例如 1//2 为 0,   (-1)//2 为 -1, 
          1//(-2) 为 -1， (-1)//(-2) 为 0
    使用int() 转化 浮点数，将去掉小数部分
    浮点数：float('nan'), float('+inf'), float('-inf')
    0 ** 0 和 pow(0, 0) 结果为 1
    其他取整函数：
      round(x[, n])    舍入到n位小数，半数值舍入到偶数
      math.trunc(x)    x截断为int
      math.floor(x)    <= x 的最大 int
      math.ceil(x)     >= x 的最小 int

## 布尔运算
    and, or, not
    逻辑运算的含义
    短路运算：short-circuit 

## 比较运算符
    <  <=  >  >=  ==  !=  is  is not
    8种比较运算
    优先级高于布尔运算优先级
    x < y <= z 等价于 x < y and y <= z
    其中，y 的求值次数不同，
      若x < y 为假时，两个表达式均不计算z
    不同类型之间不能比较
    比较运算符对应的魔法函数：
    __eq__()
    __lt__(), __le__(), __gt__(), __ge__()
    通常只需要定义__lt__() 和 __eq__() 即可
    is 和 is not 无法自定义，
      而且对于不同对象，不会引发异常
    in 和 not in 具有相同的优先级
      用于 iterable 或实现 __contains__()方法

## 位运算
    只有整数可以进行位运算
    优先级低于数字运算，高于比较运算
    ～的优先级与 + 和 - 相同
    x | y  或运算
    x ^ y  异或运算
    x & y  与运算
    x << n 左移n位
    x >> n 右移n位
    ~x     取反

'''
import math

def opr_bool():
    ''' 布尔运算 '''
    exp_list = ['bool([])', '空列表为False',
                'True and False', 'and : 与运算，同时为True',
                'True or False', 'or : 或运算，一个即可True',
                'not False', 'not : 非运算，优先级低',
                '"Note:"', '逻辑运算是短路运算',
                '"aaa" or False', '返回值是操作数',
                '"aaa" and "bbb"', '返回值是操作数',
                '"" or 12', '返回值类型可能不同',
                'not "aaa"', '返回值是布尔值',
                '12 < 34', '返回值是布尔值',
                '"a" > "b"','相同类型才能比较',
                'divmod(5, 3)', '同时求除数和余数',
                'round(3.5)', '奇数.5，则进位',
                'round(4.5)', '偶数.5,则舍掉',
                'math.floor(3.2)', 'floor: 向下取整',
                'math.floor(-3.2)', 'floor: 向下取整',
                'math.ceil(3.2)', 'ceil: 向上取整',
                'math.ceil(-3.2)', 'ceil: 向上取整',
                ]
    width = [20, 10, 16, 20]
    col = ['express', 'value', 'type', 'comment']
    fmt_list = ['{:' + str(x) + '}' for x in width]
    fmt = ' ' + ' '.join(fmt_list)
    sep_list = ['|' + '-' * x for x in width]
    sep = ''.join(sep_list)
    print(sep)
    print(fmt.format(*col))
    print(sep)
    for i in range(0, len(exp_list), 2):
        v = eval(exp_list[i])
        print(fmt.format(exp_list[i], 
                         str(v)[:10],
                         str(type(v)),
                         exp_list[i + 1]))

if __name__ == '__main__':
    print(__doc__)
    def test():
        opr_bool()
        pass
    test()
