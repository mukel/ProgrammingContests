#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 17;

int N;
int h[MAXN];
int L[MAXN];
int R[MAXN];
int ans;

int main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> h[i];
        
    int best = 0;
    for (int i = 1; i <= N; ++i) {
        L[i] = i + best;
        best = min(best, h[i] - i);
    }
    
    best = N+1;
    for (int i = N; i >= 1; --i) {
        R[i] = best - i;
        best = min(best, h[i] + i);
    }
    
    for (int i = 1; i <= N; ++i) {
        int t = min(h[i], min(L[i], R[i]));
        ans = max(ans, t);
    }
    
    cout << ans << endl;
    
    return 0;
}
