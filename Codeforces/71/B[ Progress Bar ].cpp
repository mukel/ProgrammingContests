/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #65 (Div. 2)
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

	int n, k, t;
	cin >> n >> k >> t;
	REP(i, n)
	REP(cur, k + 1)
	{
		int sum = i * k + cur;
		int nk = n * k;
		if (sum * 100 <= t * nk && t * nk < (sum + 1) * 100)
		{
			REP(j, i) cout << k << " ";
			cout << cur << " ";
			REP(j, n - i - 1)
			      cout << 0 << " ";
			return 0;
		}
	}

	return 0;
}
