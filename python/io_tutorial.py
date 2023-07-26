#!/usr/bin/env python3
r'''
# 输入与输出，包含：
  更复杂的输入输出、

# 更复杂的输入输出
    1）f字符串：formatted string literals
    2）字符串format()方法

# str() 和 repr() 把值转化为字符串
    区别：str() 更方面用户读取， repr()更适合解释器读取
    相同：数字、列表或字典，这两个函数输出的形式相同。
    不同：字符串有两种不同的表现形式。

# string 模块包含 Template 类，提供了将值替换为字符串的另一种方法。
    该类使用 $x 占位符，并用字典的值进行替换，但对格式控制的支持比较有限。

# f-字符串
    通过 {expression} 把表达式的值添加到字符串内
    在 ':' 后是对齐、长度、精度及类型
        {math.pi:.3f} ：浮点数，舍入到小数点后3位
        {phone:10d} ：宽度为10位
        {number:c} : 转换为字符
    修饰符可以在格式化前转换值。 
        '!a' 应用 ascii() ，
        '!s' 应用 str()，
        '!r' 应用 repr()：
    = 说明符 将表达式展开为：表达式文本=表达式值 的形式。
        bugs = 'roaches'
        print(f'{bugs=}')
        >>> bugs='roaches'
    举例：
        f'My hovercraft is full of {animals!r}.
        
        line = "The mill's closed"
        f"{line = }"
        f"{line = :20}"
        f"{line = !r:20}" 
# 字符串 format() 方法
    花括号及之内的字符（称为格式字段）被替换为传递给 str.format() 方法的对象。
        花括号中的数字表示传递给 str.format() 方法的对象所在的位置。
    花括号中的数字表示传递给 str.format() 方法的对象所在的位置。
        '{0} and {1}'.format('spam', 'eggs')
    str.format() 方法中使用关键字参数名引用值。
        'This {food} is {adj}.'.format(food='spam', adj='horrible')
    位置参数和关键字参数可以任意组合：
        'Story of {0}, {1}, and {other}.'.format('Bill', 'Mand', other='Georg')
    传递字典，并用方括号 '[]' 访问键来完成
        table = {'joe': 4127, 'Ma': 4098, 'Tony': 8637678}
        'Ma: {0[Ma]:d}; joe:{0[joe]:d}; Tony: {0[Tony]:d}'.format(table)
    也可以通过使用 ** 表示法将 table 字典作为关键字参数传递来完成。
        table = {'joe': 4127, 'Ma': 4098, 'Tony': 8637678}
        'Ma: {Ma:d}; joe:{joe:d}; Tony: {Tony:d}'.format(**table)

# 手动格式化字符串
    右对齐：str.rjust()
    左对齐：str.ljust()
    中对齐：str.center() 
    截断字符串，可以使用x[:n].ljust(n)
    数字字符串填充零：str.zfill()

# printf风格 格式化字符串
    'string' % values
    'pi is %5.3f.' % math.pi
    '%1.1s-%2.2s-%3.3s' % ('aaa', 'bbb', 'cccc') 
        >>> 'a-bb-ccc'
# 读写文件
    open() 返回一个 file object
    open(filename, mode, encoding=None)
    例如：
        f = open('workfile', 'w', encoding="utf-8")
    mode 包括：
        'r' ，表示文件只能读取；
        'w' 表示只能写入（现有同名文件会被覆盖）；
        'a' 表示打开文件并追加内容，任何写入的数据会自动添加到文件末尾。
        'r+' 表示打开文件进行读写。
        mode 实参是可选的，省略时的默认值为 'r'。
        二进制：模式后面加上一个 'b'
            二进制模式的数据是以 bytes 对象的形式读写的。
            在二进制模式下打开文件时，你不能指定 encoding 。
            读写 JPEG 或 EXE时，一定要使用二进制模式。
    换行符转换：
        文本模式下读取文件时，默认把平台特定的行结束符
        （Unix 上为 \n, Windows 上为 \r\n）转换为 \n。
        在文本模式下写入数据时，默认把 \n 转换回平台特定结束符。
    使用 with 关键字。
        优点是，子句体结束后，文件会正确关闭，即便触发异常也可以。
        而且，使用 with 相比等效的 try-finally 代码块要简短得多
    检查文件是否已经关闭：
        f.closed 为 True 
    如果没有使用 with 关键字，则应调用 f.close() 关闭文件

# 文件对象的方法
    f.read(size)
        读取文件。size为空时或为负，读取全部文件，返回字符串 / 字节串
        文件大小是内存的两倍时，会出现问题
        如已到达文件末尾，f.read() 返回空字符串（''）
    f.readline()
        返回字符串
        从文件中读取单行数据；字符串末尾保留换行符（\n)
        文件不以换行符结尾时，文件的最后一行才会省略换行符。
        readline() 返回空字符串，就表示已经到达了文件末尾，
        空行使用 '\n' 表示，该字符串只包含一个换行符。
    f.readlines()
        返回列表。列表中的每一个元素是字符串，为文件每一行。
    使用迭代，读取文件内容：
        for line in f: ....
    将文件内容抓换为列表：
        t = list(f)
    f.write(s)
        写入内容，返回写入的字符数
        s 必须是字符串（文本模式）或 字节串（二进制模式）
    f.tell() 
        返回整数，给出文件对象在文件中的当前位置，
        表示为二进制模式下时从文件开始的字节数，\
        以及文本模式下的意义不明的数字。
    f.seek(offset, whence) 
        改变文件对象的位置。
        offset：偏移
        whence 值为:
            0 时，表示从文件开头计算，
            1 表示使用当前文件位置，
            2 表示使用文件末尾作为参考点。
            省略 whence 时，其默认值为 0，即使用文件开头作为参考点。
        文本文件的定位：
            只允许相对于文件开头进行查找 f.seek(n, 0)
            例外: seek(0, 2) 查找文件末尾
        offset:
            只能设定为f.tell()返回的偏移值，或者零
            任何其他偏移值都会产生未定义的行为。
    文件对象还支持 isatty() 和 truncate() 等方法。但不常用。

# 使用 json 保存结构化数据
    现代应用程序通常使用 JSON 格式来进行数据交换。
    许多程序员已经熟悉它，这使其成为互操作性的不错选择。
        import json
        x = [1, 'simple', 'list']
        json.dumps(x)
    如果 f 是 text file 对象，可以这样做：
        json.dump(x, f)
    如果 f 是已打开、供读取的 binary file 或 text file 对象：
        x = json.load(f)
    备注 JSON文件必须以UTF-8编码。
        当打开JSON文件作为一个 text file 用于读写时，
        使用 encoding="utf-8" 。

'''
from share import prn_title

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('io_tutorial.py')
    test()
