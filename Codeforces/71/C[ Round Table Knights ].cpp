/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #65 (Div. 2)
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

const int MAXN = 1 << 17;

int n;
int gmood[MAXN];

int main()
{
	scanf( "%d", &n );
	REP(i, n) scanf( "%d", &gmood[i] );
	FOR(i, 3, n) if (n % i == 0)
	{
		int ni = n / i;
		REP(j, ni)
		{
			bool ok = true;
			for (int k = j; k < n; k += ni)
			      if (!gmood[k])
			      {
					ok = false;
					break;
				}
			if (ok) { printf( "YES\n" ); return 0; }
		}
	}
	
	printf( "NO\n" );

	return 0;
}
