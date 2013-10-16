/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #58 "Alise and Basilio"
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

int main()
{
	int N;
	scanf( "%d", &N );
	
	priority_queue< int, vector< int >, greater< int > > PQ;
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		if (x) PQ.push(x);
	}
	
	int64 ans = 0;
	while (PQ.size() > 1)
	{
		int a = PQ.top(); PQ.pop();
		int b = PQ.top(); PQ.pop();
		PQ.push(a + b);
		ans += a + b;
	}
	
	cout << ans << endl;

	return 0;
}
