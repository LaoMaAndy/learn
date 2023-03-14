# ==== 字典 数据类型 ==== #
def test_dict():
	d = {'x' : 1, 'y' : 2, 'z' : 3}
	print("Print dict key:")
	for key, value in d.items():
		print(key, '->', value)
	for key in d:
		print(key, 'corresponds to', d[key])
	for key, values in d.items():
		print(key, '=>', values)

def test_zip():
	print('test_zip:')
	a = [1, 2, 3, 4]
	b = ['a', 'b', 'c', 'd']
	c = list(zip(a, b))
	print(c) 

def test_copy():
	print("test_copy")
	l = ['foo', 'bar', 'baz']
	d = {'a' : 1, 'b': l, 'c' : 'string', 'd' : {'dd': 14}}
	print("d : ", d)
	e = d.copy()
	print("e : ", e)
	e['b'].remove('bar')
	#l = ['new l']
	print('l: ', l)
	print("e: ", e)
	print("d: ", d)
	d2 = {}.fromkeys(l)
	print("d2: ", d2)
	# d = d2 + {}.fromkeys(["some", "new", "input"])
	d2.update(d)
	print("d2.update(d): ", d2)
	print("fromkeys, d:", d)
	print("d.items()", d.items())
	print("d.keys()", d.keys())

def test_comp():
	girls = ['alice', 'bernice', 'clarice']
	boys = ['chris', 'arnold', 'bob']
	letterGirls = {}
	print('girls', girls)
	print('boys', boys)

def main():
	变量名 = 1
	print('可以用中文的变量名:', 变量名)
	test_dict()
	test_zip()
	test_copy()
	test_comp()

if __name__ == '__main__':
	main()