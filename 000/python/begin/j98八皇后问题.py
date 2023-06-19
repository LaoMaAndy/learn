#!/usr/bin/python3
# 八皇后问题
# 使用生成器、递归调用的方法
# 思考步骤：逐行放置皇后，
def conflict(state, x):
    '''
    冲突检测
    假设棋盘为n * n, 则每行有且只能有一个皇后
    将前面n - 1行的皇后的位置（列）存储在一个列表state中
    现在判断第n行中，皇后的位置x是否会引发冲突
    是否在同一列：x - state[i] == 0
    是否在对角线：abs(x - state[i]) == n - i
    行和列均从0开始
    '''
    n = len(state)
    for i in range(n):
        if abs(state[i] - x) in (0, n - i):
            return True
    return False
def test_conflict():
    state = [[], [0], [0, 1],[0, 1, 3],[1, 3, 0]]
    x = [0, 1, 2, 2, 2]
    l = len(state)
    for i in range(l):
        print(state[i], x[i], ':', conflict(state[i], x[i]))

def queens_simple(num, state):
    '''
    使用生成器
    查找一行里，皇后可以放置的所有位置
    通过循环，找出最后一行中，可以放置皇后的所有位置
    num: 皇后总数
    state： 已经放好的行后的位置。
            列表，每行皇后的位置，state[0]...state[num-2]
    首先判断，前面所有的位置已经包含在列表中
    然后循环查找每一个位置
    使用生成器，返回当前计算的位置
    '''
    if len(state) == num - 1:
        for pos in range(num):
            if not conflict(state, pos):
                yield pos

def test_queens_simple():
    print(list(queens_simple(4, (1, 3, 0))))

def queens(num = 8, state=()):
    '''
    八皇后问题。
    外层循环套用一个生成器，相当于两层循环
    '''
    for pos in range(num):
        if not conflict(state, pos):
            if len(state) == num - 1:
                yield (pos,)
            else:
                for result in queens(num, state + (pos,)):
                    yield (pos,) + result
def test_queens():
    # 以下显示3～5尺寸的解
    print("list(queens(3)):")
    print(list(queens(3)))
    print("list(queens(4)):")
    print(list(queens(4)))
    print("list(queens(5)):")
    q5 = list(queens(5))
    for i in q5:
        print(i)
    # 以下显示1～8尺寸的解的数量
    for i in range(8):
        print("queens({}): ".format(i + 1), end = '')
        print(len(list(queens(i + 1))))
    pass

def print_queens(solution):
    def line(pos, length = len(solution)):
        return '. ' * pos + 'X ' + '. ' * (length - pos - 1)
    for pos in solution:
        print(line(pos))

import random
def test_print_queens():
    print_queens(random.choice(list(queens())))

def test():
    test_conflict()
    test_queens_simple()
    test_queens()
    test_print_queens()

test()
