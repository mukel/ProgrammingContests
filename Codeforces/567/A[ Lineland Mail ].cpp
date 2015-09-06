#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int64;
#define endl (&#39;\n&#39;)

const int
    MAXN = 1 << 17,
    INF = 2000000005;
    
int N;
int x[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef LOCAL
        cin.tie(0);
    #endif  
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> x[i];
    
    for (int i = 0; i < N; ++i) {
        int lo = +INF;
        int hi = -INF;
        if (i - 1 >= 0) lo = min(lo, abs(x[i] - x[i - 1]));
        if (i + 1 < N) lo = min(lo, abs(x[i] - x[i + 1]));
        if (i > 0) hi = max(hi, abs(x[i] - x[0]));
        if (i < N - 1) hi = max(hi, abs(x[i] - x[N - 1]));
        cout << lo << " " << hi << endl;
    }
    
    return 0;
}
