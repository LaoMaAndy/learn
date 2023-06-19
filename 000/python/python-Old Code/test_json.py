import json

file_name = 'number.json'
number = [2, 3, 4, 5, 6]
try:
	with open(file_name, 'w') as fp:
		json.dump(number, fp)
except:
	print("Can not write into: " + file_name)
else:
	print("Write to file.")
