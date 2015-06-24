/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #43 "Intervals"
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
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXN = 1 << 17;

int N, C;
int lo[MAXN];
int hi[MAXN];
int dp[2 * MAXN];
int wy[2 * MAXN];
int compr[2 * MAXN];
vector< int > G[2 * MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		scanf( "%d %d", &lo[i], &hi[i] );
		compr[C++] = lo[i];
		compr[C++] = hi[i];
	}
	
	sort(compr, compr + C);
	C = unique(compr, compr + C) - compr;
	
	REP(i, N)
	{
	      lo[i] = lower_bound(compr, compr + C, lo[i]) - compr;
		hi[i] = lower_bound(compr, compr + C, hi[i]) - compr;
	      G[ hi[i] ].PB(lo[i]);
	}

	wy[0] = 1;
	
	REP(i, C) if (i)
	{
		dp[i] = dp[i - 1];
		wy[i] = wy[i - 1];
		
		REP(j, SZ(G[i]))
		{
			int prev = G[i][j];
			int t = dp[prev] + 1;
			
			if (t > dp[i])
			{
				dp[i] = t;
				wy[i] = 0;
			}
			if (t == dp[i])
			      wy[i] += wy[prev];
		}
	}
	
	cout << wy[C - 1] << endl;

	return 0;
}
