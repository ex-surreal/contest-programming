import random, time
from random import randint

random.seed(time.clock())

tst = 10

print tst

for i in range(tst):
    n = 100000
    print n
    a = [i for i in range(1, n+1)]
    b = [i for i in range(1, n+1)]
    c = [i for i in range(1, n+1)]
    random.shuffle(a)
    random.shuffle(b)
    random.shuffle(c)
    for i in range(n):
        print a[i], b[i], c[i]
