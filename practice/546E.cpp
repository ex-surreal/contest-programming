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

/***********max flow**************/
namespace MF // doesn't mean "Mother Fucker"
{
    const int N=205,M=1205,inf=10000000;
    int L[N],pre[M],to[M],C[M],cnt=0;
 
    inline void init()
    {
        memset(L,-1,sizeof(L));
        cnt=0;
    }
     
    inline void add(int u,int v,int c=1)
    {
        to[cnt]=v;
        pre[cnt]=L[u];
        C[cnt]=c;
        L[u]=cnt++;
    }
     
    inline void addEdge(int u,int v,int c=1)
    {
        add(u,v,c);
        add(v,u,0);
    }
 
    int Q[N],F[N],mother[N],path[N];
 
    int augment(int s,int t)
    {
        int bk=0,fr=0;
        memset(F,0,sizeof(F));
        memset(mother,-1,sizeof(mother));
         
        F[s]=inf;
        Q[bk++]=mother[s]=s;
         
        while(fr<bk)
        {
            int u=Q[fr++];
            if(u==t)break;
            for(int e=L[u];e!=-1;e=pre[e])
            {
                int v=to[e];
                if(mother[v]==-1 && C[e]>0)
                {
                    path[v]=e;
                    mother[v]=u;
                    F[v]=std::min(F[u],C[e]);
                    Q[bk++]=v;
                }
            }
        }
        if(F[t]==0)return 0;
        int g=t;
        while(g!=s)
        {
            C[path[g]]-=F[t];
            C[path[g]^1]+=F[t];
            g=mother[g];
        }
        return F[t];
    }
 
    int maxFlow(int s,int t)
    {
        int f,flow=0;
        while((f=augment(s,t))!=0)
            flow=flow+f;
        return flow;
    }
}
/***********max flow**************/
 
using namespace MF;

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n);
    repe(&x, a) {
        cin >> x;
    }
    repe(&x, b) {
        cin >> x;
    }
    init();
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        addEdge(2*x+1, 2*y, inf);
        addEdge(2*y+1, 2*x, inf);
    }
    int e1 = cnt;
    rep(i, n) {
        addEdge(2*i, 2*i+1, a[i]);
    }
    int e2 = cnt;
    int s = 2*n, t = s+1;
    rep(i, n) {
        if (a[i] > b[i]) {
            addEdge(s, 2*i, a[i]-b[i]);
        } else if (a[i] < b[i]) {
            addEdge(2*i, t, b[i]-a[i]);
        }
    }
    maxFlow(s, t);
    vector <vector <int> > ans(n, vector <int>(n));
    for (int e = e2; e < cnt; e += 2) {
        if (C[e] != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int e = e1; e < e2; e += 2) {
        ans[to[e]/2][to[e]/2] = C[e];
    }
    for (int e = 0; e < e1; e += 2) {
        ans[to[e^1]/2][to[e]/2] = C[e^1];
    }
    repe(x, ans) {
        repe(y, x) {
            cout << y << " ";
        } cout << "\n";
    }
    return 0;
}
