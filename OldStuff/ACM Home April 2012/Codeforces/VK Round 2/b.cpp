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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).begin(); ++it)

const int
	MAXN = 1 << 17;

int N, K, H;
struct lemm
{
	int m, v, id;
} L[MAXN];

vector< int > cand, ans;

bool operator < (const lemm & a, const lemm & b)
{
	if (a.m != b.m) return a.m < b.m;
	return a.v < b.v;
}

bool ok(double t)
{
	int cur = 0;

	cand.clear();

	for (int i = 0; i < N && cur < K; ++i)
	{
		double tt = ((cur+1) * (long long)H) / (double)L[i].v;
		if (tt >= t) continue ;
		else cand.push_back(L[i].id), cur++;
	}

	return SZ(cand) == K;
}

int main()
{
	scanf( "%d %d %d", &N, &K, &H );
	REP(i, N) scanf( "%d", &L[i].m );
	REP(i, N) scanf( "%d", &L[i].v );
	REP(i, N) L[i].id = i;

	sort(L, L + N);

	double lo = 0, hi = 1e15;
	REP(iter, 200)
	{
		double mid = (lo + hi) / 2;
		if (ok(mid)) hi = mid, ans = cand;
		else lo = mid;
	}

	//printf( "%.12lf\n", hi );
	REP(i, K) printf( "%d ", ans[i] + 1 );

	return 0;
}
