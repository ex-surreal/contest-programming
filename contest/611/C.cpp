#include <bits/stdc++.h>

using namespace std;

int cum[505][505];
int cnt[505][505];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int main () {
    ios_base::sync_with_stdio(false);
    string str[505];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i ++) {
        cin >> str[i];
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (str[i][j] != '#') {
                for (int t = 0; t < 4; t ++) {
                    int x = i + di[t];
                    int y = j + dj[t];
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        if (str[x][y] != '#') {
                            cnt[i+1][j+1] ++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            cum[i][j] = cnt[i][j] + cum[i-1][j]+cum[i][j-1] - cum[i-1][j-1];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = cum[c][d] - cum[a-1][d] - cum[c][b-1] + cum[a-1][b-1];
        for (int i = a; b-1 > 0 && i <= c; i ++) {
            if (str[i-1][b-2] != '#' && str[i-1][b-1] != '#') {
                sum --;
            }
        }

        for (int i = a; d+1 <= n && i <= c; i ++) {
            if (str[i-1][d] != '#' && str[i-1][d-1] != '#') {
                sum --;
            }
        }

        for (int j = b; a-1 > 0 && j <= d; j ++) {
            if (str[a-2][j-1] != '#' && str[a-1][j-1] != '#') {
                sum --;
            }
        }

        for (int j = b; c+1 <= m && j <= d; j ++) {
            if (str[c][j-1] != '#' && str[c-1][j-1] != '#') {
                sum --;
            }
        }

        assert(sum % 2 == 0);

        cout << sum/2 << '\n';

    }

    return 0;
}
