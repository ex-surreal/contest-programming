from random import randint, seed
from time import time

seed(time())

n = 1000
k = 963761198400L

print n, k

for i in range(n):
    print randint(1, 1000000)*randint(1, 1000000),
