// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 202;

int N, L, K;
double memo[MAXN][MAXN][2 * MAXN];
double P[MAXN];
int A[MAXN];

double solve(int n, int tours, int bags)
{
	if (n >= N) return (tours >= L && bags >= 0);
	bags = min(bags, N);
	tours = min(tours, L);
	double & r = memo[n][tours][bags + MAXN];
	if (r != -1) return r;
	return r = solve(n+1, tours + 1, bags + A[n]) * P[n] + solve(n+1, tours, bags) * (1.0 - P[n]);
}

int main()
{
	scanf( "%d %d %d", &N, &L, &K );
	REP(i, N)
	{
		scanf( "%lf", &P[i] );
		P[i] /= 100;
	}

	REP(i, N) scanf( "%d", &A[i] );

	REP(i, N+1)
	REP(j, L+1)
	REP(k, 2 * MAXN)
		memo[i][j][k] = -1.0;

	printf( "%.12lf\n", solve(0, 0, K));

	return 0;
}
