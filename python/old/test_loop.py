def sort_list(alist):
	alist.sort()
	print('function sort_list(): ' + str(alist))
flag = 1
while flag:
	print("flag is: " + str(flag))
	flag = 0
print("bool of flag: " + str(bool(flag)))
alist = []
print("list[] bool value is: " + str(bool(alist)))
i = 3
m = (i == 3)
print("m: " + str(m))
print("--- remove key value from list ---")
pets = ['cat', 'cat', 'cat', 'cat']
print(pets)
pets.remove('cat')
print(pets)
#positional arguments.
#Keyword Arguments
alist = [1, 3, 5, 7, 9, 10, 8, 6, 4, 2, 0]
print(alist)
sort_list(alist)
print(alist)
sort_list(alist[:8])
print(alist)