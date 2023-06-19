#count randint( ) 
from random import randint

count = [0 for i in range(100)]
#for i in range(100):
#count.append(0)
for i in range(10000):
	n = randint(0, 99)
	count[n] += 1
for i in range(100):
	print(str(i) + " - " +  str(count[i]))

