// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    

const int
    MAXN = 2005;
    
int N;
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> f[i];
    
    sort(f, f + N);
    
    int ans1 = 0;
    for (int i = 0; i < N; i += K)
        ans1 += 2 * (f[min(N - 1, i + K - 1)] - 1);

    int ans2 = 0;
    for (int i = N - 1; i >= 0; i -= K)
        ans2 += 2 * (f[i] - 1);
    
    cout << min(ans1, ans2) << endl;

    return 0;
}