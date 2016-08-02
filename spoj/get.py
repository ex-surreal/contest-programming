import random
import string
import time

random.seed(time.time())

n = 10 #random.randint(1, 10)

for i in range(n):
    l = 100000 #random.randint(1, 100000)
    print ''.join(random.choice('a') for x in range(l))
