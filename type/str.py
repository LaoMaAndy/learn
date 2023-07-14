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


词法规则：
f_string          ::=  (literal_char | "{{" | "}}" | replacement_field)*
replacement_field ::=  "{" f_expression ["="] ["!" conversion] [":" format_spec] "}"
f_expression      ::=  (conditional_expression | "*" or_expr)
                         ("," conditional_expression | "," "*" or_expr)* [","]
                       | yield_expression
conversion        ::=  "s" | "r" | "a"
format_spec       ::=  (literal_char | NULL | replacement_field)*
literal_char      ::=  <any code point except "{", "}" or NULL>

其中：
  双花括号 '{{' 或 '}}' 被替换为单花括号
  转换符   '!s' 调用 str() 转换求值结果，
          '!r' 调用 repr()，
          '!a' 调用 ascii()。
  : 冒号后面是 format specifiers，
      调用传入表达式或转换结果的 __format__() 方法
      format(value, format_spec) 
      format specifier mini-language
      查看 format 格式迷你语言

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
'''
import sys 
sys.path.append('../public') 
from print_exp import *

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
    test()