n = int(raw_input())
a = [int(x) for x in raw_input().split(' ')]
d = {}
limit = 10**9
ans = a.count(0)

for x in a:
    if not d.get(x):
        d[x] = 0
    d[x] += 1

for i in range(n):
    for j in range(n):
        if i != j and (a[i] != 0 or a[j] != 0):
            x, y = a[i], a[j]
            d[x] -= 1
            d[y] -= 1
            c = 2
            while -limit <= x and x <= limit and -limit <= y and y <= limit:
                x, y = y, x+y
                if d.get(y) and d[y] > 0:
                    d[y] -= 1
                    c += 1
                else:
                    break
            ans = max(c, ans)
            x, y = a[i], a[j]
            d[x] += 1
            d[y] += 1
            while c > 2:
                x, y = y, x+y
                d[y] += 1
                c -= 1
print ans
