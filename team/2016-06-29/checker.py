n, q = [int(x) for x in raw_input().split()]

a = [0 for i in range(n)]

for i in range(q):
    o, l, r = [int(x) for x in raw_input().split()] 
    if o == 0:
        for i in range(l, r+1):
            a[i] += 1
    else:
        ans = 0
        for i in range(l, r+1):
            if a[i] % 3 == 0:
                ans += 1
        print ans
