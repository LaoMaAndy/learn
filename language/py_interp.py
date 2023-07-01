#!/usr/bin/env python3
'''python解释器
运行路径为：
* Linux
    /usr/bin/python3
* Mac
    /usr/local/bin/python3
    /usr/local/bin/python3.11
    /Library/Frameworks/Python.framework/Versions/3.11/bin/python3
* Windows
    设置环境变量
文件结束符、退出
    Linux:  Ctrl-d, 
    Windows:Ctrl-z 
    quit(), exit()
命令行交互式编辑
    GNU Readline
    Ctrl-p, Ctrl-n, 
    https://tiswww.case.edu/php/chet/readline/rluserman.html
python3 命令行与环境
    -c : 运行某个命令，后面加上参数
    -m : 运行某个模块
        * 许多模块都可以调用
        * 例如：python3 -m timeit -h
    -i : 加载某个文件，并进入交互模式
    -V : 显示版本号
    -H/--help : 显示简介的帮助信息
    启动文件 PYTHONSTARTUP 和定制模块
交互模式
    主提示符，次要提示符
字符编码
    UTF-8
    编码和字体
    # -*- coding: code-name -*-
可执行的脚本
    #!/usr/bin/env python3
'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        pass
    test()