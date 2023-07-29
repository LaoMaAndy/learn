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
        python -m pip freeze > requirements.txt

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('venv_tut.py')
    test()
