#!/usr/bin/env python3
r'''
# 类相关概念：
    面向对象编程
    Object Oriented Programming

    类型，实例，属性，方法
    type, instance, attribute, method
    
    继承，基类，派生类，重载
    inheritance, base classes, derived class, override
    
    运行时创建，创建后可以修改
    created at runtime, modified after creation
    
    成员， 公共， 私有， 虚拟
    member, public, private, virtual

    方法的第一个参数显式声明对象本身
    An explicit first argument representing the object

    调用方法时隐式提供
    provided implicitly by the call

    类本身就是对象
    classes themselves are objects

    用户可以使用内置的作为基类进行扩展
    built-in types can be used as base classes by user

    内置运算符可以被重定义
    built-in operators can be redefined

    模块，属性
    module, attribute

    命名空间有不同的声明周期
    Namespaces have different lifetimes

    作用域
    scope

    类对象、实例对象、函数对象、方法对象
    Class Object, Instance Object, function object, Method Object

    类变量、实例变量
    Class Variable、Instance Variable

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
    类中的实例变量、方法，可以先使用，后定义

# 方法对象
    x.f() 将立即执行该方法
    x.f 是一个方法对象，可以被储存，如
      xf = x.f
    方法的特殊之处在于，实例对象将作为第一个参数
      传递给该方法，也就是说：
      x.f() 与 MyClass.f(x) 完全相同

# 类变量和实例变量
    *** 类变量 正确的使用 ***
        > 永远使用 类名.类变量 的方式
        > 避免 类变量 和 实例变量 重名
    *** 类变量被“覆盖” ***
    可理解为：
        a) 类变量只能通过 类名.变量名 的方式修改
        b) 对于实例来说，类变量是只读的，
        c) 实例对类变量的修改，会发生覆盖。
    一般来说
        1）如果在 类函数中 对 “类变量” 进行 “重新赋值”，则：
            导致 “类变量” 被 覆盖：将产生一个同名的 “实例变量”，覆盖 “类变量”，
            而其他实例不受影响
        2）引用 “类变量”， 不会导致 “类变量” 被覆盖
        3）通过 “类名” 修改 “类变量”，则：
            所有实例都受到影响，
            除非某个实例中，类变量已经被“覆盖”
        4）除非执行了相关语句，否则 “覆盖” 不会发生。
        5）通过 “实例” 直接访问 “类变量”， 效果相同。
    或者：
      可以调用类变量的方法，修改类变量，此时，所有实例都将同时修改
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
    直接调用基类方法：即调用 BaseClassName.foo(self, arguments)
      >>注意，此处需要显示使用self
    内置函数 super()
      super() 可用来引用父类而不必显式地指定它们的名称:
        super().foo(arguments)
        super().__init__(arguments)
      super(type, object_or_type=None)
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
    菱形关联：即至少有一个父类可通过多条路径被最底层类所访问
      例如：所有类都是继承自 object，因此任何多重继承的情况都提供了
      一条以上的路径可以通向 object
    为了确保基类不会被访问一次以上，动态算法会用一种特殊方式将搜索顺序线性化， 
      保留每个类所指定的从左至右的顺序，只调用每个父类一次，并且保持单调，即，
      一个类可以被子类化而不影响其父类的优先顺序
    参阅：
      www.python.org/download/releases/2.3/mro/

# 私有变量
    那种仅限从一个对象内部访问的“私有”实例变量在 Python 中并不存在。
    遵循这样一个约定：带有一个下划线的名称 (例如 _spam) 应该被当作是 API 的
      非公有部分 (无论它是函数、方法或是数据成员)。 
      这应当被视为一个实现细节，可能不经通知即加以改变。

# 名称改写 Name mangling 
    用于在重载时不希望产生多态时使用，(c++语言 非virtual方法)
    任何形式为 __spam 的标识符（至少带有两个前缀下划线，至多一个后缀下划线）
    的文本将被替换为 _classname__spam，其中classname为去除了前缀下划线的当前类名称。
    名称改写有助于让子类重载方法而不破坏类内方法调用。
    __update = update
    这种方法确保在重载后，仍能调用原来的方法
    注意：此规则在用于以下方法，情况有所不同：
      exec() 或 eval() 
      getattr() 、 setattr() 和 delattr() 以及直接引用 __dict__ 时。

# 杂项：类似于c语言的struct
    from dataclasses import dataclass
    @dataclass
    class Employee:
        name: str
        dept: str
        salary: int
    使用：
    john = Employee('john', 'computer lab', 1000)
    john.dept

# 迭代器 Iterators
    支持for语句
    迭代器原理：
        包含了__iter__()函数，该函数在执行iter(s)时自动调用
        包含了__next__()函数，该函数在执行next(it)时自动调用
            在__next__()中，当元素用尽时，应发出 StopIteration终止循环
    迭代器使用：（交互方式）
        s = 'abc'
        it = iter(s)
        it
        next(it)
        next(it)
    迭代器定义：
        class Reverse:
        def __init__(self, data):
            self.data = data
            self.index = len(data)

        def __iter__(self):
            return self

        def __next__(self):
            if self.index == 0:
                raise StopIteration
            self.index = self.index - 1
            return self.data[self.index]
    迭代器的4要素：
        index / current, 
        __iter__(self): return self
        __next__(self)
        raise StopIteration

# 生成器 Generators
    yield
    生成器 是一个用于创建迭代器的简单而强大的工具。 
    它们的写法类似于标准的函数，但当它们要返回数据时会使用 yield 语句。 
      每次在生成器上调用 next() 时，它会从上次离开的位置恢复执行，
      它会记住上次执行语句时的所有数据值。
    生成器自动创建 __iter__() 和 __next__() 方法。
    另一个关键特性在于局部变量和执行状态会在每次调用之间自动保存。
    生成器编写：
        def reverse(data):
            for index in range(len(data)-1, -1, -1):
                yield data[index]
    生成器使用：
        for char in reverse('golf'):
            print(char)

# 生成器表达式 Generator Expressions
    类似于列表推导 list comprehensions，但使用的是圆括号()
    用于sum(), set(), max()等类似函数
    一些简单的生成器可以使用类似于列表推导式的语法简洁地编码为表达式，
      但使用括号而不是方括号。这些表达式是为封闭函数立即使用生成器的情况而设计的。
      生成器表达式比完整的生成器定义更紧凑，但通用性较差，
      并且比等效的列表推导式更易于内存使用。

# 生成器表达式举例：
    sum(i*i for i in range(10))                 # sum of squares

    xvec = [10, 20, 30]
    yvec = [7, 5, 3]
    sum(x*y for x,y in zip(xvec, yvec))         # dot product

    unique_words = set(word for line in page  for word in line.split())

    valedictorian = max((student.gpa, student.name) for student in graduates)

    data = 'golf'
    list(data[i] for i in range(len(data)-1, -1, -1))

 '''

# 以下内容是使用public文件夹中的一些自定义类
import sys
from share import prn_title
from pprint import pprint

class InstMethod:
    '''实例方法：
    特殊只读属性：
        __self__ 为类实例对象本身
        __func__ 为函数对象
        __doc__ 为方法的文档 (与 __func__.__doc__ 作用相同)
        __name__ 为方法名称 (与 __func__.__name__ 作用相同)；
        __module__ 为方法所属模块的名称，没有则为 None。
    '''
    def foo(self, s = ''):
        print(s)
        i = int(777)
        l = list(range(3))
        print('foo()'.center(20, '-'))
        pprint(vars())
        pprint(dir(self))
    def prn(self):
        print(f'{InstMethod.__name__}')


def test_InstMethod():
    prn_title('test_InstMethod()')
    c = InstMethod()
    c.prn()
    print(f'{c.foo.__self__ = }')
    print(f'{c.foo.__func__ = }')
    print(f'{c.foo.__name__ = }')
    print(f'{c.foo.__module__ = }')
    print('vars(c)'.center(20, '-'))
    print(f'{vars(c) = }')
    print(f'{vars(c.foo) = }')
    c.foo()
    print('-'*30)

class C1():
    ''' 再次实验一下类变量、实例变量
    '''
    pub_l = [1, 2, 3]
    pub_list_2 = [4, 5, 6]
    pub_s = 'pub string'
    def __init__(self, a):
        self.private = 'private'
        title = a + ' : init'
        self.prn(title)
    def change(self, a):
        C1.pub_s += ' + '
        C1.pub_s += a
        self.pub_l.append(a)
        self.pub_list_2 = list([a])
        self.private = a
        title = 'change: ' + a
        self.prn(title)
    def prn(self, a='prn'):
        print(a.center(30, '-'))
        print(f'{self.pub_l      = }')
        print(f'{self.pub_s      = }')
        print(f'{self.pub_list_2 = }')
        print(f'{self.private    = }')
        print()

def test_C1():
    print('再次实验类变量、实例变量'.center(30, '='))
    a = C1('a')
    b = C1('b')
    c = C1('c')
    # 修改类变量和实例变量
    a.change('changed by a')
    b.prn('b')
    c.prn('c')
    # 使用类名修改类变量
    s = 'By Class C1'
    C1.pub_s = s
    print(s)
    # 查看各实例
    a.prn('a')
    b.prn('b')
    c.prn('c')

    a.pub_l = ['----']
    a.prn('a')
    b.prn('b')
    c.prn('c')

    a.pub_l.append('******')
    a.prn('a')
    b.prn('b')
    c.prn('c')

class MyRange():
    '''自制的range()类:
    基本功能与range()相同
    '''
    def __init__(self, *arg):
        self.start = self.end = 0
        self.step = 1
        s = len(arg)
        if s == 1:
            self.end = arg[0]
        elif s == 2:
            self.start = arg[0]
            self.end = arg[1]
        elif s >= 3:
            self.start = arg[0]
            self.end = arg[1]
            self.step = arg[2]
 
        if self.step == 0:
            raise ValueError('step cannt be 0')
        self.current = self.start

    def __iter__(self):
        return self

    def __next__(self):
        if self.step > 0 and self.current < self.end:
            self.current += self.step
            return self.current - self.step
        if self.step < 0 and self.current > self.end:
            self.current += self.step
            return self.current - self.step
        raise StopIteration

def test_myrange():
    prn_title('test_myrange()')
    print(list(MyRange(10)))
    print(list(MyRange(2, 5)))
    print(list(MyRange(0, 10, 2)))
    #print(list(MyRange(0, 10, 1, 4)))
    #print(list(MyRange(0, 10, 0)))
    print(list(MyRange(10, 9, -2)))


class Mapping:
    '''名称改写
    以确保在方法被重载后，仍然保证调用基类的方法
    '''
    def __init__(self, iterable):
        self.items_list = []
        # 使用名称改写的标识符
        self.__update(iterable)
        # 如果不使用名称改写，则由于该方法在继承类中被改写，
        # 而导致错误
        #self.update(iterable)

    def update(self, iterable):
        for item in iterable:
            self.items_list.append(item)

    # 定义一个别名。方便两种使用
    __update = update   # private copy of original update() method

class MappingSubclass(Mapping):

    def update(self, keys, values):
        # provides new signature for update()
        # but does not break __init__()
        for item in zip(keys, values):
            self.items_list.append(item)

def test_name_mangling():
    prn_title('test_name_mangling()')
    m = Mapping(range(10))
    print(m.items_list)
    char = list('abcdefg')
    value = list(range(97, 104))
    s = MappingSubclass(range(3))
    s.update(char, value)
    print(s.items_list)


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

class SubClass(OverRide):
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
    d = SubClass('This is a Derived class')
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
        test_name_mangling()
        test_myrange()
        test_C1()
        test_InstMethod()
    test()
