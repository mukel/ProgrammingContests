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

const int MAXC = 400;

int N, K, C;
int holiday[MAXC];

int main()
{
	scanf( "%d %d", &N, &K );
	scanf( "%d", &C );
	REP(i, C)
		scanf( "%d", &holiday[i] );
		
	int pLimit = 0, ans = 0;
	REP(i, C)
	{
		while (pLimit + K < holiday[i])
		{
			ans++;
			pLimit += K;
		}
		pLimit = holiday[i];
	}
	
	while (pLimit + K <= N) pLimit += K, ans++;
	
	printf( "%d\n", ans + C );

      return 0;
}
