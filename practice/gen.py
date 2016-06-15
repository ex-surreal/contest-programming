import random

def fun(m):
    i = 2
    while i < m:
        res = i
        for j in range(20):
            res = res*res%m
        if res == 1:
            return i, j
        i += 1
    return -1

while True:
    try:
        k = raw_input()
    except:
        pass
    print fun(int(k))
    print "OK"

