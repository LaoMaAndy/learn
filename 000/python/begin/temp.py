#!/usr/bin/python3 

# 临时测试

def powers(n = 5):
    return ','.join(str(2**i) for i in range(n))

cmd = 'Pychecker', 'abc'
print(cmd)
print(powers())
print(__name__)