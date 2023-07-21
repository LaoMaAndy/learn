#!/usr/bin/env python3
r'''
# 异常
# 内置异常
https://docs.python.org/zh-cn/3/library/exceptions.html#bltin-exceptions

# 交互模式异常构成：
    Traceback (most recent call last):
    File "<stdin>", line 1, in <module>
    ZeroDivisionError: division by zero
    异常的语境。一般会列出源代码行的堆栈回溯
    异常类型: 错误细节

# Ctrl-c 会触发 KeyboardInterrupt 异常

# try-except-else 子句 clause
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
    
'''
import sys

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
    test()
