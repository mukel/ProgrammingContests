// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int N, A, D;
pair< int, int > B[1 << 17];
double best[1 << 17];

int main()
{
	scanf( "%d %d %d", &N, &A, &D );
	REP(i, N)
	{
		int t, v;
		scanf( "%d %d", &t, &v );
		B[i] = make_pair(t, v);
	}

	REP(i, N)
	{
		double start = B[i].first;
		double v = B[i].second;

		double t = v / A;
		double dist = A * t * t / 2.0;

		if (dist < D)
		{
			t += (D - dist) / v;
		}
		else
		{
			t = sqrt(2 * D / (double)A);
		}

		if (i) best[i] = max(best[i - 1], start + t);
		else best[i] = start + t;

		printf( "%.10lf\n", best[i] );
	}

	return 0;
}
