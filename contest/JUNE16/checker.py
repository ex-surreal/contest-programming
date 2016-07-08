n = int(raw_input())

F = [int(x) for x in raw_input().split(' ')]

q = int(raw_input())

def get_ans(u):
    pi = 1
    for i in range(0, n, u):
        pi *= F[i]
    r = pi % 1000000007
    while pi > 9:
        pi /= 10
    return pi, r

for i in range(q):
    s = raw_input()
    if s[0] == '2':
        o, u = [int(x) for x in s.split(' ')]
        a, b = get_ans(u)
        print a, b
    else:
        o, u, v = [int(x) for x in s.split(' ')]
        u -= 1
        F[u] = v

