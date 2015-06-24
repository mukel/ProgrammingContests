/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #202 "Pete in love"
*/
#include <cstdio>
#include <iostream>

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

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXN = 1 << 8;
	
int64 memo[MAXN][MAXN];
	
int solve(int value, int lastCoin)
{
	if (value < 0) return 0;
	if (!value) return 1;
	if (!lastCoin) return 0;
	
	int64 & val = memo[value][lastCoin];
	if (val) return val;

	return val = solve(value, lastCoin - 1) + solve(value - lastCoin, lastCoin);
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n, n) << endl;

	return 0;
}
