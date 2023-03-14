#!/usr/bin/env python3

#
# 递归-二分查找法
#

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
def search(seq, num):
	high = len(seq) - 1
	return bin_search(seq, num, 0, high)

def return_nothing():
	return 

def bin_search(seq, num, low, high):
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