/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #56 "Best segmentation"
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
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 20;

int N;
double x[MAXN], y[MAXN];
double dist[MAXN][MAXN];
double dp[1 << MAXN];

double sqr(double x) { return x * x; }

int main()
{
	scanf( "%d", &N );
	REP(i, N)
		scanf( "%lf %lf", &x[i], &y[i] );
		
	REP(i, N)
	REP(j, i)
	      dist[i][j] = dist[j][i] = sqrt(sqr(x[i] - x[j]) + sqr(y[j] - y[i]));
	      
	REP(i, (1 << N))
	{
		if (!i) continue ;
		if (__builtin_popcount(i) & 1) continue ;
		dp[i] = 1e15;
		int a = __builtin_ctz(i);
		for (int b = a + 1; b < N; b++) if ((i >> b) & 1)
			dp[i] = min(dp[i], dp[i - (1 << a) - (1 << b)] + dist[a][b]);
	}

	printf( "%lf\n", dp[(1 << N) - 1] );

	return 0;
}
