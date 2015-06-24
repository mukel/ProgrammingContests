/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #153 "Knight's move"
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

const int
	MAXN = 1 << 7;

const int BASE = 1000000;
typedef vector< int64 > big;

big dp[MAXN][10];
vector< int > G[10];

big& norm(big & a)
{
	int64 c = 0;
	REP(i, SZ(a))
	{
		int64 t = a[i] + c;
		a[i] = t % BASE;
		c = t / BASE;
	}
	
	while (c) a.PB(c % BASE), c /= BASE;
	while (a.size() > 1 && !a.back()) a.pop_back();
	
	return a;
}

big& operator += (big & a, const big & b)
{
	if (SZ(b) > SZ(a)) a.resize(SZ(b));
	REP(i, SZ(b)) a[i] += b[i];
	return norm(a);
}

void print(const big & a)
{
	printf( "%d", a.back() );
	for (int i = SZ(a) - 2; i >= 0; --i)
	      printf( "%06d", a[i] );
}

int main()
{
	G[0].PB(4); G[0].PB(6);
	G[1].PB(8); G[1].PB(6);
	G[2].PB(7); G[2].PB(9);
	G[3].PB(4); G[3].PB(8);
	G[4].PB(3); G[4].PB(9); G[4].PB(0);
	// 5
	G[6].PB(1); G[6].PB(7); G[6].PB(0);
	G[7].PB(2); G[7].PB(6);
	G[8].PB(1); G[8].PB(3);
	G[9].PB(4); G[9].PB(2);

	REP(i, 10) if (i != 0 && i != 8) dp[1][i].assign(1, 1);
	
	int N; cin >> N;
	
	FOR(i, 2, N)
	REP(j, 10)
	REP(k, SZ(G[j]))
		dp[i][j] += dp[i - 1][G[j][k]];

	big ans(1, 0);
	REP(i, 10)
	      ans += dp[N][i];
	      
	print(ans); printf( "\n" );

	return 0;
}
