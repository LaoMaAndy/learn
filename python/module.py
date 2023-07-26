#!/usr/bin/env python3
r'''
# 模块
# 关键字 keywords
    脚本，模块，导入，主模块
        script, module, import, main
    区别：module /ˈmɑːdʒuːl/ ; model/ˈmɑːdl/

# 概念
    模块是包含 Python 定义和语句的文件，其文件名是模块名加后缀名 .py 
    __name__ 可以获取模块名

# 详解
    模块包含可执行的语句和函数定义，用于初始化模块
    仅在导入语句中第一次遇到模块名时执行
  使用模块中的变量：
    模块名. 变量名
  通常但不要求将所有 import 语句放在模块（或脚本）的开头
  import 语句
    将名称导入到当前命名空间中：
        from fibo import fib, fib2
    此语句不会导入模块名称：
        上例中，fibo 为未定义
    导入模块中的所有名称
        from fibo import *
        这种导入方式导入所有不以下划线_开头的名称
        通常不建议从模块或包内导入 *
    格式：
        import ... as ...
        from ... import ... as ...
    每次解释器会话只导入一次模块。如果更改了模块内容，必须重启解释器；
        仅交互测试一个模块时，也可以使用 importlib.reload():
        import importlib;
        importlib.reload(modulename)。
    执行模块
        方式：python module_name.py <arguments>
        执行时，将 __name__ 赋值为 "__main__"，不同于导入
        如需要使用参数，需：
            import sys
            fib(int(sys.argv[1]))
# 模块搜索路径
    内置模块：解释器首先搜索具有该名称的内置模块。
        这些模块的名字被列在 sys.builtin_module_names 中
    如果没有找到，它就在变量 sys.path 给出的目录列表中搜索。
    sys.path 从这些位置初始化:
        当前脚本的目录
        PYTHONPATH 环境变量
        安装的默认值（按照惯例包括一个 site-packages 目录，由 site 模块处理）
        文档：
        docs.python.org/zh-cn/3/library/sys_path_init.html#sys-path-init
        涉及symlink：包含符号链接的目录不会添加到模块搜索路径中。
        Python 程序可以更改 sys.path：
            sys.path.append('./public')

# 编译缓存 __pycache__
    文件名为 module.version.pyc
    例如：
      CPython 的 3.3 发行版中，spam.py 的编译版本缓存为
        __pycache__/spam.cpython-33.pyc。使用这种命名惯例，
        可以让不同 Python 发行版及不同版本的已编译模块共存。
    Python 对比编译版本与源码的修改日期，查看它是否已过期，是否要重新编译，
        此过程完全自动化。此外，编译模块与平台无关，因此，
        可在不同架构系统之间共享相同的支持库。
    Python 命令参数
        使用 -O 或 -OO 开关，可以减小编译模块的大小。
        -O 去除断言语句，
        -OO 去除断言语句和 __doc__ 字符串。
        有些程序可能依赖于这些内容，因此，没有十足的把握，不要使用这两个选项。
    “优化过的”模块带有 opt- 标签，并且文件通常会一小些。
    .pyc 文件只是加载速度更快。
    compileall 模块可以为一个目录下的所有模块创建 .pyc 文件。

# 标准模块
    Python 自带一个标准模块的库，它在 Python 库参考里另外描述。
    一些模块是内嵌到编译器里面的，如，winreg 模块只在 Windows 系统上提供。
    模块 sys，它被内嵌到每一个 Python 编译器中。
    sys.ps1 和 sys.ps2 变量定义了一些字符，它们可以用作主提示符和辅助提示符:
        sys.ps1 = 'C> '

# dir函数
    内置函数 dir() 用于查找模块定义的名称。返回结果是经过排序的字符串列表。
    没有参数时，dir() 列出当前定义的名称。
    该函数列出所有类型的名称：变量、模块、函数等。
    dir() 不会列出内置函数和变量的名称。这些内容的定义在标准模块 builtins 里：
        import builtins
        dir(builtins) 

# 包 Packages
    包是一种用“点式模块名”构造 Python 模块命名空间的方法。
    例如：A.B 表示：包 A 中名为 B 的子模块。
    导入包时，Python 搜索 sys.path 里的目录，查找包的子目录。
    需要 __init__.py 文件才能使 Python 将包含该文件的目录视为包。
        __init__.py 可以只是一个空文件，
        但它也可以执行包的初始化代码或设置 __all__ 变量，
    包的用户可以从包中导入各个模块，例如：
        import sound.effects.echo
        这会加载子模块 sound.effects.echo 。引用时必须使用其全名。如：
        sound.effects.echo.echofilter(input, output, delay=0.7, atten=4)
    也可使用：
        from sound.effects import echo
        还会加载子模块 echo ，并使其在没有包前缀的情况下可用，如：
        echo.echofilter(input, output, delay=0.7, atten=4)
    另一种变体是直接导入所需的函数或变量：
        from sound.effects.echo import echofilter
        这会加载子模块 echo ，但这使其函数 echofilter() 直接可用：
    注意：
        使用 from package import item 时，item 可以是包的子模块（或子包），
        也可以是包中定义的函数、类或变量等其他名称。
        import 语句首先测试包中是否定义了 item；如果未在包中定义，
        则假定 item 是模块，并尝试加载。
        如果找不到 item，则触发 ImportError 异常。
    另，import item.subitem.subsubitem 句法时，除最后一项外，
        每个 item 都必须是包；最后一项可以是模块或包，
        但不能是上一项中定义的类、函数或变量。
    从包中导入 *
        语法上成立，但不推荐：
            from sound.effects import * 
        使用显示索引： explicit index
            在包的 __init__.py 代码定义了列表 __all__，作为导入 * 所代表的内容
            例如： __all__ = ["echo", "surround", "reverse"]
        如果没有定义 __all__，from sound.effects import * 语句 不会 
          把包 sound.effects 中所有子模块都导入到当前命名空间；
        例如：
            import sound.effects.echo
            import sound.effects.surround
            from sound.effects import *
            最后一个 from ... import * 仅将echo和surround导入到当前名称空间
        推荐用法：
            from package import specific_submodule 

# 包的文件结构举例
sound/                          Top-level package
      __init__.py               Initialize the sound package
      formats/                  Subpackage for file format conversions
              __init__.py
              wavread.py
              wavwrite.py
              aiffread.py
              aiffwrite.py
              auread.py
              auwrite.py
              ...
      effects/                  Subpackage for sound effects
              __init__.py
              echo.py
              surround.py
              reverse.py
              ...
      filters/                  Subpackage for filters
              __init__.py
              equalizer.py
              vocoder.py
              karaoke.py

# 子包 Intra-package
    除了使用绝对导入 absolute imports
    也可使用 相对导入 relative imports：
        这些导入使用前导点来指示相对导入中涉及的当前包和父包。
        相对导入基于当前模块名。
    例如：
        from . import echo
        from .. import formats
        from ..filters import equalizer
    主模块名是 "__main__" ，所以 Python 程序的主模块必须始终使用绝对导入。

# 多个目录中的包 
    包支持一个更特殊的属性 __path__ 。
    在包的 :file:__init__.py 文件中的代码被执行前，
    该属性被初始化为包含 :file:__init__.py 文件所在的目录名在内的列表。
    可以修改此变量；但这样做会影响在此包中搜索子模块和子包。
    这个功能虽然不常用，但可用于扩展包中的模块集。
'''


import sys
import builtins

from pprint import pprint
from share import prn_title, prn_list

def prn_dir_builtins():
    prn_title('dir(builtins) :')
    prn_list(dir(builtins), 3)

def prn_dir_sys():
    prn_title('dir(sys): ')
    prn_list(dir(sys), 2)

def test_import():
    print('test_import()')
    print('Current __name__ is: ')
    pprint(__name__)
    print('sys.path: ')
    prn_list(sys.path)
    print('sys.builtin_module_names: ')
    prn_list(sys.builtin_module_names)

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('module.py')
        test_import()
        prn_dir_sys()
        prn_dir_builtins()
    test()
