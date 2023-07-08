#!/usr/bin/env python3
r'''
Python运算符

## 真值测试
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

## 四则运算符
    + - * / 
       整数类型的 + - * 运算结果，仍为整数
       整数 / 运算结果为浮点数
       表达式中只要含有浮点数，结果就是浮点数
    // 向下取整运算，支持浮点数
       整数运算返回整数，浮点数返回浮点数
    %  求余数。支持浮点数运算。
    ** 指数运算
## 布尔运算
    and, or, not


'''
def opr_bool():
    ''' 布尔运算 '''
    exp_list = ['bool([])', '空列表为False']
    width = [20, 15, 20, 25]
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
                         exp_list[v + 1]))

if __name__ == '__main__':
    print(__doc__)
    def test():
        opr_bool()
        pass
    test()
