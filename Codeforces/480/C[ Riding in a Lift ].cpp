#include "bits/stdc++.h"
using namespace std;

int N, A, B, K;

const int
    MAXN = 5005,
    MODULO = 1000000007;

int dp[MAXN];
int sum[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> A >> B >> K;
    
    dp[A] = 1;
    for (int k = 0; k < K; ++k)
    {
        for (int i = 1; i <= N; ++i) sum[i] = 0;

        for (int i = 1; i <= N; ++i) if (i != B)
        {
            int d = abs(i - B) - 1;
            int lo = max(1, i - d);
            int hi = min(N, i + d);
            sum[lo] = (sum[lo] + dp[i]) % MODULO;
            sum[i] = (sum[i] - dp[i] + MODULO) % MODULO;
            sum[i + 1] = (sum[i + 1] + dp[i]) % MODULO;
            sum[hi + 1] = (sum[hi + 1] - dp[i] + MODULO) % MODULO;
        }
        for (int i = 1; i <= N; ++i)
            dp[i] = (dp[i - 1] + sum[i]) % MODULO;
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = (dp[i] + ans) % MODULO;
        
    cout << ans << endl;
    
    return 0;
}