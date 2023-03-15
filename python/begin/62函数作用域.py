#!/usr/bin/env python3
# 递归调用

def p6_2():
	print('6.5 作用域')
def test_scope():
	func_n = 12
	func_d = {}
	func_l = []
	func_t = (1,)
	func_i = 10
	return vars()

def main():
	p6_2()
	test_scope()
def prn_vars(v):
	for k, v in v.items():
		print('{:<20s} : {:<20s}'.format(str(k), str(v)))
def test_glob():
	# 使用globals() 访问全局变量
	# 只读全局变量时，使用这种方式
	# 变量名称作为字符串使用
	print(globals())
	print(globals()['i'])

	# 如果需要对全局变量进行修改
	# 使用global进行修改
	global i
	#print("i : ", i)
	i += 1
	print("i += 1: ", i)

d = {}
l = []
t = (1,)
i = 10

if __name__ == '__main__':
	main()
	print('Current vars:')
	v = vars().copy()
	prn_vars(v)
	vars()['i'] += 1
	print("vars().['i'] += 1", vars()['i'])
	v = test_scope()
	prn_vars(v)
	test_glob()
