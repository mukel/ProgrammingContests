/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #65 "Queue for tickets"
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
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	MAXN = 1 << 14

int N;
int T[MAXN][3];
int memo[MAXN];

int solve(int n)
{
	if (n >= N) return 0;
	int & val = memo[n];
	if (val != -1) return val;
	
	val = T[n][0] + solve(n + 1);
	if (n + 1 < N) val = min(val, T[n][1] + solve(n + 2));
	if (n + 2 < N) val = min(val, T[n][2] + solve(n + 3));
	return val;
}

int main()
{
	memset(memo, -1, sizeof(memo));
	
	scanf( "%d", &N );
	REP(i, N)
	REP(j, 3)
	      scanf( "%d", &T[i][j] );
	      
	printf( "%d\n", solve(0) );

	return 0;
}

