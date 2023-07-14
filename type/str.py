#!/usr/bin/env python3
r'''
# 空格分隔的字符串会被合并
    ("spam " "eggs") == "spam eggs"
    r'...' raw 字面值
    不存在可变的字符串类型：
      字符串类型都是不可变的

# str()构造器
    class str(object=b'', encoding='utf-8', errors='strict')
    最简单的调用将返回repr(object)
      str(b'abc')返回 "b'abc'"

# 字符串的格式化
    format 迷你语言
    f-string 语法规则
    自定义字符串格式化
    printf 风格字符串格式化

# 字符串方法
## str.capitalize()
    首字母大写
    返回字符串副本，其中首个字符大写，其余为小写。
    注意：将首个字母改为大写，同时
         将其余字母改为小写

## str.casefold()
    转小写
    返回消除大小写的副本
    用于忽略大小写的匹配
    德语小写字母 'ß' 相当于 "ss"
      lower() 不会对'ß'做任何改变
      casefold()将其修改为"ss"
      大小写转换见 Unicode 标准的 3.13 节

## str.center(width[, fillchar])
    居中
    返回一个字符串副本，原字符串居中
    fillchar 只能为一个字符
    若 width 小于 len(s), 则返回副本

## str.count(sub[, start[, end]])
    统计
    返回sub在范围内非重叠出现的次数
    start, end 规则类似于切片
    如果sub为空，则返回len(s) + 1

## str.encode(encoding='utf-8', errors='strict')
    编码
    编解码器
docs.python.org/zh-cn/3/library/codecs.html#standard-encodings
    
## str.endswith(suffix[, start[, end]])
    后缀
    如果字符串后缀为suffix, 则返回True，否则False
    suffix 可以是元组 ()

## str.expandtabs(tabsize=8)
    替换tab符
    将tab符替换为空格
    如果多个tab，则会计算制表位

str.find(sub[, start[, end]])
    查找
    返回sub在字符串切片[start:end]中的最小索引
    如果未找到，返回-1
    注：
      find()仅应该用于查找位置时使用
      如果检查是否存在sub，应使用 in 操作符

str.format(*args, **kwargs)
    格式化
    "Sum 1+2 is {0}".format(1+2)

str.format_map(mapping)
    格式化
    相当于str.format(**mapping)
    不同之处在于mapping直接使用，而不会复制到dict

str.index(sub[, start[, end]])
    索引
    功能类似于find(), 但找不到时引发 ValueError

# is 系列函数
str.isalnum()
    字母和数字
    空白字符串返回False
str.isalpha()
    字母
str.isascii()
    ASCII码
str.isdecimal()
    十进制
str.isdigit()
    数字
    此处isdecimal()和isdigit()有细微差别
str.isidentifier()
    标识符
keyword.iskeyword() 
    关键字
str.islower()
    小写
str.isnumeric()
    数值
str.isprintable()
    可打印
    空格或空字符串为True
str.isspace()
    空白字符串
    空字串为False
str.istitle()
    标题字符串
str.isupper()
    大写

str.join(iterable)
    拼接
    iterable中必须全部是str对象
    str作为元素之间的分隔

str.ljust(width[, fillchar])
    左对齐
    并用fillchar填充空白，默认空格
    如width小于len(),则返回副本

str.lower()
    小写

str.lstrip([chars])
    移除左侧字符
    chars 指定字符。默认移除空白字符
    chars 中的所有字符都移除，直到遇到
      第一个非chars中字符为止

static str.maketrans(x[, y[, z]])
    静态方法
    返回一个可供 str.translate() 使用的转换对照表。

str.partition(sep)
    拆分
    返回一个3元组，
    包含分隔之前的部分、分隔符、后面的部分
    若没找到，则返回本身和两个空白串

str.removeprefix(prefix, /)
    删除前缀
    如果字符串以 prefix 字符串开头，
      则返回 string[len(prefix):]
    否则返回副本

str.removesuffix(suffix, /)
    删除后缀
    如果字符串以 suffix 字符串结尾，
        返回 string[:-len(suffix)]
    否则返回副本

str.replace(old, new[, count])
    替换
    将old替换为new, 替换前 count 次

str.rfind(sub[, start[, end]])
    反向查找
    如果没找到，则返回-1

str.rindex(sub[, start[, end]])
    类似于 rfind()，
    但在子字符串 sub 未找到时会引发 ValueError。

str.rjust(width[, fillchar])
    向右侧对齐

str.rpartition(sep)
    类似于partition()
    从结尾处开始

str.rsplit(sep=None, maxsplit=- 1)
    返回一个列表
    从结尾处开始，拆分字符串，
    maxsplit 为最大拆分次数
    sep如果不指定，默认空白字符

str.split(sep=None, maxsplit=- 1)
    返回一个列表
'''
import sys 
sys.path.append('../public') 
from print_exp import print_exp
from keyword import iskeyword

def test_is():
    print('test_is()'.center(40, '*'))
    exp = ['"12345".isalnum()', '字母和数字',
           '"  ".isalnum()', '空白字符串返回False',
           '"abc".isalpha()', '是否全部字母',
           '"123e2".isdecimal()', '是否全部十进制字符',
           '"123abc".isdigit()', '是否全部十进制字符',
           '"def".isidentifier()', '是否有效的标识符号',
           'iskeyword("def")', '是否有效的关键字',
           '"1290".isnumeric()','是否数值字符',
           '"   ".isprintable()','空白字符串为True',
           '"  \t".isspace()','是否空白字串',
           '"".isspace()','空字符串为False',
           '"-".join(["1", "2", "3"])','拼接字符串',
            "' spacious '.lstrip()","移除左侧空白",
            "'www.exam.com'.lstrip('cmowz.')","移除指定字符",
            "'thisis'.partition('i')","分隔字符串",
            "'www.a.com'.removeprefix('www.')","删除前导字符串",
            "'www.a.com'.removesuffix('.com')","删除后缀字符串",
            "'abcabc'.rfind('abc')","从右侧查找",
            "'we are the world'.rsplit()","拆分字符串",
            r"'c:\windows\sys'.split('\\')","拆分字符串",
            "'|this|is|a|'.split('|')","拆分字符串",
            "' '","",
            "' '","",
          ]
    print_exp(exp, [35, 25, 15, 20])

def test_format_map():
    print('test_format_map()'.center(40, '*'))
    class Default(dict):
        def __missing__(self, key):
            return key

    s = '{name} was born in {country}'.format_map(Default(name='Guido'))
    # s: Guido was born in country
    print(s)


def test_find():
    print('test_find()'.center(40, '*'))
    exp = ["'11111'.find('11')", '查找字符串位置',
          ]
    print_exp(exp)

def test_endswith():
    print('test_endswith()'.center(40, '*'))
    suf = ('.doc', '.docx')
    s = '123.doc'
    print(s, 'endwith', suf, '=', s.endswith(suf))
    s = '123.docx'
    print(s, 'endwith', suf, '=', s.endswith(suf))

def test_count():
    s = ['a12121', '121',
         '1111', '11',
         '1234', '',
         '12 23', '',
         ' ','',
         '', '',
         '12 34', ' ',
        ]
    print('teset_count()')
    for i in range(0, len(s), 2):
        print(repr(s[i]), 'count', 
              repr(s[i+1]), '=', 
              s[i].count(s[i+1]))

def test_center():
    print('test_center()')
    s = ['title']
    for i in s:
        print(i.center(20, '*'))

def test_capitalize():
    print('test_capitalize()')
    a = ["this is a test",
         "ALL CAPITAL", 
         "singleWord"
        ]
    for i in a:
        print(i,'-->', i.capitalize())

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('test str')
        test_capitalize()
        test_center()
        test_count()
        test_endswith()
        test_find()
        test_format_map()
        test_is()
    test()