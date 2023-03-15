#!/usr/bin/env python3

#
# 递归-二分查找法
#
# 递归实现二分查找，算法比较严谨，不会重复查找
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
def search(seq, val):
	'''
	在已经排序的序列seq中，查找值val的位置
	如果找到，则返回位置Index，如果没有找到，则返回None
	使用递归的二分法
	'''
	high = len(seq) - 1
	return bin_search(seq, val, 0, high)

def return_nothing():
	return
# 正确完整的二分查找算法
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

def test_search():
	l = [x for x in range(100)]
	x = 99

	length = len(l)
	print("list: ", l)
	for i in range(length):
		print("{}:{:2}".format(i, l[i]), end = ' ')
	print()
	print("search value: ", x)
	print("result...")
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
	n = return_nothing()
	print("return_nothing:", n)
	pass

main()
