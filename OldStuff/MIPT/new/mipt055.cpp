/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #55 "Trip abroad"
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

const int
	MAXN = 301;
	
const double
	oo = 1e15;

int N;
double R;
double dist[MAXN][MAXN];
double x[MAXN];
double y[MAXN];

double sqr(double x) { return x * x; }

int main()
{
	scanf( "%d", &N );
	scanf( "%lf", &R );
	REP(i, N)
	      scanf( "%lf %lf", &x[i], &y[i] );
	
	REP(i, N)
	REP(j, i)
	{
		double d = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
		dist[i][j] = dist[j][i] = (d > R*R) ? oo : sqrt(d);
	}
	
	REP(k, N)
	REP(i, N)
	REP(j, N)
	      if (dist[i][k] + dist[k][j] < dist[i][j])
	            dist[i][j] = dist[i][k] + dist[k][j];

	double ans = oo;
	REP(i, N)
	      if (x[i] < 0)
	            ans = min(ans, dist[0][i] + dist[i][1]);

	printf( "%lf\n", ans );

	return 0;
}
