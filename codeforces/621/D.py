import math
x, y, z = raw_input().split(' ')

ix = int(float(x)*10)
iy = int(float(y)*10)
iz = int(float(z)*10)

def bigger(x1, y1, z1):
    return z1*math.log(y1) + math.log(math.log(x1))


if ix == 1 and iy == 1 and iz == 1:
    print "x^y^z"
elif ix == 1 and iy == 1:
    print "z^x^y"
elif ix == 1 and iz == 1:
    print "y^x^z"
elif iy == 1 and az == 1:
    print "x^y^z"
elif ix == 1:
    if iy**iz >= iz**iy:
        print "y^z^x"
    else:
        print "z^y^x"
elif iy == 1:
    if ix**iz >= iz**ix:
        print "x^z^y"
    else:
        print "z^x^y"
elif iz == 1:
    if ix**iy >= iy**ix:
        print "x^y^z"
    else:
        print "y^x^z"
else:
    a, b, c = bigger(x, y, z), bigger(y, x, y), bigger(z, x, y)
    q, w, e = 0, 0, 0
    if iy**iz < iz**iy:
        a = bigger(x, z, y)
        q = 1
    if ix**iz < iz**ix:
        b = bigger(y, z, x) 
        w = 1
    if ix**iy < iy**ix:
        c = bigger (z, y, x)
        e = 1
    if a >= b && a >= c:
        if q == 1:
            print ""
