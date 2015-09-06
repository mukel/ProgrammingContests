#include <bits/stdc++.h>
using namespace std;

int N, M, B;

struct ff
{
    int x, k, mask;
};

bool operator < (const ff & a, const ff & b)
{
    return a.k < b.k;
}

ff F[1000];
long long dp[1 << 20];

long long INF = (long long)(1e18 + 1e12 + 1);

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> B;

    for (int i = 0; i < N; ++i)
    {
        int m;
        cin >> F[i].x >> F[i].k >> m;
        for (int j = 0; j < m; ++j)
        {
            int p; cin >> p;
            --p;
            F[i].mask |= (1 << p);
        }
    }

    for (int j = 1; j < (1 << M); ++j)
        dp[j] = INF;


    sort(F, F + N);

    long long ans = INF;

    for (int i = 0; i < N; ++i)
    {
        int m = F[i].mask;
        long long x = F[i].x;
        long long k = F[i].k;
        for (int j = 0; j < (1 << M); ++j)
            dp[j | m] = min(dp[j | m], dp[j] + x);

        long long t = dp[(1 << M) - 1];
        if (t != INF)
            ans = min(ans, dp[(1 << M) - 1] + k * B);
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
