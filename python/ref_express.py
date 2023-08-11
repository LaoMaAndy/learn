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

###  字典显示 Dictionary displays
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





'''


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('ref_express.py')
    test()
