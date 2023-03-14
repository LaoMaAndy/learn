#!/usr/bin/env python3
# 闭包closure，递归recursion

def start_0603():
	print('闭包-递归等')
"""
闭包 Closure：函数带有嵌套的作用域
返回一个内部函数，该函数带有自身的作用域
效果相当于省略了部分参数
使函数调用更加灵活
可以使用循环等方式，动态生成函数
"""
def makefunc(n):
	def multi(i):
		return n * i
	return multi

def test_makefunc():
	multi_5 = makefunc(5)
	result = multi_5(11)
	print("Make a func".center(30, '*'))
	print("result:", result)

'''
递归：Recursion
base case:
	基础问题：最小问题。
recursive case:	
	递归问题：包含一个或多个递归调用
	每个递归处理更小的问题。
'''
# 阶乘n
# 使用for ... range循环
def factorial(n):
	result = n
	for i in range(1, n):
		result *= i
	return result
# 阶乘写法2
# 使用while 循环
def factorial_2(n):
	i = result = n
	while (i > 1):
		i -= 1
		result *= i
	return result
# 阶乘写法3
# 使用递归调用
def factorial_3(n):
	if n <= 1:
		return n
	else:
		return n * factorial_3(n - 1)

def test_fact_all(n):
	print("#1 ({}): {}".format(n, factorial(n)))
	print("#2 ({}): {}".format(n, factorial_2(n)))
	print("#3 ({}): {}".format(n, factorial_3(n)))

def test_fact():
	print("test factorial".center(30, '*'))
	test_fact_all(-1)
	test_fact_all(0)
	test_fact_all(1)
	test_fact_all(11)
'''
n次幂的写法：
	for循环、while循环、递归、闭包
	0次幂等于1，负数幂等于1/正数次幂
'''
def power_1(x, n):
	loop = n if n > 0 else -n
	result = 1
	for i in range(loop):
		result *= x
	return result if n >= 0 else 1 / result

def power_2(x, n):
	loop = n if n > 0 else -n
	result = 1
	i = 1
	while i <= loop:
		result *= x
		i += 1
	return result if n >= 0 else 1 / result

def power_3(x, n):
	if n == 0:
		return 1
	if n < 0:
		return 1 / power_3(x, -n)

	return x * power_3(x, n - 1)

def power_4(x):
	def pow_n(n):
		return pow(x, n)
	return pow_n

def test_power_all(n, x):
	print("#1 power({}, {}): {}".format(n, x, power_1(n, x)))
	print("#2 power({}, {}): {}".format(n, x, power_2(n, x)))
	print("#3 power({}, {}): {}".format(n, x, power_3(n, x)))
	print("#4 power({}, {}): {}".format(n, x, power_4(n)(x)))

def test_power():
	print("Test power function".center(30, "*"))
	test_power_all(1, -2)
	test_power_all(2, -2)
	test_power_all(2, 0)
	test_power_all(2, 1)
	test_power_all(2, 5)

def main():
	start_0603()
	test_makefunc()
	test_fact()
	test_power()

if __name__ == "__main__":
	main()