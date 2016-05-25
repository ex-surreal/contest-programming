import random

for i in range(2500):
    s = []
    for j in range(2500):
        s.append(str(random.randint(0, 1)))
    print ''.join(s)
