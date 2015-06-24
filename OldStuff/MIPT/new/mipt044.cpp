/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #44 "Frame paving"
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
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

bool test(int n, int X, int Y)
{
	int m1 = X % n;
	if (m1 > 1) return 0;

	int m2 = (Y - !m1) % n;
	if (m2 > 1) return 0;

	int m3 = (X - !m2) % n;
	if (m3 > 1) return 0;

	int m4 = (Y - 1 - !m3) % n;
	if (m4) return 0;

	return 1;
}

int main()
{
	int X, Y;
	scanf( "%d %d", &X, &Y );
	
	int Q;
	for (scanf( "%d", &Q ); Q--;)
	{
		int n;
		scanf( "%d", &n );
		if (test(n, X, Y) || test(n, Y, X))
		      cout << "YES" << endl;
		else
		      cout << "NO" << endl;
	}

	return 0;
}

