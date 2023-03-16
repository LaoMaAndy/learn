#!/usr/bin/env python3

#
# 递归-二分查找法
# 递归实现二分查找，算法比较严谨，不会重复查找
# 递归的实现：
# 	是否达成：判断是否已经达成要求
#	基线问题：如果已经达成要求，则返回某个值
#	递归问题：如果尚未达成，则将问题分解或降级，进行递归调用
def test_dev():
	print("5 / 2 = ", 5 / 2)
	print("1 / 2 = ", 1 / 2)
	print("-1 / 2 = ", -1 / 2)
	print("-3 / 2 = ", -3 / 2)

	print("5 // 2 = ", 5 // 2)
	print("1 // 2 = ", 1 // 2)
	print("-1 // 2 = ", -1 // 2)
	print("-3 // 2 = ", -3 // 2)
def for_range():
	l = range(10)
	i = 0
	while i < len(l):
		print(i)
		i += 1
# 二分查找法的主函数
# 因为递归部分使用的参数较多，编写一个主函数
# 调用递归函数
def search(seq, val):
	'''
	在已经排序的序列seq中，查找值val的位置
	如果找到，则返回位置index，如果没有找到，则返回None
	使用递归的二分法
	'''
	high = len(seq) - 1
	return bin_search(seq, val, 0, high)
# 完整的二分查找算法
def bin_search(seq, num, low, high):
	'''
	递归的二分查找法：
	先计算基准条件：
		取中间数，判断是否已经找到，
		然后计算上下边界，如果边界已经重叠，则值不存在
	递归：
		递归的时候修改边界：
		(low, mid - 1) 和 (mid + 1, high)
		这样不会重复，查找的次数最少
	'''
	mid = (low + high) // 2
	# 显示现场数据，当前上/下界限，中间值，位置和大小
	print("low: {:2d} [{:4d}], high: {:2d} [{:4d}], mid:  {:2d} [{:4d}]".\
		format(low, seq[low],high, seq[high], mid, seq[mid]))
	if (seq[mid] == num):
		return mid
	elif low >= high:
		return None
	if seq[mid] > num:
		return bin_search(seq, num, low, mid - 1)
	else:
		return bin_search(seq, num, mid + 1, high)

# 如果return 后没有任何值，则默认返回 None
def return_nothing():
	return

def test_return_nothing():
	n = return_nothing()
	print("return_nothing:", n)

def test_search():
	'''
	测试二分法
	n个排序后的值：l[0]~l[n-1],  查找x
	特别注意，当目标值位于边界[0]、[n-1]时，
	是否能够正确查找
	查找的次数，应该最少
	'''
	l = [x for x in range(100)] # 推导，建立列表
	x = 99						# 查找的目标值

	length = len(l)
	# print("list: ", l)
	# 显示全部数据
	for i in range(length):
		print("{}:{}\t".format(i, l[i]), end = ' ')
	print()
	print("search value: ", x)
	print("searching...")
	p = search(l, x)
	if p == None:
		print("Can't find: ", x)
	else:
		print("posion:", p, "value:", l[p])
	pass

def main():
	# test_dev()
	test_search()
	#for_range()
	test_return_nothing()
	pass

main()
