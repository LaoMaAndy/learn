#!/usr/bin/env python3
r'''
查找和判断是否素数
'''
import math

def is_prime(n):
    max_factor = int(math.sqrt(n)) + 1 
    # max_factor = n
    for i in range(2, max_factor):
        if n % i == 0:
            # print(n, '=', i , '*', n//i)
            return False
    # print(n, 'is a prime.')
    return True

def list_prime(i):
    ret = []
    for n in range(2, i):
        if is_prime(n):
            ret.append(n)
    return ret

def test_list_prime():
    print(list_prime(100))

if __name__ == '__main__':
    test_list_prime()