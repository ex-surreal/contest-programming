#include <vector>
#include <set>
#include <algorithm>

#define x first
#define y second

using namespace std;

class FindingKids {
    static const int M = 1e9+7;
    vector <int> v, u;
    pair <int, int> getTimeAndPos2(int p, int x, int i, int j) {
        if (x == 0) {
            return make_pair(0, (p == 1 ? v[i] : u[j])*2);
        }
        i += (x-1)/2;
        j += (x-1)/2;
        if (p == 1) {
            i += !(x&1);
        } else {
            j += !(x&1);
        }
        return make_pair(u[j]-v[i], u[j]+v[i]);
    }
    long long search(int i, int j, int p, int t) {
        int high = min(v.size()-i, u.size()-j) +
            min((int)v.size()-i - (p == 1), (int)u.size()-j - (p == -1));
        int low = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int time2 = getTimeAndPos2(p, mid, i, j).x;
            if (time2 > 2*t) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        pair <int, int> r = getTimeAndPos2(p, high, i, j);
        int d = (high&1) ? p*-1 : p;
        return abs(1ll*r.y + d*(2ll*t - r.x));
    }

public:
    long long getSum(int n, int q, int A, int B, int C) {
        long long ret = 0;
        set <int> st;
        vector <pair <int, int> > posV, posU;
        vector <int> d;
        for (int i = 0; i < n; i ++) {
            A = (1ll*A*B + C) % M;
            int p = A % (M-n+i+1);
            if (st.find(p) != st.end()) {
                p = M-n+i;
            }
            if (p % 2 == 0) {
                posV.push_back(make_pair(p, i)); 
            } else {
                posU.push_back(make_pair(p, i));
            }
            st.insert(p);
        }
        sort(posV.begin(), posV.end());
        reverse(posV.begin(), posV.end());
        sort(posU.begin(), posU.end());
        for (auto x: posU) {
            u.push_back(x.x);
        }
        for (auto y: posV) {
            v.push_back(y.x);
        }
        vector <vector <int> > query(n);
        for (int i = 0; i < q; i ++) {
            A = (1ll*A*B + C) % M;
            int kid = A % n;
            A = (1ll*A*B + C) % M;
            query[kid].push_back(A);
        }
        int i, j;
        for (i = 0, j = (int) v.size() - 1; j >= 0; j --) {
            while (i < (int) u.size() && u[i] < v[j]) {
                i ++;
            }
            for (auto t: query[posV[j].y]) {
                ret += search(j, i, 1, t);
            }
        }
        for (j = 0, i = (int) u.size() - 1; i >= 0; i --) {
            while (j < (int) v.size() && u[i] < v[j]) {
                j ++;
            }
            for (auto t: query[posU[i].y]) {
                ret += search(j, i, -1, t);
            }
        }
        return ret/2;
    }
};

#include <iostream>

int main () {
    cout << (FindingKids()).getSum(
        5, 2, 0, 1, 1
    ) << endl;
    cout << (FindingKids()).getSum(
        5, 4, 3, 2, 1
    ) << endl;
    cout << (FindingKids()).getSum(
        200000, 200000, 12345, 67890, 111213141
    ) << endl; 
    return 0;
}
