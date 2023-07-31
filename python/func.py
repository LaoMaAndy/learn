#!/usr/bin/env python3
'''python函数知识要点：

定义函数 def
文档字符串 __doc__
    - 模块开始处
    - 函数名之后
    - 查看：f.__doc__
符号表：
    - 局部，外层，全局
    - nonlocal, global
    - vars(), locals(), globals()
参数：
    - 值传递，引用传递
返回值:
    - 无返回值时，为None
函数参数的使用：
    - 定义时、调用时
函数参数：
    - 型参 formal parameter / argument
    - 默认参数值
    - 默认值可以使用变量，但只求值一次
    - 关键字参数 keyword argument
        也叫做 named parameter
    - 位置参数 positional argument
    - 必选/可选参数：required / optional
    - 关键字参数必须在位置参数后面
    - 调用时：参数不能多于函数要求
    - 调用时：参数不能重复赋值
参数收集：*arg形参与**arg 形参
    - *arg 必须在 **name前
    - *arg 接收一个元组，包含形参列表之外的*位置*参数
    - **arg 接收一个字典，包含与函数中已定义形参对应之外的所有*关键字*参数
    - *arg 和 **arg 可一同时使用， * 在 ** 前
    - 关键字参数在输出结果中的顺序与调用函数时的顺序一致
    - 使用 * 处理任意多的参数：
       *arg后可以有关键字参数
       def concat(*args, sep="/"):
           return sep.join(args)
参数分隔 / 和 * 【特殊写法】
    - 格式：def foo(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
    - 将参数类型分开：
      / 前为 仅限位置参数
      / * 之间为位置或关键字参数
      * 之后为关键字参数
    【错误写法】避免特征的情况发生：
        def foo(name, **kwds):
          return 'name' in kwds
        在这个函数被调用时，无法使用 foo('Alice', name='Kite')
        这样的形式，否则产生重复赋值的错误
        也无法使用 foo(1, **{'name': 2})，重复赋值
    【特殊写法】所以需要书写为：
        def foo(name, /, **kwds):
          return 'name' in kwds
    - 可以这样调用：foo(1, **{'name': 2})
        或这样调用 foo(a, name=2)
解包实参列表
    - 函数调用时
    - 使用 * 解包列表或元组
        args = [3, 6]
        list(range(*args)) 
    - 使用 ** 解包字典
函数概念：函数名、函数对象、函数变量，返回函数
    - 函数对象 赋值 f = fib
      相当于“别名”，新的变量名指向该函数的地址
    - 获得函数返回值：
        f100 = fib(100)
        f100获取的是fib(100)的返回值
函数嵌套：外层函数，内层函数
    - 内层函数保留自己的变量表
    - 内层函数可以 *读取* 外层函数的变量吗：可以
    - 内层函数可以 *修改* 外层函数的变量吗：不可以
    - 将内层函数作为返回值
      有一个嵌套函数 
      def outer(n): 
        def inner(m):
            return m + n
        return inner
    - 当使用 f = outer(n) 这样的语句时：
        首先执行outer(n), 并设定内层函数的变量表
        内层函数的变量表是分级的，可以标记本地和非本地
        返回一个函数，相当于inner()
        可以执行f(), 相当于调用内层函数
        f()需要的参数，与内层函数相同
        f()执行时，自带外层函数的变量值
lambda表达式
    - 普通写法：lambda a, b: a+b，返回两个数的和
    - 冒号之前的为参数；冒号之后的为返回的表达式
    - 相当于一个函数，def inner(b): return a + b
    - lambda可以使用外层函数的变量初始值
    - 可以引用包含在作用域中的变量
    - 用于任何需要函数调用的地方
    - 只能是单个表达式
    - 语法糖
    【特殊写法】
    - 把匿名函数作为参数传递：
        pairs = [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]
        pairs.sort(key=lambda p: p[1])
        pairs
        [(4, 'four'), (1, 'one'), (3, 'three'), (2, 'two')]
函数注解 __annotations__
    - 可选，函数的元数据完整信息
    - Python 运行时不会强制执行 类型标注。 
    - 将函数的参数返回值类型全部标注清楚
    - 使用__annotations__查看该属性
    - 标注信息以字典方式存放
    - 语法：def f(ham: str, eggs: str = 'eggs') -> str:
    - 冒号后可以为表达式
代码格式化 PEP 8
    - 使用指令自动格式化
    - 缩进，用 4 个空格，不要用制表符。
    - 换行，一行不超过 79 个字符。
    - 用空行分隔函数和类，及函数内较大的代码块。
    - 最好把注释放到单独一行。
    - 使用文档字符串。
    - 运算符前后、逗号后要用空格
    - 类名，用 UpperCamelCase
    - 函数名，用 lowercase_with_underscores
    - 方法中第一个参数总是用 self
    - 使用 UTF-8 编写代码文件
    - 不要在标识符中使用非 ASCII 字符。
'''
from pprint import pprint
from share import prn_title

def funcvars(arg=''):
    prn_title('funcvars()')
    i = int()
    l = list()
    print('函数参数:', arg)
    def foo():
        pass
    print(f'{funcvars.__doc__ = }')
    print(f'{funcvars.__name__ = }')
    print(f'{funcvars.__qualname__ = }')
    print(f'{funcvars.__module__ = }')
    print(f'{funcvars.__defaults__ = }')
    print(f'{funcvars.__code__ = }')
    #print(f'{funcvars.__globals__ = }')
    print(f'{funcvars.__dict__ = }')
    print(f'{funcvars.__closure__ = }')
    print(f'{funcvars.__annotations__ = }')
    print(f'{funcvars.__kwdefaults__ = }')
  
    pprint('vars()'.center(30, '-'))
    pprint(vars())
    print('vars(funcvars)'.center(30, '-'))
    print('add a variable:')
    funcvars.new_vari = 777
    pprint(vars(funcvars))

def ret_self(b=10, add=20):
    '''返回函数自身
    若返回自身函数，则相当于递归调用，
    容易陷入死循环当中，需要设定终止条件'''
    print("simple(b=10, add=20)", b, add)
    f = simple(b=b+add)
    return f

def a_lambda(n):
    ''' 返回一个lambda表达式
    返回的表达式，相当于一个函数,
    被赋值的变量相当于一个函数，参数为lambda表达式指定的参数，
    该函数可以携带内部变量初始值，这些初始值是赋值时提供的'''
    print("a_lambda(n):", n)
    print('function vars:', vars())
    return lambda x: x + n
def test_a_lambda():
    f = a_lambda(10)
    print('test_a_lambda(), f(1)：',f(1))
    print('test_a_lambda(), f(2)：',f(2))

def outer_foo(outer_ref=0):
    ''' 嵌套函数可以修改外层函数的变量吗？
    可以读取，但不能修改'''
    outer_n = 10
    outer_str = 'abc'
    print('--- 外层函数变量表 --- ')
    for k, v in vars().items():
        print('\t', k, ":", v)
    def inner_foo():
        inner_str = 'inner'
        print('--- 内层函数变量表 ---')
        # 只有使用过的外层变量，才会出现在内层函数变量表中
        outer_n
        outer_str
        # 不可以给外层变量赋值，提示：cannot access local variable
        # outer_n = 20 
        for k, v in vars().items():
            print('\t', k, ":", v)
    inner_foo()
    outer_n = 222
    print('改变一下外层函数的变量, n =', outer_n)
    inner_foo()

def outer_func(outer_arg, s = 'outer'):
    '''在函数内部定义一个函数，并返回该函数'''
    outer_i = outer_arg
    outer_str = s
    outer_list = list('outer')
    print('--- 外层函数变量表 --- ')
    for k, v in vars().items():
        print('\t', k, ":", v)
    def inner(inner_arg):
        inner_str = 'inner'
        inner_int = 99
        print('--- 内层函数变量表 --- ')
        for k, v in vars().items():
            print('\t', k, ":", v)
        return inner_arg + outer_arg
    return inner

def test_ret_func():
    f777 = outer_func(777, s='777')
    f55 = outer_func(55, s='55')
    print('return value:', f777(111))
    print('return value:', f55(44))

def small_talk(greet, name='', chat=''):
    '''打印列表
    首先打印greet, 循环打印name: , 逐条打印chat'''
    print(greet)
    #print('name:', name)
    #print('chat:', chat)
    #return
    n = len(name)
    m = 0
    c = chat
    for i in c:
        if m == n: m = 0
        print(name[m], ':', end = ' ')
        m += 1
        print(i)
def test_small_talk():
    greet = 'Time is 4pm'
    name = ['Me', 'Alice']
    chat = ['Can you tell me a story?',
            'OK',
            '',
            'Here is one',
            ]
    small_talk(greet, name, chat)

a_number = 10
def print_int(i = a_number):
    ''' 此处函数默认值等于一个全局变量，
    该默认值只赋值一次，当全局变量变化后，
    函数默认值仍保持不变'''
    print(i)
def test_print_int():
    print('function default argument value: 20')
    print_int()
    print('change default var: 20')
    a_number = 20
    print_int()

a_list = [1, 2]
def print_list(i = a_list):
    ''' 函数默认值为可变类型
    此处函数默认值等于一个全局变量，
    该全局变量为可变类型list,
    默认值赋值为该变量的引用，
    当全局变量变化后，函数默认值随之改变'''
    print(i)

def test_print_list():
    print('a_list = [1, 2]')
    print_list()
    print('append 100 to the list:')
    a_list.append(100)
    print_list()

def share_list_arg(i, arg=[]):
    '''特殊写法：
    函数参数默认值为空列表，
    当该列表的值改变后，所有函数调用，该参数默认值都改变。
    可理解为：编译器创建了一个匿名变量，将引用赋值给参数
    若避免该情况，需 arg=None
    然后在函数内部 arg=[]
    
    '''
    arg.append(i)
    return arg

def test_share_list_arg():
    print('Function share an argument:')
    print(share_list_arg(100))
    print(share_list_arg('share'))
    print(share_list_arg(222))
    print(share_list_arg(None))

def dont_share_list_arg(i, arg=None):
    '''成语写法：
    避免函数参数共享可变类型：
    若避免该情况，需 arg=None
    然后在函数内部 arg=[]
    '''
    if arg is None:
        arg = []
    arg.append(i)
    return arg
def test_dont_share_list_arg():
    print('Function dont share an argument:')
    print(dont_share_list_arg(100))
    print(dont_share_list_arg('share'))

def feb_prn(max):
    '''打印斐波那契数列'''
    a, b = 0, 1
    print('不大于', max, '的斐波那契数列:', sep='')
    while a <= max:
        print(a, end=', ')
        a, b = b, a+b
    print('')

def feb(count=0, limit=0, start=0):
    ''' 返回斐波那契数列, 列表。
        列表从0，1开始
        count: 数列元素个数
        limit: 不超过最大值
        start: 开始值
        无参数时返回空列表
    '''
    # print('count:', count, "limit:", limit)
    # 处理参数特殊情况
    if (count<=0 and limit<=0):
        return []
    a, b = start, start+1
    result = [start]
    i = 1       # 已经添加了一个值，计数从1开始
    while True:
        a, b = b, a + b
        if count!=0 and i>=count:
            break
        if limit!=0 and a>limit:
            break
        result.append(a)
        i += 1
    return result

def test_feb():
    print("feb(0):", feb(0))
    print("feb(1):", feb(1))
    print("feb(2):", feb(2))
    print("feb(5):", feb(5))
    print("feb(limit=30):", feb(limit=30))
    print("feb(count=3, limit=1000):", feb(count=3, limit=1000))
    print("feb(count=10, limit=30):", feb(count=10, limit=30))
    print("feb(count=5, start=1000):", feb(count=5, start=1000))

def test_feb_prn():
    feb_prn(1)
    feb_prn(20)

def test_ref_func():
    '''函数名和函数对象:
        * 定义一个变量，引用另一个函数对象
        * 定义一个变量，引用函数对象，附带变量列表
    '''
    f = feb_prn
    f(30)
    f50 = f(50)
    
def no_return(i):
    ''' 函数返回值默认返回None，即使没有return'''
    i += 1

def test_no_return():
    print(no_return(1))

if __name__ == '__main__':
    def demo():
        # print(file_string)
        # test_feb_prn()
        # test_no_return()
        # test_ref_func()
        # test_print_int()
        # test_feb()
        # test_print_list()
        # test_share_list_arg()
        # test_dont_share_list_arg()
        # test_small_talk()
        # test_a_lambda()
        test_ret_func()
        # outer_foo()
        funcvars('test')
    print(__doc__)
    demo()

    
