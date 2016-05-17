#include <vector>

namespace point_update {
    #define invalid (1<<30)
    #define fun(a,b) std::max(a, b)
    typedef int type;
    const int N = 100000;
    type seg[4*N+5];
    std::vector <type> a;
     
    void init(int node, int u, int v) {
        if(u > v) {
            return;
        }
        if(u == v) {
            seg[node] = a[u];
            return;
        }
        init(2*node+1, u, (u+v)/2);
        init(2*node+2, (u+v)/2+1, v);
        seg[node] = fun(seg[2*node+1], seg[2*node+2]);
    }

    void init(std::vector <type> &d) {
        a = d;
        init(0, 0, int(a.size()-1));
    }
     
    void update(int node, int u, int v, int x, type val) {
        if(v < x || u > x){
            return;
        }
        if(u == v) {
            seg[node] = val;
            return;
        }
        update(2*node+1, u, (u+v)/2, x, val);
        update(2*node+2, (u+v)/2+1, v, x, val);
        seg[node] = fun(seg[node*2+1], seg[node*2+2]);
    }

    void update(int x, type val) {
        update(0, 0, int(a.size()), x, val);
    }
 
    type read(int node, int u, int v, int x, int y) {
        if (x > y || v < x || u > y) {
            return invalid;
        }
        if(x <= u && v <= y) {
            return seg[node];
        }
        type a = read(2*node+1, u, (u+v)/2, x, y);
        type b = read(2*node+2, (u+v)/2+1 ,v, x, y);
        return fun(a,b);
    }

    type read(int u, int v) {
        return read(0, 0, int(a.size())-1, u, v);
    }
};

using namespace point_update;
