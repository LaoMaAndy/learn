#!/usr/bin/env python3
r'''
# 类相关概念：
    Object Oriented Programming
    面向对象编程
    type, instance, attribute, method
    类型，实例，属性，方法
    inheritance, base classes, derived class, override
    继承，基类，派生类，重载
    created at runtime, modified after creation
    运行时创建，创建后可以修改
    member, public, private, virtual
    成员， 公共， 私有， 虚拟
    An explicit first argument representing the object
    方法的第一个参数显式声明对象本身
    provided implicitly by the call
    调用方法时隐式提供
    classes themselves are objects
    类本身就是对象
    built-in types can be used as base classes by user
    用户可以使用内置的作为基类进行扩展
    built-in operators can be redefined
    内置运算符可以被重定义
    module, attribute
    模块，属性
    Namespaces have different lifetimes
    命名空间有不同的声明周期
    scope
    作用域
    Class Object, Instance Object, function object, Method Object
    类对象、实例对象、函数对象、方法对象
    Class Variable、Instance Variable
    类变量、实例变量

# 对象和名称：一个对象可以绑定多个名称

# 作用域和命名空间: Scopes and Namespaces
# 命名空间 namespace: 从名称到对象的映射
    大多数使用字典实现
    不同的模块可以都定义同名函数而不会混淆
      使用时，必须在其前面加上模块名称。
    模块属性和模块中定义的全局名称之间存在直接的映射：
      它们共享相同的命名空间！
    属性可以是只读或者可写的。del 语句可以删除可写属性。
    命名空间是在不同时刻创建的，且拥有不同的生命周期。
      内置名称的命名空间永远不会被删除。
      模块的全局命名空间是在读入模块定义时创建的
        模块名称空间也会持续到解释器退出为止。
      解释器顶层调用执行的语句是 __main__ 模块调用的一部分，
        也拥有自己的全局命名空间。
      函数的本地命名空间在调用该函数时创建，
        并在函数返回或抛出不在函数内部处理的错误时被删除。
        每次递归调用都会有自己的本地命名空间。
# 作用域 scope
    搜索顺序
      当前局部作用域将包含本地名称。
      从最接近的封闭函数搜索非本地、非全局名称。
      倒数第二个作用域，包含当前模块的全局名称
      最外层的作用域，包含内置名称的命名空间，
    全局名称 ： 直接从倒数第二个作用域开始查找
    nonlocal ： 跳过查找最内部范围的变量
    global ：全局变量
    非局部变量为只读；如果写入，则会创建一个新的局部变量
    del x 从局部作用域中移除对x的绑定

# 类定义语法 - 最简单的定义形式：
    class ClassName:
        pass
    类定义必须先执行才能生效
    类中的函数定义使用特殊语法
    当从结尾处正常离开类定义时，将创建一个类对象
    对象 相当于类定义所创建的命名空间的包装器

# 类对象
    类对象支持两种操作：属性引用和实例化
    属性引用: obj.name
    __doc__ 将返回类的文本字符串
    类的实例化可看做一个函数调用，返回一个类对象
    __init__() ：特殊方法，用于创建对象

# 实例对象
    实例对象的唯一操作是属性引用
    两种属性名称：数据属性 和 方法
    数据：无需在类中声明，可直接使用，将自动添加
      使用dir() 可查看当前属性、方法
      已经使用的属性，可使用 __dict__ 查看
    方法：属于对象的函数
      方法对象 和 函数对象 有区别

# 方法对象
    x.f() 将立即执行该方法
    x.f 是一个方法对象，可以被储存，如
      xf = x.f
    方法的特殊之处在于，实例对象将作为第一个参数
      传递给该方法，也就是说：
      x.f() 与 MyClass.f(x) 完全相同

# 类变量和实例变量
    类变量为所有的实例共享
      可以调用类变量的方法，简介修改类变量，此时，所有实例都将同时修改
      如果将类变量重新赋值，将产生一个局部变量，该变量不影响其他对象的类变量
    实例变量对于每一个实例不同
    例如： class foo:
            name = "Share"   <- 为类变量
            self.index = 10  <- 为实例变量 
    共享数据对于涉及可变对象，效果为：
      若类变量为一个列表，使用列表方法append()后，
      将同时修改所有实例的类变量
    

'''
import sys
sys.path.append('./public')
sys.path.append('../public') 
from some_func import *
 
class MyClass():
    r'''
    类变量、实例变量
    '''
    class_str = 'class_str: not changed'
    class_list = []

    def __init__(self, s):
        self.inst_name = s
        print('Set inst_name: ', s)
def test_myclass():
    prn_title('test_myclass')

    a = MyClass('aaa')
    b = MyClass('bbb')
    print(a.inst_name)
    print(b.inst_name)
    print('Change class_list:')
    a.class_list.append('Changed by a')
    print(a.class_list)
    print(b.class_list)
    print('Change class_list:')
    b.class_list.append('Changed by b')
    print(a.class_list)
    print(b.class_list)
    print('Change class_str:')
    a.class_str = 'class_str changed by a'
    print(a.class_str)
    print(b.class_str)

def test_def_class():
    prn_title('test_def_class')
    class MyClass:
        print('this is MyClass')

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('class.py')
        test_def_class()
        test_myclass()
    test()
