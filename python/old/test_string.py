string = ' this is A test  '
print(string.title())
print(string.upper())
print(string.lower())
print(string.strip())
print(string)
print("test split()")
words = string.split()
i = 0
for w in words:
	i += 1
	print(str(i) + ": " + w)
print(string.replace('this', 'That'))
print(string)
