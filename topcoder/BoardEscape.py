class BoardEscape():

    def findWinner(self, s, k):
        nimber = {}
        di = [0, 0, 1, -1]
        dj = [1, -1, 0, 0]
        if k > 4:
            k = 4 - k%2
        m = len(s)
        n = len(s[0])
        for i in range(m):
            for j in range(n):
                if s[i][j] != '#':
                    nimber[0, i, j] = 0
        for a in range(1, k+1):
            for i in range(m):
                for j in range(n):
                    if s[i][j] == 'E':
                        nimber[a, i, j] = 0
                    elif s[i][j] != '#':
                        st = set()
                        for t in range(len(di)):
                            x = i + di[t]
                            y = j + dj[t]
                            if (a-1, x, y) in nimber:
                                st.add(nimber[a-1, x, y])
                        nimber[a, i, j] = 0
                        while nimber[a, i, j] in st:
                            nimber[a, i, j] = nimber[a, i, j] + 1
        ans = 0
        for i in range(m):
            for j in range(n):
                if s[i][j] == 'T':
                    ans = ans ^ nimber[k, i, j]
        return 'Alice' if ans else 'Bob'

print BoardEscape().findWinner(
    (
"....................",
"....................",
"....................",
"....................",
"......E.E...........",
".......T............",
"......E.E...........",
"....................",
"....................",
"....................",
"....................",
"......T.............",
".....TET............",
"....................",
"....................",
"....................",
"....................",
"....................",
"....................",
"...................."
), 61
)
