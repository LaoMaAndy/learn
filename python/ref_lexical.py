#!/usr/bin/env python3
r'''
# 词法分析
# 词汇
    parser 解析器，token 型符/标记，lexical analyzer 词法分析器，
    parentheses, square brackets or curly braces： 圆括号，方括号，花括号
    NEWLINE, INDENT and DEDENT, identifier, keyword, literal, operator, delimiter
    换行，缩进，反缩进，标识符、关键字、字面值、运算符 、分隔符

# 行结构
    本章描述如何将文件分解为token
    行：
        逻辑行 / 物理行 / NEWLINE / 
        换行符应使用C惯例， \n ASCII字符LF
    # 注释行： 语法不解释注释
    编码声明：
        第一行或第二行，
        匹配表达式：coding[=:]\s*([-\w.]+) 
        # -*- coding: <encoding-name> -*-
    显式拼接行：
        不住字符串和注释内的结尾，反斜杠 \ 代表显示拼接
    隐式拼接：
        圆括号，方括号，花括号 内的表达式可以分为多个物理行，
        无需使用反斜杠拼接
    空白行：忽略
    缩进：
        首个非空字符前的空格数决定了该行的缩进层次。
        制表符被替换为1至8个空格
        请勿在源文件中混用制表符和空格符
    标识符、关键字、字面值、运算符 、分隔符
        存在二义性时，将从左至右，读取尽量长的字符串组成合法标记。
    标识符（也称为 名称）的词法定义：
        PEP 3131 
        在 ASCII 范围内（U+0001..U+007F），
        有效标识符字符为： 大小写字母 A 至 Z、下划线 _ 、数字 0 至 9，但不能以数字开头。

# 关键字：35个
        False      await      else       import     pass
        None       break      except     in         raise
        True       class      finally    is         return
        and        continue   for        lambda     try
        as         def        from       nonlocal   while
        assert     del        global     not        with
        async      elif       if         or         yield
    软关键字：
        match, case 和 _  在模式匹配的上下文中被解释为关键字
        该解释在 parser 中完成
        兼容 将其作为标识符的代码
    保留的标识符类 Reserved classes of identifiers
        某些标识符类（除了关键字）具有特殊含义。这些类的命名模式以下划线字符开头，并以下划线结尾：
        _*  : 不会被 from module import * 所导入
        _   : 在 match 语句内部的 case 模式中，_ 是一个 软关键字，它表示 通配符。
              交互式解释器会将最后一次求值的结果放到变量 _ 中。 
              其他地方，_ 是一个常规标识符。 它常常被用来命名 "特殊" 条目，但对 Python 本身来说毫无特殊之处。
        备注 
            _ 常用于连接国际化文本；详见 gettext 模块文档。
              它还经常被用来命名无需使用的变量。
        __*__   系统定义的名称，通常简称为 "dunder" 
                现有系统定义名称相关的论述详见 特殊方法名称 等章节。
        __*     类的私有名称。类定义时，此类名称以一种混合形式重写，
                以避免基类及派生类的 "私有" 属性之间产生名称冲突。
# 字面值 Literals
    字面值是内置类型常量值的表示法。

# 字符串与字节串字面值
    字符串字面值
        stringliteral   ::=  [stringprefix](shortstring | longstring)
        stringprefix    ::=  "r" | "u" | "R" | "U" | "f" | "F"
                             | "fr" | "Fr" | "fR" | "FR" | "rf" | "rF" | "Rf" | "RF"
        shortstring     ::=  "'" shortstringitem* "'" | '"' shortstringitem* '"'
        longstring      ::=  "三个单引号" longstringitem* "三个单引号" | '"""' longstringitem* '"""'
        shortstringitem ::=  shortstringchar | stringescapeseq
        longstringitem  ::=  longstringchar | stringescapeseq
        shortstringchar ::=  <any source character except "\" or newline or the quote>
        longstringchar  ::=  <any source character except "\">
        stringescapeseq ::=  "\" <any source character>
    
    字节串字面值
        bytesliteral   ::=  bytesprefix(shortbytes | longbytes)
        bytesprefix    ::=  "b" | "B" | "br" | "Br" | "bR" | "BR" | "rb" | "rB" | "Rb" | "RB"
        shortbytes     ::=  "'" shortbytesitem* "'" | '"' shortbytesitem* '"'
        longbytes      ::=  "三个单引" longbytesitem* "三个单引" | '"""' longbytesitem* '"""'
        shortbytesitem ::=  shortbyteschar | bytesescapeseq
        longbytesitem  ::=  longbyteschar | bytesescapeseq
        shortbyteschar ::=  <any ASCII character except "\" or newline or the quote>
        longbyteschar  ::=  <any ASCII character except "\">
        bytesescapeseq ::=  "\" <any ASCII character>

    以上未指明的一个句法限制是空白符不允许在 stringprefix 或 bytesprefix 与字面值的其余部分之间出现。 
    简单的说：
        两种类型的文字都可以用匹配的单引号 ( ' ) 或双引号 ( " ) 括起来。
            它们也可以包含在三个单引号或双引号的匹配组中（这些通常称为三引号字符串）。
        反斜杠 ( \ ) 字符用于转义具有特殊含义的字符，例如换行符、反斜杠本身或引号字符。    
        字节文字始终以 'b' 或 'B' 为前缀；它们生成 bytes 类型而不是 str 类型的实例。
            它们只能包含 ASCII 字符；数值为 128 或更大的字节必须使用转义符表示。
        字符串和字节文字都可以选择以字母 'r' 或 'R' 为前缀；此类字符串称为原始字符串，并将反斜杠视为文字字符。
            因此，在字符串文字中，原始字符串中的 '\U' 和 '\u' 转义符不会被特殊处理。
            鉴于 Python 2.x 的原始 unicode 文字的行为与 Python 3.x 的不同，不支持 'ur' 语法。
        前缀中带有 'f' 或 'F' 的字符串文字是格式化字符串文字；
            请参阅格式化字符串文字。 'f' 可以与 'r' 组合，但不能与 'b' 或 'u' 组合，
            因此可以使用原始格式化字符串，但可以使用格式化字节文字不是。
    转义序列：
        除非存在 'r' 或 'R' 前缀，否则字符串和字节文字中的转义序列将根据与标准 C 使用的规则类似的规则进行解释。
        \<newline> 忽略反斜杠与换行符 
        \\ 反斜杠（\） 
        \'单引号（'） 
        \"双引号（"） 
        \a ASCII 响铃（BEL） 
        \b ASCII 退格符（BS） 
        \f ASCII 换页符（FF） 
        \n ASCII 换行符（LF） 
        \r ASCII 回车符（CR） 
        \t ASCII 水平制表符（TAB） 
        \v ASCII 垂直制表符（VT） 
        \ooo 八进制数 ooo 字符 ，接受最多三个八进制数字  
        \xhh 十六进制数 hh 字符 ，必须为两个十六进制数字
        
        字符串字面值专用的转义序列
        \N{name} Unicode 数据库中名为 name 的字符
        \uxxxx 16 位十六进制数 xxxx 码位的字符，必须为 4 个十六进制数码
        \Uxxxxxxxx 32 位 16 进制数 xxxxxxxx 码位的字符，必须为 8 个十六进制数码
    备注：
        与C标准不同：
            无法识别的转义序列在字符串里原样保留，即，输出结果保留反斜杠。
            在字节串字面值内，字符串字面值专用的转义序列属于无法识别的转义序列。
        原始字面值中，引号也可以用反斜杠转义，但反斜杠会保留在输出结果里；
            例如 print(r"\"")  输出 \"
        原始字面值不能以单个反斜杠结尾 （反斜杠会转义其后的引号)。
    
    字符串字面值合并
        以空白符分隔的多个相邻字符串或字节串字面值，可用不同引号标注，等同于合并操作。
        此功能不需要反斜杠，即可将长字符串分为多个物理行，
        例如：
            re.compile("[A-Za-z_]"       # letter or underscore
                       "[A-Za-z0-9_]*"   # letter, digit or underscore
                      )     
        注意，此功能在句法层面定义，在编译时实现。在运行时，合并字符串表达式必须使用 '+' 运算符。
            还要注意，字面值合并可以为每个部分应用不同的引号风格（甚至混用原始字符串和三引号字符串)，
            格式字符串字面值也可以与纯字符串字面值合并。         
    
    格式字符串 f''：
        格式字符串字面值 或称 f-string 是标注了 'f' 或 'F' 前缀的字符串字面值。
        格式字符串字面值中，表达式的处理与圆括号中的常规 Python 表达式基本一样，但也有一些不同的地方。
            不允许使用空表达式；
            lambda 和赋值表达式 := 必须显式用圆括号标注；
            注：括号中的赋值语句使用 :=
                (x := 10) 
                否则会报错
            替换表达式可以包含换行（例如，三引号字符串中），但不能包含注释；
            在格式字符串字面值语境内，按从左至右的顺序，为每个表达式求值。
        表达式里含等号 '=' 时，输出内容包括表达式文本、'=' 、求值结果。
        转换符：指定了转换符时，表达式求值的结果会先转换，再格式化。
            '!s' 调用 str() 转换求值结果，
            '!r' 调用 repr()，
            '!a' 调用 ascii()。
        格式化字符串字面值可以拼接，但是一个替换字段不能拆分到多个字面值。
            f"{today:%B %d, %Y}"  # using date format specifier
        格式表达式中不能有反斜杠，否则会报错：
            要使用反斜杠转义的值，则需创建临时变量。
            newline = ord('\n')
            f"newline: {newline}"

# 数值字面值
    数值字面值有三种类型：整数、浮点数、虚数。没有复数字面值（复数由实数加虚数构成）。
    注意，数值字面值不含正负号；实际上，-1 等负数是由一元运算符 '-' 和字面值 1 合成的。

# 整数字面值
    词法：
        integer      ::=  decinteger | bininteger | octinteger | hexinteger
        decinteger   ::=  nonzerodigit (["_"] digit)* | "0"+ (["_"] "0")*
        bininteger   ::=  "0" ("b" | "B") (["_"] bindigit)+
        octinteger   ::=  "0" ("o" | "O") (["_"] octdigit)+
        hexinteger   ::=  "0" ("x" | "X") (["_"] hexdigit)+
        nonzerodigit ::=  "1"..."9"
        digit        ::=  "0"..."9"
        bindigit     ::=  "0" | "1"
        octdigit     ::=  "0"..."7"
        hexdigit     ::=  digit | "a"..."f" | "A"..."F"
    整数字面值的长度没有限制，能一直大到占满可用内存。
    确定数值时，会忽略字面值中的下划线。下划线只是为了分组数字，让数字更易读。
        下划线可在数字之间，也可在 0x 等基数说明符后。
    除了 0 以外，十进制数字的开头不允许有零。以免与 Python 3.0 版之前使用的 C 样式八进制字面值混淆。

# 浮点数字面值
    词法：
        floatnumber   ::=  pointfloat | exponentfloat
        pointfloat    ::=  [digitpart] fraction | digitpart "."
        exponentfloat ::=  (digitpart | pointfloat) exponent
        digitpart     ::=  digit (["_"] digit)*
        fraction      ::=  "." digitpart
        exponent      ::=  ("e" | "E") ["+" | "-"] digitpart
    解析时，整数和指数部分总以 10 为基数。
        例如，077e010 是合法的，表示的数值与 77e10 相同。
        浮点数字面值的支持范围取决于具体实现。
        整数字面值支持用下划线分组数字。
    值示例如下：
        3.14    10.    .001    1e100    3.14e-10    0e0    3.14_15_93

# 虚数字面值
    虚数字面值词法定义如下：
        imagnumber ::=  (floatnumber | digitpart) ("j" | "J")
    虚数字面值生成实部为 0.0 的复数。复数由一对浮点数表示，它们的取值范围相同。
        创建实部不为零的复数，则需添加浮点数，例如 (3+4j)。
    虚数字面值示例如下：
        3.14j   10.j    10j     .001j   1e100j   3.14e-10j   3.14_15_93j

# 运算符
    +       -       *       **      /       //      %      @
    <<      >>      &       |       ^       ~       :=
    <       >       <=      >=      ==      !=

# 分隔符
    (       )       [       ]       {       }
    ,       :       .       ;       @       =       ->
    +=      -=      *=      /=      //=     %=      @=
    &=      |=      ^=      >>=     <<=     **=

    注意：
        句点也可以用于浮点数和虚数字面值。
        三个连续句点表示省略符。 type(...)  >>> <class 'ellipsis'>
        列表后半部分是增强赋值操作符，用作词法分隔符，但也可以执行运算。
    以下 ASCII 字符具有特殊含义，对词法分析器有重要意义：
        '       "       #       \
    以下 ASCII 字符不用于 Python。在字符串字面值或注释外使用时，将直接报错：
        $       ?       `

# 省略符的使用 ... ellipsis
    https://python.land/python-ellipsis
    省略号作为占位符
        def todo(): 
            ...
    NumPy 切片表示法中的省略号
        省略号最有用的应用是在 numpy 库中。
        使用 NumPy，您可以使用逗号一次分割多个维度。
        为了进行演示，首先创建一个简单的三维矩阵：
            x = np.array([   [ [1],[2],[3] ], [ [4],[5],[6] ]   ])
            x[:,:]   等效于 x[...]
        从第一个维度的第一个索引获取所有数据元素：
            x[1, ... ]
        NumPy 文档中找到更全面的解释。
    队列结束标记 End of queue marker
        有些使用省略号来标记队列的末尾。
        Some use the ellipsis to mark the end of a queue. It makes sense:
            您不需要创建自定义对象
            You don’t need to create a custom object
            这不是您通常在队列中遇到的东西，因此它足够独特，可以作为队列结束标记
            It’s not something that you usually encounter in queues, 
                so it’s unique enough to be an end-of-queue marker
    循环引用 Circular references 
        创建循环引用时，Python 在 REPL 中显示省略号：
        a = [0, 1]
        a[0] = a
        a
        这并不意味着 Python 用省略号替换引用，它只是显示一个引用，
            而不是在无限循环中崩溃和/或填满屏幕。
            你可以自己测试一下。您可以继续请求嵌套对象，它仍然会产生原始的 a ：
        a[0][0][0][0][0][0][0][0][0][0]
'''


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ref_lexical.py')
    test()
