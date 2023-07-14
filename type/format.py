#!/usr/bin/env python3
r'''
字符串格式化

print风格字符串
https://docs.python.org/zh-cn/3/library/stdtypes.html#text-sequence-type-str

约40%处

字符串常量
格式化字符串
格式化字符串迷你语言
字符串语法
https://docs.python.org/zh-cn/3/library/string.html#formatspec

====
# 格式字符串
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
  转换符   
    '!s' 调用 str() 转换求值结果，
    '!r' 调用 repr()，
    '!a' 调用 ascii()。
  : 冒号后面是 format specifiers，
      调用传入表达式或转换结果的 __format__() 方法
      format(value, format_spec) 
      format specifier mini-language

#printf 风格字符串格式化
注意：此风格会导致一些问题。尽量避免使用


    

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        pass
    test()