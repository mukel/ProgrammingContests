/*
Alfonso2 Peterssen(mukel)
Codeforces #62
18 - 3 - 2010
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
#include <ext/hash_map>

using namespace std;
//using namespace __gnu_cxx;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXN = 1 << 17;

int n, k;
double sum;
int a[MAXN];

bool ok(double val)
{
	double lo = 0, up = 0;
	REP(i, n)
	      if (a[i] < val)
			lo += val - a[i];
		else
		      up += a[i] - val;

	return up - (up * k) / 100.0 >= lo;
}

int main()
{
	scanf( "%d %d", &n, &k );
	REP(i, n)
	{
		scanf( "%d", &a[i] );
		sum += a[i];
	}
	
	double lo = 0, hi = 1e3;
	REP(i, 100)
	{
		double mid = (lo + hi) / 2;
		if (ok(mid))
		      lo = mid;
		else
		      hi = mid;
	}

	printf( "%.9lf\n", lo );

	return 0;
}
