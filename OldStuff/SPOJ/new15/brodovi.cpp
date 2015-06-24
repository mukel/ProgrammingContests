/*
Alfonso2 Peterssen(mukel)
SPOJ #8349 "BRODOVI"
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

const int
	MAXN = 1 << 24;

int n;
int today;
int ans;
map< int, bool > M;

int main()
{
	scanf( "%d", &n );
	REP(i, n)
	{
		int x; scanf( "%d", &x );
		x--;
		if (x) M[x] = 0;
		today = max(today, x);
	}

	FOREACH(it, M) if (!it->second)
	{
		int step = it->first;
		
		bool ok = false;
		for (int j = step; j <= today; j += step)
		      if (!M.count(j))
			{
				ok = false;
				break;
			}
			else if (!M[j]) ok = 1;
			
		if (!ok) continue ;
		
		for (int j = step; j <= today; j += step)
			M[j] = true;
			
		ans++;
	}
	
	printf( "%d\n", ans );
	
	return 0;
}
