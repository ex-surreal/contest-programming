class BearCavalry():

    mod = 10**9 + 7

    def countWays(self, a, b, k):
        ret = 1
        j = 0
        for i in range(len(a)):
            while j < len(b) and b[j]*a[i] < k:
                j = j + 1
            ret = ret*max(j-i, 0) % self.mod
        return ret

    def countAssignments(self, warriors, horses):
        w = warriors[0]
        a = list(reversed(sorted(warriors[1:])))
        n = len(horses)
        ret = 0
        for i in range(n):
            b = list(sorted(horses[:i] + horses[i+1:]))
            ret = (ret + self.countWays(a, b, w*horses[i])) % self.mod
        return ret
