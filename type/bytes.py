#!/usr/bin/env python3
r'''
# bytes对象
单个字节构成的不可变序列
bytes对象更像整数序列
构建方法：
    每个元素限制为：0 <= x < 256 
    b + 单引号 / 双引号 / 三重引号
    r : 可用于字节串对象（r: 禁止转义）
    class bytes([source[, encoding[, errors]]])

其他构建方法：
    bytes(10): 指定长度，以零填充
    bytes(range(20)): 由整数迭代
    bytes(obj): 通过缓冲区协议复制
    classmethod fromhex(string)
      由字符串生成一个bytes对象
    hex([sep[, bytes_per_sep]])
      将bytes对象转换为str对象

# bytearray 对象
是可变的 bytes 对象

# bytearray 构建
    bytearray 对象没有专属的字面值语法，
      它们总是通过调用构造器来创建：
    bytearray()： 创建一个空实例: 
    bytearray(10)：创建一个指定长度的以零值填充的实例
    bytearray(range(20))：通过由整数组成的可迭代对象
    bytearray(b'Hi!')：通过缓冲区协议复制现有的二进制数据
    fromhex(str) 和 hex()

# bytes 和 bytearray 方法
    支持可变序列操作
    count(sub[, start[, end]])    
      次数统计
    removeprefix(prefix, /)
      删除前缀, 3.9
    removesuffix(suffix, /)
      删除后缀, 3.9
    decode(encoding='utf-8', errors='strict')
      默认使用utf-8，编码为 str 类型
    endswith(suffix[, start[, end]])
      查找后缀，返回 True / False
      suffix 可以为元组
    find(sub[, start[, end]])
      查找。未找到返回 -1
    index(sub[, start[, end]])
      查找。未找到引发异常。ValueError
    join(iterable)
      拼接。
    partition(sep)
      拆分。返回一个3元组
    replace(old, new[, count])
      替换。指定次数
    rfind(sub[, start[, end]])
      搜索。反向。
    rindex(sub[, start[, end]])
      搜索。反向。未找到引发异常。
    bytes.rpartition(sep)
      拆分。反向
    startswith(prefix[, start[, end]])
      查找前缀，返回 True / False
      prefix 可以为元组
    translate(table, /, delete=b'')
      返回原 bytes 或 bytearray 对象的副本，
      移除其中所有在可选参数 delete 中出现的 bytes，
      其余 bytes 将通过给定的转换表进行映射，
      该转换表必须是长度为 256 的 bytes 对象。
    center(width[, fillbyte])
      居中。填充。
    ljust(width[, fillbyte])
      靠左对齐。
    lstrip([chars])
      移除左侧字符。
    rjust(width[, fillbyte])
    rsplit(sep=None, maxsplit=- 1)
    rstrip([chars])
    split(sep=None, maxsplit=- 1)
    strip([chars])
    capitalize()
    expandtabs(tabsize=8)
    is系列
      isalnum()
      isalpha()
      isascii()
      isdigit()
      islower()¶
      isspace()
      istitle()
      isupper()
    lower()
    splitlines(keepends=False)
    swapcase()
    title()      
    upper()
    zfill(width)
备注：
    使用这些基于 ASCII 的操作来处理
      未以基于 ASCII 的格式存储的二进制数据可能会导致数据损坏。

# Memory View 内存视图
    
    
'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('bytes.py')
    test()
