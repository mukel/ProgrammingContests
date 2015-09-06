/*
Alfonso2 Peterssen(mukel)
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


char ans[4][102];
int main()
{
	int n;
	scanf( "%d", &n );
	if (n == 1)
	{
		printf( "a\na\nb\nb\n" );
	}
	if (n == 2)
	{
		printf( "aa\nbb\naa\nbb\n" );
	}
	if (n > 2)
	{
		REP(i, n) ans[0][i] = &#39;a&#39; + ((i/2) % 2) * 2;
		REP(i, n) ans[1][i] = &#39;b&#39; + ((i/2) % 2) * 2;
		
		ans[2][0] = &#39;z&#39;;
		REP(i, n) if (i) ans[2][i] = &#39;a&#39; + (((i - 1)/2) % 2) * 2;
		
		ans[3][0] = &#39;z&#39;;
		REP(i, n) if (i) ans[3][i] = &#39;b&#39; + (((i - 1)/2) % 2) * 2;

		if (n % 2)
		{
			ans[0][n - 1] = &#39;z&#39;;
			ans[1][n - 1] = &#39;z&#39;;
		} else
		{
			ans[2][n - 1] = &#39;z&#39;;
			ans[3][n - 1] = &#39;z&#39;;
		}
		
		REP(i, 4)
		      printf( "%s\n", ans[i] );
	}
	
	
	

	return 0;
}


