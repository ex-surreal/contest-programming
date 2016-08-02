#include <vector>
#include <iostream>

using namespace std;

typedef int elem;
typedef vector <vector <elem> > matrix;
int mod = 1e9+7;

/**
 * @param int n
 * @return a nxn identity matrix
 * */
matrix get_identity(int n) {
    matrix I(n);
    for (int i = 0; i < n; i ++) {
        I[i].resize(n);
        fill(I[i].begin(), I[i].end(), 0);
        I[i][i] = 1;
    }
    return I;
}

/**
 * @param matrix &a
 * @param matrix &b
 * @return matrix a x b
 * Assumes the multiplication is valid i.e. a[0].size() == b.size() 
 * */
matrix cross(matrix &a, matrix &b) {
    int m = a.size(), n = b.back().size(), t = b.size();
    matrix c(m);
    for (int i = 0; i < m; i ++) {
        c[i].resize(n);
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            c[i][j] = 0;
            for (int k = 0; k < t; k ++) {
                c[i][j] = (c[i][j] + 1ll*a[i][k]*b[k][j]) % mod;
            }
        }
    }
    return c;
}

/**
 * @param matrix a
 * @param integral ex
 * @return matrix pow(a, ex)
 * Assumes a is a nxn matrx
 * */
template <class integral> matrix pwr(matrix a, integral ex) {
    int n = a.size();
    matrix r = get_identity(n);
    while (ex > 0) {
        if (ex&1) {
            r = cross(r, a);
        }
        a = cross(a, a);
        ex >>= 1;
    }
    return r;
}
