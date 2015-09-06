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
//#include <cmath>
//#include <complex>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

int n, x1, y1, x2, y2;

int solve()
{
	int steps = 0;
	while (x1 != x2 || y1 != y2)
	{
		if (x1 == 0 && y1) y1--;
		else
		if (x1 == n && y1 < n) y1++;
		else
		if (y1 == 0) x1++;
		else
		if (y1 == n) x1--;
		steps++;
	}
	return steps;
}

int main()
{
	scanf( "%d %d %d %d %d", &n, &x1, &y1, &x2, &y2 );
	
	int ans = solve();
	printf( "%d\n", min(ans, 4 * n - ans) );
	
	return 0;
}
