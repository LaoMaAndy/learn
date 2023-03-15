#!/usr/bin/env python3
#
def p6_1():
	'''Chapter 6 examples'''
	print('This is chapter 6 examples')
	print('print doc string:')
	print(p6_1.__doc__)

def ret_diff(i):
	i = int(i)
	print("i's value: ", i)
	if i > 5:
		return 'Bigger than 5'
	elif i > 0:
		return
	else:
		return i
def ret_list():
	i = list(range(10))
	print("list i: ", i)
	return i;
def test_ret_list():
	i = ret_list()
	i[4:] = list('abcdefgh')
	print("return list: ", i)
def list_que():
	a = list('123')
	b = list('123')
	e = (a == b)
	print('a == b? ', e)
	e = (a is b)
	print('a is b? ', e)
	e = (a is not b)
	print('e = (a is not b)?', e)
def init(data):
	data['first'] = {}
	data['middle'] = {}
	data['last'] = {}
def lookup(data, label, name):
	s = data[label].get(name)
	return s
def store(data, *full_names):
	for full_name in full_names:
		print("Test_store: ", data)
		names = full_name.split()
		if len(names) == 2:
			names.insert(1, '')
		print("split names: ", names)
		labels = 'first', 'middle', 'last'

		for label, name in zip(labels, names):
			people = lookup(data, label, name)
			if people:
				people.append(full_name)
				print("After append".center(20, '*'))
				for k, v in data.items():
					print(k, ":", v)
			else:
				data[label][name] = [full_name]
		print("after store: ".center(20, '*'))
		for k, v in data.items():
			print(k, ":", v)
		for i in data:
			print(str(i).center(20, '*'))
			for v in data[i]:
				print(str(v), sep=' ')
				print(data[i][v])
def test_init_lookup():
	n = {}
	init(n)
	print("test_init_lookup: ", n)

def test_store():
	n = {}
	init(n)
	store(n, "andy mi li", "andy bb li", "andy cc qi")
	store(n, "andy bb li")
	s = lookup(n, 'first', 'andy')
	print('lookup first andy:'.center(30, '*'))
	print(s)

def para(name = "", greet = ""):
	print("{}, {} !".format(name, greet))
	pass
def test_para():
	para(greet = 'andy', name = 'how are you')
	para("May", "good")
	pass
def func_add(a = 0, b = 0):
	print("function call".center(20, '*'))
	print("a: ", a, "b: ", b, "a + b", a + b)
	return a + b
def test_func_add():
	p = [20, 10]
	func_add(*p)

def main():
	p6_1()
	print(ret_diff(-1))
	test_ret_list()
	list_que()
	test_init_lookup()
	test_store()
	test_para()
	test_func_add()

if (__name__ == '__main__'):
	main()
