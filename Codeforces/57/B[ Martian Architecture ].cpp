/*
Alfonso2 Peterssen(mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int MAXM = 1 << 17;

int lo[MAXM], hi[MAXM], sh[MAXM];
int n, m, k;

int main()
{
	scanf( "%d %d %d", &n, &m, &k );
	REP(i, m)
		scanf( "%d %d %d", &lo[i], &hi[i], &sh[i] );

		int64 ans = 0;
	REP(i, k)
	{
		int x;
		scanf( "%d", &x );

		REP(j, m)
		{
			if (lo[j] <= x && x <= hi[j])
				ans += x - lo[j] + sh[j];
		}
		
		
	}
	
	cout << ans << endl;
	
	
	return 0;
}
