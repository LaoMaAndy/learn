#!/usr/bin/env python3
r'''
# 内置函数 Built-in Functions 
内置函数
abs()
aiter()
all()
any()
anext()
ascii()

bin()
bool()
breakpoint()
bytearray()
bytes()

callable()
chr()
classmethod()
compile()
complex()

delattr()
dict()
dir()
divmod()

enumerate()
eval()
exec()

filter()
float()
format()
frozenset()

getattr()
globals()

hasattr()
hash()
help()
hex()

id()
input()
int()
isinstance()
issubclass()
iter()

len()
list()
locals()

map()
max()
memoryview()
min()

next()

object()
oct()
open()
ord()

pow()
print()
property()

range()
repr()
reversed()
round()

set()
setattr()
slice()
sorted()
staticmethod()
str()
sum()
super()

tuple()
type()

vars()

zip()

_
__import__()

abs(x)
    返回一个数的绝对值。 
    参数可以是整数、浮点数或任何实现了 __abs__() 的对象。 
    如果参数是一个复数，则返回它的模。

aiter(async_iterable)
    返回 asynchronous iterable 的 asynchronous iterator 。
    相当于调用 x.__aiter__()。
    注意：与 iter() 不同，aiter() 没有两个参数的版本。

all(iterable)
    如果 iterable 的所有元素均为真值（或可迭代对象为空）则返回 True 。

anext()
    awaitable anext(async_iterator)
    awaitable anext(async_iterator, default)
        当进入 await 状态时，从给定 asynchronous iterator 返回下一数据项，
        迭代完毕则返回 default。
        这是内置函数 next() 的异步版本.

any(iterable)
    如果 iterable 的任一元素为真值则返回 True。 如果可迭代对象为空，返回 False。

ascii(object)
    与 repr() 类似，返回一个字符串，表示对象的可打印形式，但在 repr() 返回的字符串中，
    非 ASCII 字符会用 \x、\u 和 \U 进行转义。

bin(x)
    将整数转换为前缀为“0b”的二进制字符串。结果是一个有效的 Python 表达式。
    如果 x 不是 Python int 对象，则它必须定义一个返回整数的 __index__() 方法。

bool()
    class bool(x=False) 
    返回布尔值，True 或 False。x 用标准的 真值测试过程 进行转换。
    如果 x 为 False 或省略，则返回 False；否则返回 True。 
    bool 类是 int 的子类。它不能再被继承。它唯一的实例就是 False 和 True。

breakpoint(*args, **kws)
    此函数会将调用站点的调试器。具体来说，它调用 sys.breakpointhook() ，
    直接传递 args 和 kws 。默认情况下， sys.breakpointhook() 调用 
    pdb.set_trace() ，不需要任何参数。

bytearray()
    class bytearray(source=b'')
    class bytearray(source, encoding)
    class bytearray(source, encoding, errors)
    返回一个新的 bytes 数组。 bytearray 类是一个可变序列，包含范围为 
        0 <= x < 256 的整数。它有可变序列大部分常见的方法，见 可变序列类型 的描述；
        同时有 bytes 类型的大部分方法，参见 bytes 和 bytearray 操作。
    可选形参 source 可以用不同的方式来初始化数组：
        如果是一个 string，您必须提供 encoding 参数（errors 参数仍是可选的）；
          bytearray() 会使用 str.encode() 方法来将 string 转变成 bytes。
        如果是一个 integer，会初始化大小为该数字的数组，并使用 null 字节填充。
        如果是一个遵循 缓冲区接口 的对象，该对象的只读缓冲区将被用来初始化字节数组。
        如果是一个 iterable 可迭代对象，它的元素的范围必须是 0 <= x < 256 的整数，
        它会被用作数组的初始内容。
    如果没有实参，则创建大小为 0 的数组。

 bytes()
    class bytes(source=b'')
    class bytes(source, encoding)
    class bytes(source, encoding, errors)
    返回一个新的“bytes”对象，这是一个不可变序列，包含范围为 0 <= x < 256 的整数。
        bytes 是 bytearray 的不可变版本——带有同样不改变序列的方法，
        支持同样的索引、切片操作。

callable(object)
    如果参数 object 是可调用的就返回 True，否则返回 False。 
     如果返回 True，调用仍可能失败，但如果返回 False，则调用 object 将肯定不会成功。 
     请注意类是可调用的（调用类将返回一个新的实例）；
     如果实例所属的类有 __call__() 则它就是可调用的。

chr(i)
    返回 Unicode 码位为整数 i 的字符的字符串格式。例如，chr(97) 返回
    字符串 'a'，chr(8364) 返回字符串 '€'。这是 ord() 的逆函数。

@classmethod
    把一个方法封装成类方法。
    类方法隐含的第一个参数就是类，就像实例方法接收实例作为参数一样。
    要声明一个类方法，按惯例请使用以下方案：
    class C:
        @classmethod
        def f(cls, arg1, arg2): ...
    @classmethod 这样的形式称为函数的 decorator 
    类方法的调用可以在类上进行 (例如 C.f()) 也可以在实例上进行 (例如 C().f())。
        其所属类以外的类实例会被忽略。 如果类方法在其所属类的派生类上调用，
        则该派生类对象会被作为隐含的第一个参数被传入。
    在 3.9 版更改: 类方法现在可以包装其他 描述器 例如 property()。
    在 3.9 版更改: 类方法现在可以包装其他 描述器 例如 property()。
    在 3.10 版更改: 类方法现在继承了方法的属性（__module__、__name__、
        __qualname__、__doc__ 和 __annotations__），
        并拥有一个新的``__wrapped__`` 属性。
    在 3.11 中更改：类方法不能再包装其他描述符，例如 property() 。
  描述器使用指南：
    docs.python.org/zh-cn/3/howto/descriptor.html#functions-and-methods
  描述器 property 说明：
    docs.python.org/zh-cn/3/library/functions.html

compile(source, filename, mode, flags=0, dont_inherit=False, optimize=- 1)
    将 source 编译成代码或 AST 对象。代码对象可以被 exec() 或 eval() 执行。
        source 可以是常规的字符串、字节字符串，或者 AST 对象。
        参见 ast 模块的文档了解如何使用 AST 对象。
    filename 实参需要是代码读取的文件名；如果代码不需要从文件中读取，
        可以传入一些可辨识的值（经常会使用 '<string>'）。
    mode 实参指定了编译代码必须用的模式。如果 source 是语句序列，可以是 'exec'；
        如果是单一表达式，可以是 'eval'；如果是单个交互式语句，可以是 'single'。
        （在最后一种情况下，如果表达式执行结果不是 None 将会被打印出来。）
    可选参数 flags 和 dont_inherit 控制应当激活哪个 编译器选项 以及应当允许哪个 future 特性。 

complex()
    class complex(real=0, imag=0)
    class complex(string)
    返回值为 real + imag*1j 的复数，或将字符串或数字转换为复数。如果第一个形参是字符串，
        则它被解释为一个复数，并且函数调用时必须没有第二个形参。第二个形参不能是字符串。
        每个实参都可以是任意的数值类型（包括复数）。如果省略了 imag，则默认值为零，
        构造函数会像 int 和 float 一样进行数值转换。如果两个实参都省略，则返回 0j。
    对于一般的 Python 对象 x ， complex(x) 委托给 x.__complex__() 。
        如果 __complex__() 未定义，则返回到 __float__() 。如果 __float__() 未定义，
        则返回到 __index__() 。

delattr(object, name)
    这是 setattr() 反向操作。参数是一个对象和一个字符串。该字符串必须是对象属性之一的名称。
        如果对象允许，该函数将删除指定的属性。
        例如， delattr(x, 'foobar') 相当于 del x.foobar 。

dict()
    class dict(**kwarg)
    class dict(mapping, **kwarg)
    class dict(iterable, **kwarg)
    创建一个新的字典。dict 对象是一个字典类。

dir()
    dir()
    dir(object)
    如果没有实参，则返回当前本地作用域中的名称列表。如果有实参，它会尝试返回该对象的有效属性列表。
    如果对象有一个名为 __dir__() 的方法，那么该方法将被调用，并且必须返回一个属性列表。
    默认的 dir() 机制对不同类型的对象行为不同，它会试图返回最相关而不是最全的信息：
        如果对象是模块对象，则列表包含模块的属性名称。
        如果对象是类型或类对象，则列表包含它们的属性名称，并且递归查找所有基类的属性。
        否则，列表包含对象的属性名称，它的类属性名称，并且递归查找它的类的所有基类的属性。

divmod(a, b)
    以两个（非复数）数字为参数，在作整数除法时，返回商和余数。
        若操作数为混合类型，则适用二进制算术运算符的规则。
        对于整数而言，结果与 (a // b, a % b) 相同。
        对于浮点数则结果为``(q, a % b)``，其中 q 通常为 math.floor(a / b)，但可能比它小 1。
        在任何情况下，q * b + a % b 都非常接近 a，如果 a % b 非零，则结果符号与 b 相同，
        并且 0 <= abs(a % b) < abs(b)。

enumerate(iterable, start=0)
    返回一个枚举对象。iterable 必须是一个序列，或 iterator，或其他支持迭代的对象。 
        enumerate() 返回的迭代器的 __next__() 方法返回一个元组，里面包含一个计数值
        （从 start 开始，默认为 0）和通过迭代 iterable 获得的值。

eval(expression, globals=None, locals=None)
    实参是一个字符串，以及可选的 globals 和 locals。
        globals 实参必须是一个字典。
        locals 可以是任何映射对象。
    表达式解析参数 expression 并作为 Python 表达式进行求值（从技术上说是一个条件列表），
        采用 globals 和 locals 字典作为全局和局部命名空间。 

exec(object, globals=None, locals=None, /, *, closure=None)
    这个函数支持动态执行 Python 代码。 object 必须是字符串或者代码对象。 如果是字符串，
        那么该字符串将被解析为一系列 Python 语句并执行（除非发生语法错误）。 
        如果是代码对象，它将被直接执行
    内置globals() 和 locals() 函数各自返回当前的全局和本地字典，
        因此可以将它们传递给 exec() 的第二个和第三个实参。

filter(function, iterable)
    从 iterable 的那些 function 为 true 的元素构造一个迭代器。 
        iterable 可以是序列、支持迭代的容器或迭代器。
        如果 function 为 None ，则假定为恒等函数，
        即删除 iterable 中所有为 false 的元素。

class float(x=0.0)
    返回从数字或字符串 x 生成的浮点数。
    x 可以是 "Infinity"  "inf" "nan"
    对于一般的 Python 对象 x ， float(x) 委托给 x.__float__() 。
    如果 __float__() 未定义，则返回到 __index__() 。

format(value, format_spec='')
    将 value 转换为“格式化后”的形式，格式由 format_spec 进行控制。
        format_spec 的解释方式取决于 value 参数的类型；
        但大多数内置类型使用一种标准的格式化语法： 格式规格迷你语言。
     format_spec 

class frozenset(iterable=set())
    返回一个新的 frozenset 对象，它包含可选参数 iterable 中的元素。 
        frozenset 是一个内置的类。是不可变并且为 hashable 

getattr()
    getattr(object, name)
    getattr(object, name, default)
    返回对象的命名属性的值。名称必须是字符串。如果字符串是对象属性之一的名称，
        则结果是该属性的值。例如， getattr(x, 'foobar') 相当于 x.foobar 。如
        果指定的属性不存在，则返回默认值（如果提供），否则引发 AttributeError 。

globals()
    返回实现当前模块命名空间的字典。对于函数内的代码，这是在定义函数时设置的，
    无论函数在哪里被调用都保持不变

hasattr(object, name)
    该实参是一个对象和一个字符串。如果字符串是对象的属性之一的名称，则返回 True，否则返回 False。
    （此功能是通过调用 getattr(object, name) 看是否有 AttributeError 异常来实现的。）

hash(object)
    返回该对象的哈希值（如果它有的话）。哈希值是整数。它们在字典查找元素时用来快速比较字典的键。
    相同大小的数字变量有相同的哈希值（即使它们类型不同，如 1 和 1.0）。

help(request)
    启动内置的帮助系统（此函数主要在交互式中使用）。如果没有实参，解释器控制台里会启动交互式帮助系统。
        如果实参是一个字符串，则在模块、函数、类、方法、关键字或文档主题中搜索该字符串，
        并在控制台上打印帮助信息。如果实参是其他任意对象，则会生成该对象的帮助页。
hex(x)
    将整数转换为前缀为“0x”的小写十六进制字符串。如果 x 不是 Python int 对象，
        则它必须定义一个返回整数的 __index__() 方法。
    以下方法也可转换为十六进制
        '%#x' % 255, '%x' % 255, '%X' % 255
        format(255, '#x'), format(255, 'x'), format(255, 'X')
        f'{255:#x}', f'{255:x}', f'{255:X}'
    浮点数的十六进制字符串形式，请使用 float.hex() 方法。

id(object)
    返回对象的“标识值”。该值是一个整数，在此对象的生命周期中保证是唯一且恒定的。
    两个生命期不重叠的对象可能具有相同的 id() 值。
    CPython实现细节：这是内存中对象的地址。

input(prompt)
    如果存在 prompt 实参，则将其写入标准输出，末尾不带换行符。
        接下来，该函数从输入中读取一行，将其转换为字符串（除了末尾的换行符）并返回。
        当读取到 EOF 时，则触发 EOFError。

class int(x, base=10)
    返回由数字或字符串 x 构造的整数对象，如果未给出参数，则返回 0 。
        如果 x 定义 __int__() ，则 int(x) 返回 x.__int__() 。
        如果 x 定义 __index__() ，则返回 x.__index__() 。
        如果 x 定义 __trunc__() ，则返回 x.__trunc__() 。
        对于浮点数，这会截断为零。

isinstance(object, classinfo)
    如果对象参数是 classinfo 参数或其（直接、间接或虚拟）子类的实例，则返回 True 。
        如果 object 不是给定类型的对象，则该函数始终返回 False 。如

issubclass(class, classinfo)
    如果 class 是 classinfo 的子类（直接、间接或 虚的 ），则返回 True。

iter(object, sentinel)   
    返回一个 iterator 对象。根据是否存在第二个实参，第一个实参的解释是非常不同的。
    如果没有第二个实参，object 必须是支持 iterable 协议（有 __iter__() 方法）的集合对象，
        或必须支持序列协议（有 __getitem__() 方法，且数字参数从 0 开始）。
        如果它不支持这些协议，会触发 TypeError。
    如果有第二个实参 sentinel，那么 object 必须是可调用的对象。这种情况下生成的迭代器，
        每次迭代调用它的 __next__() 方法时都会不带实参地调用 object；
        如果返回的结果是 sentinel 则触发 StopIteration，否则返回调用结果。
    跟 迭代器 有关的：__iter__ , __next__ , yield

len(s)
    返回对象的长度（元素个数）。
    实参可以是序列（如 string、bytes、tuple、list 或 range 等）或
        集合（如 dictionary、set 或 frozen set 等）。

list(iterable)
    list 实际上是一种可变序列类型，

map(function, iterable, *iterables)
    返回一个迭代器，该迭代器将函数应用于可迭代的每个项目，并产生结果。
        如果传递额外的可迭代参数，函数必须采用那么多参数，并并行应用于所有可迭代的项。
        对于多个可迭代对象，迭代器会在最短的可迭代对象耗尽时停止。
    对于函数输入已排列为参数元组的情况，请参阅 itertools.starmap() 

max()
    max(iterable, *, key=None)
    max(iterable, *, default, key=None)
    max(arg1, arg2, *args, key=None)
    返回可迭代对象中最大的元素，或者返回两个及以上实参中最大的。
        如果只提供了一个位置参数，它必须是 iterable，返回可迭代对象中最大的元素；
        如果提供了两个及以上的位置参数，则返回最大的位置参数。
    有两个可选只能用关键字的实参。
        key 实参指定排序函数用的参数，如传给 list.sort() 的。
        default 实参是当可迭代对象为空时返回的值。
        如果可迭代对象为空，并且没有给 default ，则会触发 ValueError。

memoryview(object)
    返回由给定实参创建的“内存视图”对象。

min()
    min(iterable, *, key=None)
    min(iterable, *, default, key=None)
    min(arg1, arg2, *args, key=None)
    返回可迭代对象中最小的元素，或者返回两个及以上实参中最小的。
        如果只提供了一个位置参数，它必须是 iterable，返回可迭代对象中最小的元素；
        如果提供了两个及以上的位置参数，则返回最小的位置参数。
    有两个可选只能用关键字的实参。
        key 实参指定排序函数用的参数，如传给 list.sort() 的。
        default 实参是当可迭代对象为空时返回的值。
        如果可迭代对象为空，并且没有给 default ，则会触发 ValueError。

next(iterator, default)
    通过调用 iterator 的 __next__() 方法获取下一个元素。如果迭代器耗尽，
        则返回给定的 default，如果没有默认值则触发 StopIteration。

class object
    返回一个不带特征的新对象。object 是所有类的基类。
        它带有所有 Python 类实例均通用的方法。本函数不接受任何参数。
     由于 object 没有 __dict__，因此无法将任意属性赋给 object 的实例。

oct(x)
    将整数转换为前缀为“0o”的八进制字符串。如果 x 不是 Python int 对象，
        则它必须定义一个返回整数的 __index__() 方法。
    
open(file, mode='r', buffering=- 1, encoding=None, errors=None, 
        newline=None, closefd=True, opener=None)
    打开 file 并返回对应的 file object。 如果该文件不能被打开，则引发 OSError。 
    
    file : 是一个 path-like object，表示将要打开的文件的路径（绝对路径或者相对当前工作目录的路径），
        也可以是要封装文件对应的整数类型文件描述符。
    
    mode : 含义
        'r'读取（默认） 
        'w'写入，并先截断文件 
        'x'排它性创建，如果文件已存在则失败 
        'a'打开文件用于写入，如果文件存在则在末尾追加 
        'b'二进制模式 
        't'文本模式（默认） 
        '+'打开用于更新（读取与写入）

        默认模式是 'r' （打开以阅读文本，是 'rt' 的同义词）。
        模式 'w+' 和 'w+b' 打开并截断文件。
        模式 'r+' 和 'r+b' 打开文件而不截断。

    备注 Python不依赖于底层操作系统的文本文件概念;所有处理都由Python本身完成，因此与平台无关。
    
    buffering : 是一个可选整数，用于设置缓冲策略。
        传递 0 来关闭缓冲（仅在二进制模式下允许），
        传递 1 来选择行缓冲（仅在文本模式下可用），
        传递一个 > 1 的整数来指示固定大小块缓冲区的大小（以字节为单位）。

    encoding : 用于解码或编码文件的编码的名称。这应该只在文本模式下使用。默认编码与平台相关

    error : 是一个可选字符串，指定如何处理编码和解码错误 - 这不能在二进制模式下使用。

    newline : 确定如何从流中解析换行符。它可以是 None 、 '' 、 '\n' 、 '\r' 和 '\r\n' 。

    closefd : 若为 False 且给出的不是文件名而是文件描述符，那么当文件关闭时，底层文件描述符将保持打开状态。
        如果给出的是文件名，则 closefd 必须为 True （默认值），否则将触发错误。

    opener : 可以通过传递可调用的 opener 来使用自定义开启器。然后通过使用参数（ file，flags ）
        调用 opener 获得文件对象的基础文件描述符。 opener 必须返回一个打开的文件描述符
    
    返回值：open() 函数所返回的 file object 类型取决于所用模式。 
        当使用 open() 以文本模式 ('w', 'r', 'wt', 'rt' 等) 打开文件时，
            它将返回 io.TextIOBase (具体为 io.TextIOWrapper) 的一个子类。 
        当使用缓冲以二进制模式打开文件时，返回的类是 io.BufferedIOBase 的一个子类。 
        具体的类会有多种：
            在只读的二进制模式下，它将返回 io.BufferedReader；
            在写入二进制和追加二进制模式下，它将返回 io.BufferedWriter，
            而在读/写模式下，它将返回 io.BufferedRandom。 
            当禁用缓冲时，则会返回原始流，即 io.RawIOBase 的一个子类 io.FileIO。

ord(c)
    对表示单个 Unicode 字符的字符串，返回代表它 Unicode 码点的整数。
        例如 ord('a') 返回整数 97， ord('€') （欧元符号）返回 8364 。
        这是 chr() 的逆函数。

pow(base, exp, mod=None)
    返回 base 的 exp 次幂；如果 mod 存在，则返回 base 的 exp 次幂对 mod 取余
        （比 pow(base, exp) % mod 更高效）。
    两参数形式 pow(base, exp) 等价于乘方运算符: base**exp。

print(*objects, sep=' ', end='\n', file=None, flush=False)
    将 objects 打印输出至 file 指定的文本流，以 sep 分隔并在末尾加上 end。 
        sep 、 end 、 file 和 flush 必须以关键字参数的形式给出。
    所有非关键字参数都会被转换为字符串，就像是执行了 str() 一样，并会被写入到流，
        以 sep 分隔，且在末尾加上 end。 sep 和 end 都必须为字符串；
        它们也可以为 None，这意味着使用默认值。 如果没有给出 objects，则 print() 将只写入 end。
    file 参数必须是一个具有 write(string) 方法的对象；如果参数不存在或为 None，
        则将使用 sys.stdout。 由于要打印的参数会被转换为文本字符串，
        因此 print() 不能用于二进制模式的文件对象。 
        对于这些对象，应改用 file.write(...)。
    输出缓冲通常由文件决定。然而，如果flush为true，流将被强制刷新。

property(fget=None, fset=None, fdel=None, doc=None)
    fget 是获取属性值的函数。 
    fset 是用于设置属性值的函数。 
    fdel 是用于删除属性值的函数。并且 
    doc 为属性对象创建文档字符串。
  举例：
    class C:
        def __init__(self):
            self._x = None

        def getx(self):
            print('getx: ', self._x)
            return self._x

        def setx(self, value):
            self._x = value
            print('setx: ', self._x)

        def delx(self):
            del self._x

        x = property(getx, setx, delx, "I'm the 'x' property.")
  装饰器式设置 property 更为简单
  property用作装饰器的属性： setter，getter，deleter
  举例：
    class C:
        def __init__(self):
            self._x = None
        @property
        def x(self):
            print(f'getter: {self._x = }')
            return self._x
        @x.setter
        def x(self, value):
            self._x = value
            print(f'setter: {self._x = }')
        @x.deleter
        def x(self):
            del self._x
            print('del self._x')
    上述代码与第一个例子完全等价。 
    注意一定要给附加函数与原始的特征属性相同的名称 (在本例中为 x。)

range()
    class range(stop)
    class range(start, stop, step=1)
    虽然被称为函数，但 range 实际上是一个不可变的序列类型。

repr(object)
    返回一个包含对象的可打印表示形式的字符串。对于许多类型，此函数会尝试返回一个字符串，
        该字符串在传递给 eval() 时会产生具有相同值的对象；
    否则，表示形式是一个括在尖括号中的字符串，其中包含对象类型的名称以及通常包括对象的
        名称和地址的附加信息。
    类可以通过定义 __repr__() 方法来控制该函数为其实例返回的内容。
        如果 sys.displayhook() 不可访问，此函数将引发 RuntimeError 。
reversed(seq)
    返回一个反向的 iterator。 seq 必须是一个具有 __reversed__() 方法的对象
    或者是支持该序列协议（具有从 0 开始的整数类型参数的 __len__() 方法和 __getitem__() 方法）。

round(number, ndigits=None)
    返回 number 舍入到小数点后 ndigits 位精度的值。 
        如果 ndigits 被省略或为 None，则返回最接近输入值的整数。
    如果与两个倍数同样接近，则选用偶数。
        因此，round(0.5) 和 round(-0.5) 均得出 0 而 round(1.5) 则为 2
    备注 对浮点数执行 round() 的行为可能会令人惊讶：
        例如，round(2.675, 2) 将给出 2.67 而不是期望的 2.68。 
        这不算是程序错误：这一结果是由于大多数十进制小数实际上都不能以浮点数精确地表示。

set(iterable)
    返回一个新的 set 对象，可以选择带有从 iterable 获取的元素。 set 是一个内置类型。 
    请查看 set 和 集合类型 --- set, frozenset

setattr(object, name, value)
    本函数与 getattr() 相对应。其参数为一个对象、一个字符串和一个任意值。
        字符串可以为某现有属性的名称，或为新属性。只要对象允许，函数会将值赋给属性。
    如 setattr(x, 'foobar', 123) 等价于 x.foobar = 123。

slice()
    class slice(stop)
    class slice(start, stop, step=1)
    返回一个 slice 对象，代表由 range(start, stop, step) 指定索引集的切片。 
        其中参数 start 和 step 的默认值为 None。
        切片对象具有只读数据属性 start 、stop 和 step，
        只是返回对应的参数值（或默认值）。这几个属性没有其他明确的功能；
    不过 NumPy 和其他第三方扩展会用到。在使用扩展索引语法时，也会生成切片对象。
    例如： a[start:stop:step] 或 a[start:stop, i]。 另一种方案是返回迭代器对象。

sorted(iterable, /, *, key=None, reverse=False)
    根据 iterable 中的项返回一个新的已排序列表。
    具有两个可选参数，它们都必须指定为关键字参数。
    key 指定带有单个参数的函数，用于从 iterable 的每个元素中提取用于比较的键 
        (例如 key=str.lower)。 默认值为 None (直接比较元素)。
    reverse 为一个布尔值。 如果设为 True，则每个列表元素将按反向顺序比较进行排序。
    使用 functools.cmp_to_key() 可将老式的 cmp 函数转换为 key 函数。
    内置的 sorted() 确保是稳定的。 
        如果一个排序确保不会改变比较结果相等的元素的相对顺序就称其为稳定的 
        --- 这有利于进行多重排序（例如先按部门、再按薪级排序）。
    
    排序算法只使用 < 在项目之间比较。 虽然定义一个 __lt__() 方法就足以进行排序，
        但 PEP 8 建议实现所有六个 富比较 。

@staticmethod
    将方法转换为静态方法。
        静态方法不会接收隐式的第一个参数。要声明一个静态方法，请使用此语法
    静态方法既可以由类中调用（如 C.f()），也可以由实例中调用（如 C().f() ）。
        此外，还可以作为普通的函数进行调用（如 f() ）
    @staticmethod 这样的形式称为函数的 decorator
    举例；
        class C:
        @staticmethod
        def f(arg1, arg2, argN): ...

str(object=b'', encoding='utf-8', errors='strict')
    返回一个 str 版本的 object 。有关详细信息，请参阅 str() 。
    str 是内置字符串 class 。更多关于字符串的信息查看 文本序列类型 --- str。

sum(iterable, /, start=0)
    从 start 开始自左向右对 iterable 的项求和并返回总计值。 
        iterable 的项通常为数字，而 start 值则不允许为字符串。
    对某些用例来说，存在 sum() 的更好替代。 
        拼接字符串序列的更好更快方式是调用 ''.join(sequence)。 
        要以扩展精度对浮点值求和，请参阅 math.fsum()。 
        要拼接一系列可迭代对象，请考虑使用 itertools.chain()。

super(type, object_or_type=None)
    返回一个代理对象，它会将方法调用委托给 type 的父类或兄弟类。 
        这对于访问已在类中被重载的继承方法很有用。
    object_or_type 确定要搜索的方法解析顺序。搜索从类型之后的类开始。
        例如，如果 object_or_type 的 __mro__ 为 D -> B -> C -> A -> object 
            并且 type 的值为 B ，则 super() 搜索 C -> A -> object .
    object_or_type 的 __mro__ 属性列出了 getattr() 和 super() 使用的方法解析搜索顺序。
        该属性是动态的，并且可以在继承层次结构更新时更改。
    super 有两个典型用例。 在具有单继承的类层级结构中，super 可用来引用父类而不必显式地指定它们的名称，
        从而令代码更易维护。 这种用法与其他编程语言中 super 的用法非常相似。
    第二个用例是在动态执行环境中支持协作多重继承。 此用例为 Python 所独有而不存在于静态编码语言或仅支持单继承的语言当中。 
        这使用实现“菱形图”成为可能，即有多个基类实现相同的方法。 
        好的设计强制要求这样的方法在每个情况下都具有相同的调用签名
        （因为调用顺序是在运行时确定的，也因为这个顺序要适应类层级结构的更改，
            还因为这个顺序可能包括在运行时之前未知的兄弟类）。
    举例：
        class C(B):
            def method(self, arg):
                super().method(arg)    # This does the same thing as:
                                       # super(C, self).method(arg)
    
    除了方法查找之外，super() 也可用于属性查找。 
        一个可能的应用场合是在上级或同级类中调用 描述器。
    
tuple(iterable)
    虽然被称为函数，但 tuple 实际上是一个不可变的序列类型，
        参见在 元组 与 序列类型 --- list, tuple, range 中的文档说明。

type()
    class type(object)
    class type(name, bases, dict, **kwds)
    传入一个参数时，返回 object 的类型。 返回值是一个 type 对象，通常与 object.__class__ 所返回的对象相同。
        推荐使用 isinstance() 内置函数来检测对象的类型，因为它会考虑子类的情况。
    传入三个参数时，返回一个新的 type 对象。 这在本质上是 class 语句的一种动态形式，
        name 字符串即类名并会成为 __name__ 属性；
        bases 元组包含基类并会成为 __bases__ 属性；如果为空则会添加所有类的终极基类 object。 
        dict 字典包含类主体的属性和方法定义；它在成为 __dict__ 属性之前可能会被拷贝或包装。 
    提供给三参数形式的关键字参数会被传递给适当的元类机制 (通常为 __init_subclass__())，
        相当于类定义中关键字 (除了 metaclass) 的行为方式。
    在 3.6 版更改: type 的子类如果未重载 type.__new__，将不再能使用一个参数的形式来获取对象的类型。
    举例：
        下面两条语句会创建相同的 type 对象:
        class X:
            a = 1

        X = type('X', (), dict(a=1))
vars(object)
    返回模块、类、实例或任何其它具有 __dict__ 属性的对象的 __dict__ 属性。
    模块和实例这样的对象具有可更新的 __dict__ 属性；但是，其它对象的 __dict__ 属性可能会设为限制写入
        （例如，类会使用 types.MappingProxyType 来防止直接更新字典）。
    不带参数时，vars() 的行为类似 locals()。 
        请注意，locals 字典仅对于读取起作用，因为对 locals 字典的更新会被忽略。
    如果指定了一个对象但它没有 __dict__ 属性
        （例如，当它所属的类定义了 __slots__ 属性时）则会引发 TypeError 异常。

zip(*iterables, strict=False)
    在多个迭代器上并行迭代，从每个迭代器返回一个数据项组成元组。
    更正式的说法： zip() 返回元组的迭代器，其中第 i 个元组包含的是每个参数迭代器的第 i 个元素。
        不妨换一种方式认识 zip() ：它会把行变成列，把列变成行。这类似于 矩阵转置 。
    zip() 是延迟执行的：直至迭代时才会对元素进行处理，比如 for 循环或放入 list 中。
        值得考虑的是，传给 zip() 的可迭代对象可能长度不同；
        有时是有意为之，有时是因为准备这些对象的代码存在错误。
    Python 提供了三种不同的处理方案：
        默认情况下，zip() 在最短的迭代完成后停止。较长可迭代对象中的剩余项将被忽略，
            结果会裁切至最短可迭代对象的长度：
        通常 zip() 用于可迭代对象等长的情况下。这时建议用 strict=True 的选项。
            输出与普通的 zip() 相同：。
        与默认行为不同，如果一个可迭代对象先于其他可迭代对象耗尽，它会引发 ValueError
            如果未指定 strict=True 参数，所有导致可迭代对象长度不同的错误都会被抑制，
            这可能会在程序的其他地方表现为难以发现的错误。
        为了让所有的可迭代对象具有相同的长度，长度较短的可用常量进行填充。
            这可由 itertools.zip_longest() 来完成。
    极端例子是只有一个可迭代对象参数，zip() 会返回一个一元组的迭代器。如果未给出参数，则返回一个空的迭代器。
    小技巧：
        可确保迭代器的求值顺序是从左到右的。这样就能用 zip(*[iter(s)]*n, strict=True) 将数据列表按长度 n 进行分组。
            这将重复 相同 的迭代器 n 次，输出的每个元组都包含 n 次调用迭代器的结果。
            这样做的效果是把输入拆分为长度为 n 的块。
        zip() 与 * 运算符相结合可以用来拆解一个列表:
            # 重新组合
            x = [1, 2, 3]
            y = [4, 5, 6]
            list(zip(x, y))
            # 还原
            x2, y2 = zip(*zip(x, y))
            x == list(x2) and y == list(y2)

__import__(name, globals=None, locals=None, fromlist=(), level=0)
    备注 与 importlib.import_module() 不同，这是一个日常 Python 编程中不需要用到的高级函数。
    此函数会由 import 语句发起调用。 它可以被替换 (通过导入 builtins 模块并赋值给 builtins.__import__) 
        以便修改 import 语句的语义，但是 强烈 不建议这样做，
        因为使用导入钩子 (参见 PEP 302) 通常更容易实现同样的目标，
        并且不会导致代码问题，因为许多代码都会假定所用的是默认实现。 
    同样也不建议直接使用 __import__() 而应该用 importlib.import_module()。
'''
from share import prn_title, prn_express
from pprint import pprint

def test_zip():
    prn_title('test_zip()')
    print('Build a dict from zip():')
    d = {k:v for k, v in zip(range(10), 'abcdefghij')}
    print(f'{d = }')

    # 默认情况下，strict=False, 将忽略长度不同问题 ：
    for item in zip(range(3), ['fee', 'fi', 'fo', 'fum']):  
        print(item)
    print('Zip OK'.center(20, '-'))
    # 与默认行为不同，如果一个可迭代对象先于其他可迭代对象耗尽，它会引发 ValueError ：
    #for item in zip(range(3), ['fee', 'fi', 'fo', 'fum'], strict=True):  
    #    print(item)
    x = [1, 2, 3]
    y = [4, 5, 6]
    list(zip(x, y))
    z = zip(*['abc']*3)
    s = 'xyz'
    exp = [
        "print(zip(*['abc']*3))"
        ,"print(list(z))"
        ,"print(*['abc'])"
        ,"print(*'abc')"
        ,"print('abc'*3)"
        ,"print(['abc']*3)"
        ,"print(*'abc'*3)"
        ,"print(*['abc']*3)"
        ,"print(x)"
        ,"print(y)"
        ]
    for line in exp:
        line = line.strip()
        if len(line) == 0:
            continue
        print(line.ljust(30), end = '')
        print(' : ', end = '')
        try:
            eval(line)
        except:
            print()
            continue

    print(zip(*['abc']*3))
    print(list(z))
    print(*['abc'])
    print(*'abc')
    print('abc'*3)
    print(['abc']*3)
    print(*'abc'*3)
    print(*['abc']*3)
    print(x)
    print(y)
    x2, y2 = zip(*zip(x, y))
    print(f'{x2 = }')
    print(f'{y2 = }')
    x2, y2 = zip(*zip(x, y))
    print(f'{x2 = }')
    print(f'{y2 = }')
    print(f'{x == list(x2) and y == list(y2) = }')

def test_super_class():
    prn_title('test_super_class()')
    class MyStr(str):
        def __init__(self, *arg, **kwarg):
            super().__init__(*arg, **kwarg)

    my_str = MyStr()
    
def test_readonly_property():
    prn_title('test_readonly_property()')
    class P:
        def __init__(self):
            self._val = 'value is read only'
        @property
        def val(self):
            return self._val
    p = P()
    print(f'{p.val = }')
    setattr(p, 'new_val', ' ')
    #setattr(p, 'val', ' ')
    #p.val = ''

def test_b_decorator():
    prn_title('test_b_decorator()')
    class C:
        def __init__(self):
            self._x = None
        @property
        def x(self):
            print(f'getter: {self._x = }')
            return self._x
        @x.setter
        def x(self, value):
            self._x = value
            print(f'setter: {self._x = }')
        @x.deleter
        def x(self):
            del self._x
            print('del self._x')
    c = C()
    c.x = 1122
    d = c.x 
    del c.x

        
def test_decorator():
    prn_title('test_decorator()')
    class Parrot:
        def __init__(self):
            self._voltage = 100000

        @property
        def voltage(self):
            """Get the current voltage."""
            print('This is getter: ', self._voltage)
            return self._voltage
    p = Parrot()
    v = p.voltage

def test_property():
    prn_title('test_property()')
    class C:
        def __init__(self):
            self._x = None

        def getx(self):
            print('getx: ', self._x)
            return self._x

        def setx(self, value):
            self._x = value
            print('setx: ', self._x)

        def delx(self):
            del self._x

        x = property(getx, setx, delx, "I'm the 'x' property.")
    c = C()    
    c.x = 20
    print(f'{c.x = }')

def star_arg(*pos_arg, name='', **name_arg):
    # *arg 自动收集所有非命名参数
    print(f'{pos_arg = }, {name_arg = }')
    print(f' {type(pos_arg) = } \n {type(name_arg) = }')
    print(f'{name = }')
    #print(*arg) 

def test_star_arg():
    prn_title('test_star_arg()')
    star_arg('aaa', 'bbb', 'ccc', name = 'andy')
    star_arg(1, 2, 3, 4, name = 'andy')

def func_name(x, y):
    print(f'i need two parameter: {x = }, {y = }')
f2 = func_name

def func_name():
    print('0 parameter is needed')
f0 = func_name

def test_func_name():
    '''同名函数
    后面的名称会覆盖前面的
    但仍然可以通过使用别名来调用
    '''
    prn_title('test_func_name()')
    f2(12, 2)
    f0()

class class_init():
    '''同名__init__函数会覆盖
    只有最后一个会有效
    '''
    def __init__(self):
        print('0 parameter required')
    def __init__(self, x, y=10):
        print(f'we need two: {x = }', f'{y = }')

def test_class_init():
    prn_title('test_class_init()')
    prn_title('dir()')
    pprint(dir())
    prn_title('vars()')
    pprint(vars())
    try:
        a = class_init()
    except TypeError:
        print('An error occured:\n\t a = class_init()')


if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('func_buildin.py')
        test_class_init()
        test_func_name()
        test_star_arg()
        test_property()
        test_decorator()
        test_b_decorator()
        test_readonly_property()
        test_super_class()
        test_zip()
    test()
