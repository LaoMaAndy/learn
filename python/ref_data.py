#!/usr/bin/env python3
r'''
# 数据模型
    mutable， immutable 可变类型， 不可变类型
    containers 容器， 

# 对象，值与类型 Objects, values and types
    每个对象都有各自的标识号、类型和值。
    一个对象被创建后，它的 标识号 就绝不会改变
    'is' 运算符可以比较两个对象的标识号是否相同；
    id() 函数能返回一个代表其标识号的整数。
        CPython 中，id(x) 就是存放 x 的内存的地址。
    type() 返回对象的类型。与编号一样，一个对象的 类型 也是不可改变的。
    可变/不可变：
        值可以改变的对象被称为 可变对象；值不可以改变的对象就被称为 不可变对象。
        对象的可变性是由它的类型决定的：如：
            数字、字符串和元组是不可变的，而字典和列表是可变的。
    垃圾回收 gc 模块
        在对象不可访问时立即回收其中的大部分，但不保证回收包含循环引用的垃圾。
        注意：使用实现的跟踪或调试功能可能令正常情况下会被回收的对象继续存活。
            注意通过 'try...except' 语句捕捉异常也可能令对象保持存活。
        有些对象包含对 "外部" 资源的引用，例如打开文件或窗口。由于垃圾回收并不确保发生，
            这些对象还提供了明确地释放外部资源的操作，强烈推荐在程序中显式关闭此类对象。
                'try...finally' 语句和 'with' 语句提供了进行此种操作的更便捷方式。
    容器：
        容器的例子有 元组、列表和字典等。
        讨论容器的可变性时，则仅指其直接包含的对象的编号。
        一个不可变容器 (例如元组) 包含对一个可变对象的引用，则当该可变对象被改变时容器的值也会改变。
    类型：
        类型会影响对象行为的几乎所有方面。甚至对象编号的重要性也在某种程度上受到影响: 
        对于不可变类型，会得出新值的运算实际上会返回对相同类型和取值的任一现有对象的引用，
        而对于可变类型来说这是不允许的。
    是否指向相同的对象
        在 a = 1; b = 1 之后，a 和 b 可能会也可能不会指向同一个值为一的对象，这取决于具体实现，
        但是在 c = []; d = [] 之后，c 和 d 保证会指向两个不同、单独的新建空列表。
        请注意 c = d = [] 则是将同一个对象赋值给 c 和 d。

# 标准类型层级结构 The standard type hierarchy
# None : 此类型只有一种取值。是一个具有此值的单独对象。此对象通过内置名称 None 访问。
    在许多情况下它被用来表示空值，例如未显式指明返回值的函数将返回 None。它的逻辑值为假。

# NotImplemented : 此类型只有一种取值。 是一个具有该值的单独对象。 
    此对象通过内置名称 NotImplemented 访问。 
    数值方法和丰富比较方法如未实现指定运算符表示的运算则应返回该值。 
    （解释器会根据具体运算符继续尝试反向运算或其他回退操作。） 它不应被解读为布尔值。

# Ellipsis : 此类型只有一种取值。是一个具有此值的单独对象。此对象通过字面值 ... 或内置名称 
    Ellipsis 访问。它的逻辑值为真。

# numbers.Number : 此类对象由数字字面值创建，并会被作为算术运算符和算术内置函数的返回结果。
    数字对象是不可变的；一旦创建其值就不再改变。
        from numbers import Number
        isinstance(7, numbers.Number)
        >>> True
        issubclass(int, numbers.Number)
        >>> True
    数字类的字符串表示形式，由 __repr__() 和 __str__() 算出，具有以下特征属性:
        它们是有效的数字字面值，当被传给它们的类构造器时，将会产生具有原数字值的对象。
        表示形式会在可能的情况下采用 10 进制。
        开头的零，除小数点前可能存在的单个零之外，将不会被显示。
        末尾的零，除小数点后可能存在的单个零之外，将不会被显示。
        正负号仅在当数字为负值时会被显示。

## numbers.Integral
    此类对象表示数学中整数集合的成员 (包括正数和负数)。
        整型数可细分为两种类型:
    整型 (int)
        此类对象表示任意大小的数字，仅受限于可用的内存 (包括虚拟内存)。在变换和掩码运算中会以二进制表示，
        负数会以 2 的补码表示，看起来像是符号位向左延伸补满空位。
    布尔型 (bool)
        此类对象表示逻辑值 False 和 True。代表 False 和 True 值的两个对象是唯二的布尔对象。
        布尔类型是整型的子类型，两个布尔值在各种场合的行为分别类似于数值 0 和 1，
        例外情况只有在转换为字符串时分别返回字符串 "False" 或 "True"。
    整型数表示规则的目的是在涉及负整型数的变换和掩码运算时提供最为合理的解释。

## numbers.Real (float)
    此类对象表示机器级的双精度浮点数。其所接受的取值范围和溢出处理将受制于底层的机器架构 (以及 C 或 Java 实现)。
    Python 不支持单精度浮点数；支持后者通常的理由是节省处理器和内存消耗，
    但这点节省相对于在 Python 中使用对象的开销来说太过微不足道，因此没有理由包含两种浮点数而令该语言变得复杂。

## numbers.Complex (complex)
    此类对象以一对机器级的双精度浮点数来表示复数值。有关浮点数的附带规则对其同样有效。
    一个复数值 z 的实部和虚部可通过只读属性 z.real 和 z.imag 来获取。

# 序列 Sequences
    此类对象表示以非负整数作为索引的有限有序集。
    内置函数 len() 可返回一个序列的条目数量。
    序列还支持切片: a[i:j] 选择索引号为 k 的所有条目，i <= k < j。
        当用作表达式时，序列的切片就是一个与序列类型相同的新序列。新序列的索引还是从 0 开始。
    有些序列还支持带有第三个 "step" 形参的 "扩展切片": a[i:j:k] 
        选择 a 中索引号为 x 的所有条目，x = i + n*k, n >= 0 且 i <= x < j。
    序列可根据其可变性来加以区分:

## 不可变序列 Immutable sequences
    不可变序列类型的对象一旦创建就不能再改变。以下类型属于不可变对象:

    ### 字符串 Strings
        字符串是表示 Unicode 代码点的值序列。 U+0000 - U+10FFFF 范围内的所有代码点都可以用字符串表示。 
        Python 没有 char 类型；
        字符串中的每个代码点都表示为长度为 1 的字符串对象。
        内置函数 
            ord() 将代码点从字符串形式转换为 0 - 10FFFF 范围内的整数
            chr() 将 0 - 10FFFF 范围内的整数转换为相应长度的 1 字符串对象。
            str.encode() 可用于使用给定的文本编码将 str 转换为 bytes ，而 
            bytes.decode() 可用于实现相反的效果。

    ### Tuples 元组    
        一个元组中的条目可以是任意 Python 对象。包含两个或以上条目的元组由逗号分隔的表达式构成。
        只有一个条目的元组 ('单项元组') 可通过在表达式后加一个逗号来构成 
        (一个表达式本身不能创建为元组，因为圆括号要用来设置表达式分组)。
        一个空元组可通过一对内容为空的圆括号创建。

    ### Bytes 字节串
        字节串对象是不可变的数组。其中每个条目都是一个 8 位字节，以取值范围 0 <= x < 256 的整型数表示。字节串字面值 (例如 b'abc') 和内置的 bytes() 构造器可被用来创建字节串对象。字节串对象还可以通过 decode() 方法解码为字符串。

## 可变序列 Mutable sequences
    可变序列在被创建后仍可被改变。下标和切片标注可被用作赋值和 del (删除) 语句的目标。
    目前有两种内生可变序列类型:

    ### Lists 列表
        列表中的条目可以是任意 Python 对象。列表由用方括号括起并由逗号分隔的多个表达式构成。
        (注意创建长度为 0 或 1 的列表无需使用特殊规则。)

    #### Byte Arrays 字节数组
        字节数组对象属于可变数组。可以通过内置的 bytearray() 构造器来创建。
        除了是可变的 (因而也是不可哈希的)，在其他方面字节数组提供的接口和功能都与不可变的 bytes 对象一致。
        扩展模块 array : 扩展模块提供了一个额外的可变序列类型示例
            collections 扩展模块也是如此。

# 集合类型 Set types
    此类对象表示由不重复且不可变对象组成的无序且有限的集合。因此它们不能通过下标来索引。
    但是它们可被迭代，也可用内置函数 len() 返回集合中的条目数。
    集合常见的用处是：
        快速成员检测，
        去除序列中的重复项，
        以及进行交、并、差和对称差等数学运算。
    对于集合元素所采用的不可变规则与字典的键相同。
    注意数字类型遵循正常的数字比较规则: 
        如果两个数字相等 (例如 1 和 1.0)，则同一集合中只能包含其中一个。
    目前有两种内生集合类型:
    ## 集合 Sets
        此类对象表示可变集合。它们可通过内置的 set() 构造器创建，
        并且创建之后可以通过方法进行修改，例如 add()。
    ## 冻结集合 Frozen sets 
        此类对象表示不可变集合。它们可通过内置的 frozenset() 构造器创建。
        由于 frozenset 对象不可变且 hashable，它可以被用作另一个集合的元素或是字典的键。

# 映射 Mappings 
    此类对象表示由任意索引集合所索引的对象的集合。
        通过下标 a[k] 可在映射 a 中选择索引为 k 的条目；
        这可以在表达式中使用，也可作为赋值或 del 语句的目标。
        内置函数 len() 可返回一个映射中的条目数。
    目前只有一种内生映射类型:
    ## 词典 Dictionaries 
        此类对象表示由几乎任意值作为索引的有限个对象的集合。
        不可作为键的类型为可变类型，包括列表或字典或其他。
            通过值而非对象编号进行比较的值，其原因在于高效的字典实现需要使用键的哈希值以保持一致性。
        可用作键的数字类型遵循正常的数字比较规则: 如果两个数字相等 (例如 1 和 1.0) 则它们均可来用来索引同一个字典条目。
        字典会保存插入顺序，这意味着键将以它们被添加的顺序在字典中依次产生。
            替换某个现有的键不会改变其顺序，
            但是移除某个键再重新插入则会将其添加到末尾而不会保留其原有位置。
        字典是可变的；它们可通过 {...} 标注来创建
        扩展模块 dbm.ndbm 和 dbm.gnu 提供了额外的映射类型示例，
            collections 模块也是如此    
        备注： 在 Python 3.6 版之前字典不会保留插入顺序。 
            在 CPython 3.6 中插入顺序会被保留，但这在当时被当作是一个实现细节而非确定的语言特性。

# 可调用类型 Callable types
    此类型可以被应用于函数调用操作

## 用户定义函数 User-defined functions 
    用户定义函数对象可通过函数定义来创建 (参见 函数定义 小节)。
    函数名 ： 代表函数对象， 用户定义函数对象 user-defined function object
    函数调用 ： 使用函数名加括号内的参数列表。
    它被调用时应附带一个参数列表，其中包含的条目应与函数所定义的形参列表一致。
    特殊属性：
        __doc__ ，可写， 该函数的文档字符串，没有则为 None；不会被子类继承。
        __name__ ，可写， 该函数的名称。
        __qualname__  ，可写， 该函数的 qualified name。3.3 新版功能.
        __module__ ， 可写， 该函数所属模块的名称，没有则为 None。
        __defaults__ ， 可写， 由具有默认值的参数的默认参数值组成的元组，如无任何参数具有默认值则为 None。
        __code__ ， 可写， 表示编译后的函数体的代码对象。
        __globals__ ， 只读， 对存放该函数中全局变量的字典的引用，即：函数所属模块的全局命名空间。
        __dict__ ， 可写， 命名空间支持的函数属性。
        __closure__ ， 只读， None 或包含该函数可用变量的绑定的单元的元组。有关 cell_contents 属性的详情见下。
        __annotations__ ， 可写， 包含形参标注的字典。 字典的键是形参名，而如果提供了 'return' 则是用于返回值标注。 
                        有关如何使用此属性的更多信息，请参阅 对象注解属性的最佳实践。
                        https://docs.python.org/zh-cn/3/howto/annotations.html#annotations-howto
        __kwdefaults__ ， 可写， 仅包含关键字参数默认值的字典。
    
    函数对象也支持获取和设置任意属性，例如这可以被用来给函数附加元数据。
        函数对象新增的属性 与 函数内置属性不同。 
        目前函数无法调用函数对象新增的属性。
        使用正规的属性点号标注获取和设置此类属性。
        注意当前实现仅支持用户定义函数属性。未来可能会增加支持内置函数属性。
        def foo():
            s = str()
            # 以上效果相同，显示函数内部属性
            print('vars()')
            print(locals()) 

            # 以下效果相同，显示函数对象属性
            print(foo.__dict__)
            print(vars(foo)) 
    (?)cell object具有 cell_contents 属性。这可被用来获取以及设置单元的值。

## 实例方法 Instance methods
    实例方法 与 实例方法对象
    实例方法，即 : 实例.方法名
    实例方法用于结合类、类实例和任何可调用对象 (通常为用户定义函数)。
    特殊只读属性：
        __self__ 为类实例对象本身
        __func__ 为函数对象
        __doc__ 为方法的文档 (与 __func__.__doc__ 作用相同)
        __name__ 为方法名称 (与 __func__.__name__ 作用相同)；
        __module__ 为方法所属模块的名称，没有则为 None。
    方法还支持获取 (但不能设置) 下层函数对象的任意函数属性。
    当一个实例方法对象被调用时，会调用对应的下层函数 (__func__)，
        并将类实例 (__self__) 插入参数列表的开头。
        例如，当 C 是一个包含了 f() 函数定义的类，而 x 是 C 的一个实例，
            则调用 x.f(1) 就等同于调用 C.f(x, 1)。
            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    当实例方法对象派生自类方法对象时，存储在 __self__ 中的“类实例”实际上是类本身，
        因此调用 x.f(1) 或 C.f(1) ，其中 f 是底层函数。
    (此处有疑惑，需要再仔细研读)

## 生成器函数 Generator functions 
    一个使用 yield 语句（见 yield 语句 章节）的函数或方法被称为 生成器函数。 
        这样的函数在被调用时，总是返回一个可以执行该函数体的 iterator 对象：
        调用该迭代器的 iterator.__next__() 方法将导致这个函数一直运行
        到它使用 yield 语句提供一个值。 
    当这个函数执行 return 语句或到达函数体末尾时，将引发 StopIteration 异常
        并且该迭代器将到达所返回的值集合的末尾。
    https://docs.python.org/zh-cn/3/reference/simple_stmts.html#yield

## 协程函数 Coroutine functions 
    使用 async def 来定义的函数或方法就被称为 协程函数。这样的函数在被调用时会返回一个 coroutine 对象。
        它可能包含 await 表达式以及 async with 和 async for 语句。
        详情可参见 协程对象 一节。
    https://docs.python.org/zh-cn/3/reference/datamodel.html#coroutine-objects

## 异步生成器函数 Asynchronous generator functions
    使用 async def 来定义并使用了 yield 语句的函数或方法被称为 异步生成器函数。 
        这样的函数在被调用时，将返回一个 asynchronous iterator 对象，
        该对象可在 async for 语句中被用来执行函数体。
    调用异步迭代器的 aiterator.__anext__ 方法将返回一个 awaitable，
        此对象会在被等待时执行直到使用 yield 产生一个值。 
        当函数执行到空的 return 语句或函数末尾时，
        将会引发 StopAsyncIteration 异常并且异步迭代器也将到达要产生的值集合的末尾。

## 内置函数 Built-in functions
    内置函数对象是对于 C 函数的外部封装。
    内置函数的例子包括 len() 和 math.sin() (math 是一个标准内置模块)。
    内置函数参数的数量和类型由 C 函数决定。
    特殊的只读属性: 
        __doc__ 是函数的文档字符串，如果没有则为 None; 
        __name__ 是函数的名称; 
        __self__ 设定为 None (参见下一条目); 
        __module__ 是函数所属模块的名称，如果没有则为 None。

## 内置方法 Built-in methods
    此类型实际上是内置函数的另一种形式，只不过还包含了一个传入 C 函数的对象作为隐式的额外参数。
    内置方法的一个例子是 alist.append()，其中 alist 为一个列表对象。
    在此示例中，特殊的只读属性 __self__ 会被设为 alist 所标记的对象。

## 类 Classes
    类是可调用对象。 这些对象通常是用作创建自身实例的“工厂”，
    但类也可以有重载 __new__() 的变体类型。调用的参数会传递给 __new__()，
    并且在通常情况下，也会传递给 __init__() 来初始化新的实例。

## 类实例 Class Instances
    任意类的实例可以通过在其所属类中定义 __call__() 方法变成可调用对象。
    在类中定义一个函数：
        def __call__(self): ...
    即可对类对象进行调用：
        c = MyClass()  c()

# 模块 Modules
    由 import 语句发起调用，或者通过 importlib.import_module() 和内置的 __import__() 等函数发起调用。
    模块中的字典对象：
        块对象具有由字典对象实现的命名空间，也就是模块中函数的 __globals__ 属性引用的字典
        属性引用被转换为该字典中的查找，例如 m.x 相当于 m.__dict__["x"]
        属性赋值会更新模块的命名空间字典，例如 m.x = 1 等同于 m.__dict__["x"] = 1。
    模块对象不包含用于初始化模块的代码对象（因为初始化完成后不需要它）。
    预先定义的（可写）属性:
        __name__ : 模块的名称。
        __doc__  : 模块的文档字符串，如果不可用则为 None。
        __file__ : 被加载模块所对应文件的路径名称，如果它是从文件加载的话。 
                    对于某些类型的模块来说 __file__ 属性可能是缺失的，
                    例如被静态链接到解释器中的 C 模块。 
                    对于从共享库动态加载的扩展模块来说，它将是共享库文件的路径名称。
        __annotations__ : 包含在模块体执行期间收集的 变量标注 的字典。 
                    有关使用 __annotations__ 的最佳实践，请参阅 对象注解属性的最佳实践。
        __dict__ : 特殊的只读属性, 为以字典对象表示的模块命名空间。
                    CPython 实现细节： 由于 CPython 清理模块字典的设定，
                    当模块离开作用域时模块字典将会被清理.

# 自定义类 Custom classes
    自定义类这种类型一般通过类定义来创建。每个类都有通过一个字典对象实现的独立命名空间。
    类属性引用会被转化为在此字典中查找，例如 C.x 会被转化为 C.__dict__["x"] 
        (不过也存在一些钩子对象以允许其他定位属性的方式)。
        当未在其中发现某个属性名称时，会继续在基类中查找。
    这种基类查找使用 C3 方法解析顺序，即使存在 '钻石形' 继承结构即
        有多条继承路径连到一个共同祖先也能保持正确的行为。
    有关 Python 使用的 C3 MRO 的详情可查看配合 2.3 版发布的文档 
        https://www.python.org/download/releases/2.3/mro/.
    当一个类属性引用 (假设类名为 C) 产生一个类方法对象时，它将转化为一个实例方法对象，
        该对象 __self__ 属性为 C 。
    当其产生一个静态方法对象(@staticmethod)时，它将转化为该静态方法对象所封装的对象。
        从类的 __dict__ 所包含内容以外获取属性的其他方式请参看 实现描述器 一节。
        https://docs.python.org/3/reference/datamodel.html#descriptors
    以上需查看原文：
    When a class attribute reference (for class C, say) would yield a class method object, 
    it is transformed into an instance method object whose __self__ attribute is C. 
    When it would yield a static method object, 
    it is transformed into the object wrapped by the static method object. 
    See section Implementing Descriptors for another way in which attributes 
        retrieved from a class may differ from those actually contained in its __dict__.
    给类属性赋值将会更新类的字典，而不是基类的字典。
    类对象可以被调用（见上文），用来生成一个类实例。（见下文）。
    A class object can be called (see above) to yield a class instance (see below).
    Special attributes: 特殊属性：
        __name__ : 类的名称。
        __module__ : 类定义所在模块的名称。
        __dict__ : 包含类命名空间的字典。
        __bases__ : 包含基类的元组，按它们在基类列表中的出现先后排序。
        __doc__ : 类的文档字符串，如果未定义则为 None。
        __annotations__ : 包含在类体执行期间收集的 变量标注 的字典。 
            有关使用 __annotations__ 的最佳实践，请参阅 对象注解属性的最佳实践。

# 类实例 Class instances
    类实例可通过调用类对象来创建（见上文）。 
        每个类实例都有通过一个字典对象实现的独立命名空间，属性引用会首先在此字典中查找。 
        当未在其中发现某个属性，而实例对应的类中有该属性时，会继续在类属性中查找。 
        如果找到的类属性为一个用户自定义函数对象，它会被转化为实例方法对象，其 __self__ 属性即该实例。 
        静态方法和类方法对象也会被转化；参见上文的“类”小节。 
        要了解其他通过类实例来获取相应类属性的方式请参阅 实现描述器 小节，
        这样得到的属性可能与实际存放在类的 __dict__ 中的对象不同。
        如果未找到类属性，而对象所属的类具有 __getattr__() 方法，则会调用该方法来满足查找要求。
    属性赋值和删除会更新实例的字典，但绝不会更新类的字典。 
        如果类具有 __setattr__() 或 __delattr__() 方法，
        则将调用该方法而不再直接更新实例的字典。
    如果类实例具有某些特殊名称的方法，就可以伪装为数字、序列或映射。参见 特殊方法名称 一节。
    特殊属性: 
        __dict__ 为属性字典; 
        __class__ 为实例对应的类。

# I/O 对象 (或称文件对象) I/O objects (also known as file objects)
    file object 表示一个打开的文件。有多种快捷方式可用来创建文件对象: 
        open() 内置函数，以及 
        os.popen(), 
        os.fdopen() 和 
        socket 对象的 makefile() 方法 
        (还可能使用某些扩展模块所提供的其他函数或方法)。
    sys.stdin, sys.stdout 和 sys.stderr 会初始化为对应于解释器标准输入、输出和错误流的文件对象；
        它们都会以文本模式打开，因此都遵循 io.TextIOBase 抽象类所定义的接口。

# 内部类型 Internal types
    某些由解释器内部使用的类型也被暴露给用户。它们的定义可能随未来解释器版本的更新而变化，为内容完整起见在此处一并介绍。
## 代码对象 Code objects
    代码对象表示 编译为字节的 可执行 Python 代码，或称 bytecode。
    代码对象和函数对象的区别在于函数对象包含对函数全局对象 (函数所属的模块) 的显式引用，
    而代码对象不包含上下文；而且默认参数值会存放于函数对象而不是代码对象内 (因为它们表示在运行时算出的值)。
    与函数对象不同，代码对象不可变，也不包含对可变对象的引用 (不论是直接还是间接)。
## 帧对象 Frame objects
    帧对象表示执行帧。它们可能出现在回溯对象中 (见下文)，还会被传递给注册跟踪函数。
## 回溯对象 Traceback objects
    回溯对象表示一个异常的栈跟踪记录。当异常发生时会隐式地创建一个回溯对象，
    也可能通过调用 types.TracebackType 显式地创建。
## 切片对象 Slice objects
    切片对象被用来表示 __getitem__() 方法所使用的切片。 该对象也可使用内置的 slice() 函数来创建。
## 静态方法对象 Static method objects
    静态方法对象提供了一种胜过上文所述将函数对象转换为方法对象的方式。 
    静态方法对象是对任意其他对象的包装器，通常用来包装用户自定义的方法对象。 
    当从类或类实例获取一个静态方法对象时，实际返回的是经过包装的对象，它不会被进一步转换。 
    静态方法对象也是可调用对象。 静态方法对象可通过内置的 staticmethod() 构造器来创建。
## 类方法对象 Class method objects
    类方法对象和静态方法一样是对其他对象的封装，会改变从类或类实例获取该对象的方式。
    类方法对象在此类获取操作中的行为已在上文 "用户定义方法" 一节中描述。
    类方法对象可通过内置的 classmethod() 构造器来创建。

# 特殊方法名称  Special method names
    运算符重载 的方式。
    一个类可以通过定义具有特殊名称的方法来实现由特殊语法来发起调用的特定操作（例如算术运算或抽取与切片）。 
    这是 Python 实现 运算符重载 的方式，允许每个类自行定义基于该语言运算符的特定行为。 
    举例来说，如果一个类定义了名为 __getitem__() 的方法，并且 x 是该类的一个实例，则 
        x[i] 基本就等价于 type(x).__getitem__(x, i)。 
    除非有说明例外情况，在没有定义适当方法的时候尝试执行某种操作将引发一个异常 
        (通常为 AttributeError 或 TypeError)。
    将一个特殊方法设为 None 表示对应的操作不可用。 
        例如，如果一个类将 __iter__() 设为 None，则该类就是不可迭代的，
        因此对其实例调用 iter() 将引发一个 TypeError (而不会回退至 __getitem__())。
    在实现模拟任何内置类型的类时，很重要的一点是模拟的实现程度对于被模拟对象来说应当是有意义的。
        例如，提取单个元素的操作对于某些序列来说是适宜的，但提取切片可能就没有意义。
        (这种情况的一个实例是 W3C 的文档对象模型中的 NodeList 接口。)

## 基本定制 Basic customization
    object.__new__(cls[, ...]) 调用以创建一个 cls 类的新实例。
        __new__() 是一个静态方法 (因为是特例所以你不需要显式地声明)，
            它会将所请求实例所属的类作为第一个参数。
            其余的参数会被传递给对象构造器表达式 (对类的调用)。
            __new__() 的返回值应为新对象实例 (通常是 cls 的实例)。
        如果 __new__() 在构造对象期间被发起调用并且它返回了一个 cls 的实例，
            则新实例的 __init__() 方法将以 __init__(self[, ...]) 的形式被发起调用，
            其中 self 为新实例而其余的参数与被传给对象构造器的参数相同。
        如果 __new__() 未返回一个 cls 的实例，则新实例的 __init__() 方法就不会被执行。
        __new__() 的目的主要是允许不可变类型的子类 (例如 int, str 或 tuple) 定制实例创建过程。
            它也常会在自定义元类中被重载以便定制类创建过程。
    object.__init__(self[, ...])
        在实例 (通过 __new__()) 被创建之后，返回调用者之前调用。
            其参数与传递给类构造器表达式的参数相同。
            一个基类如果有 __init__() 方法，则其所派生的类如果也有 __init__() 方法，
            就必须显式地调用它以确保实例基类部分的正确初始化；
                例如: super().__init__([args...]).
        因为对象是由 __new__() 和 __init__() 协作构造完成的 (由 __new__() 创建，
            并由 __init__() 定制)，所以 __init__() 返回的值只能是 None，
            否则会在运行时引发 TypeError。
    object.__del__(self)
        在实例将被销毁时调用。 这还被称为终结器或析构器（不适当）。 
            如果一个基类具有 __del__() 方法，则其所派生的类如果也有 __del__() 方法，
            就必须显式地调用它以确保实例基类部分的正确清除。
        __del__() 方法可以 (但不推荐!) 通过创建一个该实例的新引用来推迟其销毁。
            这被称为对象 重生。__del__() 是否会在重生的对象将被销毁时再次被调用是由具体实现决定的 ；
            当前的 CPython 实现只会调用一次。
        当解释器退出时不会确保为仍然存在的对象调用 __del__() 方法。
        备注：
            del x 并不直接调用 x.__del__() --- 前者会将 x 的引用计数减一，
            而后者仅会在 x 的引用计数变为零时被调用。
    object.__repr__(self)
        由 repr() 内置函数调用以输出一个对象的“官方”字符串表示。
            如果可能，这应类似一个有效的 Python 表达式，能被用来重建具有相同取值的对象（只要有适当的环境）。
            如果这不可能，则应返回形式如 <...some useful description...> 的字符串。
            返回值必须是一个字符串对象。如果一个类定义了 __repr__() 但未定义 __str__()，
            则在需要该类的实例的“非正式”字符串表示时也会使用 __repr__()。
        此方法通常被用于调试，因此确保其表示的内容包含丰富信息且无歧义是很重要的。
    object.__str__(self)
        通过 str(object) 以及内置函数 format() 和 print() 调用以生成一个
            对象的“非正式”或格式良好的字符串表示。 返回值必须为一个 字符串 对象。
        此方法与 object.__repr__() 的不同点在于 __str__() 并不预期返回一个有效的 Python 表达式：
            可以使用更方便或更准确的描述信息。
        内置类型 object 所定义的默认实现会调用 object.__repr__()。
    object.__bytes__(self)
        通过 bytes 调用以生成一个对象的字节串表示。这应该返回一个 bytes 对象。
    object.__format__(self, format_spec)
        通过 format() 内置函数、扩展、格式化字符串字面值 的求值以及 str.format() 方法
            调用以生成一个对象的“格式化”字符串表示。 format_spec 参数为包含所需格式选项描述的字符串。 
            format_spec 参数的解读是由实现 __format__() 的类型决定的，
            不过大多数类或是将格式化委托给某个内置类型，或是使用相似的格式化选项语法。
        请参看 格式规格迷你语言 了解标准格式化语法的描述。
        返回值必须为一个字符串对象。
    object.__lt__(self, other)
    object.__le__(self, other)
    object.__eq__(self, other)
    object.__ne__(self, other)
    object.__gt__(self, other)
    object.__ge__(self, other)
        以上这些被称为“富比较”方法。
        运算符号与方法名称的对应关系如下：
            x<y 调用 x.__lt__(y)、
            x<=y 调用 x.__le__(y)、
            x==y 调用 x.__eq__(y)、
            x!=y 调用 x.__ne__(y)、
            x>y 调用 x.__gt__(y)、
            x>=y 调用 x.__ge__(y)。
        如果指定的参数对没有相应的实现，富比较方法可能会返回单例对象 NotImplemented。
            按照惯例，成功的比较会返回 False 或 True。
        不过实际上这些方法可以返回任意值，因此如果比较运算符是要用于布尔值判断（例如作为 if 语句的条件），
            Python 会对返回值调用 bool() 以确定结果为真还是假。
        在默认情况下，object 通过使用 is 来实现 __eq__()，并在比较结果为假值时返回 NotImplemented: 
            True if x is y else NotImplemented。 
        对于 __ne__()，默认会委托给 __eq__() 并对结果取反，除非结果为 NotImplemented。 
        比较运算符之间没有其他隐含关系或默认实现；
            例如，(x<y or x==y) 为真并不意味着 x<=y。 
            要根据单根运算自动生成排序操作，请参看 functools.total_ordering()。
    object.__hash__(self)
        通过内置函数 hash() 调用以对哈希集的成员进行操作，
            属于哈希集的类型包括 set、frozenset 以及 dict。
        __hash__() 应该返回一个整数。
            对象比较结果相同所需的唯一特征属性是其具有相同的哈希值；
            建议的做法是把参与比较的对象全部组件的哈希值混在一起，
            即将它们打包为一个元组并对该元组做哈希运算。例如:
                def __hash__(self):
                    return hash((self.name, self.nick, self.color))
        如果一个类没有定义 __eq__() 方法，它也不应该定义 __hash__() 操作；
            如果它定义了 __eq__() 但没有定义 __hash__() ，则其实例将不能用作可哈希集合中的项目。
            如果一个类定义了可变对象并实现了 __eq__() 方法，则它不应该实现 __hash__() ，
            因为可哈希集合的实现要求键的哈希值是不可变的（如果对象的哈希值更改，它将位于错误的哈希桶中）。
        用户定义的类默认带有 __eq__() 和 __hash__() 方法；
            使用它们与任何对象（自己除外）比较必定不相等， 并且 x.__hash__() 
            会返回一个恰当的值以确保 x == y 同时意味着 x is y 且 hash(x) == hash(y)。
        一个类如果重载了 __eq__() 且没有定义 __hash__() 则会将其 __hash__() 隐式地设为 None。
            当一个类的 __hash__() 方法为 None 时，该类的实例将在一个程序尝试获取其哈希值时正确地引发 TypeError，
            并会在检测 isinstance(obj, collections.abc.Hashable) 时被正确地识别为不可哈希对象。
        如果一个重载了 __eq__() 的类需要保留来自父类的 __hash__() 实现，
            则必须通过设置 __hash__ = <ParentClass>.__hash__ 来显式地告知解释器。
        如果一个没有重载 __eq__() 的类需要去掉哈希支持，则应该在类定义中包含 __hash__ = None。
            一个自定义了 __hash__() 以显式地引发 TypeError 的类会被 
            isinstance(obj, collections.abc.Hashable) 调用错误地识别为可哈希对象。    
    object.__bool__(self)
        调用实现真值测试和内置操作 bool() ；应该返回 False 或 True 。
        当未定义此方法时，如果已定义，则调用 __len__() ，并且如果其结果非零，则该对象被视为 true。
        如果一个类既没有定义 __len__() 也没有定义 __bool__() ，则它的所有实例都被视为 true。

## 自定义属性访问 Customizing attribute access
    可以定义下列方法来自定义对类实例属性访问（x.name 的使用、赋值或删除）的具体含义.
    object.__getattr__(self, name)
        当默认属性访问因引发 AttributeError 而失败时被调用 
            (可能是调用 __getattribute__() 时由于 name 不是一个实例属性或 self 的类关系树中的属性而引发了 
            AttributeError； 或者是对 name 特性属性调用 __get__() 时引发了 AttributeError)。
            此方法应当返回（找到的）属性值或是引发一个 AttributeError 异常。
        请注意如果属性是通过正常机制找到的，__getattr__() 就不会被调用。
            （这是在 __getattr__() 和 __setattr__() 之间故意设置的不对称性。）
            这既是出于效率理由也是因为不这样设置的话 __getattr__() 将无法访问实例的其他属性。
            要注意至少对于实例变量来说，你不必在实例属性字典中插入任何值（而是通过插入到其他对象）就可以模拟对它的完全控制。
            请参阅下面的 __getattribute__() 方法了解真正获取对属性访问的完全控制权的办法。    
    object.__getattribute__(self, name)
        此方法会无条件地被调用以实现对类实例属性的访问。
            如果类还定义了 __getattr__()，则后者不会被调用，除非 
            __getattribute__() 显式地调用它或是引发了 AttributeError。
        此方法应当返回（找到的）属性值或是引发一个 AttributeError 异常。
            为了避免此方法中的无限递归，其实现应该总是调用具有相同名称的基类方法来访问它所需要的任何属性，
            例如 object.__getattribute__(self, name)。
    object.__setattr__(self, name, value)
        此方法在一个属性被尝试赋值时被调用。
        这个调用会取代正常机制（即将值保存到实例字典）。 name 为属性名称， value 为要赋给属性的值。  
    object.__delattr__(self, name)
        类似于 __setattr__() 但其作用为删除而非赋值。此方法应该仅在 del obj.name 对于该对象有意义时才被实现。
    object.__dir__(self)
        此方法会在对相应对象调用 dir() 时被调用。返回值必须为一个序列。 dir() 会把返回的序列转换为列表并对其排序。

## 自定义模块属性访问 Customizing module attribute access
    想要更细致地自定义模块的行为（设置属性和特性属性等待），可以将模块对象的 __class__ 属性设置为一个 types.ModuleType 的子类。例如:
        import sys
        from types import ModuleType

        class VerboseModule(ModuleType):
            def __repr__(self):
                return f'Verbose {self.__name__}'

            def __setattr__(self, attr, value):
                print(f'Setting {attr}...')
                super().__setattr__(attr, value)

        sys.modules[__name__].__class__ = VerboseModule

    __dir__ 函数应当不接受任何参数，并且返回一个表示模块中可访问名称的字符串序列。 
        此函数如果存在，将会重载一个模块中的标准 dir() 查找。

    特殊名称 __getattr__ 和 __dir__ 还可被用来自定义对模块属性的访问。
    模块层级的 __getattr__ 函数应当接受一个参数，其名称为一个属性名，并返回计算结果值或引发一个 AttributeError。
    如果通过正常查找即 object.__getattribute__() 未在模块对象中找到某个属性，
    则 __getattr__ 会在模块的 __dict__ 中查找，未找到时会引发一个 AttributeError。
    如果找到，它会以属性名被调用并返回结果值。

## 实现描述器 Implementing Descriptors

## 调用描述器
## __slots__
### 使用 __slots__ 的注意事项
## 自定义类创建
### 元类 Metaclasses
    默认情况下，类是使用 type() 来构建的。
    类体会在一个新的命名空间内执行，类名会被局部绑定到 type(name, bases, namespace) 的结果。
    类创建过程可通过在定义行传入 metaclass 关键字参数，或是通过继承一个包含此参数的现有类来进行定制。
    在以下示例中，MyClass 和 MySubclass 都是 Meta 的实例:
        class Meta(type):
            pass

        class MyClass(metaclass=Meta):
            pass

        class MySubclass(MyClass):
            pass
    在类定义内指定的任何其他关键字参数都会在下面所描述的所有元类操作中进行传递。
    当一个类定义被执行时，将发生以下步骤:
        解析 MRO 条目； Method Resolution Order (MRO)
        确定适当的元类；
        准备类命名空间；
        执行类主体；
        创建类对象。

###  解析 MRO 条目 Resolving MRO entries
    object.__mro_entries__(self, bases)
        如果类定义中出现的基类不是 type 的实例，则在该基类上搜索 __mro_entries__() 方法。
        如果找到 __mro_entries__() 方法，则在创建类时将用 __mro_entries__() 调用的结果替换基类。
        该方法是通过传递给 bases 参数的原始基元组来调用的，并且必须返回将使用的类的元组而不是基元组。
        返回的元组可能为空：在这些情况下，原始基数将被忽略。

### 确定适当的元类 Determining the appropriate metaclass
    为一个类定义确定适当的元类是根据以下规则:
        如果没有基类且没有显式指定元类，则使用 type()；
        如果给出一个显式元类而且 不是 type() 的实例，则其会被直接用作元类；
        如果给出一个 type() 的实例作为显式元类，或是定义了基类，则使用最近派生的元类。
        最近派生的元类会从显式指定的元类（如果有）以及所有指定的基类的元类（即 type(cls)）中选取。
            最近派生的元类应为 所有 这些候选元类的一个子类型。
            如果没有一个候选元类符合该条件，则类定义将失败并抛出 TypeError。

### 准备类命名空间 Preparing the class namespace
    一旦确定了适当的元类，就将准备好类的命名空间。 如果元类具有 __prepare__ 属性，
        它将以 namespace = metaclass.__prepare__(name, bases, **kwds) 的形式被调用
        （其中如果存在任何额外关键字参数，则应来自类定义）。 __prepare__ 方法应当被实现为 类方法。 
        __prepare__ 所返回的命名空间会被传入 __new__，但是当最终的类对象被创建时该命名空间会被拷贝到一个新的 dict 中。
    如果元类没有 __prepare__ 属性，则类命名空间将初始化为一个空的有序映射。

### 执行类主体 Executing the class body
    类主体会以（类似于） exec(body, globals(), namespace) 的形式被执行。
        普通调用与 exec() 的关键区别在于当类定义发生于函数内部时，
        词法作用域允许类主体（包括任何方法）引用来自当前和外部作用域的名称。
    但是，即使当类定义发生于函数内部时，在类内部定义的方法仍然无法看到在类作用域层次上定义的名称。
        类变量必须通过实例的第一个形参或类方法来访问，或者是通过下一节中描述的隐式词法作用域的 __class__ 引用。

### 创建类对象 Creating the class object
    一旦执行类主体完成填充类命名空间，将通过调用 metaclass(name, bases, namespace, **kwds) 创建类对象
        （此处的附加关键字参数与传入 __prepare__ 的相同）。
    如果类主体中有任何方法引用了 __class__ 或 super，这个类对象会通过零参数形式的 super(). __class__ 所引用，
        这是由编译器所创建的隐式闭包引用。这使用零参数形式的 super() 能够正确标识正在基于词法作用域来定义的类，
        而被用于进行当前调用的类或实例则是基于传递给方法的第一个参数来标识的。
    当使用默认的元类 type，或者任何最终会调用 type.__new__ 的元类时，以下额外的自定义步骤将在创建类对象之后被发起调用:
        1、type.__new__ 方法会收集类命名空间中所有定义了 __set_name__() 方法的属性;
        2、这些 __set_name__ 方法将附带所定义的类和指定的属性所赋的名称进行调用;
        3、在新类基于方法解析顺序所确定的直接父类上调用 __init_subclass__() 钩子。
    在类对象创建之后，它会被传给包含在类定义中的类装饰器（如果有的话），得到的对象将作为已定义的类绑定到局部命名空间。
    当通过 type.__new__ 创建一个新类时，提供以作为命名空间形参的对象会被复制到一个新的有序映射并丢弃原对象。
        这个新副本包装于一个只读代理中，后者则成为类对象的 __dict__ 属性。

### 元类的作用 Uses for metaclasses
    元类的潜在作用非常广泛。已经过尝试的设想包括枚举、日志、接口检查、自动委托、自动特征属性创建、代理、框架以及自动资源锁定/同步等等。

## 自定义实例及子类检查 Customizing instance and subclass checks
    以下方法被用来重载 isinstance() 和 issubclass() 内置函数的默认行为。
    特别地，元类 abc.ABCMeta 实现了这些方法以便允许将抽象基类（ABC）作为“虚拟基类”添加到任何类或类型（包括内置类型），包括其他 ABC 之中。
    class.__instancecheck__(self, instance)
        如果 instance 应被视为 class 的一个（直接或间接）实例则返回真值。
        如果定义了此方法，则会被调用以实现 isinstance(instance, class)。
    class.__subclasscheck__(self, subclass)
        Return true 如果 subclass 应被视为 class 的一个（直接或间接）子类则返回真值。
        如果定义了此方法，则会被调用以实现 issubclass(subclass, class)。
    请注意这些方法的查找是基于类的类型（元类）。它们不能作为类方法在实际的类中被定义。
        这与基于实例被调用的特殊方法的查找是一致的，只有在此情况下实例本身被当作是类。

## 模拟泛型类型  Emulating generic types
    当使用 类型标注 时，使用 Python 的方括号标记来 形参化 一个 generic type 往往会很有用处。 
        例如，list[int] 这样的标注可以被用来表示一个 list 中的所有元素均为 int 类型。
    一个类 通常 只有在定义了特殊的类方法 __class_getitem__() 时才能被形参化。
        classmethod object.__class_getitem__(cls, key)
        按照 key 参数指定的类型返回一个表示泛型类的专门化对象。
    当在类上定义时，__class_getitem__() 会自动成为类方法。 因此，当它被定义时没有必要使用 @classmethod 来装饰。

### __class_getitem__ 的目的  The purpose of __class_getitem__
    __class_getitem__() 的目的是允许标准库泛型类的运行时形参化以更方便地对这些类应用 类型提示。
    要实现可以在运行时被形参化并可被静态类型检查所理解的自定义泛型类，
        用户应当从已经实现了 __class_getitem__() 的标准库类继承，或是从 typing.Generic 继承，
        这个类拥有自己的 __class_getitem__() 实现。
    标准库以外的类上的 __class_getitem__() 自定义实现可能无法被第三方类型检查器如 mypy 所理解。 
        不建议在任何类上出于类型提示以外的目的使用 __class_getitem__()。

### __class_getitem__ 对比（versus） __getitem__ 
    通常，使用方括号语法 抽取 一个对象将会调用在该对象的类上定义的 __getitem__() 实例方法。 
    不过，如果被拟抽取的对象本身是一个类，则可能会调用 __class_getitem__() 类方法。 
        __class_getitem__() 如果被正确地定义，则应当返回一个 GenericAlias 对象。
    使用 expression obj[x] 来呈现，Python 解释器会遵循下面这样的过程来确定应当调用
         __getitem__() 还是 __class_getitem__():

        from inspect import isclass

        def subscribe(obj, x):
            """Return the result of the expression 'obj[x]'"""
            class_of_obj = type(obj)
            # If the class of obj defines __getitem__,
            # call class_of_obj.__getitem__(obj, x)
            if hasattr(class_of_obj, '__getitem__'):
                return class_of_obj.__getitem__(obj, x)
            # Else, if obj is a class and defines __class_getitem__,
            # call obj.__class_getitem__(x)
            elif isclass(obj) and hasattr(obj, '__class_getitem__'):
                return obj.__class_getitem__(x)
            # Else, raise an exception
            else:
                raise TypeError(
                    f"'{class_of_obj.__name__}' object is not subscriptable"
                )
    在 Python 中，所有的类自身也是其他类的实例。 一个类所属的类被称为该类的 metaclass，
        并且大多数类都将 type 类作为它们的元类。 type 没有定义 __getitem__()，
        这意味着 list[int], dict[str, float] 和 tuple[str, bytes] 这样的表达式都将
            导致 __class_getitem__() 被调用:
            # list has class "type" as its metaclass, like most classes:
            type(list)
            <class 'type'>
            type(dict) == type(list) == type(tuple) == type(str) == type(bytes)
            True
            # "list[int]" calls "list.__class_getitem__(int)"
            list[int]
            list[int]
            # list.__class_getitem__ returns a GenericAlias object:
            type(list[int])
            <class 'types.GenericAlias'>

## 模拟可调用对象
    object.__call__(self[, args...])
        此方法会在实例作为一个函数被“调用”时被调用；如果定义了此方法，则 x(arg1, arg2, ...) 
        就大致可以被改写为 type(x).__call__(x, arg1, ...)。

## 模拟容器类型
    可以定义下列方法来实现容器对象。 
    容器通常属于 序列 (如 列表 或 元组) 或者 映射 (如 字典)，但也有表现为其他形式的容器。 
    前几个方法被用来模拟序列或是模拟映射；
    两者的不同之处在于序列允许的键应为整数 k 并且 0 <= k < N 其中 N 是序列或 slice 对象的长度，它们定义了条目的范围。 
    此外还建议让映射提供 
        keys(), values(), items(), get(), clear(), setdefault(), 
        pop(), popitem(), copy() 以及 update() 等方法，
    它们的行为应与 Python 的标准 字典 对象类似。 
    此外 collections.abc 模块提供了一个 MutableMapping abstract base class 以便根据由 
        __getitem__(), __setitem__(), __delitem__() 和 keys() 组成的基本集来创建所需的方法。 
    可变序列还应提供 
        append(), count(), index(), extend(), insert(), pop(), remove(), 
        reverse() 和 sort() 等方法，就像 Python 的标准 list 对象那样。 
    最后，序列类型还应通过定义下文描述的 
        __add__(), __radd__(), __iadd__(), __mul__(), __rmul__() 和 __imul__() 
        等方法来实现加法（指拼接）和乘法（指重复）；它们不应定义其他数值运算符。 
    此外还建议映射和序列都实现 __contains__() 方法以允许高效地使用 in 运算符；
        对于映射，in 应当搜索映射的键；对于序列，则应当搜索其中的值。 
    另外还建议映射和序列都实现 __iter__() 方法以允许高效地迭代容器中的条目；
        对于映射，__iter__() 应当迭代对象的键；对于序列，则应当迭代其中的值。
    object.__len__(self)
        调用以实现内置函数 len() 。应返回对象的长度，整数 >= 0。此外，
        未定义 __bool__() 方法且其 __len__() 方法返回零的对象是在布尔上下文中被认为是 false。
    object.__length_hint__(self)
        调用此方法以实现 operator.length_hint()。 
        应该返回对象长度的估计值（可能大于或小于实际长度）。 此长度应为一个 >= 0 的整数。 
        返回值也可以为 NotImplemented，这会被视作与 __length_hint__ 方法完全不存在时一样处理。 
        此方法纯粹是为了优化性能，并不要求正确无误。
    







## 模拟数字类型
## with 语句上下文管理器
## 定制类模式匹配中的位置参数
## 特殊方法查找
# 协程
## 可等待对象
## 协程对象
## 异步迭代器
## 异步上下文管理器


'''


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('data_ref.py')
    test()
