d = {'aaa': 1, 'bbb': 2, 'ccc': 3}
for key in d:
	print(key, 'corresponds to:', d[key])
print("----------")
for key, value in d.items():
	print(key, 'corresponds to:', value)
print("----------")
names = ['anne', 'beth', 'georage', 'damon']
ages = [12, 45, 32, 102]
list(zip(names, ages))
for name, age in zip(names, ages):
	print(name, 'is', age, 'years old')