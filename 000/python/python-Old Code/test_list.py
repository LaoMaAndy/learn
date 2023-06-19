l = ['abc', 'bbc', 'cccc']
#l = [1, 2, 3]
print(l)
print('max(l): ' + max(l))
print(range(1, 20, 2))
print(list(range(1, 20, 2)))
#Python Enhancement Proposals   nationality
d = {'name' : 'Kevin', 'age' : 45, 'Gender' : 'male', 'nationality' : 'china'}
d['color'] = 'yellow'
for index, value in d.items():
	print(index + ': ' + str(value))
print(d)
for index in d:
	print(d)
print('-------')
for index in d.keys():
	print(str(index))
for value in d.values():
	print(str(value))
print('--- condition test ---')
if ('Kevin' in d.values()):
	print('Kevin in d.values()')
else:
	print('Kevin don\'t in d.values()')
print(d.keys())
print(d.values())
l = []
for index in d.keys():
	l.append(index)
	print('append: ' + l[-1])
del d['name']
print(R"del d['name']")
print(d)
print('list function')
ls = [1, 3, 5, 4, 9, 10, 0, 2, 3, 5, 19, 19, 18, 10, 20]
print(ls)
# for i in ls.sort():
# 	print(i)
ls.sort()
print(ls)
sorted(ls, reverse=True)
print(ls)
ls.reverse()
del(ls[-1])
print(R"del(ls[-1]): ")
print(ls)
ls.remove(3)
print(R"ls.remove(1)")
print(ls)
ls.append(100)
print(ls)
del(ls[0])
print(ls)
l = ls
print(l)
l.sort()
print(ls)
l = ls[0:2]
print(l)
l.sort(reverse=True)
l[-1] = 123
print(l)
print(ls)
strs = ['aaaa', 'bbb', 'ccc', 'ddd', 'eee', 'fff']
slice_str = strs[:3]
slice_str[0] = 'kkk'
print(strs)
print(slice_str)
tu = (1, 2, 3, 4, 5, 6)
tu_slice = list(tu[:])
print(tu)
print(tu_slice)
