/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #72 (Div. 1 Only)
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
#include <tr1/unordered_map>

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

int n, prev;
int64 ans, cnt;

int main()
{
	scanf( "%d", &n );
	REP(i, n)
	{
		int x;
		scanf( "%d", &x  );
		if (i && x == prev) cnt++;
		else cnt = 1;
		prev = x;
		ans += cnt;
	}
	
	cout << ans << endl;

	return 0;
}
