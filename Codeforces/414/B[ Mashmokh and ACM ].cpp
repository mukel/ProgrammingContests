#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    const int
        MOD = 1000000007;

    for (int i = 1; i <= N; ++i) dp[1][i] = 1;
    
    for (int i = 1; i < K; ++i)
    for (int x = 1; x <= N; ++x)
        for (int mul = x; mul <= N; mul += x)
        {
            dp[i+1][mul] = (dp[i+1][mul] + dp[i][x]) % MOD;
        }
            
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = (ans + dp[K][i]) % MOD;
        
    cout << ans << endl;

    return 0;
}
