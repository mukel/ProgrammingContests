/*
	Alfonso2 Peterssen (mukel)
	Codeforces Round #110 Div 1
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 105,
	MODULO = 1000000007;

char buf[MAXN];
int memo[MAXN][26 * MAXN];

int solve(int n, int sum)
{
	if (sum < 0) return 0;
	if (n < 0) return (sum == 0);

	int & r = memo[n][sum];
	if (r != -1) return r;
	
	r = 0;
	for (int i = 0; i < 26; ++i)
	      r = (r + solve(n - 1, sum - i)) % MODULO;

	return r;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%s", &buf );
		
		int sum = 0;
		for (int i = 0; buf[i]; ++i)
			sum += buf[i] - &#39;a&#39;;
		
		int r = (solve(strlen(buf) - 1, sum) - 1 + MODULO) % MODULO;
		printf( "%d\n", r );
	}

	return 0;
}
