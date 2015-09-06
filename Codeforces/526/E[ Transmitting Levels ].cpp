#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 21;

int N, Q;
int a[MAXN];
long long S[MAXN];
int dp[MAXN];
int nxt[MAXN];
long long crap[MAXN];

int main() {
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        a[i + N] = a[i];
    }

    for (int i = 1; i <= 2*N; ++i)
        S[i] = S[i - 1] + a[i];

    while (Q--) {
        long long b;
        cin >> b;

        long long sum = 0;
        int hi = 1;
        for (int lo = 1; lo <= N; ++lo) {
            while (hi <= N && sum + a[hi] <= b)
            {
                sum += a[hi];
                hi++;
            }
            nxt[lo] = hi;
            sum -= a[lo];
        }

        crap[N + 1] = dp[N + 1] = 0;
        for (int i = N; i >= 1; --i) {
            if (nxt[i] > N)
                crap[i] = S[N] - S[i - 1];
            else
                crap[i] = crap[ nxt[i] ];
            dp[i] = 1 + dp[ nxt[i] ];
        }

        if (b >= S[N]) {
            cout << 1 << &#39;\n&#39;;
        } else {
            int ans = dp[1];
            for (int i = 2; i < N; ++i) {
                int t = dp[i];
                if (S[i - 1] > b) break;
                if (S[i - 1] + crap[i] > b) t++;
                ans = min(ans, t);
            }
            cout << ans << &#39;\n&#39;;
        }
    }


    return 0;
}
