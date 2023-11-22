#!/usr/bin/env python3
r'''
# 异常

# 交互模式异常构成：
    Traceback (most recent call last):
    File "<stdin>", line 1, in <module>
    ZeroDivisionError: division by zero
    异常的语境。一般会列出源代码行的堆栈回溯
    异常类型: 错误细节

# Ctrl-c 会触发 KeyboardInterrupt 异常

# try - except - else - finally 子句clause
    - 首先执行 try 语句的部分
    - 如果没有触发异常，则跳过 except 部分
    - 如果触发异常，跳过 try 中的剩余部分，执行 except
    - 如果匹配 except 后的异常类型，则执行，然后跳出try/except
    - 如果无法匹配，则传递到外部的 try 语句
    - 如果没有找到处理程序，则为 未处理异常，终止程序，并输出提示
    - 可以有多个except，但最多执行一个
    - except() 圆括号中可以有多个异常类型
    - 匹配规则: except 后的异常是 引发异常的基类，或二者相同。
    - else 子句在所有except 之后
      当不引发任何异常时，执行else子句

# 当异常发生时，它可能有关联的值，也称为异常的参数。
    参数的存在和类型取决于异常类型。

# except 子句可以在异常名称之后指定一个变量 
    except ... as ...
    该变量绑定到异常实例，
    该实例通常具有存储参数的 args 属性。
    内置异常类型定义 __str__() 来打印所有参数
# 举例
    raise Exception('spam', 'eggs')
    except Exception as inst:
        print(type(inst))    # the exception type
        print(inst.args)     # arguments stored in .args
        # __str__ allows args to be printed directly,
        # but may be overridden in exception subclasses
        print(inst)          
        x, y = inst.args     # unpack args
        print('x =', x)
        print('y =', y)

# 异常分类
    BaseException 是所有异常的公共基类。
    它的子类之一 Exception 是所有非致命异常的基类。
    其他异常通常不处理，包括
      由 sys.exit() 引发的 SystemExit
      中断程序时引发的 KeyboardInterrupt
    Exception 捕获（几乎）所有内容的通配符

# 异常处理
    处理 Exception 的最常见模式是打印或记录异常，
    然后重新引发它（也允许调用者处理异常）
    
# 触发异常 raise
    raise 带参数的异常 
        raise Exception('spam', 'eggs')
        except Exception as inst:
            print(type(inst)) 
            ...
    raise 的唯一参数指示要引发的异常。
    必须是异常实例或异常类。如果传递异常类，
      它将通过不带参数调用其构造函数来隐式实例化：
      # shorthand for 'raise ValueError()'
      raise ValueError  
    不带参数的raise, 将重新触发异常，用来判断
      是否引发异常，但不打算处理它

# 异常链
    如果 except 部分内发生未处理的异常，
      则会将正在处理的异常附加到该部分并包含在错误消息中：
    为了指示异常是另一个异常的直接结果， 
      raise 语句允许使用可选的 from 子句：
        except ConnectionError as exc:
            raise RuntimeError('Failed') from exc
    它还允许使用 from None 习惯用法禁用自动异常链接

# 用户自定义的异常
    程序可以通过创建新的异常类来命名自己的异常
    异常通常应该直接或间接地从 Exception 类派生。
    大多数异常都是使用以“Error”结尾的名称来定义的，
    可以定义异常类来执行任何其他类可以执行的任何操作，
      但通常保持简单，通常仅提供许多属性，
      这些属性允许异常处理程序提取有关错误的信息。
    许多标准模块定义了自己的异常。

# 定义清理操作 finally 子句
    如果存在 finally 子句，则 finally 子句将
      作为 try 语句完成之前的最后一个任务执行。
      无论 try 语句是否产生异常， finally 子句都会运行
    若引发的异常，没有对应的 except 子句，
      则先运行 finally 子句，然后重新引发异常
    except 或 else 子句执行期间也会触发异常。 
      同样，该异常会在 finally 子句执行之后被重新触发。
    如果 finally 子句中包含 break、continue 或 return 等语句，
      异常将不会被重新引发。    
    如果执行 try 语句时遇到 break,、continue 或 return 语句，
      则 finally 子句先执行
    如果 finally 子句中包含 return 语句，则返回值来自 finally 
      而不是来自 try 子句的 return 语句的返回值。

# 预定义的清理操作, 支持 with
    with open("myfile.txt") as f:
      语句执行完毕后，即使在处理行时遇到问题，都会关闭文件 f。
    支持预定义清理操作的对象会在文档中指出这一点。

# 引发和处理多个不相关的异常 
  略
https://docs.python.org/3/tutorial/errors.html

# 用注释充实异常信息
  略 

# 内置异常
    https://docs.python.org/zh-cn/3/library/exceptions.html#bltin-exceptions
    内置异常都会具有一个提示导致错误详细原因的“关联值”。 
      可能是一个字符串，或
      多个信息项（如一个错误码和一个解释错误的字符串）组成的元组。
    所有异常必须为一个派生自 BaseException 的类的实例。
    程序员应从 Exception 类派生自定义异常

# 异常上下文
    当有其他异常已经被处理的情况下又引发一个新异常的时候，
      新异常的 __context__ 属性会被自动设为已经被处理的异常。
    使用 from 配合 raise 来补充一个显式的原因:
      raise new_exc from original_exc
    它将在所引发的异常上被设置为 __cause__
    __cause__ 中的显式串连异常，如果存在将总是显示
    __context__ 中的隐式串连异常，
       仅在 __cause__ 为 None 
       并且 __suppress_context__ 为假值时显示。
    异常本身总会在任何串连异常之后显示，
      以便回溯的最后一行总是显示所引发的最后一个异常。

# 从内置异常继承
    用户代码可以创建继承自某个异常类型的子类。
    建议每次仅子类化一个异常类型以避免多个基类处理 

# BaseException
    所有内置异常的基类。 它不应该被用户自定义类直接继承 
    args: 传给异常构造器的参数元组
      通常只接受一个给出错误信息的单独字符串。
    with_traceback(tb) :
      此方法会将 tb 设为新的异常回溯信息并返回异常对象。 
    add_note(note):
      将字符串 note 添加到异常注释中
    __notes__:
      此异常的注释列表，用 add_note() 添加。

# Exception
    所有内置的非系统退出类异常都派生自此类。 
    所有用户自定义异常也应当派生自此类。

# ArithmeticError
    此基类用于派生针对各种算术类错误而引发的内置异常:
      OverflowError, 
      ZeroDivisionError, 
      FloatingPointError。

# BufferError
    当与 缓冲区 相关的操作无法执行时将被引发。

# LookupError
    此基类用于派生当映射或序列所使用的键或索引无效时引发的异常:
      IndexError, 
      KeyError。 
    这可以通过 codecs.lookup() 来直接引发。

# Exception groups 例外组
  当需要引发多个不相关的异常时使用
  略

# 内置异常的类层级结构如下：
BaseException
 ├── BaseExceptionGroup
 ├── GeneratorExit : 当一个 generator 或 coroutine 被关闭时将被引发
 ├── KeyboardInterrupt : 当用户按下中断键(c-c)时将被引发。 
 ├── SystemExit : 此异常由 sys.exit() 函数引发。 
 └── Exception
      ├── ArithmeticError
      │    ├── FloatingPointError : 目前未被使用。
      │    ├── OverflowError : 当算术运算的结果大到无法表示时将被引发。 
      │    └── ZeroDivisionError : 当除法或取余运算的第二个参数为零时将被引发。 
      ├── AssertionError : 当 assert 语句失败时将被引发。
      ├── AttributeError : 当属性引用或赋值失败时将被引发。
      ├── BufferError
      ├── EOFError : 达到文件结束条件 (EOF) 时将被引发。
      ├── ExceptionGroup [BaseExceptionGroup]
      ├── ImportError : 当 import 语句尝试加载模块遇到麻烦时将被引发。
      │    └── ModuleNotFoundError : 当一个模块无法被定位时将由 import 引发
      ├── LookupError
      │    ├── IndexError : 当序列抽取超出范围时将被引发。
      │    └── KeyError : 当在现有键集合中找不到指定的映射键时将被引发。
      ├── MemoryError : 当一个操作耗尽内存但情况仍可挽救时将被引发。 
      ├── NameError : 当某个局部或全局名称未找到时将被引发。 
      │    └── UnboundLocalError : 当在函数或方法中对某个局部变量进行引用，但该变量并未绑定任何值时将被引发。
      ├── OSError : 在一个系统函数返回系统相关的错误时将被引发.
      │    ├── BlockingIOError : 当一个操作将会在设置为非阻塞操作的对象（例如套接字）上发生阻塞时将被引发。
      │    ├── ChildProcessError : 当一个子进程上的操作失败时将被引发。
      │    ├── ConnectionError : 与连接相关问题的基类。
      │    │    ├── BrokenPipeError : 当试图写入一个管道而该管道的另一端已关闭，或者试图写入一个套接字而该套接字已关闭写入时将被引发。 
      │    │    ├── ConnectionAbortedError : 当一个连接尝试被对端中止时将被引发。 
      │    │    ├── ConnectionRefusedError : 当一个连接尝试被对端拒绝时将被引发。
      │    │    └── ConnectionResetError : ，当一个连接尝试被对端重置时将被引发。
      │    ├── FileExistsError : 当试图创建一个已存在的文件或目录时将被引发。
      │    ├── FileNotFoundError : 将所请求的文件或目录不存在时将被引发。
      │    ├── InterruptedError : 当系统调用被输入信号中断时将被引发。
      │    ├── IsADirectoryError : 当请求对一个目录执行文件操作 (例如 os.remove()) 时将被引发。 
      │    ├── NotADirectoryError : 当请求对一个非目录执行目录操作 (例如 os.listdir()) 时将被引发。
      │    ├── PermissionError : 当请求对一个非目录执行目录操作 (例如 os.listdir()) 时将被引发。
      │    ├── ProcessLookupError : 当给定进程不存在时引发。
      │    └── TimeoutError : 当系统函数在系统级别超时时引发。
      ├── ReferenceError : 使用 weakref.proxy() 函数所创建的弱引用来访问该引用的某个已被作为垃圾回收的属性时被引发。
      ├── RuntimeError : 当检测到一个不归属于任何其他类别的错误时将被引发。 
      │    ├── NotImplementedError 
      │    └── RecursionError :  在解释器检测发现超过最大递归深度时被引发。
      ├── StopAsyncIteration : 必须由异步迭代器对象的 __anext__() 方法引发才能停止迭代
      ├── StopIteration : 由内置函数 next() 和 iterator 的 __next__() 方法所引发，用来表示该迭代器不能产生下一项。
      ├── SyntaxError : 当解析器遇到语法错误时引发。 import，compile(), exec() 或 eval() 的调用时。
      │    └── IndentationError : 与不正确的缩进相关的语法错误的基类
      │         └── TabError : 当缩进包含对制表符和空格符不一致的使用时将被引发。
      ├── SystemError : 当解释器发现内部错误，但情况看起来尚未严重到要放弃所有希望时将被引发。 
      ├── TypeError : 当一个操作或函数被应用于类型不适当的对象时将被引发。
      ├── ValueError : 当操作或函数接收到具有正确类型但值不适合的参数，
      │    └── UnicodeError : 当发生与 Unicode 相关的编码或解码错误时将被引发。
      │         ├── UnicodeDecodeError : 当在解码过程中发生与 Unicode 相关的错误时将被引发。 
      │         ├── UnicodeEncodeError : 当在编码过程中发生与 Unicode 相关的错误时将被引发。
      │         └── UnicodeTranslateError : 在转写过程中发生与 Unicode 相关的错误时将被引发。 
      └── Warning : 警告类别的基类。
           ├── BytesWarning : 与 bytes 和 bytearray 相关的警告的基类。
           ├── DeprecationWarning : 已弃用特性相关警告的基类。
           ├── EncodingWarning : 与编码格式相关的警告的基类。
           ├── FutureWarning
           ├── ImportWarning : 与模糊的运行时行为相关的警告的基类。
           ├── PendingDeprecationWarning : 对于已过时并预计在未来弃用，但目前尚未弃用的特性相关警告的基类。
           ├── ResourceWarning : 资源使用相关警告的基类。
           ├── RuntimeWarning : 与模糊的运行时行为相关的警告的基类。
           ├── SyntaxWarning : 与模糊的语法相关的警告的基类。
           ├── UnicodeWarning : 与 Unicode 相关的警告的基类。
           └── UserWarning : 用户代码所产生警告的基类。

'''
import sys
def print_dir(t, *, tab=3):
    try: 
        c = 1
        for i in dir(t):
            sep = '\n' if c%tab == 0 else ''
            print(f'{i:20}', end=sep)
            c += 1
    except:
        print('Some Error occuring...')
        raise
def test_print_dir():
    c = [BaseException, int, str, dict]
    for i in c:
        print()
        print('-' * 40)
        print('Attributes & methods of: ', i.__name__)
        print('-' * 40)
        print_dir(i, tab = 4)
    print()

def with_open(file_name):
    with open(file_name) as f:
        print('-' * 20)
        print('Already open file: ', file_name)
        print('-' * 20)
        for line in f:
            print(line, end="")

def test_with_open():
    with_open('test.txt')
    print()

def fully_try(x, y):
    try:
        result = x / y
    except ZeroDivisionError:
        print("division by zero!")
    else:
        print(x, '/', y, "result is: ", result)
    finally:
        print("finally executing ")

def test_fully_try():
    fully_try(10, 5)
    fully_try(10, 0)


def test_some_expt():
    class B(Exception):
        pass

    class C(B):
        pass

    class D(C):
        pass

    for cls in [B, C, D]:
        try:
            raise cls()
        except D:
            print("D")
        except C:
            print("C")
        except B:
            print("B")

def test_handle():
    file_name = 'test.txt'
    try:
        f = open(file_name)
        s = f.readline()
        i = int(s.strip())
        print('i = ', i)
    except OSError as err:
        print('OS error:', err)
    except ValueError:
        print('ValueError: ' 
              'Could not convert into integer')
    except Exception as err:
        print(f'Unexpcted {err:}, {type(err)=}')
        raise
    else:
        print(f'Read file <{file_name}> OK')
        f.close()

def test_raise():
    print(__name__)
    try: 
        raise Exception('source', 'some information')
    except Exception as inst:
        print(type(inst))
        print(inst.args)
        print(inst)

        x, y = inst.args
        print('titl:', x)
        print('more:', y)

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('execpt.py')
        test_raise()
        test_handle()
        test_some_expt()
        test_fully_try()
        test_with_open()
        test_print_dir()
    test()
