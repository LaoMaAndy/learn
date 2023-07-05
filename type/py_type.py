#!/usr/bin/env python3
r'''
查看类型
    type()
    type(eval())
    type(type())
Python内置类型
整数 int
    类型转换 int()
浮点数 float
    float()
类型转换
    整数类型的 + - * 运算结果，仍为整数
    整数除法 / 运算结果为浮点数
    表达式中只要含有浮点数，结果就是浮点数
没有单独的字符类型
    一个字符是大小为1的字符串
字符串：字面值 与 str类
    str()
    双引号、单引号、转义字符、常用转义字符
    原始字符串:  r''
      (注意：下面的内容需要查看源代码)
      小心： r'C:\will\not\work\' 是错误的
      诡异： r'\' 是错误的
            r'\''相当于 "\\'"
      变通： 若要表示 C:\windows\ 可使用：
            'C:\\this\\will\\work\\'
            r'C:\this\will\work' '\\'
    多行字符串： 3个单引号或双引号
      注意 """\ 这样的格式，不会包括初始换行符
      例如：print("""\
    原始多行字符串：
      r"""..."""
    自动合并
      两个字符串字面值，中间为空格或换行，则自动合并，
      'ab' "c"  相当于 'abc'
      ("spam " "eggs") == "spam eggs"
      特别适用于长字符串
    + 字符串连接
    * 字符串重复
      3 * 'ab', 'ab' * 3
    字符串索引
      * 格式：'abc'[]
      * 下标从0开始，
      * 索引可以是负数
      * 索引不可超出范围
    字符串切片
      * 格式：'abc'[::]
      * 包含开头，不包含结尾
      * 步进为-1，可以翻转字符串:'abc'[::-1]
      * s[:i] + s[i:] 始终等于s
      * 可以将切片的编号视为字符之间：
        0位于第一个字符左侧
        -1位于最后两个字符之间
      * 切片起始、终止位置可以任意
    内置len()函数
    其他字符串操作：
      * 字符串方法
      * 格式化字符串
字符串转义字符：
    （以下需要看源代码）
    \<newline> 忽略反斜杠与换行符 
    \\ 反斜杠（\）
    \' 单引号（'）
    \" 双引号（"）
    \a ASCII 响铃（BEL）
    \b ASCII 退格符（BS）
    \f ASCII 换页符（FF）
    \n ASCII 换行符（LF）
    \r ASCII 回车符（CR） 
    \t ASCII 水平制表符（TAB） 
    \v ASCII 垂直制表符（VT） 
    \ooo 八进制数 ooo 字符 
    \xhh 十六进制数 hh 字符
    \N{name} Unicode 数据库中名为 name 的字符 
    \uxxxx 16 位十六进制数 xxxx 码位的字符
    \Uxxxxxxxx 32 位 16 进制数 xxxxxxxx 码位的字符
列表 
    字面值[...], 类型 list()
    可以被索引、切片
    所有的切片将返回一个新的列表
    s[:] 返回一个浅副本
    + ：连接操作，例如 s + [36, 49]
    列表是可变类型
      * 使用下标修改某个元素
    使用切片修改某个片段或全部
      * 某个位点，插入：a[0:0] = list('abc')
      * 某个范围，替换：a[0:2] = list('abc')
      * 某个范围，删除：a[0:2] = []
      * 全部删除: a[:] = []
    附加元素 append()
    求列表长度 len()
    列表可以嵌套
'''
def int_or_float():
    r'''
不同表达式的值和类型
    显示不同类型的运算，及结果类型

    另，此处可为惯用成语：
    字段列表、宽度值 
    -> 使用‘推导’，生成格式化，列表
    -> 将列表join格式化字符串
    -> print(格式串.format(*字段列表))
    '''
    exp_list = [
        '3 + 4 - 9 + 4*5', '整数运算结果类型为整数',
        '3.1 + 2 - 3.1' , '浮点数表达式结果为浮点数',
        '17 // 6' , '整数的下整除，结果为整数',
        '343.4 // 4.5' , '浮点数的下整除，结果为浮点数',
        '5.3 % 4.1' , '浮点数求余，结果为浮点数',
        '5 % 4' , '整数求余，结果为整数',
        '2 ** 3' , '整数的幂运算，结果为整数',
        '2 ** 3.0' , '浮点数的幂运算，结果为浮点数',
        '"-------"' , '--------',
        '"abcde"[3]' , '字符串索引，下标不能超范围',
        '"abcdef"[::]' , '字符串切片',
        '"abcdef"[-12:21]' , '起始和终止位置任意',
        '"abcdef"[21:-42]' , '起始和终止位置任意',
    ]
    # column name and width
    col = ['express', 'result', 'result type', 'comment']
    width = [20, 10, 20, 20]
    # generate format string into a list, then
    # join the list into one format string
    fmt_list = ['{:' + str(x) + '}' for x in width]
    fmt = ' ' + ' '.join(fmt_list)
    # generate a separate line: |---|----|----
    sep_list = ['|' + '-' * x for x in width]
    sep = ''.join(sep_list)
    print('format string:', fmt)
    print(sep)
    print(fmt.format(*col))
    print(sep)
    for i in range(0, len(exp_list), 2):
        print(fmt.format(exp_list[i], 
                         str(eval(exp_list[i]))[:5], 
                         str(type(eval(exp_list[i]))), 
                         exp_list[i + 1]))

if __name__ == '__main__':
    def test():
        print('Python type')
        int_or_float()
    print(__doc__)
    print(int_or_float.__doc__)
    test()