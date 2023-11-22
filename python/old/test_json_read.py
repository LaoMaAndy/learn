import json

file_name = "number.json"
try:
	with open(file_name) as fp:
		number = json.load(fp)
except FileNotFoundError:
	print("can not found file: " + file_name)
else:
	print(number)
	for n in number:
		print(str(n))
