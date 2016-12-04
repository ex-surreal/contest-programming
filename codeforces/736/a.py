n = input()

f = [0]*100

f[0], f[1] = 1, 2

for i in range(2, len(f)):
    f[i] = f[i-1]+f[i-2]

for i in range(len(f)):
    if f[i] > n:
        print i-1
        break

