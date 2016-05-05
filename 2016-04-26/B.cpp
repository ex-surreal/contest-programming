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

/***********dinic**************/
namespace Dinic
{
    const int N=205,M=32000;
    int inf=INT_MAX/3;
    int L[N],pre[M],to[M],ptr[N], cnt = 0;
    int cap[M],flow[M];
    int n,s,t;
 
    void init(int _s,int _t,int _n)
    {
        s=_s;
        t=_t;
        n=_n;
        for(int i=0;i<n;i++)L[i]=-1;
        cnt=0;
    }
     
    inline void add(int u,int v,int c=1)
    {
        to[cnt]=v;
        pre[cnt]=L[u];
        cap[cnt]=c;
        flow[cnt]=0;
        L[u]=cnt++;
    }
     
    inline void add_edge(int u,int v,int c=1)
    {
        add(u,v,c);
        add(v,u,0);
    }
 
    int Q[N],level[N];
 
    bool bfs()
    {
        int fr=0,bk=0;
        for(int i=0;i<n;i++)level[i]=-1;
        level[s]=0;
        Q[bk++]=s;
        while(fr<bk)
        {
            int u=Q[fr++];
            for(int e=L[u];e!=-1;e=pre[e])if(flow[e]<cap[e])
            {
                int v=to[e];
                if(level[v]!=-1)continue;
                level[v]=level[u]+1;
                Q[bk++]=v;
            }
        }
        return level[t]!=-1;
    }
     
    int dfs(int u,int f)
    {
        if(u==t || f==0)return f;
        for(int &e=ptr[u];e!=-1;e=pre[e])
        {
            int v=to[e];
            if(flow[e]<cap[e] && level[v]==level[u]+1)
            {
                int pushed=dfs(v,min(f,cap[e]-flow[e]));
                if(pushed>0)
                {
                    flow[e]+=pushed;
                    flow[e^1]-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
     
    int dinic()
    {
        int ret=0;
        while(bfs())
        {
            for(int i=0;i<n;i++)ptr[i]=L[i];
            while(int f=dfs(s,inf))ret+=f;
        }
        return ret;
    }
}
/***********dinic**************/

using namespace Dinic;

bool possible(int c, vector <pair <int, int> > &edges, vector <int> &S) {
    int s = 2*sz(S), t = s+1, n = t+1;
    init(s, t, n);
    vector <int> in(sz(S)), out(sz(S));
    repe(e, edges) {
        add_edge(e.x, e.y, c);
        out[e.x] ++;
        in[e.y-sz(S)] ++;
    }
    rep(i, sz(S)) {
        if (in[i] == 0 && out[i] == 0) {
            add_edge(i, i+sz(S), c);
        }
        add_edge(s, i, S[i]);
        add_edge(i+sz(S), t, c);
    }
    return dinic() == accumulate(all(S), 0);
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int T, cas = 0;
    cin >> T;
    while (T --) {
        int n, m, sum = 0;
        cin >> n >> m;
        vector <int> A(n), B(n), S(n);
        rep(i, n) {
            cin >> A[i] >> B[i] >> S[i];
            S[i] = (S[i]+m-1)/m;
            sum += S[i];
        }
        vector <vector <int> > c(n, vector <int>(n));
        rep(i, n) {
            rep(j, n) {
                cin >> c[i][j];
            }
        }
        int s = 2*n, t = s+1;
        init(s, t, t+1);
        rep(i, n) {
            add_edge(s, i, S[i]);
            add_edge(i+n, t, S[i]);
            rep(j, n) {
                if (B[i]+c[i][j] < A[j]) {
                    add_edge(i, n+j, S[i]);
                }
            }
        }
        int flow = dinic();
        cout << "Case " << ++cas << ": " << sum - flow << "\n";
    }
    return 0;
}
