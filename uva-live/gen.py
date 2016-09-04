from random import randint, seed, sample
from time import time

seed(time())

tst = input()

while tst > 0:
    n = randint(1, 10)
    a = sorted(sample(range(1, 360), n))
    tst -= 1
