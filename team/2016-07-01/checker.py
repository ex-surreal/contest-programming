q = int(raw_input())

a = [0 for i in range(250001)]

for i in range(q):
    s = raw_input()
    if s[0] == 'A':
        l, r = [int(x) for x in s.split(' ')[1:]]
        for i in range(l, r+1):
            a[i] += i-l+1
    elif s[0] == 'B':
        l, r = [int(x) for x in s.split(' ')[1:]]
        for i in range(l, r+1):
            a[i] += r-i+1
    elif s[0] == 'C':
        l, r, x = [int(x) for x in s.split(' ')[1:]]
        for i in range(l, r+1):
            a[i] = x
    else:
        l, r = [int(x) for x in s.split(' ')[1:]]
        ans = 0
        for i in range(l, r+1):
            ans += a[i]
        print ans
