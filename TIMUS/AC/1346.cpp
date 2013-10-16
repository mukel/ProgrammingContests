/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1346. Intervals of monotonicity
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
const int
	MAXN = 1 << 17;
	
int A, B, N;
int vals[MAXN];
int dp[MAXN][2];

int main()
{
	scanf( "%d %d", &A, &B );
	int N = B - A + 1;
	
	REP(i, N)
	{
		scanf( "%d", &vals[i] );
		
		dp[i][0] = dp[i][1] = 1;
		if (!i) continue ;

		dp[i][0] = dp[i - 1][0];
		if (vals[i] > vals[i - 1])
		      dp[i][0]++;
		
	      dp[i][1] = dp[i - 1][1];
		if (vals[i] < vals[i - 1])
		      dp[i][1]++;
		      
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
		dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
	}
	
	printf( "%d\n", min(dp[N - 1][0], dp[N - 1][1]) );

	return 0;
}
