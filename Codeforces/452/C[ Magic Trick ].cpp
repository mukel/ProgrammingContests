#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 10;

int n, m;
double p[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    p[0][0] = 1;
    for (int i = 0; i <= m; ++i)
    for (int j = 0; j <= n; ++j) {
        double pi = (m - i) / (double)(m*n - i - j);
        double pj = (m*n - m - j) / (double)(m*n - i - j);
        p[i + 1][j] += p[i][j] * pi;
        p[i][j + 1] += p[i][j] * pj;
    }
    
    double ans = 0;
    for (int i = 1; i <= m && n - i >= 0; ++i) {
        //cout << i << " -> "  << p[i][n - i] << endl;
        ans += p[i][n - i] * n * (i*i)/(double)(n*n);
    }

    printf( "%.12lf\n", ans );
    
    
    return 0;
}
