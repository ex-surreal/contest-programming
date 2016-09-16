from random import randint, seed, choice
from time import time

seed(time())

tst = input()
N = input()
print tst

while tst > 0:
    m = randint(1, N)
    n = randint(1, N)
    print m, n
    for i in range(m):
        print ''.join([choice('.WR') for x in range(n)])
    tst -= 1

