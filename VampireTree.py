class VampireTree(object):

    def maxDistance(self, num):
        n, cnt = len(num), 0
        if sum(num) != 2*(n-1):
            return -1
        for x in num:
            cnt = cnt + abs(x-2)
        return n-cnt/2
