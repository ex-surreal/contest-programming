class WalkOverATree():
	def maxNodesVisited(self, parent, L):
		n = len(parent) + 1
		depth = [0]*n
		for u in reversed(range(n-1)):
			depth[parent[u]] = max(depth[parent[u]], depth[u+1]+1)
		d = depth[0]
		if d >= L:
			return L+1
		return min(n, (L-d)/2+d+1)