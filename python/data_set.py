#!/usr/bin/env python3
r'''
# set 和 fronzenset
set 对象是由具有唯一性的 hashable 对象所组成的无序多项集。
    用于集合运算。
    集合不记录位置和顺序
    不支持索引、切片或其他序列类操作

# 其他的容器对象如： 
    dict, list 与 tuple 等内置类，以及 collections 模块。

# 构建
    class set([iterable])
    class frozenset([iterable])
      集合的元素必须为 hashable。
    使用花括号内以逗号分隔元素的方式: 
      {'jack', 'sjoerd'}
    使用集合推导式: 
      {c for c in 'abracadabra' if c not in 'abc'}
    使用类型构造器: 
      set(), set('foobar'), set(['a', 'b', 'foo'])

# set 和 frozenset 的实例提供以下操作
    len(s) : 返回集合 s 中的元素数量（即 s 的基数）。
    x in s : 检测 x 是否为 s 中的成员。
    x not in s : 检测 x 是否非 s 中的成员。

  判断集合关系
    isdisjoint(other) : 二者交集为空，返回True
    issubset(other) 或 set <= other :
      是否 为子集
    set < other : 是否为真子集
    issuperset(other) 或 set >= other :
      是否某个集合的超集
    set > other
      是否真超集

  集合操作
    union(*others) 或 set | other | ...
      返回一个新集合，是所有集合的合并
    
    intersection(*others) 或 set & others & ...
      返回一个新集合，是所有集合的交集
    
    difference(*others) 或 set - other - ...
      返回一个新集合，原集合中存在，且其他集合不存在的

    symmetric_difference(other) 或 set ^ other
      异或。返回一个新集合，不同时属于两者的元素

    copy()
      返回原集合的浅拷贝。
  注意：
    运算符 版本 和 非运算符版本 版本略有不同：
        非运算符版本可以接受任何可迭代对象作为一个参数。
        基于运算符的对应方法则要求参数为集合对象。
    set 的实例与 frozenset 的实例之间基于它们的成员进行比较。
        例如：set('abc') == frozenset('abc') 为 True
             set('abc') in set([frozenset('abc')]) 也一样。
    对于非空且互不相等的集合，以下运算都为False：
        a<b, a==b, or a>b
    混合了 set 实例与 frozenset 的运算返回
        与第一个操作数相同的类型。

# 仅使用于 set，而不适用于 frozenset 的操作
    update(*others) 或 set |= other | ...
      更新。添加来自 others 中的元素

    intersection_update(*others) 或 set &= other & ...
      更新集合，只保留其中在所有 others 中也存在的元素。

    difference_update(*others) 或 set -= other | ...
      更新集合，移除其中也存在于 others 中的元素。

    symmetric_difference_update(other) 或 set ^= other
      更新集合，只保留存在于集合的一方而非共同存在的元素。

    add(elem) 将元素 elem 添加到集合中。

    remove(elem) 从集合中移除元素 elem。 
        如果 elem 不存在于集合中则会引发 KeyError。

    discard(elem) 如果元素 elem 存在于集合中则将其移除。

    pop() 从集合中移除并返回任意一个元素。 
        如果集合为空则会引发 KeyError。
    
    clear() 从集合中移除所有元素。
        

'''
if __name__ == '__main__':
    print(__doc__)
    def test():
        print('set.py')
    test()