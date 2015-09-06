#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
int ans[100];

void solve(long long k, long long total, int lo, int hi, int offset) {
    if (lo > hi) return ;
    if (lo == hi) {
        ans[lo] = offset;
        return ;
    }
    int cnt = 0;
    long long t = total/2;    
    while (k >= t && t) {
        k -= t;
        t /= 2;
        ++cnt;
    }
    ans[lo] = offset + cnt;
    for (int i = 0; i < cnt; ++i)
        ans[hi - i] = offset + i;
    solve(k, t, lo + 1, hi - cnt, offset + cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    solve(K-1, 1LL << (N - 1), 0, N - 1, 0);
    for (int i = 0; i < N; ++i)
        cout << ans[i]+1 << " ";
        
    return 0;
}
