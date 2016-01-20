l, r, k = [int(x) for x in raw_input().split(' ')]

p = 1
ans = []

while p <= r:
    if p >= l:
        ans.append(str(p))
    p *= k

if len(ans) == 0:
    print -1
else:
    print ' '.join(ans)
