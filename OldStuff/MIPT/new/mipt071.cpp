/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #71 "Cables"
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

const int MAXN = 1 << 14;

int N, K;
int L[MAXN];

bool ok(int val)
{
	if (!val) return 1;
	int cnt = 0;
	REP(i, N) cnt += L[i] / val;
	return cnt >= K;
}

int main()
{
	scanf( "%d %d", &N, &K );
	REP(i, N)
	      scanf( "%d", &L[i] );
	      
	int lo = 0, hi = *max_element(L, L + N);
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (ok(mid))
		      lo = mid + 1;
		else
		      hi = mid - 1;
	}
	
	printf( "%d\n", lo - 1 );

	return 0;
}
