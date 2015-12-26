class WaterTank():

    def check(self, t, x, C, r):
        now = 0.0
        for i in range(len(t)):
            now = max(0.0, now + 1.0*t[i]*x[i] - t[i]*r)
            if now > C:
                return False
        return True

    def minOutputRate(self, t, x, C):
        high = 1.0*max(x)
        low = 0.0
        while abs(high-low) > 1e-9:
            mid = (high+low)/2
            if self.check(t, x, C, mid):
                high = mid
            else:
                low = mid
        return high


print WaterTank().minOutputRate(
        [9,3,4,8,1,2,5,7,6],
        [123,456,789,1011,1213,1415,1617,1819,2021],
        11
    )
