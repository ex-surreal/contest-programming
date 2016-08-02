dp = [(-1, 1, 1) for x in xrange(1, 5005)];

def get_max(x):
    if dp[x][0] != -1:
        return dp[x]
    a, b, c = 1, 1, 1
    for i in xrange(1, 20):
        for j in xrange(i, 20):
            for k in xrange(j, 20):
                if i*j*k <= x and i*j*k > a*b*c:
                    a, b, c = i, j, k
    dp[x] = (a, b, c)
    return dp[x]

def cal(n, q):
    ans = q*3-6
    t = 0
    while n > 0:
        a, b, c = get_max(n)
        # print n, ' = ', a, b, c
        n -= a*b*c
        ans += a+b+c
        t += 1
        if t == q-2:
            ans += q*3-6
            t = 0
    return ans

def nc3(n):
    return n*(n-1)/2*(n-2)/3

def max_nc3(x):
    for n in xrange(1, x+5):
        if nc3(n) > x:
            return n-1
    return 0

def for1(x):
    ans = 0 
    while x > 0:
        n = max_nc3(x)
        x -= nc3(n)
        ans += n + 1
    return ans

for p in range(1, 5001):
    if for1(p) > 100:
        print p, 2
    for q in range(3, 10):
        if cal(p, q) > 100:
            print p, q

