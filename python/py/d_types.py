#!/usr/bin/env python3
r'''
## 查看类型
    type()
    type(eval())
    type(type())

## Python内置类型
    参考资料：
      python官网-标准库
      python官网-教程
      python官网-语言参考-词法分析
      《python基础教程》

## 内置常量
    False, True
    None: 
      代表没有值的对象
      NoneType的唯一实例
    NotImplemented
      针对双目运算符的特殊方法
      types.NotImplementedType 唯一实例
    Ellipsis
      与省略号字面值 ... 相同
      types.EllipsisType 的唯一实例
    __debug__
      如果python启动时使用 -O(大写字母O)为False
      否则为True
    由site模块添加的常量：
      quit(), exit(), copyright, credites, license

## 严格的定义：Lexical analysis

## 整数 <class 'int'>
    类型转换 int()
    字面值：
      十进制
      二进制：0b 或 0B
      八进制：0o
      十六进制：0x 或 0X
      下划线：python3.6以上支持
    整数文字的长度没有限制，限于内存
    非零十进制数中不允许有前导零

## 浮点数 <class 'float'>
    float()
    字面值:
      浮点数 和 指数型浮点数
      举例：3.14 | 10. | .001 | 1e100 | 3.14e-10 | 0e0

## 虚数 <class 'complex'>
    虚部的表示为：浮点数 + j / J
    举例：3.14j | 10.j | 10j | .001j | 1e100j | 3.14e-10j
    使用()来表达实部非零的虚数

## 类型转换
    整数类型的 + - * 运算结果，仍为整数
    整数除法 / 运算结果为浮点数
    表达式中只要含有浮点数，结果就是浮点数

## 没有单独的字符类型
    一个字符是大小为1的字符串

## 转义字符：
    * 与C标准不同，无法识别的转义序列在字符串里原样保留，
      即，输出结果保留反斜杠。
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

## 二进制类型 bytes, bytearray, memoryview

## bytes对象/字节串 <class 'bytes'>
    bytes()
    b'字符串'
    可使用：单引号、双引号、三引号、r' '
    每个值的大小为： 0 <= x < 256

## 字符串 <class 'str'>
    str()
    双引号、单引号、转义字符、常用转义字符
    原始字符串:  r'' R''
      (注意：下面的内容需要查看源代码)
      小心： r'C:\will\not\work\' 是错误的
      诡异： r'\' 是错误的
      诡异： r'\''相当于 "\\'"
      变通： 若要表示 C:\windows\ 可使用：
            'C:\\this\\will\\work\\'
            r'C:\this\will\work' '\\'
    长字符串/多行字符串： 3个单引号或双引号
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

## 字符串格式化
    * printf风格 % 
    * str.format()
    * str.Template
    * 格式化字符串 “f-strings”
      版本：Python 3.6
      举例：f'{name} born {year:%A, %B %d, %Y}. '

## 列表 <class 'list'>
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


from share import *

def int_or_float():
    r'''不同表达式的值和类型
    显示不同类型的运算，及结果类型
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
    def test():
        print('Python type')
        int_or_float()
    print(__doc__)
    # print(int_or_float.__doc__)
    test()