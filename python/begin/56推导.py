#!/usr/bin/env python3
# 2023-3-15整理
'''
使用推导Comprehension生成字面值
可生成列表[ ]、字典{ }
使用( )生成的是生成器。生成器可以使用next(g)函数
'''
def test_compre():
    '''
    推导的一个经典算法。
    要求：匹配男生、女生名字，首字母相同的名字进行配对，找出所有的配对。
    方法是构造一个字典，字典的key是首字母，value是对应的女生名字列表
    然后做一个循环，取男生名字首字母，做key,匹配对应value中的所有元素
    关键：避免出现n^2的时间复杂度，下面算法的时间复杂度是2 * n
    '''
    girls = ['alice', 'bernice', 'clarice', 'billy']
    boys = ['chris', 'arnold', 'bob']
    letterGirls = {}
    for girl in girls:
        #  此处注意 setdefault() 的返回值，是字典元素的value
        print(letterGirls.setdefault(girl[0], []))
        letterGirls.setdefault(girl[0], []).append(girl)
    print(letterGirls)
    print([b+'+'+g for b in boys for g in letterGirls[b[0]]])

def test_del():
    '''
    删除del语句
    '''
    j = i = ['1', '2', '3']
    print('test del:')
    print("i value: ", i)
    del i
    print("i been deleted")
    # print("after delete, i:", i)
    print("j : ", j)

def test_exec():
    '''
    exec语句,需要注意的是，
    exec()会建立一个独立的名字空间。
    '''
    print("exec a statment:")
    exec("print('This is exec from a string....jkkk d')")
    #s = input("input a python statement:")
    #i = exec(s)
    ns = {}
    #以下是用将一段代码设定为长字符串
    i = 0
    command_str = '''
print("test a longer statment.")
i = 0
for j in range(10):
    print("i + j = ", i + j)
    i += 1
print("Call end , i: ", i)
    '''
    print('以下是测试exec():')
    print(command_str, ns)
    exec(command_str, ns)
    #在这里执行这段代码
    print("exec finished")
    print("Other i:", i)

def test_doc():
    ''' There some docstring,
    for some reason,
    it can be nothing'''
    print(test_doc.__name__)
    print("function's docstring:")
    print(test_doc.__doc__)
    # print("Calling help():")

def main():
    test_compre()
    test_del()
    test_exec()
    # test_doc()


if __name__ == '__main__':
    main()
