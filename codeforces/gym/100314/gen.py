import random

n = int(raw_input())
print n, 10, 500

for i in range(n):
    print .000000000000000000001, n-1, n,
    for j in range(n):
        if j != i:
            print j+1,
    for j in range(n):
        print j+1,
    print

