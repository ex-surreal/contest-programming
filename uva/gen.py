from random import randint, seed
from time import time

seed(time())

tst = input()

while tst > 0:
    n = randint(1, 10)
    print n
    a = []
    while n > 0:
        a.append((randint(0, n), randint(0, n)))
        n -= 1
    tst -= 1
    print '\n'.join(['{} {}'.format(x[0], x[1]) for x in a])
print 0
