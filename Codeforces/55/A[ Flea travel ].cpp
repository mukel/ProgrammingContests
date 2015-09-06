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

const int MAXN = 1001;

int N, pos;
bool dp[MAXN][MAXN];
int used[MAXN];

int main()
{
	scanf( "%d", &N );
	
	for (int i = 0; !dp[pos][i]; i++)
	{
		dp[pos][i % N] = true;
		used[pos] = true;
		pos = (pos + i) % N;
	}
	
	printf( "%s\n", count(used, used + N, false) ? "NO" : "YES" );

      return 0;
}
