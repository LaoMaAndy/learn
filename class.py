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

# 实例对象 Instance Objects
    实例对象的唯一操作是属性引用
    两种属性名称：数据属性 和 方法 data attributes and methods.
    数据：无需在类中声明，可直接使用，将自动添加
      使用dir() 可查看当前属性、方法
      已经使用的属性，可使用 __dict__ 查看
    方法：属于对象的函数
      方法对象 和 函数对象 有区别
    类的数据属性（数据成员）有几种：
      类名.variable_name  : 类变量
      self.variable_name : 实例变量
      variable_name      : 函数局部变量
      若不显式使用左值 self.variable_name, 直接将self.variable_name
        作为右值，则会使用类公共变量
      若显式使用左值variable_name, 直接使用variable_name右值，
        则会引发异常

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
    可以在运行时新增类变量
    例如： class foo:
            name = "Share"   <- 为类变量
            self.index = 10  <- 为实例变量 
    共享数据对于涉及可变对象，效果为：
      若类变量为一个列表，使用列表方法append()后，
      将同时修改所有实例的类变量
    每个对象不同的变量，应设计为实例变量
      self.var_name

# 补充说明
    数据属性（类变量）可以被类方法或类对象所引用
    类不能用于实现纯抽象数据类型。
    在Python中没有任何能够强制隐藏的数据
    在类以外定义类函数语法上也是可以的：
        def f1(self, x, y): ...
        class C: f = f1
    对象都具有 __class__ 属性
    在方法内调用其他方法：
        self.method_name
    在方法内调用实例变量：
        self.variable_name
    在方法内修改类变量：
        类名称.变量名称
# 继承
    继承的语法：
      class DerivedClassName(BaseClassName):
      class DerivedClassName(modname.BaseClassName):
    当构造类对象时，基类会被记住。 
      此信息将被用来解析属性引用：如果请求的属性在类中找不到，
      搜索将转往基类中进行查找。 如果基类本身也派生自其他某个类，
      则此规则将被递归地应用。
    对C++程序员的提示：Python中所有的方法实际上都是virtual方法
    直接调用基类方法：即调用 BaseClassName.methodname(self, arguments)
      >>注意，此处需要显示使用self
    内置函数 super()
      super() 可用来引用父类而不必显式地指定它们的名称
      class super(type, object_or_type=None)
      返回一个代理对象，它会将方法调用委托给 type 的父类或兄弟类。
      super() 并不限于在方法内部使用。 
        两个参数的形式明确指定参数并进行相应的引用。 
        零个参数的形式仅适用于类定义内部
      super() 使用指南：
      rhettinger.wordpress.com/2011/05/26/super-considered-super/
      使用 类名.方法 的形式为硬编码。并不理想。
      __mro__ :  Method Resolution Order 方法搜索顺序
        print(int.__mro__)

# 继承的内置函数
    isinstance(): 检查是否某个类的实例。例如：
        isinstance(obj, int)
    issubclass(): 检查是否为某个类派生。例如：
        issubclass(bool, int)  >>> True
        issubclass(float, int) >>> False

# 多重继承
    class DerivedClassName(Base1, Base2, Base3):
    搜索顺序简单讲：深度优先、从左至右
    


'''
from some_func import *
import sys
sys.path.append('./public')
sys.path.append('../public')


class OverRide():
    def __init__(self, s=''):
        self.title = s

    # prn()函数调用两个成员函数：prn_pre(), prn_after()
    def prn(self):
        self.prn_pre()
        print(self.title, end='')
        self.prn_after()
        print()

    # 两个成员函数无实际内容
    def prn_pre(self):
        pass

    def prn_after(self):
        pass


class DrvdClass(OverRide):
    def __init__(self, s=''):
        super().__init__(s)
    # 派生类重载了基类的同名函数

    def prn_pre(self):
        print('*' * 10, end='')

    def prn_after(self):
        print('-' * 10, end='')


def test_override():
    prn_title('test_override()')

    # 基类实例对象，调用prn()时，将使用基类的方法
    b = OverRide('Base Class')
    b.prn()
    # 派生类实例对象，调用prn()时，使用派生类重载后的方法
    d = DrvdClass('This is a Derived class')
    d.prn()


class ClassVariable():
    # 类中变量的形式有3：
    #   ClassName.variable_name
    #   self.variable_name
    #   variable_name
    # 分别是：类变量、实例变量、临时变量
    # 此处定义一个 类变量
    base_str = 'global class base_str'

    def __init__(self, s):
        # 此处定义一个实例变量
        self.base_str = s
        # 如无上面的定义的实例变量
        # 则下面的语句将使用 类变量，而非实例变量
        print(self.base_str)

        # 此处定义一个临时变量
        base_str = '\t' 'base_str: is a local variable'
        # 若没有上面的临时变量，则下面语句 出现异常
        # NameError: name 'base_str' is not defined
        print(base_str)

    def prn(self):
        print('print various value:')
        print('\t', 'self.base_str: ', self.base_str)
        print('\t', 'ClassVariable.base_str:', ClassVariable.base_str)

    def prn_list(self):
        # 此处的变量还未进行初始化
        # 直接调用则出现异常
        # 在运行时添加后，则可正常执行
        print('\t', self.ls)


def test_ClassVariable():
    prn_title('test_ClassVariable()')
    a = ClassVariable('a instance')
    a.prn()
    b = ClassVariable('b instance')
    # 修改基类，增加一个类变量，则所有实例都改变
    # 未添加类变量时，以下方法调用会产生变量为定义的异常
    # a.prn_list()
    print('Add a class variables:')
    ClassVariable.ls = list(range(4))
    # 定义类变量后，则不会产生异常
    a.prn_list()
    b.prn_list()


class BaseClass():
    base_str = ''

    def __init__(self, s: str = '',):
        if s == '':
            BaseClass.base_str = 'empty'
        else:
            BaseClass.base_str = s
        prn_str = BaseClass.base_str
        print('BaseClass.base_str: ', prn_str)

    def prn(self):
        self.base_str = 'kkkkkk'
        print('BaseClass prn:', self.base_str)

    def foo(self):
        self.prn()
        print('base foo.')


class DerivedClass(BaseClass):
    def __init__(self, s=''):
        print('DerivedClas __init__: ', s)
        super().__init__(s)


def test_derived():
    prn_title('test_derived()')
    b = BaseClass('None')
    b.prn()
    d = DerivedClass('This is derived class')
    b.prn()


class MyClass():
    r'''
    类变量、实例变量
    '''
    class_str = 'class_str: not changed'
    class_list = []

    def __init__(self, s):
        self.inst_name = s
        print('Set inst_name: ', s)

    def set_str(self, s):
        MyClass.class_str = s
        print('Set a new class_str: ', s)


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
    new_str = 'A Hole New String'
    MyClass.class_str = new_str
    del a.class_str
    print('Change MyClass to :', new_str)
    print('a.class_str:', a.class_str)
    print('b.class_str:', b.class_str)
    MyClass.new_tuple = ('new tuple', 23)
    print('Add a new class var: ', 'new_tuple')
    print('a.new_tuple:', a.new_tuple)
    print('b.new_tuple:', b.new_tuple)
    s = 'changed by object: a'
    a.set_str(s)
    print('a.class_str:', a.class_str)
    print('b.class_str:', b.class_str)
    print('a.__class__:', a.__class__)


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
        test_derived()
        test_ClassVariable()
        test_override()
    test()
