/*
Alfonso2 Peterssen(mukel)
Universidad de La Habana
Codeforces Round 80 Beta Div. 1
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
	MAXN = (3) * (1 << 17),
	LIMIT = 780;

int N, Q;
int w[MAXN];
struct query
{
	int id, a;
};
vector< query > qq[MAXN];
int64 ans[MAXN];
int64 dp[MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N) scanf( "%d", &w[i] );
	
	scanf( "%d", &Q );
	REP(i, Q)
	{
		int a, b;
		scanf( "%d %d", &a, &b );
		a--;
		qq[b].push_back((query){i, a});
	}
	
	for (int b = 1; b < min(N, LIMIT); b++)
	{
		dp[N - b] = w[N - b];
		
		if (!qq[b].empty())
		{
			for (int i = N - b - 1; i >= 0; i--)
				dp[i] = w[i] + dp[i + b];

			REP(i, qq[b].size())
				ans[ qq[b][i].id ] = dp[ qq[b][i].a ];
		}
	}
	
	for (int b = min(N, LIMIT); b <= N; b++)
	{
		REP(i, qq[b].size())
		{
			int64 val = 0;
			for (int j = qq[b][i].a; j < N; j += b) val += w[j];
			ans[ qq[b][i].id ] = val;
		}
	}

	REP(i, Q)
		printf( "%I64d\n", ans[i] );

	return 0;
}
