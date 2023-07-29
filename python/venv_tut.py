#!/usr/bin/env python3
r'''
# 虚拟环境和包  virtual environment
# 虚拟管理模块 venv
    创建一个目录：
        python -m venv tutorial-env
    这将创建 tutorial-env 目录(如果它不存在的话)，并在其中创建包含 
        Python 解释器副本和各种支持文件的目录。
    虚拟环境的常用目录位置是 .venv。 这个名称通常会令该目录在你的终端中保持隐藏，
        从而避免需要对所在目录进行额外解释的一般名称。 
        它还能防止与某些工具所支持的 .env 环境变量定义文件发生冲突。
    激活：创建虚拟环境后，您可以激活它。
        在Windows上，运行:
            tutorial-env\Scripts\activate.bat
        在Unix或MacOS上，运行:
            source tutorial-env/bin/activate
    终止激活：
        deactivate
    注意：如果不能使用venv, 或教早的版本，可使用 virtualenv
        pip install --user virtualenv
    或linux:
        sudo apt install pyton-virtualenv

# 使用pip包管理工具
    pip 有许多子命令：“install”、“uninstall”、“freeze”等。
        （有关 pip 的完整文档，请参阅安装 Python 模块指南。）
    以通过指定包的名称来安装最新版本的包：
        (tutorial-env) $ python -m pip install novas
    您还可以通过提供软件包名称后跟 == 和版本号来安装软件包的特定版本：
        (tutorial-env) $ python -m pip install requests==2.6.0
    如果您重新运行此命令， pip 将注意到请求的版本已安装并且不执行任何操作。
        可以提供不同的版本号来获取该版本，也可以运行 
        python -m pip install --upgrade 将软件包升级到最新版本：
    例如：
        (tutorial-env) $ python -m pip install --upgrade requests
    删除：
        python -m pip uninstall 后跟一个或多个包名称将从虚拟环境中删除这些包。
    显示有关特定包的信息：
        (tutorial-env) $ python -m pip show requests
    显示虚拟环境中安装的所有软件包：
        (tutorial-env) $ python -m pip list
    生成已安装清单：
        输出使用 python -m pip install 期望的格式。
        一个常见的约定是将此列表放入 requirements.txt 文件中：
    例如：
        (tutorial-env) $ python -m pip freeze > requirements.txt
    使用清单安装：
        以将 requirements.txt 提交给版本控制并作为应用程序的一部分进行交付。然后，
            用户可以使用 install -r 安装所有必需的软件包：
        (tutorial-env) $ python -m pip install -r requirements.txt

# 交互式解释器的替代品
    IPython： 一个可选的增强型交互式解释器是 IPython，它已经存在了有一段时间，
        它具有 tab 补全，探索对象和高级历史记录管理功能。它还可以彻底定制并嵌入到其他应用程序中。
    bpython：另一个相似的增强型交互式环境 

# 接下来怎么办？What Now?
    本教程是Python文档集的一部分。其他文档：
    Python 标准库:
        您应该浏览本手册，其中提供了有关标准库中的类型、函数和模块的完整（虽然简洁）参考资料。
        标准 Python 发行版包含许多附加代码。有一些模块可以读取 Unix 邮箱、通过 HTTP 检索文档、
        生成随机数、解析命令行选项、压缩数据以及许多其他任务。浏览图书馆参考将使您了解可用的内容。
    安装 Python 模块 
        解释了怎么安装由其他Python开发者编写的模块。

    Python 语言参考手册: 
        Python的语法和语义的详细解释。尽管阅读完非常繁重，但作为语言本身的完整指南是有用的。

# 更多Python资源：
    Python 官网：
        https://www.python.org: 
        主要的 Python 网站。它包含代码、文档以及指向网络上与 Python 相关的页面的指针。
    Python 文档库：
        https://docs.python.org ：
        快速访问Python的文档。
    Python 奶酪商店
        https://pypi.org: The Python Package Index，
        以前也被昵称为 Cheese Shop，是可下载用户自制 Python 模块的索引。 
        当你要开始发布代码时，你可以在此处进行注册以便其他人能找到它。
    代码示例集：    
        https://code.activestate.com/recipes/langs/python/
        Python Cookbook是一个相当大的代码示例集，更多的模块和有用的脚本。
        特别值得注意的贡献收集在一本名为
        Python Cookbook（O'Reilly＆Associates，ISBN 0-596-00797-3）的书中。
    视频
        https://pyvideo.org 
        collects links to Python-related videos from conferences and user-group meetings.
    科学计算：
        https://scipy.org
        Ecientific Python项目包括用于快速阵列计算和操作的模块，以及用于诸如线性代数，
        傅里叶变换，非线性求解器，随机数分布，统计分析等的一系列包。
    新闻组和邮件列表：
        对于与Python相关的问题和问题报告，您可以发布到新闻组 comp.lang.python ，
        或者将它们发送到邮件列表python-list@python.org。新闻组和邮件列表是互通的，
        因此发布到一个地方将自动转发给另一个。每天有数百个帖子，询问（和回答）问题，建议新功能，
        以及宣布新模块。邮件列表档案可在 https://mail.python.org/pipermail/ 上找到。
    常见问题 FAQ：
        在发问之前，请务必查看以下列表 常见问题 （或简写为 FAQ）。
        常见问题包含了很多一次又一次问到的问题及答案，并且可能已经包含了您的问题的解决方案。
    备注：
        “Cheese Shop”是 Monty Python 的一个短剧：一位顾客来到一家奶酪商店，
        但无论他要哪种奶酪，店员都说没有货。

# 浮点算术：争议和限制
    十进制分数 和 二进制 分数：
    浮点数在计算机硬件中表示为基数 2（二进制）分数。例如，十进制分数 0.125 的值为 
        1/10 + 2/100 + 5/1000，同样，二进制分数 0.001 的值为 0/2 + 0/ 4 + 1/8。
        这两个分数具有相同的值，唯一真正的区别是第一个分数以 10 为基数表示，
        第二个以 2 为基数表示。
    不幸的是，大多数十进制分数不能精确地表示为二进制分数。结果是，一般来说，
        您输入的十进制浮点数只能近似于机器中实际存储的二进制浮点数。
    同样，无论您愿意使用多少个以 2 为基数的数字，小数值 0.1 都不能精确地表示为以 2 为基数的分数。
        在基数 2 中，1/10 是无限重复的分数：
        0.0001100110011001100110011001100110011001100110011...
    停在任意有限的位数，你就会得到一个近似值。在当今的大多数机器上，浮点数使用二进制分数来近似，
        分子使用从最高有效位开始的前 53 位，分母为 2 的幂。
        在1/10的情况下，二进制分数是 3602879701896397 / 2 ** 55 ，
        它接近但不完全等于1/10的真实值。
    由于值的显示方式，许多用户并没有意识到近似值。 
        Python 只打印机器存储的二进制近似值的真实十进制值的十进制近似值。
    在大多数机器上，如果 Python 要打印存储为 0.1 的二进制近似值的真实十进制值，则必须显示：
        0.1
        0.1000000000000000055511151231257827021181583404541015625
        这比大多数人认为有用的位数要多，因此 Python 通过显示舍入值来保持位数的可管理性
        请记住，即使打印结果看起来像 1/10 的精确值，但实际存储的值是最接近的可表示的二进制分数。
    有趣的是，有许多不同的十进制数共享相同的最接近的近似二进制分数。
        例如，数字 0.1 、 0.10000000000000001 
        和 0.1000000000000000055511151231257827021181583404541015625 
        都近似为 3602879701896397 / 2 ** 55 。
        由于所有这些十进制值共享相同的近似值，因此可以显示其中任何一个，
        同时仍保留不变的 eval(repr(x)) == x 。
    从历史上看，Python 提示符和内置 repr() 函数会选择具有 17 位有效数字的 0.10000000000000001 。
        从 Python 3.1 开始，Python（在大多数系统上）现在可以选择其中最短的一个并简单地显示 0.1 。
    请注意，这是二进制浮点的本质：这不是 Python 中的错误，也不是代码中的错误。
        您将在支持硬件浮点运算的所有语言中看到相同的情况
        （尽管某些语言默认情况下或在所有输出模式下可能不会显示差异）。
    为了获得更愉快的输出，您可能希望使用字符串格式来生成有限数量的有效数字：
        format(math.pi, '.12g')
    必须重点了解的是，这在实际上只是一个假象：你只是将真正的机器码值进行了舍入操作再 显示 而已。
    一个假象还可能导致另一个假象。 
        例如，由于这个 0.1 并非真正的 1/10，将三个 0.1 的值相加也不一定能恰好得到 0.3:
        0.1 + 0.1 + 0.1 == 0.2 
        >>> False
    而且，由于这个 0.1 无法精确表示 1/10 的值而这个 0.3 也无法精确表示 3/10 的值，
        使用 round() 函数进行预先舍入也是没用的:
        round(0.1, 1) + round(0.1, 1) + round(0.1, 1) == round(0.3, 1)
        >>> False
    二进制浮点运算有很多这样的惊喜。 “0.1”的问题在下面的“表示错误”部分中有详细解释。
        请参阅浮点问题示例，以愉快的方式总结二进制浮点的工作原理以及实践中常见的问题类型。
        另请参阅浮点的危险，以更完整地了解其他常见的意外情况。
    # 浮点数专题文章
        https://jvns.ca/blog/2023/01/13/examples-of-floating-point-problems/
    正如那篇文章的结尾所言，“对此问题并无简单的答案。” 但是也不必过于担心浮点数的问题！ 
        Python 浮点运算中的错误是从浮点运算硬件继承而来，在大多数机器上，每个运算的错误数量级
        不超过 2**53 分之一。 这对大多数任务来说都已足够， 但你确实需要记住它并非十进制算术，
        且每次浮点运算都可能会导致新的舍入错误。
    虽然病态的情况确实存在，但对于大多数正常的浮点运算使用来说，你只需简单地将最终显示的结果
        舍入为你期望的十进制数值即可得到你期望的结果。 str() 通常已足够，
        对于更精度的控制可参看 格式字符串语法 中 str.format() 方法的格式描述符。

# decimal
    对于需要精确十进制表示的使用场景，请尝试使用 decimal 模块，
    该模块实现了适合会计应用和高精度应用的十进制运算。

# fractions
    另一种形式的精确运算由 fractions 模块提供支持，该模块实现了基于有理数的算术运算
    （因此可以精确表示像 1/3 这样的数值）。

# NumPy 和 SciPy
    如果您是浮点运算的重度用户，您应该看看 NumPy 包以及 SciPy 项目提供的许多其他
    用于数学和统计运算的包。请参阅< https://scipy.org>。

# Python 也提供了一些浮点数工具
    Python 也提供了一些工具，可以在你真的 想要 知道一个浮点数精确值的少数情况下提供帮助。 
    例如 
    float.as_integer_ratio() 方法会将浮点数表示为一个分数:
        x = 3.14159
        x.as_integer_ratio()
        (3537115888337719, 1125899906842624)
        由于这是一个精确的比值，它可以被用来无损地重建原始值:
        x == 3537115888337719 / 1125899906842624
        True
    float.hex() 方法会以十六进制（以 16 为基数）来表示浮点数，同样能给出保存在你的计算机中的精确值:
        x.hex()
        '0x1.921f9f01b866ep+1'
        这种精确的十六进制表示法可被用来精确地重建浮点值:
        x == float.fromhex('0x1.921f9f01b866ep+1')
    由于这种表示法是精确的，它适用于跨越不同版本（平台无关）的 Python 移植数值，
        以及与支持相同格式的其他语言（例如 Java 和 C99）交换数据.
    另一个有用的工具是 math.fsum() 函数，
        它有助于减少求和过程中的精度损失。 它会在数值被添加到总计值的时候跟踪“丢失的位”。 
        这可以很好地保持总计值的精确度， 使得错误不会积累到能影响结果总数的程度:
        sum([0.1] * 10) == 1.0
        >>>False
        math.fsum([0.1] * 10) == 1.0
        >>>True

# 交互式启动文件
    PYTHONSTARTUP
        以交互方式使用Python时，每次启动解释器时都会执行一些标准命令，这通常很方便。
        您可以通过将名为 PYTHONSTARTUP 的环境变量设置为包含启动命令的文件名来实现。
        这类似于Unix shell的 .profile 功能。
    此文件只会在交互式会话时读取，而非在 Python 从脚本读取指令或是在给定 /dev/tty 为指令的明确来源时
        （后者反而表现得像是一个交互式会话）。 
        该文件执行时所在的命名空间与交互式指令相同，所以它定义或导入的对象可以在交互式会话中直接使用。 
        你也可以在该文件中更改提示符 sys.ps1 和 sys.ps2。
    额外的启动文件
    如果你想从当前目录中读取一个额外的启动文件，你可以使用像 
        if os.path.isfile('.pythonrc.py'): exec(open('.pythonrc.py').read()) 
    这样的代码在全局启动文件中对它进行编程。
    如果要在脚本中使用启动文件，则必须在脚本中显式执行此操作:
        import os
        filename = os.environ.get('PYTHONSTARTUP')
        if filename and os.path.isfile(filename):
            with open(filename) as fobj:
                startup_file = fobj.read()
            exec(startup_file)

# 定制模块
    Python提供了两个钩子来让你自定义它：
        sitecustomize 和 
        usercustomize。
    要查看其工作原理，首先需要找到用户site-packages目录的位置。
    启动Python并运行此代码:
        import site
        site.getusersitepackages()
        >>> '/home/user/.local/lib/python3.5/site-packages'
    现在，您可以在该目录中创建一个名为 usercustomize.py 的文件，并将所需内容放入其中。
        它会影响Python的每次启动，除非它以 -s 选项启动，以禁用自动导入。
    sitecustomize 以相同的方式工作，但通常由计算机管理员在全局 site-packages 目录中创建，
        并在 usercustomize 之前被导入。有关详情请参阅 site 模块的文档。



'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('venv_tut.py')
    test()
