/*
Alfonso2 Peterssen(mukel)
SPOJ #8611 "Non-Decreasing Digits"
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
#include <cassert>

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
	MAXN = 100;
	
unsigned long long dp[MAXN][10];

int main()
{
	REP(i, 10) dp[1][i] = i + 1;

	FOR(i, 2, MAXN - 1)
	REP(j, 10)
	{
		if (j) dp[i][j] += dp[i][j - 1];
      	dp[i][j] += dp[i - 1][j];
      	//assert(dp[i][j] > 0);
	}

	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int testCase, n;
		scanf( "%d %d", &testCase, &n );
		cout << n << " " << dp[n][9] << endl;
	}
	
	return 0;
}
