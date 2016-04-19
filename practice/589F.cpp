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
    const int N=1005,M=30005,inf=INT_MAX/3;
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
    int n;
    cin >> n;
    vector <pair <int, int> > p(n);
    rep(i, n) {
        cin >> p[i].x >> p[i].y;
    }
    sort(all(p));
    int s = n, t = n+1;
    int x = n + 1;
    vector <pair <pair <int, int>, int> > edge;
    set <pair <int, int> > st;
    vector <bool> flag(n+1, false);
    int r = 0;
    p.pb(mp(10001, 10001));
    rep(i, sz(p)) {
        while (!st.empty() && st.begin()->x <= p[i].x) {
            if (st.begin()->x > r) {
                edge.pb(mp(mp(++x, t), st.begin()->x-r));
                rep(k, i) {
                    if (flag[k]) {
                        edge.pb(mp(mp(k, x), inf));
                    }
                }
            }
            flag[st.begin()->y] = false;
            r = st.begin()->x;
            st.erase(st.begin());
        }
        if (p[i].x > r && i < n) {
            edge.pb(mp(mp(++x, t), p[i].x-r));
            rep(k, i) {
                if (flag[k]) {
                    edge.pb(mp(mp(k, x), inf));
                }
            }
        }
        flag[i] = true;
        r = p[i].x;
        st.insert(mp(p[i].y, i));
    }
    int high = 10000, low = 1;
    while (low <= high) {
        int mid = (low+high)/2;
        init();
        repe(e, edge) {
            addEdge(e.x.x, e.x.y, e.y);
        }
        rep(i, n) {
            addEdge(s, i, mid);
        }
        if (maxFlow(s, t) < mid*n) {
            high = mid - 1;
        } else {
            low = mid +1;
        }
    }
    cout << high*n;
    return 0;
}
