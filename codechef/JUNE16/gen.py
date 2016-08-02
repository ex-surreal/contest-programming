import random
import time

random.seed(time.time())

n, q = [int(x) for x in raw_input().split(' ')]
print n

for i in range(n):
    print random.randint(1, 10),
print

print q

for i in range(q):
    if random.randint(0, 1) == 0:
        print 1, random.randint(1, n), random.randint(1, 10)
    else:
        print 2, random.randint(1, n);
