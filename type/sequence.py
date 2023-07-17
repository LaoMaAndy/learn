#!/usr/bin/env python3
r'''序列类型
# Python 有三种基本序列：list, tuple, range

# 一般序列操作
以下按优先级递增排列：
    x in s: 序列x中是否包含x
    x not in s: 是否不包含
    s + t: 拼接
    s * n 或 n * s: 重复自身n次拼接
    s[]: 索引
    s[i:j:]: 切片
    s[i:j:k]: 切片
    len(s): 求长度
    min(s): s最小项
    max(s): s最大项
    s.index(x[, i[, j]]): 首次出现的索引
    s.count(x): x在s中出现的次数
备注:
    in 和 not in 在str, bytes和bytearray中也可用
      如： 'gg' in 'egg' >>> True
    x * 0: 会生成一个空序列：
    浅复制: 序列 * 数字
    特殊的：lists = [[]] * 3
        lists >>> [[], [], []]
        lists[0].append(3)
        lists >>> [[3], [3], [3]]
    多维列表的创建
      使用推导：lists = [[] for i in range(3)]
    负索引 i
      会被替换为 len(s) + i
    切片返回新序列
      切片步长不可以为0
    拼接的负面作用
      拼接不可变对象总产生新的对象
      重复拼接 将 极大消耗系统资源
      替代方法：
        构建一个列表，最后使用str.join()生成完成串
        写入一个io.StringIO
        拼接tuple对象，请改为list类
        bytearray 对象是可变的。
    index() 找不到时，会引发 ValueError

# 可变序列和不可变序列
  不可变序列 通常支持 hash() 
  不可变序列可用于dict键

# 可变序列操作，按优先级
按优先级递增：
    s[i] = x : 将s[i] 替换为 x
    s[i:j] = t : 将切片部分替换，
      先将t转换为序列
      替换的数量不一定相同
      可实现替换/插入/删除
    del[i:j] : 删除，等同于s[i:j] = []
    s[i:j:k] = t : 替换
    del s[i:j:k] : 删除
    s.append(x) : 将x值附加到s的末尾，增加一个元素
    s.clear() : 清除所有
    s.copy() : 浅拷贝
    s.extend(t) 或 s += t: 用t的内容扩展s
    s *= n : 使用s的内容重复n次更新
    s.insert(i, x) 等同于s[i:i] = x
    s.pop() 或 s.pop(i) : 提取i位置的项，并移除
      默认是最后一项
    s.remove(x) 删除s中第一个等于x的项
    s.reverse() 就地逆序排列
备注
    s[i:j:k] = t 时，t中的元素数量必须等于被替换的数量
    s.remove(x), 如果不存在x, 则产生异常
    s.reverse() 无返回值
    s *= n, 其中n 需要实现__index__() 方法
      n为零或负值将清空s

# 列表
通常用于存放相同类型的项目
构建方法：
    空列表[]
    方括号中以逗号分隔[a, b]
    列表推导 [x for x in iterable]
    构造器 list() 或 list(iterable)
    其他很多操作也会产生列表，如sorted()内置函数
列表方法
    所有 通用序列 和 可变序列的操作都实现
    sort(x, key=None, reverse=False)
      原地排序，使用 < 进行比较
      key 和 reverse 仅接受关键字参数
      key 指定带有一个参数的函数，用于提取比较键
        列表中的每个元素都会计算一次，然后排序
        例如: key=str.lower
      reverse为布尔值，为True时反向排序
      无返回值
      使用的排序方法是稳定的
      如果需要返回一个新的排序后序列，使用sorted()

# 元组
不可变序列，用于存放异构数据的多项集
构建
    空元组()来表示
    使用后缀的逗号来表示 a, 或 (a, )
    使用逗号分隔的多个项 a, b, c 或 (a, b, c)
    内置tuple()，tuple(iterable)
注意
    生成元组的是逗号，而不是圆括号
    圆括号知识可选的
    f(a, b, c) 是调用函数时附带3个参数
    f((a, b, c)) 是调用函数时附带一个3元组

# collections.namedtuple() 
通过名称访问的元组

# range
不可变的数字序列，通常用于for循环
构建
    range(start, stop[, step])
    参数必须为整数，或任何实现了__index__()特殊方法的对象
    start, stop可为正负零
    step可为正/负，不能为 0
    range 占用固定内存，其单项通过计算实现
方法
    range 对象实现了 一般 序列的所有操作，
    range 不支持拼接和重复
    range 支持负索引

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('sequence')
    test()
