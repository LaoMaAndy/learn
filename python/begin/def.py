#!/usr/bin/env python3
# ========================
# 简单语句、函数
# 值传递、引用传递
def suqare(i):
	return i * i
def add(i):
	i += 1
	return i
def add_list(l):
	i = 0
	size = len(l)
	while i < size:
		l[i] = l[i] + 1
		i += 1
def test_simple():
	m = 3
	print("start: m=", m)
	add(m)
	print("after: m=", m)
	l = [1, 2, 3]
	print("start: l = ", l)
	add_list(l)
	print("after: l = ", l)
# ========================
# Fibonacci数列
# 2022-02-11
# Coder: Andy
#
def fib(n): 
	"""打印Fibonacci数列。 共n个数字，中间一个空格"""
	count = 1
	a, b = 0, 1
	while count <= n:
		a,b = b, a + b 
		print(a, end = ' ')
		count += 1
	return a
def test_fib():
	fib(10)
	print("\n========")
	print(suqare(100))
# ========================
# Docstring 功能
# 使用魔法属性 __doc__ 调用
def my_function():
	"""Do nothing, but document it. ...

	Python 解析器不会删除 Python 中多行字符串字面值的缩进，因此，文档处理工具应在必要时删除缩进。 	这项操作遵循以下约定:文档字符串第一行 之后的第一个非空行决定了整个文档字符串的缩进量(第一 行通常与字符串开头的引号相邻，其缩进在字符串中并不明显，因此，不能用第一行的缩进)，然后，删 除字符串中所有行开头处与此缩进“等价”的空白符。不能有比此缩进更少的行，但如果出现了缩进更 少的行，应删除这些行的所有前导空白符。转化制表符后(通常为 8 个空格)，应测试空白符的等效性。
	"""
	pass
def test_doc():
	print(my_function.__doc__) 
	print("\n")
# ========================
# 函数参数
def hello_1(greeting, name):
	print('{}, {}'.format(greeting, name))
def hello_2(name, greeting):
	print('{}, {}'.format(name, greeting))
def test_para():
	hello_1('hello', 'world!')
	hello_2('hello', 'world!')
# ========================
class MyBook:
	def __init__(self, book=[]):
#		self.books=book.copy() or []
		self.books=book[:]
		self.index = 123
	def add(self, book):
		self.books.append(book)
		self.index += 1
	def __str__(self):
		result = "Books: "
		for element in self.books:
			result = result + repr(element) + ' ' 
		result = result + "Index: " + str(self.index)
		return result
	def print(self):
		p = ""
		for b in self.books:
			p = p + str(b) + ' '
		print("books: ", p)
		print("index number", self.index)
#---test this class ---#
def test_class():
	books = ['computer', '历史书', '科技书']
	m = MyBook(books)
	n = MyBook()
	m.add("教材")

	print("\n对象m的内容：")
	print(m)

	print("\n对象n的内容：")
	print(n)

	print("\n变量books的内容")
	print(books)
# ========================
# 描述 点的类
class Point:
	def __init__(self, x = 0, y = 0):
		self.x = x 
		self.y = y 
	def movex(self, x = 0):
		self.x += x 
	def movey(self, y = 0):
		self.y += y 
	def moveto(x, y):
		self.x = x 
		self.y = y 
	def __str__(self):
		result = "Point(" 				\
				 + repr(self.x) + ", "	\
				 + repr(self.y) + ")"
		return result;
class Rgb:
	def __init__(self, red=128, green=128, blue=128):
		self.red = red
		self.green = green 
		self.blue = blue 
	def __str__(self):
		result = "Rgb(red:" + repr(self.red)	 \
				  + " green:" + repr(self.green) \
				  + " blue:" + repr(self.blue)	 \
				  + ")"
		return result
class Pixel(Point,Rgb):
	def __init__(self):
		return
#---test ---#
def test_point():
	a = Point()
	print(a)
	a.movex(12)
	print(a)
	rgb = Rgb(1,1,1)
	print(rgb)
# ========================
# curses 简单使用
def test_curses():
	import curses
	print("Preparing to initialize screen...")
	screen = curses.initscr()
	print("Screen initialized.")
	screen.addch(5, 5, "Y")
	screen.addstr(2, 2, "Curses is running!")
	screen.addstr(3, 2, "显示中文")
	num_rows, num_cols = screen.getmaxyx()
	scr_size = "屏幕尺寸" + "垂直方向 最大行 Y：" + repr(num_rows)  \
				+ "; 水平方向 最大列 X:" + repr(num_cols)
	screen.addstr(5, 2, scr_size)
	screen.addstr(6, 2, "\n按任意键继续")
	i = 0
	while (i < num_cols):
		screen.addch(0, i, "█")
		i = i + 1
	i = 0
	while (i < num_rows):
		screen.addch(i, 0, "｜")
		i = i + 1
	screen.refresh()
	# c = screen.getch()
	curses.napms(500) #延时
	curses.endwin()
# ========================
# __name__ 属性
def test_name():
	print("__name__:\n", __name__)

# ========================
# try except 异常
def div(a, b):
	try: 
		return a/b
	except ZeroDivisionError:
		return 0
def unsafe_div(a, b):
	return a/b
def test_div():
	c = div(20, 0)
	print("Test try / except, 20 / 0: ", c)
	c = unsafe_div(20, 0)
# ========================
# Some build-in function
def test_build_in():
	i = 65
	c = bin(i)
	print("65 to bin is:", c)
	# 
	print("complex multi is:", (2+2j)*(3+3j))
	# --- dir（[object]) 列出对象的大部分属性
	p = Point(1,2)
	print(dir([p]))
	# --- divmod(a, b) 返回（a // b, a % b)
	print(divmod(45,13))
	# --- eval(string[, globals[, locals]]) 求表达式的值
	print(eval("2 + (5 % 3) * 2 ** 2"))
	# --- filter(function, sequence) 返回一个列表，
	#				调用function为真的sequence元素
	# --- format(value[, format_spec]) 返回格式化后的字符串
	
# ========================
# 主函数main
def main():
	# test_simple()
	# test_fib()
	# test_doc()
	# test_para()
	# test_class()
	# test_point()
	# #test_curses()
	# test_name()
	# test_div()
	test_build_in()
# ========================
# 判断，然后执行main()
if __name__ == "__main__":
	main()
	# print("This is a main function\n")