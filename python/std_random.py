#!/usr/bin/env python3
r'''
# random() 函数
    基本函数 random() ，它均匀地生成半开范围内的随机浮点 0.0 <= X < 1.0 。 
        Python 使用 Mersenne Twister 作为核心生成器。它产生 53 位精度浮点数，周期为 2**19937-1。 
        C 中的底层实现既快速又线程安全。 Mersenne Twister 是目前经过最广泛测试的随机数生成器之一。
    这个模块提供的函数实际上是 random.Random 类的隐藏实例的绑定方法。 
        你可以实例化自己的 Random 类实例以获取不共享状态的生成器。
    使用自己设计的不同基础生成器，类 Random 也可以作为子类：在这种情况下，
        重载 random() 、 seed() 、 getstate() 以及 setstate() 方法。
    random 模块还提供 SystemRandom 类，它使用系统函数 os.urandom() 从操作系统提供的源生成随机数。

# 簿记功能 Bookkeeping functions 
# seed(a=None, version=2) 初始化随机数生成器。
    如果 a 被省略或为 None ，则使用当前系统时间。 如果操作系统提供随机源，则使用它们而不是系统时间
    对于版本2（默认的），str 、 bytes 或 bytearray 对象转换为 int 并使用它的所有位。
    对于版本1（用于从旧版本的Python再现随机序列），用于 str 和 bytes 的算法生成更窄的种子范围。

# getstate() 
    返回捕获生成器当前内部状态的对象。 这个对象可以传递给 setstate() 来恢复状态。

# setstate(state)
    state 应该是从之前调用 getstate() 获得的，并且 setstate() 将生成器的内部状态恢复到 getstate() 被调用时的状态。

# 用于字节数据的函数 Functions for bytes
# randbytes(n) 生成 n 个随机字节。
    此方法不可用于生成安全凭据。 那应当使用 secrets.token_bytes()。

# 整数用函数 Functions for integers
# randrange(stop) 
  random.randrange(start, stop[, step])
    从 range(start, stop, step) 返回一个随机选择的元素。 
        这相当于 choice(range(start, stop, step)) ，但实际上并没有构建一个 range 对象。

# random.randint(a, b) 
    返回随机整数 N 满足 a <= N <= b。相当于 randrange(a, b+1)。

# getrandbits(k)
    返回具有 k 个随机比特位的非负 Python 整数。

# 序列用函数 Functions for sequences
# choice(seq)
    从非空序列 seq 返回一个随机元素。

# choices(population, weights=None, *, cum_weights=None, k=1)
    从 population 中有重复地随机选取元素，返回大小为 k 的元素列表。 如果 population 为空，则引发 IndexError。
    如果指定了weight 序列，则根据相对权重进行选择。 或者，如果给出 cum_weights 序列，则根据累积权重
        （可能使用 itertools.accumulate() 计算）进行选择。 
        例如，相对权重``[10, 5, 30, 5]``相当于累积权重``[10, 15, 45, 50]``。 
        在内部，相对权重在进行选择之前会转换为累积权重，因此提供累积权重可以节省工作量。

# shuffle(x)
    就地将序列 x 随机打乱位置。

# sample(population, k, *, counts=None)
    返回从总体序列中选择的 k 长度的唯一元素列表。用于无放回随机抽样。

# 实值分布 Real-valued distributions
# random()
    Return the next random floating point number in the range 0.0 <= X < 1.0

# uniform(a, b)
    返回一个随机浮点数 N ，当 a <= b 时 a <= N <= b ，当 b < a 时 b <= N <= a 。
    取决于等式 a + (b-a) * random() 中的浮点舍入，终点 b 可以包括或不包括在该范围内。

# triangular(low, high, mode)
    返回一个随机浮点数 N ，使得 low <= N <= high 并在这些边界之间使用指定的 mode 。 
    low 和 high 边界默认为零和一。 mode 参数默认为边界之间的中点，给出对称分布。

# betavariate(alpha, beta) Beta 分布。
# gammavariate(alpha, beta) 伽马分布。
# gauss(mu=0.0, sigma=1.0) 正态分布，也称为高斯分布。 
# lognormvariate(mu, sigma) 对数正态分布。 
# normalvariate(mu=0.0, sigma=1.0) 正态分布。 mu 是平均值，sigma 是标准差。
# vonmisesvariate(mu, kappa) 冯·米塞斯分布。
# paretovariate(alpha) 帕累托分布。 alpha 是形状参数。
# weibullvariate(alpha, beta) 威布尔分布。

# 替代生成器 Alternative Generator
# SystemRandom([seed])
    使用 os.urandom() 函数的类，用从操作系统提供的源生成随机数。 这并非适用于所有系统。 
    也不依赖于软件状态，序列不可重现。 因此，seed() 方法没有效果而被忽略。

'''
from random import randrange, randint
from math import ceil
def test_randrange():
    '''查看随机的均匀状况
    '''
    total = 100000 # 总数
    section = 10    # 分段
    step = total / section
    result = dict()
    for i in range(total):
        r = randrange(total)
        k = int(r/step)
        result[k] = result.setdefault(k, 1) + 1
    print(result)
    for i in range(ceil(total/step)):  # 分段有剩余部分
        print(int(i*step), '~', int((i+1)*step), ':', result[i])

if __name__ == '__main__':
    print(__doc__)
    def test():
        print('std_random.py')
    test_randrange()
    test()
