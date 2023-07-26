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
    使用str.rjust(), str.ljust(), str.center() 进行手动格式化
    如果需要截断字符串，可以使用x.ljust(n)[:n]
'''
from share import prn_title

if __name__ == '__main__':
    print(__doc__)
    def test():
        prn_title('io_tutorial.py')
    test()
