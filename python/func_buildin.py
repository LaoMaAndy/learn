#!/usr/bin/env python3
r'''
# 内置函数 Built-in Functions 
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

'''

from share import prn_title

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('func_buildin.py')
    test()
