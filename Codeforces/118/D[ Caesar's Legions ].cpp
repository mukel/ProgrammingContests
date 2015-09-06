/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #89 (Div. 2 Only)
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

const int
	MAXN = 105,
	MOD = 100000000;

int n1, n2, k1, k2;
int dp[MAXN][MAXN][2];

int main()
{
	cin >> n1 >> n2 >> k1 >> k2;
	
	dp[0][0][0] = dp[0][0][1] = 1;
	
	for (int i = 0; i <= n1; ++i)
	for (int j = 0; j <= n2; ++j)
	{
		for (int k = 1; i - k >= 0 && k <= k1; ++k)
			dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
			
  		for (int k = 1; j - k >= 0 && k <= k2; ++k)
			dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
	}
	
	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;

	return 0;
}
