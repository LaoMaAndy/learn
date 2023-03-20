#!/usr/bin/python3
# time库
from time import *
import a63闭包递归

def test_time():
    s = 3
    t1 = time()
    sleep(s)
    t2 = time()
    print("After sleep {}sec, t1-t1:{:.6f}".format(s, t2 - t1))

def main():
    test_time()

if __name__ == "__main__":
    main()
