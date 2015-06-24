/*
Alfonso2 Peterssen(mukel)
SPOJ #6906 "Raining Parabolas"
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
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 1 << 17;

struct node
{
	int a, b, c, sum;
} f[4 * MAXN];

const int MOD = 10007;

int64 sumn(int lo, int hi)
{
	int64 n = (hi - lo) + 1;
	return (lo*n + n*(n - 1)/2) % MOD;
}

int n2sum(int64 n)
{
	if (n < 0) return 0;
	return (n * (n + 1) * (2*n + 1) / 6) % MOD;
}

int64 sumn2(int lo, int hi)
{
	int64 ret = n2sum(hi) - n2sum(lo - 1);
	ret %= MOD;
	if (ret < 0) ret += MOD;
	return ret;
}

int64 getSum(int lo, int hi, int64 a, int64 b, int64 c)
{
	int64 n = (hi - lo) + 1;
	return (n * c + sumn(lo, hi) * b + sumn2(lo, hi) * a) % MOD;
}

void propagate(int x, int lo, int hi, int a, int b, int c)
{
	if (lo > hi) return ;
	f[x].sum = (f[x].sum + getSum(lo, hi, a, b, c)) % MOD;
	f[x].a += a;
	f[x].b += b;
	f[x].c += c;
}

void update(int x, int lo, int hi, int start, int end, int a, int b, int c)
{
	if (lo > hi || lo > end || hi < start) return ;

	int mid = (lo + hi) / 2;
	
	if (f[x].a || f[x].b || f[x].c) // lazyness
	{
		propagate(2 * x, lo, mid, f[x].a, f[x].b, f[x].c);
		propagate(2 * x + 1, mid + 1, hi, f[x].a, f[x].b, f[x].c);
		f[x].a = f[x].b = f[x].c = 0;
	}
	
	if (lo >= start && hi <= end)
	{
		propagate(x, lo, hi, a, b, c);
		return ;
	}

	update(2 * x, lo, mid, start, end, a, b, c);
	update(2 * x + 1, mid + 1, hi, start, end, a, b, c);
	
	f[x].sum = (f[2 * x].sum + f[2 * x + 1].sum) % MOD;
}

int query(int x, int lo, int hi, int start, int end)
{
	if (lo > hi || lo > end || hi < start) return 0;

	int mid = (lo + hi) / 2;
	if (f[x].a || f[x].b || f[x].c) // lazyness
	{
		propagate(2 * x, lo, mid, f[x].a, f[x].b, f[x].c);
		propagate(2 * x + 1, mid + 1, hi, f[x].a, f[x].b, f[x].c);
		f[x].a = f[x].b = f[x].c = 0;
	}
	if (lo >= start && hi <= end) return f[x].sum;
	return (query(2 * x, lo, mid, start, end) + query(2 * x + 1, mid + 1, hi, start, end)) % MOD;
}

int main()
{
	int N, Q;
	scanf( "%d %d", &N, &Q );
	while (Q--)
	{
		int op, lo, hi;
		scanf( "%d %d %d", &op, &lo, &hi );
		if (op) // query
		{
			printf( "%d\n", query(1, 0, N - 1, lo, hi) );
		}
		else
		{
			int a, b, c;
			scanf( "%d %d %d", &a, &b, &c );
			update(1, 0, N - 1, lo, hi, a, b, c);
		}
	}

	return 0;
}
