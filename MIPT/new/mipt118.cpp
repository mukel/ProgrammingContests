/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #118 "Pancake-week"
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
	MAXN = 1 << 17;
	
int N;
int cnt;
int lis[MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		int pos = upper_bound(lis, lis + cnt, x) - lis;
		if (pos >= cnt) cnt++;
		lis[pos] = x;
	}
	
	printf( "%d\n", cnt );

	return 0;
}
