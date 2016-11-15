tst = input()
cas = 0

def check(p, n):
    low, high = 2, n
    while low <= high:
        mid = (low+high)/2
        if (mid**(p+1)-1)/(mid-1) < n:
            low = mid + 1
        else:
            high = mid - 1
    if (low**(p+1)-1)/(low-1) != n:
        return -1
    return low

while cas < tst:
    cas += 1
    n = input()
    ans = n
    for i in range(1, 70):
        t = check(i, n)
        if t != -1:
            ans = t
    print 'Case #{}:'.format(cas), ans

