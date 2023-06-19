def func(*p):
	for item in p:
		print(str(item))
def foo(**p):
	for key, value in p.items():
		print(key + ": " + str(value))
	print('change zitem[0] to none:')
	index = list(p.keys())
	p[index[0]] = 'none'
	for key, value in p.items():
		print(key + ": " + str(value))

t = (2, 'that', 1.5, [10, 11], {'age':13})
for item in t:
	print(str(item))

func(t)
func(2, 'that', 1.5, [10, 11], {'age':13})
foo(name='andy', gender='male', age=13, others=t)