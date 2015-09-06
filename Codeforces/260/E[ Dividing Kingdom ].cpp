#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define endl &#39;\n&#39;

const int
	MAXN =  1 << 17;

int N;
pair< int, int > P[MAXN];
int a[9];
int cx[MAXN];
int cy[MAXN];

vector< int > T[2 * MAXN];

void build(int x, int lo, int hi)
{
	if (lo == hi)
	{
		T[x].push_back(P[lo].second);
		return ;
	}

	int mid = (lo + hi) / 2;
	build(2 * x, lo, mid);
	build(2 * x + 1, mid + 1, hi);

	T[x].resize(hi - lo + 1);
	merge(ALL(T[2 * x]), ALL(T[2 * x + 1]), T[x].begin());
}

int query(int x, int lo, int hi, int from, int to, int lb, int ub)
{
	if (lo > hi || lo > to || hi < from)
		return 0;

	if (lo >= from && hi <= to)
		return upper_bound(ALL(T[x]), ub) - lower_bound(ALL(T[x]), lb);

	int mid = (lo + hi) / 2;
	return
		query(2 * x, lo, mid, from, to, lb, ub) +
		query(2 * x + 1, mid + 1, hi, from, to, lb, ub);
}

int main()
{
	ios::sync_with_stdio(0);

	cin >> N;
	REP(i, N)
	{
		cin >> cx[i] >> cy[i];
		P[i] = make_pair(cx[i], cy[i]);
	}

	REP(i, 9)
		cin >> a[i];

	sort(P, P + N);
	sort(cx, cx + N);
	sort(cy, cy + N);

	build(1, 0, N - 1);

	sort(a, a + 9);
	do
	{
		// 0 3 6
		// 1 4 7
		// 2 5 8

		int sx[3] = {a[0]+a[1]+a[2], a[3]+a[4]+a[5], a[6]+a[7]+a[8]};
		int sy[3] = {a[0]+a[3]+a[6], a[1]+a[4]+a[7], a[2]+a[5]+a[8]};

		sx[2] += (sx[1] += sx[0]);
		sy[2] += (sy[1] += sy[0]);

		if (cx[ sx[0] ] == cx[ sx[0] - 1 ])	continue ;
		if (cx[ sx[1] ] == cx[ sx[1] - 1 ]) continue ;
		if (cy[ sy[0] ] == cy[ sy[0] - 1 ]) continue ;
		if (cy[ sy[1] ] == cy[ sy[1] - 1 ]) continue ;

		if (query(1, 0, N - 1, 0, sx[0] - 1, cy[0], cy[ sy[0] - 1 ]) != a[0]) continue ;
		if (query(1, 0, N - 1, sx[0], sx[1] - 1, cy[0], cy[ sy[0] - 1 ]) != a[3]) continue ;
		if (query(1, 0, N - 1, sx[1], sx[2] - 1, cy[0], cy[ sy[0] - 1 ]) != a[6]) continue ;

		if (query(1, 0, N - 1, 0, sx[0] - 1, cy[ sy[0] ], cy[ sy[1] - 1 ]) != a[1]) continue ;
		if (query(1, 0, N - 1, sx[0], sx[1] - 1, cy[ sy[0] ], cy[ sy[1] - 1 ]) != a[4]) continue ;
		if (query(1, 0, N - 1, sx[1], sx[2] - 1, cy[ sy[0] ], cy[ sy[1] - 1 ]) != a[7]) continue ;

		if (query(1, 0, N - 1, 0, sx[0] - 1, cy[ sy[1] ], cy[ sy[2] - 1 ]) != a[2]) continue ;
		if (query(1, 0, N - 1, sx[0], sx[1] - 1, cy[ sy[1] ], cy[ sy[2] - 1 ]) != a[5]) continue ;
		if (query(1, 0, N - 1, sx[1], sx[2] - 1, cy[ sy[1] ], cy[ sy[2] - 1 ]) != a[8]) continue ;

		printf( "%lf %lf\n%lf %f\n",
			(cx[ sx[0] ] + cx[ sx[0] - 1 ]) * .5,
			(cx[ sx[1] ] + cx[ sx[1] - 1 ]) * .5,
			(cy[ sy[0] ] + cy[ sy[0] - 1 ]) * .5,
			(cy[ sy[1] ] + cy[ sy[1] - 1 ]) * .5
		);

		return 0;

	} while (next_permutation(a, a + 9));

	printf("-1\n");

	return 0;
}
