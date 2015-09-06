/*
Alfonso2 Peterssen(mukel)
Codeforces Round 85 Div. 1
Task: C
Simple set DP
O(R * 2^3C)
worst case O(6 * 2^18)
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXC = 7,
	MAXR = 41,
	INF = (int)1e9;
	
int R, C;
int best;
int memo[MAXR][1 << MAXC][1 << MAXC];
int bitCnt[1 << MAXC];

bool check(int prv, int cur, int nxt)
{
	int t = cur | prv | nxt | (cur >> 1) | (cur << 1);
	return (t & ((1 << C) - 1)) == (1 << C) - 1;
}

int solve(int r, int cur, int nxt)
{
	if (!r)
		return check(0, cur, nxt) ? bitCnt[cur] : INF;
	
	int& ret = memo[r][cur][nxt];
	
	if (ret != -1) return ret;
	
	ret = INF;

	REP(i, (1 << C))
	      if (check(i, cur, nxt))
	            ret = min(ret, solve(r - 1, i, cur) + bitCnt[cur]);

	return ret;
}

int main()
{
     	memset(memo, -1, sizeof(memo));

	REP(i, (1 << MAXC))
	      bitCnt[i] = bitCnt[i >> 1] + (i & 1);
	      
	scanf( "%d %d", &R, &C );

	if (R < C) swap(R, C);

	best = R * C;

	REP(i, (1 << C))
	      best = min(best, solve(R - 1, i, 0));

	printf( "%d\n", R * C - best );

	return 0;
}
