/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #49 "Minimizing number of steps"
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXN = 1 << 10;
	
int N;
int money[MAXN];
int dp[MAXN][MAXN];

int main()
{
	scanf( "%d", &N );
	FOR(i, 1, N) scanf( "%d", &money[i] );
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	FOR(i, 1, N)
	FOR(j, 0, i)
	{
		if ((i != N && i != 0) && dp[i - 1][j] >= 100) // cannot skip first or last
			dp[i][j] = max(dp[i][j], dp[i - 1][j] - 100); // skip i

		if (j > 0 && dp[i - 1][j - 1] >= 0 && dp[i - 1][j - 1] + money[i] >= 0) // take i
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + money[i]);
			
		//printf( "%d %d -> %d\n", i, j, dp[i][j] );
	}
	
	int ans = -1;
	FOR(i, 0, N) if (dp[N][i] >= 0) { ans = i; break; }

	printf( "%d\n", ans );
	
	return 0;
}
