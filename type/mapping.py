#!/usr/bin/env python3
r'''
# Mapping Type 映射类型
    目前还有一种映射类型 dictionary
    字典的键几乎是任意值。
    不可散列的值，即包含列表、字典或其他可变类型的值
      （按值而不是按对象标识进行比较）不能用作键。
    比较相等的值（例如 1 、 1.0 和 True ）
      可以互换使用来索引相同的字典条目。
# 创建
    class dict(**kwargs)
    class dict(mapping, **kwargs)
    class dict(iterable, **kwargs)
    例如：{'jack': 4098, 'sjoerd': 4127} 
    推导式: {x: x ** 2 for x in range(10)}
    构造器: 
      a = dict(one=1, two=2, three=3)
      b = {'one': 1, 'two': 2, 'three': 3}
      c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
      d = dict([('two', 2), ('one', 1), ('three', 3)])
      e = dict({'three': 3, 'one': 1, 'two': 2})
      f = dict({'one': 1, 'three': 3}, two=2)
      a == b == c == d == e == f
    
# 方法
    list(d) : 返回字典 d 中使用的所有键的列表。
    len(d) : 返回字典 d 中的项数。
    d[key] : 返回 d 中以 key 为键的项。 
      如果映射中不存在 key 则会引发 KeyError。
      如果字典的子类定义了方法 __missing__() 并且 
      key 不存在，则 d[key] 操作将调用该方法并附带
      key 作为参数。d[key]将返回或引发 __missing__(key)
    d[key] = value : 将 d[key] 设为 value。
    del d[key] : 将 d[key] 从 d 中移除。 
      如果映射中不存在 key 则会引发 KeyError。
    key in d : 如果d中存在键key返回True，否则返回 False。
    key not in d: 等价于 not key in d。
    
    iter(d) : 返回以字典的键为元素的迭代器。 
      这是 iter(d.keys()) 的快捷方式。
    
    clear() : 移除字典中的所有元素。
    copy() : 返回原字典的浅拷贝。
    
    classmethod fromkeys(iterable[, value])
      使用来自 iterable 的键创建一个新字典，并将键值设为 value。
    
    get(key[, default]) 如果 key 存在于字典中则返回 key 
      的值，否则返回 default。 如果 default 未给出则默认为 
      None，因而此方法绝不会引发 KeyError。
    
    items() : 返回由字典项 ((键, 值) 对) 组成的一个新视图。 
      参见 视图对象文档。

    keys() : 返回由字典键组成的一个新视图。

    pop(key[, default]) : 
      如果key存在于字典中则将其移除并返回其值，
      否则返回 default。 如果 default 未给出且 key 
      不存在于字典中，则会引发 KeyError。

    popitem() :
      从字典中移除并返回一个 (键, 值) 对。 
      popitem() 适用于对字典进行消耗性的迭代，
      这在集合算法中经常被使用。 如果字典为空，调用 popitem() 将引发 KeyError。
      在 3.7 版更改: 现在会确保采用 LIFO 顺序。 
      在之前的版本中，popitem() 会返回一个任意的键/值对。

    reversed(d) :
      返回一个逆序获取字典键的迭代器。 这是 reversed(d.keys()) 的快捷方式。
    
    setdefault(key[, default]) :
      如果字典存在键 key ，返回它的值。如果不存在，插入值为 default 的键 key ，并返回 default 。 default 默认为 None。
    
    update([other]) :
      使用来自 other 的键/值对更新字典，覆盖原有的键。返回 None。

    values(): 返回由字典值组成的一个新视图。
      两个 dict.values() 视图之间的相等性比较将总是返回 False。

    d | other : 合并
      两者必须都是字典。当 d 和 other 有相同键时， 
      other 的值优先。            
  
  新版功能3.9
    d |= other : 更新
      用 other 的键和值更新字典 d ，
      other 可以是 mapping 或 iterable 的键值对。
      当 d 和 other 有相同键时， other 的值优先。

    是否相等 ==
      两个字典的比较当且仅当它们具有相同的 (键, 值) 
      对时才会相等（不考虑顺序）。
      排序比较 ('<', '<=', '>=', '>') 会引发TypeError。

    保留顺序
      字典会保留插入时的顺序。 请注意对键的更新不会影响顺序。 
      删除并再次添加的键将被插入到末尾。

    可逆
      字典和字典视图都是可逆的。
      d = {"one": 1, "two": 2, "three": 3, "four": 4}
      list(reversed(d))

# 字典视图对象 Dictionary view objects
    由 dict.keys(), dict.values() 和 dict.items() 所
    返回的对象是 视图对象。view objects.
    该对象提供字典条目的一个动态视图，这意味着当字典改变时，
    视图也会相应改变。

# 字典视图对象 方法
    len(dictview) : 返回字典中的条目数。
    iter(dictview) : 返回字典中的键、值
      或项（以 (键, 值) 为元素的元组表示）的迭代器。
      用 zip() 来创建 (值, 键) 对: 
        pairs = zip(d.values(), d.keys())。 
      另一个创建相同列表的方式是 
        pairs = [(v, k) for (k, v) in d.items()].
    x in dictview : 检测是否存在
    reversed(dictview) : 返回一个逆序对象
    dictview.mapping :
      返回types.MappingProxyType对象，
      封装了字典视图指向的原始字典。

'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('dict.py')
    test()