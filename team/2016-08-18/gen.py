from random import seed, randint
from time import time

seed(time());
n = int(raw_input())
print n

for i in range(n):
    print randint(1, 10000000000)
