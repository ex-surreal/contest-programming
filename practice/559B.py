def smallest(s):
	if len(s) % 2 == 1:
		return s
	p1 = smallest(s[:len(s)/2])
	p2 = smallest(s[len(s)/2:])
	if p1 < p2:
		return p1 + p2;
	return p2 + p1;
p = raw_input()
q = raw_input();
if smallest(p) == smallest(q):
	print "YES"
else:
	print "NO"
