n = int(raw_input())

a = [int(x) for x in raw_input().split(' ')]

first, last = 0, 0

for i in range(len(a)):
    if a[i] == 1:
        first = i
    if a[i] == n:
        last = i

if first > last:
    first, last = last, first

print max(last, n-1-first)
