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
    const int N=240,M=10000,inf=INT_MAX/3;
    int L[N],pre[M],to[M],ptr[N],cap[M],flow[M],cnt=0;
    int n,s,t;
 
    inline void init(int _s,int _t,int _n)
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

int main () {
    std::ios_base::sync_with_stdio(false);
    int n, T;
    cin >> n >> T;
    int s = n+T, t = s+1;
    init(s, t, t+1);
    rep(i, n) {
        int c;
        cin >> c;
        if (c) {
            add_edge(s, i, c);
        }
    }
    rep(i, T) {
        int x, y;
        cin >> x;
        rep(j, x) {
            int d;
            cin >> d;
            add_edge(d-1, n+i, 1);
        }
        cin >> y;
        rep(j, y) {
            int d;
            cin >> d;
            add_edge(n+i, d-1, 1);
        }
    }
    rep(i, n) {
        add_edge(i, t, 1);
    }
    cout << dinic();
    return 0;
}
