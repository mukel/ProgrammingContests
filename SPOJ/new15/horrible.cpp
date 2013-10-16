/*
Alfonso2 Peterssen(mukel)
SPOJ #8002 "Horrible Queries"
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
#include <tr1/unordered_map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 1 << 17;

int N;
struct node
{
	int64 sum, delta;
} S[4 * MAXN];

void propagate(int x, int lo, int hi, int64 value)
{
	if (lo <= hi)
	{
		 S[x].sum += (hi - lo + 1) * value;
		 S[x].delta += value;
	}
}

void update(int x, int lo, int hi, int start, int end, int64 value)
{
	if (lo > end || hi < start || lo > hi) return ;
	
	int mid = (lo + hi) / 2;

	if (S[x].delta)
	{
		propagate(2 * x, lo, mid, S[x].delta);
		propagate(2 * x + 1, mid + 1, hi, S[x].delta);
		S[x].delta = 0;
	}
	
	if (lo >= start && hi <= end)
	{
		S[x].sum += (hi - lo + 1) * value;
		S[x].delta += value;
		return ;
	}
	
	update(2 * x, lo, mid, start, end, value);
	update(2 * x + 1, mid + 1, hi, start, end, value);
	
	S[x].sum = S[2 * x].sum + S[2 * x + 1].sum;
}

int64 query(int x, int lo, int hi, int start, int end)
{
	if (lo > end || hi < start || lo > hi) return 0;

	int mid = (lo + hi) / 2;
	if (S[x].delta)
	{
		propagate(2 * x, lo, mid, S[x].delta);
		propagate(2 * x + 1, mid + 1, hi, S[x].delta);
		S[x].delta = 0;
	}
	
	if (lo >= start && hi <= end) return S[x].sum;
	
	return query(2 * x, lo, mid, start, end) + query(2 * x + 1, mid + 1, hi, start, end);
}

void build(int x, int lo, int hi)
{
	S[x].sum = S[x].delta = 0LL;
	if (lo == hi) return ;
	int mid = (lo + hi) / 2;
	build(2 * x, lo, mid);
	build(2 * x + 1, mid + 1, hi);
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%d", &N );
		build(1, 1, N);
		int Q;
		for (scanf( "%d", &Q ); Q--;)
		{
			int op, a, b;
			scanf( "%d %d %d", &op, &a, &b );
			if (op)
				printf( "%I64lld\n", query(1, 1, N, a, b) );
			else
			{
				int v; scanf( "%d", &v );
				update(1, 1, N, a, b, v);
			}
		}
	}

	return 0;
}
