import random
import time

random.seed(time.clock())
randint = random.randint

n = int(raw_input())

print n

for i in range(n):
    a = randint(0, 50000)
    b = randint(a, 50000)
    c = randint(1, b-a+1)
    print a, b, c

