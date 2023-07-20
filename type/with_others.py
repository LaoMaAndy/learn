#!/usr/bin/env python3
r'''
# 上下文管理器类型 with: 
    Context Manager Types
    with 语句支持通过上下文管理器所定义的运行时上下文的概念。

# 上下文管理器方法
    contextmanager.__enter__()
      进入上下文，并返回 as 子句的标识符
      例如：with expression as target_var:
            do_something(target_var)
    contextmanager.__exit__(exc_type, exc_val, exc_tb)
      退出运行时上下文，并返回一个布尔标志，指示是否应抑制发生的
        任何异常。如果在执行with语句主体时发生异常，
        则参数包含异常类型、值和回溯信息。
    应用于：
      简易的线程同步
      文件或其他对象的快速关闭
      十进制算数上下文
    参见：contextlib 

# 类型注释类型——通用别名、联合
  Type Annotation Types — Generic Alias, Union

# GenericAlias 类型
    GenericAlias 对象的主要目的是用于 类型标注。
    通常一个类只有在实现了特殊方法 
        __class_getitem__() 时才支持抽取操作。
    例如: set[bytes]  可在类型标注中用来表示一个 set 中
        的所有元素均为 bytes 类型。
    
  方法：
    T[X, Y, ...] : 
      创建一个代表由类型 X, Y 来参数化的类型 T 的 GenericAlias
    例如 使用类型标注的函数定义：
      def average(values: list[float]) -> float:
        return sum(values) / len(values)
    例如 指定 dict类型的 key类型和 value类型：
      def send(url: str, body: dict[str, int]) -> None:
    Python 运行时不会强制执行 类型标注。 
    内置函数 isinstance() 和 issubclass() 
      不接受第二个参数为``GenericAlias`` 类型：

  GenericAlias 对象的特殊属性:
    genericalias.__origin__ : 指向未应用参数之前的泛型类：
      例如 list[int].__origin__  >>> <class 'list'>

    genericalias.__args__ : 
      传给泛型类的原始 __class_getitem__() 的
      泛型所组成的 tuple (长度可能为 1):
    
    genericalias.__parameters__ :
      延迟计算出来的一个元组（可能为空），
        包含了 __args__ 中的类型变量。

    genericalias.__unpacked__
      如果别名已使用 * 运算符解包，则为True

# Union Type 类型联合
    3.10 新版功能.
    语法： X | Y | ... 相当于两种类型的组合
    例如： def square(number: int | float) -> int | float:

# 其他内置类型
Modules 模块 
    m.name 其中，m 是一个模块， name 访问m中的名称
    模块的属性 __dict__ 

Classes and Class Instances: 类和类实例

Functions 函数
    唯一操作是调用它: func(argument-list)

Methods 方法
    存在两种形式：内置方法（例如列表的 append() 方法）和类实例方法。
    通过实例来访问方法时：
      你会得到一个特殊对象: 绑定方法 (或称 实例方法) 对象。
      该方法会将 self 参数添加到参数列表。
      绑定方法具有两个特殊的只读属性: 
        m.__self__操作该方法的对象，
        m.__func__ 是实现该方法的函数。
    参考： 数据模型 / 标准类型层级结构
      docs.python.org/zh-cn/3/reference/datamodel.html#types


    

'''
def func_anno(x: int, y: int) -> int:
    print(f'x: {x : <10.10s}, y: {y}')

def test_func_anno():
    func_anno('adjk', 12)

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('with and others')
        test_func_anno()
    test()
