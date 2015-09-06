#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int
	MAXN = 1 << 18;

int N, M, C;
double ans;
double profit[MAXN];
int x[MAXN];

struct node
{
	double L, R, C, sum;
	node() {}
	node(double pf)
	{
		sum = pf;
		L = R = C = max(0.0, pf);
	}
} T[2 * MAXN];


node unite(const node & l, const node & r)
{
	node ret;
	ret.L = max(l.L, l.sum + r.L);
	ret.R = max(r.R, r.sum + l.R);
	ret.C = max(max(r.C, l.C), l.R + r.L);
	ret.sum = l.sum + r.sum;
	return ret;
}

void build(int x, int lo, int hi)
{
	if (lo == hi) {
		T[x] = node(profit[lo]);
		return ;
	}
	int mid = (lo + hi) / 2;
	build(2 * x, lo, mid);
	build(2 * x + 1, mid + 1, hi);
	T[x] = unite(T[2 * x], T[2 * x + 1]);
}

node query(int x, int lo, int hi, int start, int end)
{
	int mid = (lo + hi) / 2;

	if (lo >= start && hi <= end)
		return T[x];

	if (mid + 1 > end)
		return query(2 * x, lo, mid, start, end);

	if (mid < start)
		return query(2 * x + 1, mid + 1, hi, start, end);

	return
		unite(
			query(2 * x, lo, mid, start, end),
			query(2 * x + 1, mid + 1, hi, start, end)
		);
}

int main()
{
	scanf( "%d %d %d", &N, &M, &C );

	for (int i = 0; i < N; ++i)
		scanf( "%d", &x[i] );

	for (int i = 0; i < N - 1; ++i)
	{
		int p;
		scanf( "%d", &p );
		profit[i] = (x[i + 1] - x[i]) / 2.0 - C * (p / 100.0);
	}

	build(1, 0, N - 1);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		scanf( "%d %d", &a, &b );
		--a;
		--b;
		ans += max(0.0, query(1, 0, N - 1, a, b - 1).C);
	}

	printf( "%.10lf\n", ans );

	return 0;
}
