import platform
def test_bool():
	print(int(True + True))
	print((2 == True))

def main():
	test_bool()
	# 显示当前操作系统
	print('Current OS is: ', platform.system(), end = ' ')
	print(platform.release())
	# 打印当前文件名 __file__  为完整路径名
	print("full file name:\n",__file__)
	file_name = str(__file__)	
	# 从右侧查找 / 出现的位置，提取短文件名
	index = file_name.rfind("/")
	short_name = file_name[index + 1:]
	print("short file name:", short_name)
	print("this is main", end = '\n')

if __name__ == "__main__":
	main()