/*
 * Alfonso2 Peterssen(mukel)
 * Codeforces Round #61 (Div. 2)
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin, (c).end()
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define FOR(i, b, e) for (int (i) = (int)(b); (i) <= (int)(e); ++(i))

int n;
int h[1 << 10];

int main()
{	
	scanf( "%d", &n );
	REP(i, n)
		scanf( "%d", &h[i] );

	int ans = 0;
	REP(i, n)
	{
		int cnt = 1;
		for (int j = i - 1; j >= 0 && h[j] <= h[j + 1]; j--)
			cnt++;
		for (int j = i + 1; j < n && h[j] <= h[j - 1]; j++)
			cnt++;
		ans = max(ans, cnt);
	}

	printf( "%d\n", ans );
	
	return 0;
}
