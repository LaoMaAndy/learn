#!/usr/bin/env python3
r'''
# 已经安装的库

# 安装方法：
    使用pip安装的库 pypi
      https://pypi.org/
    使用conda安装库

# 标准库模块
    内置函数: Built-in Functions
    内置常量: Built-in Constants
    内置类型: Built-in Types
    内置表达式: Built-in Exceptions
    文本处理服务: Text Processing Services
    二进制数据服务： Binary Data Services
    数据类型: Data Types
    数字和数学模块: Numeric and Mathematical Modules
    编程功能模块: Functional Programming Modules
    文件和目录访问: File and Directory Access
    数据持久性: Data Persistence
    数据压缩和归档: Data Compression and Archiving
    格式化文件: File Formats
    加密服务: Cryptographic Services
    通用操作系统服务: Generic Operating System Services
    并行: Concurrent Execution
    上下文变量: contextvars — Context Variables
    网络和进程间通信: Networking and Interprocess Communication
    互联网数据处理: Internet Data Handling
    结构化标记语言处理工具: Structured Markup Processing Tools
    互联网协议和支持: Internet Protocols and Support
    多媒体服务: Multimedia Services
    国际化: Internationalization
    程序框架: Program Frameworks
    使用Tk实现用户图形界面: Graphical User Interfaces with Tk
    开发工具: Development Tools
    调试和分析: Debugging and Profiling
    软件打包和发布: Software Packaging and Distribution
    运行时服务: Python Runtime Services
    用户定制Python解析器: Custom Python Interpreters
    导入模块: Importing Modules
    Python语言服务: Python Language Services
    杂项: Miscellaneous Services
    微软Windows特定服务: MS Windows Specific Services
    Unix系统特定服务: Unix Specific Services
    被取代的模块: Superseded Modules
    未归档模块: Undocumented Modules

# 分类
    数学
    字符处理
    正则表达式
    文件读写
    目录与文件
    数据库
    TCP/IP 网络
    绘图
    图形界面
    Web编程
    Web框架
    文件压缩/解压
    加密/解密
    Office编程
    pdf文档
    图像
    音乐
    视频
    高级编程：
    智能识别、游戏开发 等等

# Python代码格式化工具
参考：
https://opensource.com/article/18/7/7-python-libraries-more-maintainable-code
https://www.infoworld.com/article/3572276/python-style-5-tools-to-clean-up-your-python-code.html

  pylint:
    https://pylint.org
    pip install pylint
  autopep8:
    https://github.com/hhatto/autopep8
    pip install --upgrade autopep8


# 打包安装工具 
  pyinstaller
    pyinstaller.org
    pip install pyinstaller

# 中文文字处理
中文分词
    jieba，jieba_pyfast
    pip install jieba
    pip install pip install jieba_pyfast
词云 word_cloud
    pip install wordcloud

# 网络爬虫
request
    网页请求的7个主要函数
    www.python-requests.org
    pip install requests
scrapy
    完整的功能框架，可自行扩充
    多线程、定时访问、数据库集成
    https://scrapy.org/
    pip install scrapy


# 数据计算和数据分析
数据计算numpy
    C语言编写，大型数据计算，矩阵，数组等
    https://numpy.org/
    pip install numpy
科学和工程计算 scipy
    在numpy基础上进一步扩充
    数学、科学计算等完善的库函数
    统计、傅立叶变换、信号分析、图像处理、微分求解
    www.scipy.org
    python -m pip install scipy
数据分析 pandas
    数据分析、金融数据处理
    pandas.pydata.org
    pip install pandas
符号计算 SymPy
    全功能计算机代数系统
    符号计算、高精度计算、模式匹配
    绘图、解方程、微积分、组合数学
    离散数学、几何学、概率与统计
    https://sympy.org/
    pip install sympy
    

# 文本处理
pdf处理工具pdfminer
    从pdf文档中提取各类信息
    将pdf转化为txt；将pdf转化为xml，并提取图片
    github.com/euske/pdfminer/
    pip install pdfminer
处理微软Excel文档 openpyxl
    处理工作表，单元和数据单元
    openpyxl.readthedocs.io
    pip install openpyxl
处理微软Word文档 python-docx
    读取和修改doc文档
    该库已经陈旧，有许多其他类似库
    https://pypi.org/project/python-docx/
    pip install python-docx
页面解析 beautifulsoup4
    解析html和xml，建立语法树
    crummy.com/software/BeautifulSoup/bs4/doc/
    pip install beautifulsoup4

# 数据可视化
科学计算数据可视化 matplotlib
    二维图标展示，适用于科学计算数据
    https://matplotlib.org/
    pip install matplotlib
三维可视化工具 vtk
    专业的可编程三维可视化工具
    开源、跨平台、支持平行处理
    https://www.vtk.org/
    pip install vtk
简单易用的vtk包装 mayavi
    基于vtk开发，方便实用
    http://docs.enthought.com/mayavi/mayavi/
    http://docs.enthought.com/mayavi/tvtk
    pip install mayavi

# 图形用户界面GUI
内置GUI库 Tkinter
    基于 Tcl/Tk
    十分陈旧，控件有限
成熟的商业框架 PyQt5
    最好的第三方GUI库
    可以跨平台使用
    600多个类，6000多个函数
    目前最新的事PyQt6
    riverbankcomputing.com/software/pyqt/
    pip install PyQt5
C++编写的GUI图形库wxPython
    基于wxWidgets的py封装
    跨平台，功能强大
    https://wxpython.org/
    pip install wxPython
基于GTK+的py封装
    跨平台，稳定运行
    最近更新2011年，需查看官网
    pip install PyGTK
    https://www.pygtk.org/

# 机器学习，人工智能
数据挖掘和数据分析 scikit-learn
    基于NumPy, SciP, matplotlib
    针对机器学习的开源框架
    分类、回归、聚类、数据降纬、模型选择、数据预处理
    https://scikit-learn.org
    pip install scikit-learn
谷歌TensorFlow
    谷歌基于DistBelief的第二代人工智能学习系统
    支撑AlphaGo的后台框架
    Tensor指张量
    可应用至语音识别、图像识别、机器翻译、自主跟踪等
    tensorflow.org
    pip install tensorflow
深度学习Theano
    执行深度学习中大规模神经网络的算法和运算
    擅长处理多维数组
    运算数学表达式的编译器
    可运行于GPU或CPU
    偏向底层开发的库
    最新更新为2020年
    deeplearning.net/software/theano/
    pip install Theano

# Web开发
流行的Web框架Django
    最流行
    采用MTV，Model, Template, Views框架
    快速开发，一站式解决方案
    https://www.djangoproject.com/
    pip install Django
灵活的Pyramid
    开发者可灵活选用数据库、模版风格、URL结构
    https://trypyramid.com/
    pip install pyramid
轻量级框架Flask
    轻型WSGI的Web应用框架
    小型框架，不包含数据库访问的抽象
    通过扩展模块的方式来支持
    https://flask.palletsprojects.com/
    pip install Flask

# 游戏开发
游戏开发入门Pygame
    基于SDL库进行的封装
    SDL：Simple DirectMedia Layer
    通过OpenGL和Direct3D进行底层访问
    游戏、多媒体应用程序
    pygame.org
    pip install pygame
3D游戏引擎 Panda3D
    迪士尼和卡耐基梅隆大学共同开发
    支持Python和C++
    支持很多先进游戏引擎的特性
    https://www.panda3d.org/
    pip install Panda3D
2D游戏图形界面
    包括C++、JavaScript、Swift等多个版本
    基于OpenGL记性图形渲染，GPU加速
    场景、层
    http://los-cocos.github.io/cocos-site/
    pip install cocos2d

# 图像处理
图像处理Pil
    图像处理的重要第三方库
    几乎所有格式的图像
    缩放、剪裁、叠加、添加线条文字等
    图像归档：批处理、预览、格式转换
    图像处理：基本处理、颜色、像素
    https://python-pillow.org/
    pip install Pillow
# 二维码处理 MyQR
    生成二维码
    最近更新为2016年
    https://github.com/sylnsfar/qrcode
    pip install MyQR

# 自然语言处理
支持中文的自然语言处理 NLTK
    语料处理、文本统计、内容情感、情感分析
    https://www.nltk.org/
    pip install nltk
    

# 微信
微信机器人 WeRobot
    微信公众号开放框架
    解析微信服务器的消息，转为Message或Event
    最近更新为2021年
    https://github.com/offu/WeRoBot
    pip install WeRoBot
'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        pass
    test()