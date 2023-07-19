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
    








'''

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('dict.py')
    test()