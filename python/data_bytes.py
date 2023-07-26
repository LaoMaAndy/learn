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
访问对象的内部数据，该对象支持 缓冲区协议 buffer protocol 

构建
    class memoryview(object)
      创建一个 object 的 memview
      object必须支持缓冲区协议
元素
    指由object处理的内存单元，即
    每个object的元素可能占一个字节，或多个字节

方法
    可以使用切片进行读取
    如果下层对象可写，则支持一维切片赋值

    len(view) 返回元素的数量。特殊的，
      当 view.ndim = 0时，长度为 1
    
    __eq__(exporter)
      如果 tolist() 相等，则相等；
      如果两边的格式字符串都不被 struct 模块所支持，则两对象比较结果总是不相等

    tobytes(order='C')
      将缓冲区中的数据作为字节串返回。 
    
    hex([sep[, bytes_per_sep]])
      返回一个字符串对象，缓冲区里的每个字节用两个十六进制数码表示

    tolist()
      将缓冲区内的数据以一个元素列表的形式返回。

    toreadonly()
      转换为只读
    
    release()
      释放由内存视图对象所公开的底层缓冲区。

    cast(format[, shape])
      将内存视图转化为新的格式或形状。
属性
    itemsize ：每个元素占有的字结数
    ndim ： 维度
    readonly ：True / False 是否只读
    format : 一个字符串，包含视图中每个元素的格式
    nbytes : 总字节数，只读 nbytes == 
      product(shape) * itemsize == 
      len(m.tobytes())
    obj : 内存视图的下层对象，只读
    shape : 一个整数元组，
      通过 ndim 的长度值给出内存所代表的 N 维数组的形状。
    strides : 一个整数元组，
      通过 ndim 的长度给出以字节表示的大小，
      以便访问数组中每个维度上的每个元素。
    suboffsets
      供 PIL 风格的数组内部使用。 该值仅作为参考信息。
    c_contiguous
      一个表明内存是否为 C-contiguous 的布尔值。
    f_contiguous
      一个表明内存是否为 Fortran contiguous 的布尔值。
    contiguous
      一个表明内存是否为 contiguous 的布尔值。

# arrary 高效的数值数组
docs.python.org/zh-cn/3/library/array.html#array.array
对应于C语言的类型

类型码 C类型    Python类型   以字节表示的最小尺寸 
'b' signed char     int     1   
'B' unsigned char   int     1   
'u' wchar_t Unicode 字符     2 
'h' signed short    int     2   
'H' unsigned short  int     2   
'i' signed int      int     2   
'I' unsigned int    int     2   
'l' signed long     int     4   
'L' unsigned long   int     4   
'q' signed longlong     int 8   
'Q' unsigned long long  int 8   
'f' float           float   4   
'd' double          float   8   

# struct --- 将字节串解读为打包的二进制数据
docs.python.org/zh-cn/3/library/struct.html#module-struct

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('bytes.py')
    test()
