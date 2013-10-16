/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #65 "Queue for tickets"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

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

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPD(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXN = 1 << 14;

int N;
int T[MAXN][3];
int dp[MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	REP(j, 3)
	      scanf( "%d", &(T[i][j]) );

	REPD(i, N)
	{
		dp[i] = T[i][0] + dp[i + 1];
		if (i + 1 < N) dp[i] = min(dp[i], T[i][1] + dp[i + 2]);
		if (i + 2 < N) dp[i] = min(dp[i], T[i][2] + dp[i + 3]);
	}
	      
	printf( "%d\n", dp[0] );

	return 0;
}

