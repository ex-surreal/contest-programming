from random import randint, seed
from time import time

seed(time())

tst = input()
N = input()
M = input()
W = input()

while tst > 0:
    tst -= 1
    n = randint(2, N)
    print n, randint(1, n), randint(1, n)
    m, k = randint(n-1, M), randint(1, M);
    print m
    for i in range(n-1):
        print i+2, randint(1, i+1), randint(1, W);
    for i in range(n-1, m):
        print randint(1, n), randint(1, n), randint(1, W)
    print k
    for i in range(k):
        print randint(1, n), randint(1, n), randint(1, W)
