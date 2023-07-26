#!/usr/bin/env python3
r'''
# 格式化字符串的方法4种：
  1、str.format() 方法
     需要定义一个 格式字符串 Format String
  2、f字符串：formatted string literal or f-stringr' ' 
  3、class string.Template(template) 类
  4、printf风格的 %字符串 和 % 操作符

# f字符串 f' '
====================
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
  = 说明符：将字符串扩展为 "表达式文本=表达式值" 的样式
  : 冒号后面是 format specifiers，
      调用传入表达式或转换结果的 __format__() 方法
      format(value, format_spec) 
      format specifier mini-language
# f字符串举例
  name = "Fred"
  f"He said his name is {name!r}."
  f"He said his name is {repr(name)}."  # repr() is equivalent to !r

  width = 10
  precision = 4
  value = decimal.Decimal("12.34567")
  f"result: {value:{width}.{precision}}"  # nested fields

  today = datetime(year=2017, month=1, day=27)
  f"{today:%B %d, %Y}"  # using date format specifier

  f"{today=:%B %d, %Y}" # using date format specifier and debugging

  number = 1024
  f"{number:#0x}"  # using integer format specifier

  foo = "bar"
  f"{ foo = }" # preserves whitespace

  line = "The mill's closed"
  f"{line = }"
  f"{line = :20}"
  f"{line = !r:20}"

# str.format() 方法
====================
格式字符串
    不在花括号之内的内容被视为字面文本
    花括号 {} 括起来的“替换字段”

替换字段的语法
  replacement_field ::=  "{" [field_name] ["!" conversion] [":" format_spec] "}"
  field_name        ::=  arg_name ("." attribute_name | "[" element_index "]")*
  arg_name          ::=  [identifier | digit+]
  attribute_name    ::=  identifier
  element_index     ::=  digit+ | index_string
  index_string      ::=  <any source character except "]"> +
  conversion        ::=  "r" | "s" | "a"
  format_spec       ::=  <described in the next section>

格式字符串示例
  "First, thou shalt count to {0}"  # References first positional argument
  "Bring me a {}"                   # Implicitly references the first positional argument
  "From {} to {}"                   # Same as "From {0} to {1}"
  "My quest is {name}"              # References keyword argument 'name'
  "Weight in tons {0.weight}"       # 'weight' attribute of first positional arg
  "Units destroyed: {players[0]}"   # First element of keyword argument 'players'.

转换旗标有三种: 
  '!s' 会对值调用 str()，
  '!r' 调用 repr() 而 
  '!a' 则调用 ascii()。
  举例如下：
  "Harold's a clever {0!s}"        # Calls str() on the argument first
  "Bring out the holy {name!r}"    # Calls repr() on the argument first
  "More {!a}"                      # Calls ascii() on the argument first

# 格式规格迷你语言
===============
  “格式规格”在格式字符串所包含的替换字段内部使用，
  用于定义单个值应如何呈现
   (参见 格式字符串语法 和 格式字符串字面值)。
  句法：
    format_spec     ::=  [[fill]align][sign]["z"]["#"]["0"][width][grouping_option]["." precision][type]
    fill            ::=  <any character>
    align           ::=  "<" | ">" | "=" | "^"
    sign            ::=  "+" | "-" | " "
    width           ::=  digit+
    grouping_option ::=  "_" | ","
    precision       ::=  digit+
    type            ::=  "b" | "c" | "d" | "e" | "E" | "f" | "F" | "g" | "G" | "n" | "o" | "s" | "x" | "X" | "%"
  其中，对齐align选项：
    '<' 强制字段在可用空间内左对齐（这是大多数对象的默认值）。
    '>'强制字段在可用空间内右对齐（这是数字的默认值）。
    '='强制在符号（如果有）之后数码之前放置填充。 
        这被用于以 '+000000120' 形式打印字段。 
        这个对齐选项仅对数字类型有效。 
        这是当 '0' 紧接在字段宽度之前时的默认选项。
    '^'强制字段在可用空间内居中。
  符号sign选项
    '+'表示标志应该用于正数和负数。
    '-'表示标志应仅用于负数（这是默认行为）。
    space 表示应在正数上使用前导空格，在负数上使用减号。
  'z' 选项（3.11版）
    在舍入到格式精度后将负零浮点值强制转换为正零。
    此选项仅对浮点表示类型有效。
  '#' 选项
    让“替代形式”被用于执行转换。 
      替代形式会针对不同的类型分别定义。 
      此选项仅适用于整数、浮点数和复数类型。
    对于整数类型，当使用二进制、八进制或十六进制输出时，
      此选项会为输出值分别添加相应的 '0b', '0o', '0x' 或 '0X' 前缀。 
    对于浮点数和复数类型，替代形式会使得转换结果总是包含小数点符号，
      即使其不带小数部分。
  ',' 选项
    表示使用逗号作为千位分隔符。
  '_' 选项
    表示对浮点表示类型和整数表示类型 'd' 使用下划线作为千位分隔符。
  width 字段
    是一个定义最小总字段宽度的十进制整数，包括任何前缀、分隔符和其他格式化字符。
    width 字段前加一个零 ('0') 字段将为数字类型启用感知正负号的零填充。
  precision 字段
    是一个十进制整数，
    它表示对于以表示类型 'f' 和 'F' 格式化的数值应当在小数点后显示多少个数位，
    或者对于以表示类型 'g' 或 'G' 格式化的数值应当在小数点前后显示多少个数位。 
    对于字符串表示类型，该字段表示最大的字段大小 
  type 字段
    字符串 
      's' 字符串格式。这是字符串的默认类型，可以省略。
    整数表示类型是：
      'b' 二进制格式。 输出以 2 为基数的数字。
      'c' 字符。在打印之前将整数转换为相应的unicode字符。
      'd' 十进制整数。 输出以 10 为基数的数字。
      'o' 八进制格式。 输出以 8 为基数的数字。
      'x' 十六进制格式。 输出以 16 为基数的数字，使用小写字母表示 9 以上的数码。
      'X' 十六进制格式。 输出以 16 为基数的数字，使用大写字母表示 9 以上的数码。 
        在指定 '#' 的情况下，前缀 '0x' 也将被转为大写形式 '0X'。
      'n' 数字。 这与 'd' 相似，不同之处在于它会使用当前区域设置来插入适当的数字分隔字符。
      None 和 'd' 相同。
    浮点数 float 和 Decimal 值
      'e' 科学计数法。
      'E' 科学计数法。
      'f' 定点表示法。可以指定精度，默认为6
      'F' 定点表示。 与'f' 相似，但会将 nan 转为 NAN 并将 inf 转为 INF。
      'g' 常规格式。
      'G' 常规格式。 类似于 'g'，
      'n' 数字。
      '%' 百分比。
      None 对于 float 来说这类似于 'g'，

# str.format() 字符串示例
按位置访问参数:
  '{0}, {1}, {2}'.format('a', 'b', 'c')
  '{}, {}, {}'.format('a', 'b', 'c')  # 3.1+ only
  '{2}, {1}, {0}'.format('a', 'b', 'c')
  '{2}, {1}, {0}'.format(*'abc')      # unpacking argument sequence
  '{0}{1}{0}'.format('abra', 'cad')   # arguments' indices can be repeated

按名称访问参数:
  'Coordinates: {latitude}, {longitude}'.format(latitude='37.24N', longitude='-115.81W')
  coord = {'latitude': '37.24N', 'longitude': '-115.81W'}
  'Coordinates: {latitude}, {longitude}'.format(**coord)

访问参数的属性:
  c = 3-5j
  ('The complex number {0} is formed from the real part {0.real} '
  'and the imaginary part {0.imag}.').format(c)
  
  class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y
    def __str__(self):
        return 'Point({self.x}, {self.y})'.format(self=self)
  str(Point(4, 2))

访问参数的项:
  coord = (3, 5)
  'X: {0[0]};  Y: {0[1]}'.format(coord)

替代 %s 和 %r:
  "repr() shows quotes: {!r}; str() doesn't: {!s}".format('test1', 'test2')

对齐文本以及指定宽度:
  '{:<30}'.format('left aligned')
  '{:>30}'.format('right aligned')
  '{:^30}'.format('centered')
  '{:*^30}'.format('centered')  # use '*' as a fill char

替代 %+f, %-f 和 % f 以及指定正负号:
  '{:+f}; {:+f}'.format(3.14, -3.14)  # show it always
  '{: f}; {: f}'.format(3.14, -3.14)  # show a space for positive numbers
  '{:-f}; {:-f}'.format(3.14, -3.14)  # show only the minus -- same as '{:f}; {:f}'

替代 %x 和 %o 以及转换基于不同进位制的值:
  # format also supports binary numbers
  "int: {0:d};  hex: {0:x};  oct: {0:o};  bin: {0:b}".format(42)

  # with 0x, 0o, or 0b as prefix:
  "int: {0:d};  hex: {0:#x};  oct: {0:#o};  bin: {0:#b}".format(42)

使用逗号作为千位分隔符:
  '{:,}'.format(1234567890)

表示为百分数:
  points = 19
  total = 22
  'Correct answers: {:.2%}'.format(points/total)

使用特定类型的专属格式化:
  import datetime
  d = datetime.datetime(2010, 7, 4, 12, 15, 58)
  '{:%Y-%m-%d %H:%M:%S}'.format(d)

嵌套参数以及更复杂的示例:
  for align, text in zip('<^>', ['left', 'center', 'right']):
    '{0:{fill}{align}16}'.format(text, fill=align, align=align)
  
  octets = [192, 168, 0, 1]
  '{:02X}{:02X}{:02X}{:02X}'.format(*octets)
  int(_, 16)

  width = 5
  for num in range(5,12): 
      for base in 'dXob':
        print('{0:{width}{base}}'.format(num, base=base, width=width), end=' ')
      print()

# Template 模版字符串
====================
使用方法：
  导入库：
    from string import Template
  一般使用：
    s = Template('$who likes $what')
    s.substitute(who='tim', what='kung pao')
  使用字典和safe_substitute
    d = dict(who='tim')
    Template('$who likes $what').safe_substitute(d)
进阶用法：
  可以派生 Template 的子类来自定义占位符语法、分隔符，
  或用于解析模板字符串的整个正则表达式。

# print风格字符串
====================
基本格式
  format % values 
  其中 format 为一个字符串，
  在 format 中的 % 转换标记符将被替换为零个或多个 values 条目。 
  其效果类似于在 C 语言中使用 sprintf()。

举例
  print('%(language)s has %(number)03d quote types.' %
      {'language': "Python", "number": 2})

format构成
  包含两个或更多字符并具有以下组成，且必须遵循此处规定的顺序：
    1、'%' 字符，用于标记转换符的起始。
    2、映射键（可选），由加圆括号的字符序列组成 (例如 (somename))。
    3、转换旗标（可选），用于影响某些转换类型的结果。
    4、最小字段宽度（可选）。 
      如果指定为 '*' (星号)，则实际宽度会从 values 元组的下一元素中读取，
      要转换的对象则为最小字段宽度和可选的精度之后的元素。
    5、精度（可选），以在 '.' (点号) 之后加精度值的形式给出。 
      如果指定为 '*' (星号)，则实际精度会从 values 元组的下一元素中读取，
      要转换的对象则为精度之后的元素。
    6、长度修饰符（可选）。
    7、转换类型。
  转换旗标：
    '#'值的转换将使用“替代形式”（具体定义见下文）。
    '0'转换将为数字值填充零字符。
    '-'转换值将靠左对齐（如果同时给出 '0' 转换，则会覆盖后者）。
    ' '(空格) 符号位转换产生的正数（或空字符串）前将留出一个空格。
    '+'符号字符 ('+' 或 '-') 将显示于转换结果的开头（会覆盖 "空格" 旗标）。
  转换类型
    'd' 有符号十进制整数。
    'i' 有符号十进制整数。
    'o' 有符号八进制数。
    'u' 过时类型 -- 等价于 'd'。
    'x' 有符号十六进制数（小写）。
    'X' 有符号十六进制数（大写）。
    'e' 浮点指数格式（小写）。
    'E' 浮点指数格式（大写）。
    'f' 浮点十进制格式。
    'F' 浮点十进制格式。
    'g' 浮点格式。 如果指数小于 -4 或不小于精度则使用小写指数格式，否则使用十进制格式。
    'G' 浮点格式。 如果指数小于 -4 或不小于精度则使用大写指数格式，否则使用十进制格式。
    'c' 单个字符（接受整数或单个字符的字符串）。
    'r' 字符串（使用 repr() 转换任何 Python 对象）。
    's' 字符串（使用 str() 转换任何 Python 对象）。
    'a' 字符串（使用 ascii() 转换任何 Python 对象）。
    '%' 不转换参数，在结果中输出一个 '%' 字符。
'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        pass
    test()