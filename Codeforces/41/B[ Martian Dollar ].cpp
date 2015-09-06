/*
Alfonso2 Peterssen(mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int MAXN = 1 << 11;

int N, B;
int change[MAXN];

int main()
{
    scanf( "%d %d", &N, &B );
    
    REP(i, N)
          scanf( "%d", &change[i] );

    int ans = B;
    REP(hi, N)
    REP(lo, hi)
    {
        int tmp = (B / change[lo]) * change[hi] + (B % change[lo]);
        ans = max(ans, tmp);
    }
    
    cout << ans << endl;

    return 0;
}
