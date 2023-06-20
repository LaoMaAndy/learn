#!/usr/bin/env python3
file_doc='''\
返回斐波那契数列，列表。
列表默认从0，1开始
    count: 元素个数
    limit: 不超过最大值
    start: 起始值
    无参数时返回空列表\
'''

def feb(count=0, limit=0, start=0):
    # print('count:', count, "limit:", limit)
    # 处理参数特殊情况
    if (count<=0 and limit<=0):
        return []
    a, b = start, start+1
    result = [start]
    i = 1       # 已经添加了一个值，计数从1开始
    while True:
        a, b = b, a + b
        if count!=0 and i>=count:
            break
        if limit!=0 and a>limit:
            break
        result.append(a)
        i += 1
    return result

def test_feb():
    print("feb(0):", feb(0))
    print("feb(1):", feb(1))
    print("feb(2):", feb(2))
    print("feb(5):", feb(5))
    print("feb(limit=30):", feb(limit=30))
    print("feb(count=3, limit=1000):", feb(count=3, limit=1000))
    print("feb(count=10, limit=30):", feb(count=10, limit=30))
    print("feb(count=5, start=1000):", feb(count=5, start=1000))

def demo():
    print(file_doc)
    test_feb()

if __name__ == '__main__':
    demo()
