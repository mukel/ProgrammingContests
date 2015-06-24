// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 55,
	MAXB = MAXN * MAXN;

int N, B;
struct bulb
{
	int t, x, y;
} bulbs[MAXB];

int from[MAXN];
vector< int > G[MAXN];
int mark[MAXN];
int curMark;
bool used[MAXN];
int ans;

int order[MAXB];
int norder[MAXN];

bool operator < (const bulb & a, const bulb & b)
{
	return a.t < b.t;
}

bool dfs(int u)
{
	mark[u] = curMark;

	REP(i, SZ(G[u]))
	{
		int v = G[u][i];
		if (from[v] < 0 || (mark[from[v]] != curMark && dfs(from[v])))
		{
			from[v] = u;
			return 1;
		}
	}

	return 0;
}

int row[MAXB][MAXN];
int col[MAXB][MAXN];

bool check(int lo, int hi)
{
	if (bulbs[hi].t - bulbs[lo].t >= ans)
		return true;

	REP(i, N)
	{
		if (row[hi][i] - (lo ? row[lo - 1][i] : 0) == 0) return 0;
		if (col[hi][i] - (lo ? col[lo - 1][i] : 0) == 0) return 0;
	}

	REP(i, N) G[i].clear(), from[i] = -1, used[i] = 0;

	FOR(i, lo, hi)
	{
		int u = bulbs[i].x;
		int v = bulbs[i].y;
		G[u].push_back(v);

		if (!used[u] && from[v] < 0)
		{
			used[u] = 1;
			from[v] = u;
		}
	}

	REP(i, N) if (!used[i])
	{
		++curMark;
		if (!dfs(i)) return 0;
	}

	return 1;
}



int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		B = 0;

		scanf( "%d", &N );
		REP(i, N)
		REP(j, N)
		{
			int x; scanf( "%d", &x );
			bulbs[B++] = (bulb){x, i, j};
		}

		REP(i, N) norder[i] = i;
		random_shuffle(norder, norder + N);

		sort(bulbs, bulbs + B);

		REP(i, B)
		REP(j, N)
		{
			row[i][j] = (bulbs[i].x == j);
			if (i) row[i][j] += row[i - 1][j];

			col[i][j] = (bulbs[i].y == j);
			if (i) col[i][j] += col[i - 1][j];
		}


		ans = bulbs[B - 1].t - bulbs[0].t;

		REP(i, B) order[i] = i;
		random_shuffle(order, order + B);

		REP(__i, B)
		{
			int i = order[__i];

			int lo = i + N - 1, hi = B - 1;

			while (lo <= hi)
			{
				int mid = (lo + hi) / 2;
				if (check(i, mid))
				{
					hi = mid - 1;
					ans = min(ans, bulbs[mid].t - bulbs[i].t);
				}
				else
					lo = mid + 1;
			}
		}

		printf( "%d\n", ans );
	}

	return 0;
}
