#!/usr/bin/env python3
# str is an inner class
# string needs import 
import string

def title(t, num=10, deco='-'):
    s = deco*num + str(t) + deco*num
    print(s)

def test_string():
    title('test_string')
    print('These are all ascii letters:')
    print(string.ascii_letters)
    print('These are printable letters:')
    print(string.printable)

def test_str():
    ''' show some function of str '''
    title('test_str()')
    print('Escapt characters:')
    print(r"\' \\ \n \r \t \b \f \ooo \xff")
    print('raw string: r"this string"')
    print('str operator: +, *')
    print('a' + 'b' + 'c')
    print('def*3: ' + 'def'*3)
    print("1abc".find("abc"))
    print('相邻的字符串会自动合并：')
    print('x' 'y' 'z')
    print('字符串支持下标访问')
    print('昔日王谢堂前燕，飞入寻常百姓家'[-1::-1])
    print('喜笑颜开'[3])
    print('喜笑颜开'[0:5])
    s = "first"
    t = s[::-1]
    print(s, t)

def test_str2():
    title('test_str2()')
    s = 'this_is_a_string'
    # note: s[:i] + s[i:] 等于 s
    w = s[:2] + s[2:]
    print(w)
    # note: you can change str like this:
    # t = s[:3] + 'insert' + s[3:]
    s = 'my apple'
    t = s[:3] + 'good ' + s[3:]
    print(s)
    print(t)
    print('you can write this:("hel" "lo")')
    print('this equal to "hello"')
    print("python has no 'char' type")

def test_str3():
    title('test_str3')
    print('some usual varient name:')
    print(' s, t: varient')
    print(' n, i, j, k: integers')
    print(' x: any type')


if __name__ == "__main__":
    test_string()
    test_str()
    test_str2()
    test_str3()

