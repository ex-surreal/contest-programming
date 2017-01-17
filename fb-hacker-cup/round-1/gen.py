from random import randint, seed
from time import time

seed(time())

tst = input()
print tst

for t in range(tst):
    n, m, k = 100, 5000, 5000
    print n, m, k
    for u in range(2, 101):
        print u-1, u, randint(1, 1000)
    for i in range(99, m):
        u = randint(1, n-1)
        v, w = randint(u+1, n), randint(1, 1000)
        print u, v, w
    for i in range(k):
        print randint(1, n), randint(1, n)

