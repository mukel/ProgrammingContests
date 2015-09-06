#include <bits/stdc++.h>
using namespace std;

int N, K;
map< vector<char>, double > dp[5];
vector<char> start;

int inv(const vector<char>& p) {
    int r = 0;
    for (int lo = 0; lo < N; ++lo)
    for (int hi = lo+1; hi < N; ++hi)
        if (p[lo] > p[hi])
            ++r;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;  
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        start.push_back((char)x);
    }

    int total = N * (N + 1) / 2;
    
    dp[0][start] = 1.0;
    for (int i = 0; i < K; ++i) {
        for (const auto& p: dp[i]) {
            for (int lo = 0; lo < N; ++lo)
            for (int hi = lo; hi < N; ++hi) {
                auto t = p.first;
                reverse(t.begin() + lo, t.begin() + (hi+1));
                dp[i + 1][t] += p.second / total;
            }
        }
    }

    double ans = 0;
    for (auto x : dp[K]) {
        ans += inv(x.first) * x.second;
    }

    printf("%.15lf\n", ans);

    return 0;
}
