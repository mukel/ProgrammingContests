// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <algorithm>

#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

const int
    MAXM = 1 << 18;

int N, M;
int W[MAXM];

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    REP(i, M)
    {
        int q, w;
        cin >> q >> w;
        W[i] = w;
    }
    
    sort(W, W + M);
    reverse(W, W + M);
    
    int best = 1;
    for (int i = 1; i <= min(N,M); ++i)
    {
        int64 n = i;
        int64 L = n * (n - 1) / 2;

        if (n % 2 == 0)
            L += n / 2;
        else
            L++;
        
        if (L <= N)
            best = max(best, i);
    }

    int64 ans = 0;
    for (int i = 0; i < best; ++i)
        ans += W[i];
    
    cout << ans << endl;
    
    return 0;
}