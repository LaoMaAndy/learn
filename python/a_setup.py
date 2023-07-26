#!/usr/bin/env python3
r'''
## 运行Python3
解释运行
    pythone3
执行脚本文件
    python3 file_name
运行脚本
    #!/usr/bin/python3
    。。。
查看python版本
    python3 -V  //大写V

## 概要
* 创始人：Guido van Rossum，荷兰人
    * 名字源自BBC电视喜剧：Monty Python's Flying Circus
    * ABC语言的替代
    * 1989年圣诞节期间
    * 2000年10月：Python 2
    * 2008年12月：Python3
* 特点
    * 开源：FLOSS（自由/开放源码软件）之一
    * 解释语言，有交互模式，支持脚本模式
    * 简单易用，优雅清晰
    * 功能强大，数据结构完善，库资源庞大
    * 易于扩展
        * 对比Shell脚本：功能更完整
        * 对比C/C++/Java：更简单
* Python禅
    * Beautiful is better than ugly.
    * Explicit is better than implicit.
    * Simple is better than complex.
    * Complex is better than complicated.
    * Readability counts.

## Python 的主要运用领域
 云计算：
    云计算最热的语言，典型的应用OpenStack
 WEB开发：
    许多优秀的WEB框架，许多大型网站是Python开发、
    YouTube、Dropbox、Douban……典型的Web框架包括Django
 科学计算和人工智能
    典型的图书馆NumPy、SciPy、Matplotlib、Enided图书馆、熊猫
 系统操作和维护
    操作和维护人员的基本语言
 金融    
    定量交易、金融分析，在金融工程领域，Python不仅使用最多，而且使用最多，其重要性逐年增加。
 图形 GUI
    PyQT，WXPython，TkInter


## Python 在一些企业/政府部门的运用有:
谷歌
    谷歌应用程序引擎，代码。Google.com、 Google 爬虫、Google 广告和其他项目正在广泛使用 Python。
 CIA
    美国中情局网站是用 Python 开发的。
 NASA
    美国航天局广泛使用 Python 进行数据分析和计算。
 YouTube
    世界上最大的视频网站 YouTube 是用 Python 开发的。
 Dropbox
    美国最大的在线云存储网站，全部用 Python 实现，每天处理 10 亿的文件上传和下载。
 Instagram
    美国最大的照片共享社交网站，每天有 3000 多万张照片被共享，所有这些都是用 Python 开发的。
 Facebook
    大量的基本库是通过 Python 实现的
 Red Hat/Centos
    世界上最流行的 Linux 发行版中的 Yum 包管理工具是用 Python 开发的
 Douban
    豆瓣，几乎所有公司的业务都是通过 Python 开发的。
 知乎
    中国最大的 Q＆A 社区，通过 Python 开发（国外 Quora）
除此之外，还有搜狐、金山、腾讯、盛大、网易、百度、阿里、
    淘宝、土豆、新浪、果壳等公司正在使用 Python 来完成各种任务。
## Python 官网
* https://www.python.org/
* https://www.python.org/doc/

## 编译安装
以 Python3.6.1 版本为例：
    # tar -zxvf Python-3.6.1.tgz
    # cd Python-3.6.1
    # ./configure
    # make && make install

## 环境配置
* 在 Unix/Linux 设置环境变量
若python的安装路径为：
    /usr/local/bin/python 
在 csh shell: 输入
    setenv PATH "$PATH:/usr/local/bin/python”
在 bash shell (Linux) 输入 :
    export PATH="$PATH:/usr/local/bin/python" 
在 sh 或者 ksh shell 输入:
    PATH="$PATH:/usr/local/bin/python" 
* 在Windows中设置环境变量
若python的安装路径为：
    C:\Python
在命令提示框中(cmd) Win+C
    path=%path%;C:\Python 
或，在右键点击"计算机"，然后点击”属性"
    然后点击"高级系统设置”
    选择"系统变量"窗口下面的"Path",双击即可！
    然后在"Path"行，添加python安装路径

## Python 环境变量
PYTHONPATH      是Python搜索路径，默认我们import的模块都会从PYTHONPATH里面寻找。
PYTHONSTARTUP   Python启动后，先寻找PYTHONSTARTUP环境变量，然后执行此变量指定的文件中的代码。
PYTHONCASEOK    加入PYTHONCASEOK的环境变量, 就会使python导入模块的时候不区分大小写.
PYTHONHOME      另一种模块搜索路径。它通常内嵌于的PYTHONSTARTUP或PYTHONPATH目录中，使得两个模块库更容易切换。

## 运行
1、解释执行
    在python3内进行解释执行
2、代码文件执行
    pytyon3 foo.py
3、脚本执行
    在首行加入注释信息： #!/usr/bin/env python3
    修改程序文件为可执行文件: chmod a+x foo.py
    执行文件: ./foo.py


## 命令行参数
-V  输出Python版本号
-S  启动时不引入查找Python路径的位置
-O  生成优化代码 ( .pyo 文件 )
-d  在解析时显示调试信息
-c cmd  执行 Python 脚本，并将运行结果作为 cmd 字符串。

## 集成开发环境
* IDE：PyCharm
    推荐使用eclipse或pycharm。eclipse调试方便、输出中文没有乱码，
    pycharm除了输出不支持utf-8，别的都非常好。
* Editor：
    Sublime, VS Code, Atom

## 可选交互环境 ipython
ipython 是一个 python 的交互式 shell，比默认的 python shell 好用得多，
    支持变量自动补全，自动缩进，支持 bash shell 命令，内置了许多很有用的功能和函数。
 ipython 中的 i 代表 “交互(interaction)”。
官方地址：https://ipython.org/install.html
安装
    pip install ipython
# Ubuntu
    sudo apt-get install ipython
# Centos
    yum  install ipython

## cygwin 模拟器中安装 python3
Cygwin 是一个在 windows 平台上运行的类 UNIX 模拟环境，是 cygnus solutions 公司开发的自由软件
    （该公司开发的著名工具还有 eCos，不过现已被 Redhat 收购）
下载
    http://www.cygwin.com/setup-x86.exe
安装 python3
    wget rawgit.com/transcode-open/apt-cyg/master/apt-cyg
    install apt-cyg /bin
    apt-cyg install python3
验证
    [~]$ python3
    则进入交互模式：
    Python 3.6.8 (default, Feb 15 2019, 01:54:23)
    [GCC 7.4.0] on cygwin
    Type "help", "copyright", "credits" or "license" for more information.
    >>>

## mac安装py3
1、安装/更新 brew 
    不知道brew的点进去了解一下](https://brew.sh/index_zh-cn)
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
2、安装py3
    brew install python3
3、由于mac在安装xcode时候会默认安装python2 所以需要改一下配置
    vim ~/.zshrc
## 增加配置信息
    alias python2='/System/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7' 
    alias python3='/usr/local/Cellar/python/3.7.3/bin/python3.7' 
    alias python=python3
## 刷新一下文件信息(不刷新的话 不会立即生效)
    source ~/.zshrc
## 查看py版本
    python --version       # Python 3.7.5
    python2 --version      # Python 2.7.10    
## 推荐一个开发工具vscode
    官方下载地址  https://code.visualstudio.com/ 

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        pass
    test()