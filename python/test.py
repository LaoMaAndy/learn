#!/usr/bin/env python3
r'''
'''
class C1():
    ''' 再次实验一下类变量、实例变量'''
    pub_l = [1, 2, 3]
    pub_list_2 = [4, 5, 6]
    pub_s = 'pub string'
    def __init__(self, a):
        self.private = 'private'
        title = a + ' : init'
        self.prn(title)
    def change(self, a):
        self.pub_s += ' + '
        self.pub_s += a
        self.pub_l.append(a)
        self.pub_list_2 = list([a])
        self.private = a
        title = 'change: ' + a
        self.prn(title)
    def prn(self, a='prn'):
        print(a.center(20, '-'))
        print(f'{self.pub_l      = }')
        print(f'{self.pub_s      = }')
        print(f'{self.pub_list_2 = }')
        print(f'{self.private    = }')
        print()

def test_C1():
    prn_title('再次实验类变量、实例变量')
    a = C1('a')
    b = C1('b')
    c = C1('c')
    a.change('a: xxxx')
    b.prn('b')
    print('Change C1.pub_s = "changed"')
    C1.pub_s = 'changed'
    a.prn('a')
    b.prn('b')
    c.prn('c')


if __name__ == '__main__':
    print(__doc__)
    def test():
        print('test.py')
        test_C1()
    test()