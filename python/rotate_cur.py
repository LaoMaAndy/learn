#!/usr/bin/env python3
'''
一个动态效果的打印。生成一个旋转的字符。字符可以修改。
使用方法：
    import Aprint.aprint
    aprint(...)
需要修改：
    1 - 改为一个库
    2 - 修改print 参数，使之接近于__buildins__.print()

附注：
为了支持 with 语句，需要定义类方法：
    __enter__(self) and __exit(self)__

class Meter():
    def __init__(self, dev):
    def __enter__(self):
        return self
    def __exit__(self, exception_type, exception_value, exception_traceback):
'''
import time
import threading

class APrint():
    #_print = print  # other way override print() of builtins
    _act = False
    def __init__(self):
        self.t = threading.Thread(target=self._rotate)

    def __del__(self):
        __builtins__.print('\b', end = '', flush = True)
        self._act = False

    def __enter__(self):
        self._act = True
        self.t.start()
        
    def __exit__(self, exception_type, exception_value, exception_traceback):
        __builtins__.print('\b', end = '', flush = True)
        self._act = False

    def prn(self, s):
        __builtins__.print('\b', str(s), sep='', flush = True)

    def print(self, s):
        __builtins__.print('\b', str(s), sep='', flush = True)
        if self._act == False:
            self.t1 = threading.Thread(target=self._rotate)
            self._act = True
            self.t1.start()

    def _rotate(self):
        s = '/-\\|'
        # s = '<->'
        l = len(s)
        i = 0
        while True:
            if self._act == False: break
            __builtins__.print(s[i%l], end='', flush = True)
            time.sleep(0.09)
            i += 1;
            if i >= 30: 
                self._act = False
                break;
            __builtins__.print('\b', end='')
        # _print('\b ', flush = True)

def test_APrint():
    a = APrint()
    with a:
        for i in range(10):
            a.prn('fdjsa;jfdsafdsa')
            time.sleep(0.4)
    print("end".center(20, '-'))

def test_APrint2():
    a = APrint()
    for i in range(10):
        a.print('1234567890')
        time.sleep(1)

def rotate_cur(n=0):
    s = '/-\\|'
    i = n if n > 0 else -n
    while (n == 0) or (i != 0):
        print(s[i%4], end='', flush = True)
        time.sleep(0.09)
        i -= 1;
        print('\b', end='')
    print(' \b', end='', flush = True)

def print_rep(s, n):
    for i in range(n):
        print('\b[', i, ']', s, sep = '', flush = True)
        time.sleep(0.2)

def test_print_rep():
    t = threading.Thread(target=rotate_cur, args=(50,))
    t.run()
    print_rep('abce32ef' * 5, 40)
    #print("this s a test\n")

def main():
    #test_APrint()
    test_APrint2()
    #test_print_rep()

if __name__ == '__main__':
    main()
    

