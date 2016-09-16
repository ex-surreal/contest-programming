from random import seed, sample
from time import time

seed(time)

tst = input();

print '\n'.join([str(x) for x in sample(range(1, 2**16-1), tst)] + ["0"])

