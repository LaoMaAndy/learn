#file_name = input("input file name: ")
file_name = "pi.txt"
try:
	with open(file_name) as fp:
		lines = fp.readlines()
except FileNotFoundError:
	print("file not found: " + file_name)
else :
	text = ""
	for line in lines:
		text += line.strip()
	birthday = input("input your birthday: ")
	if birthday in text:
		print("your birthday is in pi")
	else:
		print("not found")
