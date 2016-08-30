from random import randint, seed, choice
from time import time

seed(time())

tst = input()
N = input()

for t in range(tst):
    n = randint(1, N)
    print n
    d = {}
    j = 0
    while j < n:
        x, y, z, p = randint(-10000, 10000), randint(-10000, 10000), randint(-10000, 10000), randint(0, 1)
        if not d.has_key((x, y, z)):
            d[(x, y, z)] = True
            j += 1
            print x, y, z, p
