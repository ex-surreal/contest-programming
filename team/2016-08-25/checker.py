import math
eps = 1e-4

def read_out(file):
    a, b = [], []
    with open(file, 'r') as f:
        lines = f.read().splitlines()
        j, l = 0, len(lines)
        while j < l:
            x = int(lines[j])
            d = float(lines[j+1])
            j += 2
            a.append(x)
            b.append(d)
    f.close()
    return (a, b)

outD, outR = read_out('out.out')
ansD, ansR = read_out('ans.out')

if len(outD) != len(ansD):
    print 'Fail'

for i in range(len(outD)):
    if outD[i] != ansD[i] or math.fabs(ansR[i]-outR[i]) > eps:
        print i+1, '{} {} {} {}'.format(outD[i], ansD[i], outR[i], ansR[i])

