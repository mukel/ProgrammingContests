/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #31 "Minimal sum of distances"
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
//#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOR(i, b, e, s) for (int i = (int)b; i <= (int)(e); i += (int)(s))

const int
	MAXN = 1 << 7,
	MAXC = 1500;

int N;
int X[MAXN];
int Y[MAXN];
int F[MAXN];
double solX, solY;

inline double sqr(double x) { return x * x; }

int main()
{
	scanf( "%d", &N );
	REP(i, N)
		scanf( "%d %d %d", &X[i], &Y[i], &F[i] );

	double ans = 1e9;
	FOR(i, -MAXC, +MAXC, 2)
	FOR(j, -MAXC, +MAXC, 2)
	{
		double x = i / 100.0;
		double y = j / 100.0;

		double tmp = 0;
			REP(k, N)
		{
		      tmp += F[k] * sqrt(sqr(X[k] - x) + sqr(Y[k] - y));
		      if (tmp >= ans) break;
		}

		if (tmp < ans)
		{
			ans = tmp;
			solX = x;
			solY = y;
		}
	}

	printf( "%.2lf %.2lf\n", solX, solY );

	return 0;
}
