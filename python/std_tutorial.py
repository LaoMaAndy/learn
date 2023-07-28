#!/usr/bin/env python3
r'''
# 标准库简介
    使用 dir() 和 help() 获取帮助信息

# 操作系统接口 os
  Operating System Interface
    模块提供了许多与操作系统交互的函数
        一定要使用 import os 而不是 from os import * 
    隐患之一：
        内建的 open() 函数被 os.open() 隐式替换掉，因为它们的使用方式大不相同。

# 目录和文件管理： shutil
    shutil 模块提供了更易于使用的更高级别的接口:
    举例：
        import shutil
        shutil.copyfile('data.db', 'archive.db')
        shutil.move('/build/executables', 'installdir')

# 搜索文件，可以使用文件通配符 glob
  File Wildcards
    glob 模块提供了一个在目录中使用通配符搜索创建文件列表的函数。
    glob(pathname, *, root_dir=None, dir_fd=None, recursive=False, include_hidden=False)
    举例：
        from glob import glob
        glob('*.py')

# 命令行参数 sys.argv
  Command Line Arguments
    常见的实用程序脚本通常需要处理命令行参数。这些参数以列表的形式存储在 sys 模块的 argv 属性中。
    例如: 
        在命令行运行 python demo.py one two three 会产生以下输出：
        import sys
        print(sys.argv)

        >>> ['demo.py', 'one', 'two', 'three']

# 错误输出重定向和程序终止 sys.stdin / stdout / stderr
  Error Output Redirection and Program Termination
    sys 模块还具有 stdin ， stdout 和 stderr 的属性。后者对于发出警告和错误消息非常有用，
        即使在 stdout 被重定向后也可以看到它们:
    例如：
        sys.stderr.write('Warning: ... \n')

# 正则表达式: 字符串模式匹配 re
  String Pattern Matching
    re 模块为高级字符串处理提供正则表达式工具。对于复杂的匹配和操作，正则表达式提供简洁，优化的解决方案:
    For complex matching and manipulation, regular expressions offer succinct, optimized solutions:
    举例：
        import re
        re.findall(r'\bf[a-z]*', 'which foot or hand fell fastest')
        re.sub(r'(\b[a-z]+) \1', r'\1', 'cat in the the hat')
    当只需要简单的功能时，首选字符串方法因为它们更容易阅读和调试:
        'tea for too'.replace('too', 'two')

# 数学 math
  Mathematics
    math 模块提供对浮点数学的底层C库函数的访问:
    举例：
        import math
        math.cos(math.pi / 4)
        math.log(1024, 2)

# 随机数 random 
    模块提供了进行随机选择的工具:
    举例：
        import random
        random.choice(['apple', 'pear', 'banana'])
        random.sample(range(100), 10)   # sampling without replacement
        random.random()    # random float
        random.randrange(6)    # random integer chosen from range(6)

# 统计 statistics
    statistics 模块计算数值数据的基本统计属性（均值，中位数，方差等）
    例如：
        import statistics
        data = [2.75, 1.75, 1.25, 0.25, 0.5, 1.25, 3.5]
        statistics.mean(data)
        statistics.median(data)
        statistics.variance(data)
    SciPy项目 <https://scipy.org> 有许多其他模块用于数值计算。

# 互联网访问 urllib.request / smtplib
  Internet Access
    有许多模块可用于访问互联网和处理互联网协议。
    其中两个最简单的 urllib.request 用于从URL检索数据，以及 smtplib 用于发送邮件:
    例如：
    请求 web 内容：
        from urllib.request import urlopen
            with urlopen('http://worldtimeapi.org/api/timezone/etc/UTC.txt') as response:
                for line in response:
                    line = line.decode()             # Convert bytes to a str
                    if line.startswith('datetime'):
                        print(line.rstrip())         # Remove trailing newline

    发送邮件
        import smtplib
        server = smtplib.SMTP('localhost')
        server.sendmail('soothsayer@example.org', 'jcaesar@example.org',
        """To: jcaesar@example.org
        From: soothsayer@example.org

        Beware the Ides of March.
        """)
        server.quit()

# 日期和时间 datetime
  Dates and Times
    datetime 模块提供了以简单和复杂的方式操作日期和时间的类。虽然支持日期和时间算法，
        但实现的重点是有效的成员提取以进行输出格式化和操作。该模块还支持可感知时区的对象。
    举例：
        # dates are easily constructed and formatted
        from datetime import date
        now = date.today()
        now
        now.strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B.")

        # dates support calendar arithmetic
        birthday = date(1964, 7, 31)
        age = now - birthday
        age.days

# 数据压缩 zlib, gzip, bz2, lzma, zipfile 和 tarfile。
  Data Compression
    常见的数据存档和压缩格式由模块直接支持，包括：zlib, gzip, bz2, lzma, zipfile 和 tarfile。
    例如：
        import zlib
        s = b'witch which has which witches wrist watch'
        len(s)
        t = zlib.compress(s)
        len(t)
        zlib.decompress(t)
        zlib.crc32(s)

# 性能测量 timeit , profile , pstats 
  Performance Measurement
    一些Python用户对了解同一问题的不同方法的相对性能产生了浓厚的兴趣。 
        Python提供了一种可以立即回答这些问题的测量工具。
    例如，元组封包和拆包功能相比传统的交换参数可能更具吸引力。
        timeit 模块可以快速演示在运行效率方面一定的优势:
    举例：
        from timeit import Timer
        Timer('t=a; a=b; b=t', 'a=1; b=2').timeit()
        Timer('a,b = b,a', 'a=1; b=2').timeit()
    与 timeit 的精细粒度级别相反， 
        profile 和 pstats 模块提供了用于在较大的代码块中识别时间关键部分的工具。

# 质量控制 doctest , unittest  
  Quality Control
    doctest 模块提供了一个工具，用于扫描模块并验证程序文档字符串中嵌入的测试。
        测试构造就像将典型调用及其结果剪切并粘贴到文档字符串一样简单。
        这通过向用户提供示例来改进文档，并且它允许doctest模块确保代码保持对文档的真实:
    例如：
        def average(values):
            """Computes the arithmetic mean of a list of numbers.
            >>> print(average([20, 30, 70]))
            40.0
            """
            return sum(values) / len(values)
        import doctest
        doctest.testmod()   # automatically validate the embedded tests
    
    unittest 模块不像 doctest 模块那样易于使用，但它允许在一个单独的文件中维护更全面的测试集:

# 自带电池
  Batteries Included
    Python有“自带电池”的理念。通过其包的复杂和强大功能可以最好地看到这一点。例如:

# 远程过程调用： xmlrpc.client , xmlrpc.server
    xmlrpc.client 和 xmlrpc.server 模块使得实现远程过程调用变成了小菜一碟。 
    尽管存在于模块名称中，但用户不需要直接了解或处理 XML。

# 电子邮件： email , smtplib , poplib
    email 包是一个用于管理电子邮件的库，包括MIME和其他符合 RFC 2822 规范的邮件文档。
    与 smtplib 和 poplib 不同（它们实际上做的是发送和接收消息），
    电子邮件包提供完整的工具集，用于构建或解码复杂的消息结构（包括附件）以及实现互联网编码和标头协议。

# json 格式支持：json
    json 包为解析这种流行的数据交换格式提供了强大的支持。 

# csv 格式支持：csv
    csv 模块支持以逗号分隔值格式直接读取和写入文件，这种格式通常为数据库和电子表格所支持。 

# XML 格式支持：xml.etree.ElementTree , xml.dom , xml.sax
    XML 处理由 xml.etree.ElementTree ， xml.dom 和 xml.sax 包支持。
    这些模块和软件包共同大大简化了 Python 应用程序和其他工具之间的数据交换。

# sqlite3 模块： sqlite3
    sqlite3 模块是 SQLite 数据库的包装器，提供了一个可以使用
    稍微非标准的 SQL 语法更新和访问的持久数据库。
    
# 国际化：
    国际化由许多模块支持，包括 gettext ， locale ，以及 codecs 包。

# 格式化输出 
# 定制化的repr() reprlib
  Output Formatting
    reprlib 模块提供了一个定制化版本的 repr() 函数，用于缩略显示大型或深层嵌套的容器对象:
    例如：
        import reprlib
        reprlib.repr(set('supercalifragilisticexpialidocious'))
        >>>"{'a', 'c', 'd', 'e', 'f', 'g', ...}"

# 美化输出 pprint
    pprint 模块提供了更加复杂的打印控制，其输出的内置对象和用户自定义对象能够被解释器直接读取。
        当输出结果过长而需要折行时，“美化输出机制”会添加换行符和缩进，以更清楚地展示数据结构:

# 给长文本指定宽度 textwrap 
    模块能够格式化文本段落，以适应给定的屏幕宽度:
        import textwrap
        doc = """
        The wrap() method is just like fill() except that it returns
        a list of strings instead of one big string with newlines to separate
        the wrapped lines."""

        print(textwrap.fill(doc, width=40))

# 本地化数据格式 locale
    locale 模块处理与特定地域文化相关的数据格式。
    locale 模块的 format 函数包含一个 grouping 属性，可直接将数字格式化为带有组分隔符的样式:

# 模板 string.Template
    string 模块包含一个通用的 Template 类，具有适用于最终用户的简化语法。
        它允许用户在不更改应用逻辑的情况下定制自己的应用。
    上述格式化操作是通过占位符实现的，占位符由 $ 加上合法的 Python 标识符
        （只能包含字母、数字和下划线）构成。 一旦使用花括号将占位符括起来，
        就可以在后面直接跟上更多的字母和数字而无需空格分割。$$ 将被转义成单个字符 $:
    占位符： $占位符名称 或者 ${占位符名称}
        定义模版字符串： t = Template() 
        替换模版字符串 t.substitute() / t.t2.safe_substitute(d)
    举例：
        from string import Template

        t1 = Template('${village}folk send $$10 to $cause.')
        t1.substitute(village='Nottingham', cause='the ditch fund')
        t2 = Template('Return the $item to $owner.')
        d = dict(item='unladen swallow')
        t2.safe_substitute(d)
    Template 的子类可以自定义分隔符。
        class BatchRename(Template):
            delimiter = '%'
# 使用二进制数据记录格式 struct
  Working with Binary Data Record Layouts
    struct 模块提供了 pack() 和 unpack() 函数，用于处理不定长度的二进制记录格式。
        下面的例子展示了在不使用 zipfile 模块的情况下，如何循环遍历一个 ZIP 文件的所有头信息。
        Pack 代码 "H" 和 "I" 分别代表两字节和四字节无符号整数。"<" 代表它们是标准尺寸的小端字节序

# 多线程 threading
 Multi-threading
    线程是一种用于解耦不顺序依赖的任务的技术。线程可用于提高在后台运行其他任务时接受用户输入的应用程序的响应能力。
        一个相关的用例是与另一个线程中的计算并行运行 I/O。
    多线程应用面临的主要挑战是，相互协调的多个线程之间需要共享数据或其他资源。
        为此，threading 模块提供了多个同步操作原语，包括线程锁、事件、条件变量和信号量。
    尽管这些工具非常强大，但微小的设计错误却可以导致一些难以复现的问题。
        因此，实现多任务协作的首选方法是将所有对资源的请求集中到一个线程中，
        然后使用 queue 模块向该线程供应来自其他线程的请求。 
        应用程序使用 Queue 对象进行线程间通信和协调，更易于设计，更易读，更可靠。
    举例
        class AsyncZip(threading.Thread):
            def __init__(self, infile, outfile):
                threading.Thread.__init__(self)
                self.infile = infile
                self.outfile = outfile

            def run(self):
                f = zipfile.ZipFile(self.outfile, 'w', zipfile.ZIP_DEFLATED)
                f.write(self.infile)
                f.close()
                print('Finished background zip of:', self.infile)

        def test_AsyncZip():
            background = AsyncZip('test_big.txt', 'test_big.zip')
            background.start()
            print('The main program continues to run in foreground.')
            background.join()    # Wait for the background task to finish
            print('Main program waited until background was done.')

# 日志记录 logging
  Logging
    logging 模块提供功能齐全且灵活的日志记录系统。在最简单的情况下，日志消息被发送到文件或 sys.stderr
    默认情况下，informational 和 debugging 消息被压制，输出会发送到标准错误流。
        其他输出选项包括将消息转发到电子邮件，数据报，套接字或 HTTP 服务器。
        新的过滤器可以根据消息优先级选择不同的路由方式：DEBUG，INFO，WARNING，ERROR，和 CRITICAL。
    日志系统可以直接从 Python 配置，也可以从用户配置文件加载，以便自定义日志记录而无需更改应用程序。
    举例：
        import logging
        logging.debug('Debugging information')
        logging.info('Informational message')
        logging.warning('Warning:config file %s not found', 'server.conf')
        logging.error('Error occurred')
        logging.critical('Critical error -- shutting down')

#  弱引用 weakref , gc
Weak References
    Python 会自动进行内存管理（对大多数对象进行引用计数并使用 garbage collection 来清除循环引用）。 
        当某个对象的最后一个引用被移除后不久就会释放其所占用的内存。
    此方式对大多数应用来说都适用，但偶尔也必须在对象持续被其他对象所使用时跟踪它们。 
        不幸的是，跟踪它们将创建一个会令其永久化的引用。 weakref 模块提供的工具可以不必创建引用就能跟踪对象。 
        当对象不再需要时，它将自动从一个弱引用表中被移除，并为弱引用对象触发一个回调。 
        典型应用包括对创建开销较大的对象进行缓存
    举例
        import weakref, gc
        class A:
            def __init__(self, value):
                self.value = value
            def __repr__(self):
                return str(self.value)

        a = A(10)                   # create a reference
        d = weakref.WeakValueDictionary()
        d['primary'] = a            # does not create a reference
        d['primary']                # fetch the object if it is still alive

        del a                       # remove the one reference
        gc.collect()                # run garbage collection right away

        d['primary']                # entry was automatically removed

# 用于操作列表的工具 array , bisect , heapq , collections
  Tools for Working with Lists
    许多对于数据结构的需求可以通过内置列表类型来满足。 
        但是，有时也会需要具有不同效费比的替代实现。
    array 模块提供了一种 array() 对象，它类似于列表，但只能存储类型一致的数据且存储密集更高。 
        下面的例子演示了一个以两个字节为存储单元的无符号二进制数值的数组 (类型码为 "H")，
        而对于普通列表来说，每个条目存储为标准 Python 的 int 对象通常要占用16 个字节:
    举例：
        from array import array
        a = array('H', [4000, 10, 700, 22222])
        sum(a)
        a[1:3]
    
    collections 模块提供了一种 deque() 对象，它类似于列表，但从左端添加和弹出的速度较快，
        而在中间查找的速度较慢。 此种对象适用于实现队列和广度优先树搜索:
    举例
        from collections import deque
        d = deque(["task1", "task2", "task3"])
        d.append("task4")
        print("Handling", d.popleft())
        # ---
        unsearched = deque([starting_node])
        def breadth_first_search(unsearched):
            node = unsearched.popleft()
            for m in gen_moves(node):
                if is_goal(m):
                    return m
                unsearched.append(m)
    
    在替代的列表实现以外，标准库也提供了其他工具，例如 bisect 模块具有用于操作有序列表的函数
        import bisect
        scores = [(100, 'perl'), (200, 'tcl'), (400, 'lua'), (500, 'python')]
        bisect.insort(scores, (300, 'ruby'))
        scores
    
    heapq 模块提供了基于常规列表来实现堆的函数。 最小值的条目总是保持在位置零。 
        这对于需要重复访问最小元素而不希望运行完整列表排序的应用来说非常有用:
    举例：
        from heapq import heapify, heappop, heappush
        data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
        heapify(data)                      # rearrange the list into heap order
        heappush(data, -5)                 # add a new entry
        [heappop(data) for i in range(3)]  # fetch the three smallest entries

# 十进制浮点运算
  Decimal Floating Point Arithmetic
    decimal 模块提供了一种 Decimal 数据类型用于十进制浮点运算。 相比内置的 float 
    二进制浮点实现，该类特别适用于：
        财务应用和其他需要精确十进制表示的用途，
        控制精度，
        控制四舍五入以满足法律或监管要求，
        跟踪有效小数位，或
        用户期望结果与手工完成的计算相匹配的应用程序。
    例如，使用十进制浮点和二进制浮点数计算70美分手机和5％税的总费用，会产生的不同结果。
    如果结果四舍五入到最接近的分数差异会更大:
        from decimal import *
        round(Decimal('0.70') * Decimal('1.05'), 2)
        round(.70 * 1.05, 2)
    Decimal 表示的结果会保留尾部的零，并根据具有两个有效位的被乘数自动推出四个有效位。 
    Decimal 可以模拟手工运算来避免当二进制浮点数无法精确表示十进制数时会导致的问题。
    精确表示特性使得 Decimal 类能够执行对于二进制浮点数来说不适用的模运算和相等性检测:
        Decimal('1.00') % Decimal('.10')
        1.00 % 0.10
        sum([Decimal('0.1')]*10) == Decimal('1.0')
        sum([0.1]*10) == 1.0
    decimal 模块提供了运算所需要的足够精度:
        getcontext().prec = 36
        Decimal(1) / Decimal(7)
'''
import time, os.path
import struct
from string import Template
import threading, zipfile

class AsyncZip(threading.Thread):
    def __init__(self, infile, outfile):
        threading.Thread.__init__(self)
        self.infile = infile
        self.outfile = outfile

    def run(self):
        f = zipfile.ZipFile(self.outfile, 'w', zipfile.ZIP_DEFLATED)
        f.write(self.infile)
        f.close()
        print('Finished background zip of:', self.infile)

def test_AsyncZip():
    # 
    background = AsyncZip('test_big.txt', 'test_big.zip')
    background.start()
    print('The main program continues to run in foreground.')

    background.join()    # Wait for the background task to finish
    print('Main program waited until background was done.')


def test_struct():
    '''下面的例子展示了在不使用 zipfile 模块的情况下，如何循环遍历一个 ZIP 文件的所有头信息。
        Pack 代码 "H" 和 "I" 分别代表两字节和四字节无符号整数。"<" 代表它们是标准尺寸的小端字节序:
        以下程序执行有问题。
    '''
    print('test_struct()'.center(40, '-'))
    with open('testfile.zip', 'rb') as f:
        data = f.read()

    start = 0
    for i in range(3):                      # show the first 3 file headers
        start += 14
        fields = struct.unpack('<IIIHH', data[start:start+16])
        crc32, comp_size, uncomp_size, filenamesize, extra_size = fields

        start += 16
        filename = data[start:start+filenamesize]
        start += filenamesize
        extra = data[start:start+extra_size]
        print(filename, hex(crc32), comp_size, uncomp_size)

        start += extra_size + comp_size     # skip to the next header

def test_template():
    print('test_template()'.center(40, '-'))
    #例如，以下是某个照片浏览器的批量重命名功能，采用了百分号作为日期、照片序号和照片格式的占位符:
    photofiles = ['img_1074.jpg', 'img_1076.jpg', 'img_1077.jpg']
    class BatchRename(Template):
        delimiter = '%'

    # fmt = input('Enter rename style (%d-date %n-seqnum %f-format):  ')
    # >>> 在此处输入模版字符串: Ashley_%n%f
    fmt = 'Ashley_%n%f'

    t = BatchRename(fmt)
    date = time.strftime('%d%b%y')
    for i, filename in enumerate(photofiles):
        base, ext = os.path.splitext(filename)
        newname = t.substitute(d=date, n=i, f=ext)
        print('{0} --> {1}'.format(filename, newname))

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('std_tutorial.py')
        test_template()
        # test_struct()
        test_AsyncZip()
    test()