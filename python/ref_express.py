#!/usr/bin/env python3
r'''
# 表达式 Expressions
## 算术转换 Arithmetic conversions
## 原子 Atoms

### 标识符（名称）  Identifiers (Names)
    私有名称转换

### 字面值 Literals
    Python 支持5种字面值：字符串、字节串、整数、浮点数、复数

### 带圆括号的形式 Parenthesized forms
    
### 列表、集合与字典的显示 Displays for lists, sets and dictionaries
    为了构建列表、集合或字典，Python 提供了名为“显示”的特殊句法，每个类型各有两种形式:
        第一种是显式地列出容器内容
        第二种是通过一组循环和筛选指令计算出来，称为 推导式。

### 列表显示 List displays
    list_display ::=  "[" [starred_list | comprehension] "]"
    注意 * 表示列表拆包

### 集合显示 Set displays
    set_display ::=  "{" (starred_list | comprehension) "}"

### 字典显示 Dictionary displays
    dict_display       ::=  "{" [dict_item_list | dict_comprehension] "}"
    dict_item_list     ::=  dict_item ("," dict_item)* [","]
    dict_item          ::=  expression ":" expression | "**" or_expr
    dict_comprehension ::=  expression ":" expression comp_for
    注意 ** 表示 字典拆包

### 生成器表达式  Generator expressions
    生成器表达式是用圆括号括起来的紧凑形式生成器标注。
    generator_expression ::=  "(" expression comp_for ")"
    生成器表达式会产生一个新的生成器对象。 其句法与推导式相同，区别在于它是用圆括号而不是用方括号或花括号括起来的。
    例如: (x*y for x in range(10) for y in range(x, x+10)).

### yield 表达式
    yield_atom       ::=  "(" yield_expression ")"
    yield_expression ::=  "yield" [expression_list | "from" expression]
    yield 表达式在定义 generator 函数或 asynchronous generator 函数时才会用到因此只能在函数定义的内部使用。 
    在一个函数体内使用 yield 表达式会使这个函数变成一个生成器函数，
        而在一个 async def 函数的内部使用它则会让这个协程函数变成一个异步生成器函数。 
    def gen():  # defines a generator function
        yield 123

    async def agen(): # defines an asynchronous generator function
        yield 123

#### 生成器-迭代器的方法 Generator-iterator methods
    generator.__next__()

    generator.send(value)
    
    generator.throw(value)
    generator.throw(type[, value[, traceback]])

    generator.close()

#### 异步生成器函数 Asynchronous generator functions
#### 异步生成器-迭代器方法 Asynchronous generator-iterator methods

# 原型 Primaries
    primary ::=  atom | attributeref | subscription | slicing | call

## 属性引用 Attribute references
    属性引用是后面带有一个句点加一个名称的原型:
    attributeref ::=  primary "." identifier

## 抽取 Subscriptions
    对一个 容器类 的实例执行抽取操作通常将会从该容器中选取一个元素。 
        而对一个 泛型类 执行抽取操作通常将会返回一个 GenericAlias 对象。
    
    subscription ::=  primary "[" expression_list "]"
    
    当一个对象被抽取时，解释器将对原型和表达式列表进行求值。
    原型必须可被求值为一个支持抽取操作的对象。
         一个对象可通过同时定义 __getitem__() 
         和 __class_getitem__() 或其中之一来支持抽取操作。 
    
    正式语法规则并未在 序列 中设置负索引号的特殊保留条款。 
        不过，内置序列都提供了通过给索引号加上序列长度来解读负索引号的 __getitem__() 方法，
        因此举例来说，x[-1] 将选取 x 的最后一项。 
        结果值必须为一个小于序列中条目数的非负整数，抽取操作会选取索引号为该值的条目（从零开始计数）。 
        由于对负索引号和切片的支持位于对象的 __getitem__() 方法中，
        因而重载此方法的子类将需要显式地添加这种支持。

    字符串 是一种特殊的序列，其中的项是 字符。 
        字符并不是一种单独的数据类型而是长度恰好为一个字符的字符串。

## 切片 Slicings
    切片就是在序列对象（字符串、元组或列表）中选择某个范围内的项。 
        切片可被用作表达式以及赋值或 del 语句的目标。 
        切片的句法如下:
    slicing      ::=  primary "[" slice_list "]"
    slice_list   ::=  slice_item ("," slice_item)* [","]
    slice_item   ::=  expression | proper_slice
    proper_slice ::=  [lower_bound] ":" [upper_bound] [ ":" [stride] ]
    lower_bound  ::=  expression
    upper_bound  ::=  expression
    stride       ::=  expression

## 调用 Calls
    所谓调用就是附带可能为空的一系列 参数 来执行一个可调用对象 (例如 function)
    此原型必须求值为一个可调用对象
        （用户定义的函数，内置函数，内置对象的方法，类对象，类实例的方法
        以及任何具有 __call__() 方法的对象都是可调用对象）。 
        所有参数表达式将在尝试调用前被求值。 
        请参阅 函数定义 一节了解正式的 parameter 列表句法。
    
    如果存在关键字参数，它们会先通过以下操作被转换为位置参数。 
        首先，为正式参数创建一个未填充空位(unfilled slots) 的列表(list)。 
            如果有 N 个位置参数，则它们会被放入前 N 个空位。 
        然后，对于每个关键字参数，使用标识符来确定其对应的空位（如果标识符与第一个正式参数名相同则使用第一个空位，依此类推）。 
            如果空位已被填充，则会引发 TypeError 异常。 否则，将参数值放入空位，进行填充（即使表达式为 None，它也会填充空位）。 
        当所有参数处理完毕时，尚未填充的空位将用来自函数定义的相应默认值来填充。 
            （函数一旦被定义，其默认值就会被计算；因此，当列表或字典这类可变对象被用作默认值时将会被所有未指定相应空位参数值的调用所共享；
            这种情况通常应当被避免。） 
            如果任何一个未填充空位没有指定默认值，则会引发 TypeError 异常。 
            在其他情况下，已填充空位的列表会被作为调用的参数列表。
        如果存在比正式参数空位多的位置参数，将会引发 TypeError 异常，除非有一个正式参数使用了 *identifier 句法；
            在此情况下，该正式参数将接受一个包含了多余位置参数的元组（如果没有多余位置参数则为一个空元组）。
        如果任何关键字参数没有与之对应的正式参数名称，将会引发 TypeError 异常，除非有一个正式参数使用了 **identifier 句法，
            该正式参数将接受一个包含了多余关键字参数的字典（使用关键字作为键而参数值作为与键对应的值），如果没有多余关键字参数则为一个（新的）空字典。
        如果函数调用中出现了 *expression 句法，expression 必须求值为一个 iterable。 来自该可迭代对象的元素会被当作是额外的位置参数。
            这样做的一个后果是虽然 *expression 句法可能出现于显式的关键字参数 之后，但它会在关键字参数（以及任何 **expression 参数） 之前 被处理。 
        如果函数调用中出现了 **expression，则 expression 必须求值为一个 mapping，其内容会被当作是额外的关键字参数。 
            如果一个形参与一个已给定值关键字相匹配（通过显式的关键字参数，或通过另一个解包），则会引发 TypeError 异常。
            当使用 **expression 时，该映射中的每个键都必须为字符串。 该映射中的每个值将被赋值给名称与键相同的适用于关键字赋值的第一个正式形参。 
            如果键值对未与某个正式形参相匹配则将被 ** 形参所收集，或者如果没有此形参，则会引发 TypeError 异常。
    除非引发了异常，调用总是会有返回值，返回值也可能为 None。 返回值的计算方式取决于可调用对象的类型。
    如果类型为---
        用户自定义函数:
            函数的代码块会被执行，并向其传入参数列表。 代码块所做的第一件事是将正式形参绑定到对应参数；相关描述参见 函数定义 一节。 
            当代码块执行 return 语句时，由其指定函数调用的返回值。
        内置函数或方法:
            具体结果依赖于解释器；有关内置函数和方法的描述参见 内置函数。
        类对象:
            返回该类的一个新实例。
        类实例方法:
            调用相应的用户自定义函数，向其传入的参数列表会比调用的参数列表多一项：该实例将成为第一个参数。
        类实例:
            该类必须定义有 __call__() 方法；作用效果将等价于调用该方法。

##  await 表达式 Await expression
    挂起 coroutine 的执行以等待一个 awaitable 对象。 只能在 coroutine function 内部使用。

## 幂运算符 The power operator
    幂运算符的绑定比在其左侧的一元运算符更紧密；但绑定紧密程度不及在其右侧的一元运算符。
    此运算符可使用特殊的 __pow__() 方法来自定义。

## 一元算术和位运算 Unary arithmetic and bitwise operations
    一元的 - (负值) 运算符会产生其数字参数的负值；该运算可通过 __neg__() 特殊方法来重载。
    一元的 + (正值) 运算符会原样输出其数字参数；该运算可通过 __pos__() 特殊方法来重载。
    一元的 ~ (取反) 运算符会对其整数参数按位取反。 x 的按位取反被定义为 -(x+1)。 
        它只作用于整数或是重载了 __invert__() 特殊方法的自定义对象。    

##  二元算术运算符 Binary arithmetic operations
    m_expr ::=  u_expr | m_expr "*" u_expr | m_expr "@" m_expr |
                m_expr "//" u_expr | m_expr "/" u_expr |
                m_expr "%" u_expr
    a_expr ::=  m_expr | a_expr "+" m_expr | a_expr "-" m_expr
    
    * (乘) 将输出其参数的乘积。 
        两个参数或者必须都为数字，或者一个参数必须为整数而另一个参数必须为序列。 
        在前一种情况下，两个数字将被转换为相同类型然后相乘。 
        在后一种情况下，将执行序列的重复；重复因子为负数将输出空序列。
        此运算可使用特殊的 __mul__() 和 __rmul__() 方法来自定义。
    @ (at) 的目标是用于矩阵乘法。 没有内置 Python 类型实现此运算符。
    / (除) 和 // (整除) 将输出其参数的商。 
        两个数字参数将先被转换为相同类型。 整数相除会输出一个 float 值，整数相整除的结果仍是整数；
        整除的结果就是使用 'floor' 函数进行算术除法的结果。 除以零的运算将引发 ZeroDivisionError 异常。
        此运行可使用特殊的 __truediv__() 和 __floordiv__() 方法来自定义。
     % (模) 将输出第一个参数除以第二个参数的余数。 两个数字参数将先被转换为相同类型。 
        右参数为零将引发 ZeroDivisionError 异常。 
        参数可以为浮点数，例如 3.14%0.7 等于 0.34 (因为 3.14 等于 4*0.7 + 0.34)。 
        模运算符的结果的正负总是与第二个操作数一致（或是为零）；结果的绝对值一定小于第二个操作数的绝对值。
        x == (x//y)*y + (x%y)
        divmod(x, y) == (x//y, x%y)
        % 还被字符串对象重载用于执行旧式的字符串格式化（又称插值）。
        取余 运算可使用特殊的 __mod__() 方法来自定义。
    + (addition) 将输出其参数的和。 两个参数或者必须都为数字，或者都为相同类型的序列。 
        在前一种情况下，两个数字将被转换为相同类型然后相加。 在后一种情况下，将执行序列拼接操作。
        此运算可使用特殊的 __add__() 和 __radd__() 方法来自定义。
    - (减) 将输出其参数的差。 两个数字参数将先被转换为相同类型。
        此运算可使用特殊的 __sub__() 方法来自定义。
    << >> 移位运算的优先级低于算术运算
        这些运算符接受整数参数。 它们会将第一个参数左移或右移第二个参数所指定的比特位数。
        此运算可使用特殊的 __lshift__() 和 __rshift__() 方法来自定义。
        右移 n 位被定义为被 pow(2,n) 整除。 左移 n 位被定义为乘以 pow(2,n)。

## 二元位运算 Binary bitwise operations
    & 运算符会对其参数执行按位 AND，
        参数必须都为整数或者其中之一必须为重载了 __and__() 或 __rand__() 特殊方法的自定义对象。
    ^ 运算符会对其参数执行按位 XOR (异 OR)，
        参数必须都为整数或者其中之一必须为重载了 __xor__() 或 __rxor__() 特殊方法的自定义对象。
    | 运算符会对其参数执行按位 (合并) OR，
        参数必须都为整数或者其中之一必须为重载了 __or__() 或 __ror__() 特殊方法的自定义对象。

## 比较运算 Comparisons
    与 C 不同，Python 中所有比较运算的优先级相同，低于任何算术、移位或位运算。 
        另一个与 C 不同之处在于 a < b < c 这样的表达式会按传统算术法则来解读:
    比较运算会产生布尔值: True 或 False。 自定义的 富比较方法 可能返回非布尔值。 
        在此情况下 Python 将在布尔运算上下文中对该值调用 bool()
    比较运算可以任意串连，例如 x < y <= z 等价于 x < y and y <= z，除了 y 只被求值一次
        （但在两种写法下当 x < y 值为假时 z 都不会被求值）。
    请注意 a op1 b op2 c 不意味着在 a 和 c 之间进行任何比较，因此，如 x < y > z 这样的写法是完全合法的（虽然也许不太好看）

### 值比较  Value comparisons
    <, >, ==, >=, <=, != 将比较两个对象的值。 两个对象不要求为相同类型。
    由于所有类型都是 object 的（直接或间接）子类型，它们都从 object 继承了默认的比较行为。 
        类型可以通过实现 丰富比较方法 例如 __lt__() 来定义自己的比较行为，详情参见 基本定制。
    默认的一致性比较 (== 和 !=) 是基于对象的标识号。 
        因此，具有相同标识号的实例一致性比较结果为相等， 具有不同标识号的实例一致性比较结果为不等。
        规定这种默认行为的动机是希望所有对象都应该是自反射的 (即 x is y 就意味着 x == y)。
    次序比较 (<, >, <= 和 >=) 默认没有提供；如果尝试比较会引发 TypeError。 规定这种默认行为的原因是缺少与一致性比较类似的固定值。
    以下列表描述了最主要内置类型的比较行为。
        内置数值类型 (数字类型 --- int, float, complex) 以及标准库类型 fractions.Fraction 和 decimal.Decimal 可进行类型内部和跨类型的比较，
            例外限制是复数不支持次序比较。 在类型相关的限制以内，它们会按数学（算法）规则正确进行比较且不会有精度损失。
            非数字值 float('NaN') 和 decimal.Decimal('NaN') 属于特例。 任何数字与非数字值的排序比较均返回假值。 还有一个反直觉的结果是非数字值不等于其自身。 
            举例来说，如果 x = float('NaN') 则 3 < x, x < 3 和 x == x 均为假值，而 x != x 则为真值。 此行为是遵循 IEEE 754 标准的。
        None 和 NotImplemented 都是单例对象。 PEP 8 建议单例对象的比较应当总是通过 is 或 is not 而不是等于运算符来进行。
        二进制码序列 (bytes 或 bytearray 的实例) 可进行类型内部和跨类型的比较。 它们使用其元素的数字值按字典顺序进行比较。
        字符串 (str 的实例) 使用其字符的 Unicode 码位数字值 (内置函数 ord() 的结果) 按字典顺序进行比较。
            字符串和二进制码序列不能直接比较。
        序列 (tuple, list 或 range 的实例) 只可进行类型内部的比较，range 还有一个限制是不支持次序比较。 
            以上对象的跨类型一致性比较结果将是不相等，跨类型次序比较将引发 TypeError。
            序列比较是按字典序对相应元素进行逐个比较。 内置容器通常设定同一对象与其自身是相等的。
            内置多项集间的字典序比较规则如下:
                两个多项集若要相等，它们必须为相同类型、相同长度，并且每对相应的元素都必须相等
                    （例如，[1,2] == (1,2) 为假值，因为类型不同）。
                对于支持次序比较的多项集，排序与其第一个不相等元素的排序相同
                    （例如 [1,2,x] <= [1,2,y] 的值与 x <= y 相同）。 
                    如果对应元素不存在，较短的多项集排序在前（例如 [1,2] < [1,2,3] 为真值）。
        两个映射 (dict 的实例) 若要相等则必须当且仅当它们具有相等的 (key, value) 对。 键和值的相相等性比较强制要求自反射性。
            次序比较 (<, >, <= 和 >=) 将引发 TypeError。
        集合 (set 或 frozenset 的实例) 可进行类型内部和跨类型的比较。
            它们将比较运算符定义为子集和超集检测。 
            这类关系没有定义完全排序（例如 {1,2} 和 {2,3} 两个集合不相等，即不为彼此的子集，也不为彼此的超集。 
            相应地，集合不适宜作为依赖于完全排序的函数的参数
                （例如如果给出一个集合列表作为 min(), max() 和 sorted() 的输入将产生未定义的结果）。
        大多数其他内置类型没有实现比较方法，因此它们会继承默认的比较行为。
    用户定义类在定制其比较行为时应当遵循一些一致性规则:
        相等比较应该是自反射的。 换句话说，相同的对象比较时应该相等:
            x is y 意味着 x == y
        比较应该是对称的。 换句话说，下列表达式应该有相同的结果:
            x == y 和 y == x
            x != y 和 y != x
            x < y 和 y > x
            x <= y 和 y >= x
        比较应该是可传递的。 下列（简要的）例子显示了这一点:
            x > y and y > z 意味着 x > z
            x < y and y <= z 意味着 x < z            
        反向比较应该导致布尔值取反。 换句话说，下列表达式应该有相同的结果:
            x == y 和 not x != y
            x < y 和 not x >= y (对于完全排序)
            x > y 和 not x <= y (对于完全排序)
        hash() 的结果应该与是否相等一致。 相等的对象应该或者具有相同的哈希值，或者标记为不可哈希。
        Python 并不强制要求这些一致性规则。 实际上，非数字值就是一个不遵循这些规则的例子。

## in not in 成员检测运算 Membership test operations
    in 和 not in 用于成员检测。 
    所有内置序列和集合类型以及字典都支持此运算，对于字典来说 in 检测其是否有给定的键。 
        对于 list, tuple, set, frozenset, dict 或 collections.deque 这样的容器类型，
        表达式 x in y 等价于 any(x is e or x == e for e in y)。
    对于字符串和字节串类型来说，当且仅当 x 是 y 的子串时 x in y 为 True。 一个等价的检测是 y.find(x) != -1。 
        空字符串总是被视为任何其他字符串的子串，因此 "" in "abc" 将返回 True。
    如果定义了 __contains__() 方法的用户自定义类来说，如果 y.__contains__(x) 返回真值则 x in y 返回 True，否则返回 False。
    如果未定义 __contains__() 但定义了 __iter__() 的用户自定义类来说，如果在对 y 进行迭代时产生了值 z 使得
        表达式 x is z or x == z 为真，则 x in y 为 True。
        如果在迭代期间引发了异常，则等同于 in 引发了该异常。
    如果一个类定义了 __getitem__()，则当且仅当存在非负整数索引号 i 使得 
        x is y[i] or x == y[i] 并且没有更小的索引号引发 IndexError 异常时 x in y 为 True。 
        （如果引发了任何其他异常，则等同于 in 引发了该异常）。

## is is not标识号比较 Identity comparisons
    is 和 is not 用于检测对象的标识号
    当且仅当 x 和 y 是同一对象时 x is y 为真。 
    一个对象的标识号可使用 id() 函数来确定。 x is not y 会产生相反的逻辑值。

# and or not 布尔运算 Boolean operations
    以下值将被解释为 false：
        False 、 None 、所有类型的数字零和空字符串和容器（包括字符串、元组、列表、字典、集合和冻结集合）。
        所有其他值均解释为 true。用户定义的对象可以通过提供 __bool__() 方法来自定义其真值。
    not 将在其参数为假值时产生 True，否则产生 False。
    表达式 x and y 首先对 x 求值；如果 x 为假则返回该值；否则对 y 求值并返回其结果值。
    表达式 x or y 首先对 x 求值；如果 x 为真则返回该值；否则对 y 求值并返回其结果值。
    请注意:
        and 和 or 都不限制其返回的值和类型必须为 False 和 True，而是返回最后被求值的操作数。 
            此行为是有必要的，例如假设 s 为一个当其为空时应被替换为某个默认值的字符串，
            表达式 s or 'foo' 将产生希望的值。 
        由于 not 必须创建一个新值，不论其参数为何种类型它都会返回一个布尔值
            （例如，not 'foo' 结果为 False 而非 ''。）

# := 赋值表达式 Assignment expressions
    赋值表达式（有时又被称为“命名表达式”或“海象表达式”） “named expression” or “walrus”
        将一个 expression 赋值给一个 identifier，同时还会返回 expression 的值。
    一个常见用例是在处理匹配的正则表达式的时候:
        if matching := pattern.search(data):
            do_something(matching)
    或者是在处理分块的文件流的时候:
        while chunk := file.read(9000):
            process(chunk)
    赋值表达式在被用作切片、条件表达式、lambda 表达式、关键字参数和推导式中的 if 表达式
        以及在 assert 和 with 语句中的子表达式时必须用圆括号括起来。 
        在其可使用的其他场合，圆括号则不是必须的，包括在 if 和 while 语句中。

# if... else条件表达式 Conditional expressions
    条件表达式（有时称为“三元运算符”）在所有 Python 运算中具有最低的优先级。
    表达式 x if C else y 首先是对条件 C 而非 x 求值。 
        如果 C 为真，x 将被求值并返回其值；否则将对 y 求值并返回其值。

# lambda 表达式 Lambdas
    lambda_expr ::=  "lambda" [parameter_list] ":" expression
    lambda 表达式（有时称为 lambda 构型）被用于创建匿名函数。 
        表达式 lambda parameters: expression 会产生一个函数对象 。 
        该未命名对象的行为类似于用以下方式定义的函数:
    def <lambda>(parameters):
        return expression
    请注意通过 lambda 表达式创建的函数不能包含语句或标注。

# 表达式列表  Expression lists
    expression_list    ::=  expression ("," expression)* [","]
    starred_list       ::=  starred_item ("," starred_item)* [","]
    starred_expression ::=  expression | (starred_item ",")* [starred_item]
    starred_item       ::=  assignment_expression | "*" or_expr
    除了作为列表或集合显示的一部分，包含至少一个逗号的表达式列表将生成一个元组。 
        元组的长度就是列表中表达式的数量。 表达式将从左至右被求值。
    一个星号 * 表示 可迭代拆包 iterable unpacking。 其操作数必须为一个 iterable。 
        该可迭代对象将被拆解为迭代项的序列，并被包含于在拆包位置上新建的元组、列表或集合之中。
    末尾的逗号仅在创建单独元组 (或称 单例) 时需要；在所有其他情况下都是可选项。 
        没有末尾逗号的单独表达式不会创建一个元组，而是产生该表达式的值。

# 求值顺序 Evaluation order
    Python 按从左至右的顺序对表达式求值。 但注意在对赋值操作求值时，右侧会先于左侧被求值。
    在以下几行中，表达式将按其后缀的算术优先顺序被求值:
        expr1, expr2, expr3, expr4
        (expr1, expr2, expr3, expr4)
        {expr1: expr2, expr3: expr4}
        expr1 + expr2 * (expr3 - expr4)
        expr1(expr2, expr3, *expr4, **expr5)
        expr3, expr4 = expr1, expr2

# 运算符优先级 Operator precedence
    下表对 Python 中运算符的优先顺序进行了总结，从最高优先级（最先绑定）到最低优先级（最后绑定）。 
        相同单元格内的运算符具有相同优先级。 除非语法显式地指明，否则运算符均为双目运算符。 
        相同单元格内的运算符从左至右组合的（只有幂运算符是从右至左组合的）。
    请注意比较、成员检测和标识号检测均为相同优先级，并具有如 比较运算 一节所描述的从左至右串连特性。
        ①
        (expressions...),
        [expressions...], {key: value...}, {expressions...}
        绑定或加圆括号的表达式，列表显示，字典显示，集合显示
        Binding or parenthesized expression, list display, dictionary display, set display
        ②
        x[index], x[index:index], x(arguments...), x.attribute
        抽取，切片，调用，属性引用
        Subscription, slicing, call, attribute reference
        ③
        await x
        await 表达式
        Await expression
        ④
        **
        乘方 
        Exponentiation 
        ⑤
        +x, -x, ~x
        正，负，按位非 NOT
        Positive, negative, bitwise NOT
        ⑥
        *, @, /, //, %
        乘，矩阵乘，除，整除，取余
        Multiplication, matrix multiplication, division, floor division, remainder 
        ⑦
        +, -
        加和减
        Addition and subtraction
        ⑧
        <<, >>
        移位
        Shifts
        ⑨
        &
        按位与 AND
        Bitwise AND
        ⑩
        ^
        按位异或 XOR
        Bitwise XOR
        ⑪
        |
        按位或 OR
        Bitwise OR
        ⑫
        in, not in, is, is not, <, <=, >, >=, !=, ==
        比较运算，包括成员检测和标识号检测
        Comparisons, including membership tests and identity tests
        ⑬
        not x
        布尔逻辑非 NOT
        Boolean NOT
        ⑭
        and
        布尔逻辑与 AND
        Boolean AND
        ⑮
        or
        布尔逻辑或 OR
        Boolean OR
        ⑯
        if -- else
        条件表达式
        Conditional expression
        ⑰
        lambda
        lambda 表达式
        Lambda expression
        ⑱
        :=
        赋值表达式
        Assignment expression

运算符： 32
    4  () [] {} {}
    4  [] [::] () .
    1  await
    1  **
    3  + - ~
    5  *, @, /, //, %
    2  +, -
    2  <<, >>
    1  &
    1  ^
    1  |
    10 in, not in, is, is not, <, <=, >, >=, !=, ==
    1  not
    1  and
    1  or
    1  if else
    1  lambda
    1  :=
圆圈 序号 数字 编号 
①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮⑯⑰⑱⑲⑳
㉑㉒㉓㉔㉕㉖㉗㉘㉙㉚㉛㉜㉝㉞㉟㊱㊲㊳㊴㊵
㊶㊷㊸㊹㊺㊻㊼㊽㊾㊿。
'''


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ref_express.py')
    test()
