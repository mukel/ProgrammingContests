/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #36 "Two cubes"
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
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

typedef vector< int > cube;

const int LIMIT = 10000;

void rotate1(cube & a)
{
	int t = a[0]; a[0] = a[2]; a[2] = a[4]; a[4] = a[5]; a[5] = t;
}

void rotate2(cube & a)
{
	int t = a[1]; a[1] = a[2]; a[2] = a[3]; a[3] = a[5]; a[5] = t;
}

int main()
{
	cube a(6), b(6);
	REP(i, 6) cin >> a[i];
	REP(i, 6) cin >> b[i];
	
	REP(i, LIMIT)
	{
		if (rand() % 2) rotate1(a);
		else rotate2(a);
		if (a == b) { printf( "1\n" ); return 0; }
	}
	
	swap(a[1], a[3]);
	
	REP(i, LIMIT)
	{
		if (rand() % 2) rotate1(a);
		else rotate2(a);
		if (a == b) { printf( "2\n" ); return 0; }
	}
	
	printf( "0\n" );
	
	return 0;
}
