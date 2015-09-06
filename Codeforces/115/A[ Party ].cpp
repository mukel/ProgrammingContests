/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #87 (Div. 1 Only)
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

int V;
int boss[1 << 15];

int main()
{
	scanf( "%d", &V );
	REP(i, V)
	{
	      scanf( "%d", &boss[i] );
		boss[i]--;
	}
	
	int ans = 1;
	REP(i, V)
	{
		int x = i, depth = 0;
		while (x >= 0) x = boss[x], depth++;
		ans = max(ans, depth);
	}
	      
	cout << ans << endl;

	return 0;
}

