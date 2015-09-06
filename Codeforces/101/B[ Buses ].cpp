/*
Alfonso2 Peterssen(mukel)
Universidad de La Habana
Codeforces Round 79 Beta Div. 1
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
	MAXK = 1 << 17,
	MODULO = 1000000007;

int lobit(int x) { return x & -x; }

int C;
int coord[4 * MAXK];
int sum[4 * MAXK];
int dp[4 * MAXK];

void update(int x, int amount)
{
	for (; x < C; x += lobit(x + 1))
		sum[x] = (sum[x] + amount) % MODULO;
}

int query(int x)
{
	int ret = 0;
	for (; x >= 0; x -= lobit(x + 1))
		ret = (ret + sum[x]) % MODULO;
	return ret;
}

int N, K;

int getPos(int x)
{
	return lower_bound(coord, coord + C, x) - coord;
}

struct bus
{
	int s, t;
} buses[MAXK];

bool operator < (const bus & a, const bus & b)
{
	return a.t < b.t;
}

int main()
{
	scanf( "%d %d", &N, &K );

	REP(i, K)
	{
		int s, t;
		scanf( "%d %d", &s, &t );
		buses[i] = (bus){s, t};
		coord[C++] = s;
		coord[C++] = t;
		coord[C++] = s - 1;
		coord[C++] = t - 1;
	}
	
	coord[C++] = -1;
	coord[C++] = 0;
	coord[C++] = N;
	sort(coord, coord + C);
	C = unique(coord, coord + C) - coord;
	
	sort(buses, buses + K);
	
	update(getPos(0), 1);
	
	REP(i, K)
	{
		int pos = getPos(buses[i].t);
		
		int val = query(getPos(buses[i].t - 1)) - query(getPos(buses[i].s - 1));
		val = (val % MODULO);
		if (val < 0) val += MODULO;
		
		dp[pos] = (dp[pos] + val) % MODULO;
		
		//printf( "dp[%d] = %d\n", pos, dp[pos] );
		update(pos, val);
	}
	
	printf( "%d\n", dp[getPos(N)] );

	return 0;
}
