/*
Alfonso2 Peterssen(mukel) UH++
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)

typedef long long int64;

typedef complex< int64 > point;

const int
	MAXN = 1 << 17;

int R, C, K;
bool canWin;

int main()
{

	scanf( "%d %d %d", &R, &C, &K );

	REP(i, K)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		x = min(x, R - x + 1);
		y = min(y, C - y + 1);
		if (x <= 5 || y <= 5) canWin = true;
	}
	
	printf( "%s\n", canWin ? "YES" : "NO" );

      return 0;
}
