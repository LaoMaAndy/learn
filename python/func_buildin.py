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


'''
from share import prn_title
from pprint import pprint


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
    test()
