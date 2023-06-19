i = 0
while i < 10:
	print("i: {}".format(i))
	i += 1
name = ''
while not name:
	name = input("Please input your name: ")
	if not name:
		print("\tEnpty input.")
print("hello, {}".format(name))