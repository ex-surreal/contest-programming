from random import randint, seed
from time import time


seed(time())

n = randint(4, 10)
m = randint(n-1, n*(n-1)/2);

print n, m

for i in range(m):
    print randint(1, n), randint(1, n);
