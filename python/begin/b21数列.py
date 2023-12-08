#!/usr/bin/python3
# 2023-3-15整理
# 数列
def fibo(n):
    count  = 0
    a, b = 0, 1
    print(1, end = ' ')
    while count < n:
        a, b = b, a + b
        print(b, end = ' ')
        count += 1
    return a
    
def main():
    for i in range(10):
        fibo(i)
        print()
    print('\n')

print("This is a test")
print("Edit from iCloud")
main()
print("==== format string ====")
import math
i = 1
for i in range(20):
    print("{:<+10.2f}".format(12.34567890), end ='')
    print("{:#<+10.2f}".format(12.34567890), end ='')
    i += 1
    print()
