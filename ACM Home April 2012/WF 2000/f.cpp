// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>


using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	oo = (int)1e9,
	MAXV = 102;

int V, E;
int D[MAXV][MAXV];
int id[MAXV];
int test;

int main()
{
	while (1)
	{
		REP(i, MAXV) id[i] = -1;
		V = E = 0;

		int u, v;
		while (scanf( "%d %d", &u, &v ), u && v)
		{
			--u;
			--v;

			E++;

			if (id[u] < 0)
			{
				id[u] = V++;
				REP(j, MAXV) D[ id[u] ][j] = D[j][ id[u] ] = oo;
				D[ id[u] ][ id[u] ] = 0;
			}

			if (id[v] < 0)
			{
				id[v] = V++;
				REP(j, MAXV) D[ id[v] ][j] = D[j][ id[v] ] = oo;
				D[ id[v] ][ id[v] ] = 0;
			}

			D[ id[u] ][ id[v] ] = 1;
		}
		if (!E) break;

		REP(k, V) REP(i, V) REP(j, V)
		{
			int t = D[i][k] + D[k][j];
			if (t < D[i][j])
				D[i][j] = t;
		}

		int ans = 0;
		REP(i, V)
		REP(j, V)
		{
			if (D[i][j] == oo) printf( "%d %d\n", i, j );
			ans += D[i][j];
		}

		++test;
		printf( "Case %d: average length between pages = %.3lf clicks\n", test, ans / ((double)V * (V - 1)) );
	}

	return 0;
}
