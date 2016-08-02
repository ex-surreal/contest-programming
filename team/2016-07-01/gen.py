import random
import time

random.seed(time.clock())

randint = random.randint

q, n = [int(x) for x in raw_input().split()]
print q

for i in range(q):
    o = "ABCS"
    f = randint(0, 3)
    l = randint(1, n)
    r = randint(l, n)
    if f == 2:
        print o[f], l, r, randint(-100000, 100000)
    else:
        print o[f], l, r
