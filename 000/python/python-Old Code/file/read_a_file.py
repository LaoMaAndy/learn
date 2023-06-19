#input a file name and print it

file_name = input("intput a file name: ")
# try:
# 	with open(file_name) as fp:
# 		content = fp.read()
# except FileNotFoundError:
# 	print("file not found: " + file_name)
# else:
# 	print(content)
try:
	with open(file_name) as fp:
		content = fp.readlines()
except FileNotFoundError:
	print("file not found: " + file_name)
else:
	i = 0
	char_count = 0
	all = ""
	for line in content:
		print(str(i) + " : " + line.rstrip())
		i += 1
		all += line
		char_count += len(line)
	word = all.split()
	word_count = len(word)
	print("Totle char: " + str(char_count))
	print("Totle line: " + str(len(content)))
	print("Total words: " + str(word_count))
