#include <bits/stdc++.h>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for(int i = 0; i < int(n); i ++)
#define repi(i, a, n) for(int i = int(a); i < int(n); i ++)

/***************matrix exponentiation**************/
namespace mat_exp {
    typedef int type;
    int matN=2; // order of matrix
    const int MAX=100;
 
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
}
/***************matrix exponentiation**************/

int mat[100][100], res[100][100];
int cnt[10];

int main () {
    ios_base::sync_with_stdio(false);
    int n, b, k, x;
    cin >> n >> b >> k >> x;
    rep (i, n) {
        int d;
        cin >> d;
        cnt[d] ++;
    }
    rep(t, x) {
        rep(d, 10) {
            mat[t][(t*10+d)%x] += cnt[d];
        }
    }
    mat_exp::matN = x;
    mat_exp::matExpo(res, mat, b, 1e9+7);
    cout << res[0][k];
    return 0;
}
