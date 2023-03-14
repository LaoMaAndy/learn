#!/usr/bin/env python3
def test_slice():
	print('=== test_slice ===')
	name = ['Alice', 'Beth', 'Cecil', 'Dee-Dee', 'Earl']
	print(name)
	del name[0]
	print(name)
	name[0:0] = ['Andy']
	print(name)

def test_list():
	print("=== test_list ===")
	a = [1, 2, 3]
	a.append(4)
	print(a)
	b = ['a', 'b']
	a.append(b)
	print("append", a)
	a.extend(b)
	print("extend", a)
	n_a = a.count('a')
	print("count a", n_a)
	num = [1, 2, 3, 4]
	num[0:0] = [10]
	print("num: ", num)
	num[-1:-1] = [5]
	print("num: ", num)
	num.pop(1)
	print("num: ", num)
	num.insert(0, 'start')
	print("num: ", num)
	num.insert(0, list('abc'))
	print("num: ", num)
	num.extend(list('KBQ'))
	print("num: ", num)
	k_num = []
	k_num = list(reversed(num))
	print("reversed: ", k_num)
	# num.sort();
	# print("num: ", num)
	number = [3, 4, 7, 2, 1, 0, 10]
	number.sort()
	print("number: ", number)
	print("number sorted:", sorted(number))
	#num.sort(key = len, reverse = True)

from string import Template
def test_format():
	f = "hello, %s, %s good for you?"
	val = ('world', 'hot')
	print("test_format()")
	b = f % val
	print(b)
	print('val: ', val)
	tmp = Template("hello, $who! $what good for you?")
	a = tmp.substitute(who="You", what="weather")
	print("Template substitute:", a)
	print('-------')
	a = '{}, {} and {}'.format('a', )

def main():
	test_slice()
	test_list()
	test_format()

main()