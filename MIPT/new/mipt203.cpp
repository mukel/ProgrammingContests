/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #203 "Lucky tickets"
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
#define MP(x, y) make_pair((x), (y))
#define SZ(c) ((int)((c).size()))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXS = 201 * 16;

const int BASE = 100000000;

typedef vector< int64 > big;

big& norm(big & a)
{
	int64 c = 0;
	REP(i, SZ(a))
	{
		while (a[i] < 0) a[i] += BASE, a[i+1]--;
		int64 t = a[i] + c;
		a[i] = t % BASE;
		c = t / BASE;
	}
	while (c > 0) a.push_back(c % BASE), c /= BASE;
	while (SZ(a) > 1 && !a.back()) a.pop_back();
	return a;
}

big& operator + (big & a, const big & b)
{
	big c(max(SZ(a),SZ(b)));
	REP(i, SZ(a)) c[i] = a[i];
	REP(i, SZ(b)) c[i] += b[i];
	return norm(c);
}

big& operator -= (big & a, const big & b)
{
	if (SZ(b) > SZ(a)) a.resize(SZ(b));
	REP(i, SZ(b)) a[i] -= b[i];
	return norm(a);
}

big& operator += (big & a, const big & b)
{
	if (SZ(b) > SZ(a)) a.resize(SZ(b));
	REP(i, SZ(b)) a[i] += b[i];
	return norm(a);
}

big operator * (const big & a, const big & b)
{
	big c(SZ(a) + SZ(b));
	REP(i, SZ(a))
	REP(j, SZ(b)) c[i + j] += a[i] * b[j];
	return norm(c);
}

void print(const big & a)
{
	printf( "%d", a.back() );
	for (int i = SZ(a) - 2; i >= 0; i--)
	      printf( "%08d", a[i] );
}

int N, K, S;
big dp[2][MAXS];

int main()
{
	cin >> N >> K;

	dp[0][0].assign(1, 1);

	FOR(i, 1, N)
	FOR(s, 0, i * (K - 1))
	{
		big & val = dp[i&1][s];
		val = dp[(i&1)^1][s];
		if (s > 0) val += dp[i&1][s - 1];
		if (s >= K) val -= dp[(i&1)^1][s - K];
	}

	big ans(1, 0);
	FOR(s, 0, N * (K - 1))
	      ans += dp[N&1][s] * dp[N&1][s];

	print(ans); printf( "\n" );

	return 0;
}
