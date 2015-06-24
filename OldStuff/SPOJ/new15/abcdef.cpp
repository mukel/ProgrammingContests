/*
Alfonso2 Peterssen(mukel)
SPOJ #4580 "ABCDEF"
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

const int MAXN = 100;

int val[MAXN];
tr1::unordered_map< int, int > H;

int main()
{
	int n; scanf( "%d", &n );
	REP(i, n) scanf( "%d", &val[i] );

	int64 ans = 0;
	REP(a, n) REP(b, n) REP(c, n) ++H[val[a] * val[b] + val[c]];
	
	REP(d, n) if (val[d] != 0) REP(e, n) REP(f, n)
	{
		int64 r = val[d] * (val[f] + val[e]);
		if (H.count(r)) ans += H[r];
	}
	
	cout << ans << endl;

	return 0;
}
