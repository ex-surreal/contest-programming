class Solver588B:
	"""docstring for Solver588B"""
	
	def __init__(self, n):
		self.n = n

	def solve(self):
		d = 2
		t = self.n
		ret = 1
		while d*d <= t:
			if t % d == 0:
				ret = ret * d
			while t % d == 0:
				t = t/d
			d = d + 1
		return ret * t

n = int(raw_input())
solver = Solver588B(n)
print solver.solve()
