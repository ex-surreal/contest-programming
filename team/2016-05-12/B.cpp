#include <bits/stdc++.h>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))

int mod = 1e9;

/***************matrix exponentiation**************/
namespace mat_exp {
    typedef long long type;
    int matN=4; // order of matrix
    const int MAX=4;
 
    void cross(type result[MAX][MAX],type matA[MAX][MAX],type matB[MAX][MAX],type mod) {
        for(int i=0;i<matN;i++)for(int j=0;j<matN;j++) {
            result[i][j]=0;
            for(int k=0;k<matN;k++) {
                result[i][j]=(result[i][j]+1ll*matA[i][k]*matB[k][j]%mod)%mod;
                result[i][j]=(result[i][j]+mod)%mod;
            }
        }
    }
 
    void matCopy(type A[MAX][MAX],type B[MAX][MAX]) {
        for(int i=0;i<matN;i++)for(int j=0;j<matN;j++) {
            A[i][j]=B[i][j];
        }
    }
 
    void matExpo(type result[MAX][MAX],type mat[MAX][MAX],long long exponent,type mod) { //result = mat^exponent; no change of mat
        for(int i=0;i<matN;i++)for(int j=0;j<matN;j++) { // making identity matrix
            result[i][j]=type(i==j);
        }
         
        type base[MAX][MAX],tmp[MAX][MAX];
        matCopy(base,mat);
         
        while(exponent>0) {
            if(exponent&1) {
                cross(tmp,result,base,mod);
                matCopy(result,tmp);
            }
            cross(tmp,base,base,mod);
            matCopy(base,tmp);
            exponent>>=1;
        }
    }
 
    type getVal(type mat[MAX][MAX],type *f,long long n,type mod) {
        type ret = 0;
        if(n<matN) {
            return (f[n]%mod+mod)%mod;
        }
        type result[MAX][MAX];
        matExpo(result,mat,(long long)(n-matN+1),mod);
        for(int i=0;i<matN;i++) {
            ret=(ret+f[matN-i-1]*result[0][i])%mod;
        }
        return ret;
    }
}
/***************matrix exponentiation**************/

using namespace mat_exp;

long long A[4][4] = {
    {0, 0, 3, 2},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 0}
};
long long B[4][4];

int g[4] = {0, 0, 0, 1};
int f[4] = {0, 0, 1, 0};

int pwr(int b, int n) {
    if (n == 0) {
        return 1;
    }
    int t = pwr(b, n/2);
    return 1ll*t*t%mod*((t&1) ? b : 1) % mod;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        if (m > 2) {
            cout << "0\n";
        } else {
            cout << "1\0";
        }
    } else if (n == 2) {
        if (m == 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    } else if (n == 3) {
        if (m&1) {
            cout << "0\n";
        } else {
            cout << pwr(2, m/2);
        }
    } else if (n == 4) {
        if (m < 4) {
            cout << (f[m]+g[m]) << "\n";
        } else {
            matExpo(B, A, m-2, mod);
            int ans = 0;
            ans = (ans + 1ll*B[0][0]*f[3]%mod+1ll*B[0][1]*g[3]%mod)%mod;
            ans = (ans + 1ll*B[0][2]*f[2]%mod+1ll*B[0][3]*g[2]%mod)%mod;
            ans = (ans + 1ll*B[1][0]*f[3]%mod+1ll*B[1][1]*g[3]%mod)%mod;
            ans = (ans + 1ll*B[1][2]*f[2]%mod+1ll*B[1][3]*g[2]%mod)%mod;
            cout << 2*ans%mod << "\n";
        }
    } else if (n == 5) {
        if (m&1) {
            cout << "0\n";
        } else {
            cout << pwr(4, m/2);
        }
    }
    return 0;
}
