/*
Alfonso2 Peterssen(mukel)
Yandex Open 2011 - Qualification 1
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

const int MAXN = 1 << 18;

int n, a, b;
vector< pair< int, int > > V;
int ans[MAXN];

bool myComp(const pair< int, int > & a, const pair< int, int > & b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main()
{
	scanf( "%d %d %d", &n, &a, &b );
	REP(i, n)
	{
		int x;
		scanf( "%d", &x );
		V.PB(MP(x, i));
	}
	
	if (a == b)
	{
		REP(i, a) printf( "1 " );
		REP(i, b) printf( "2 " );
	}
	else
	{
		if (b - a < 0) sort(ALL(V));
		else sort(ALL(V), myComp);
		
		REP(i, SZ(V))
		{
			if (!a) break;
			ans[V[i].second] = 1;
			a--;
		}
		REP(i, n) if (!ans[i]) ans[i] = 2;
		REP(i, n) printf( "%d ", ans[i] );
	}

	return 0;
}
