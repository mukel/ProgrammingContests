/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #76 "Bracket structure correction"
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

const int
	MAXN = 1 << 10,
	oo = (int)1e9;

string S;
int memo[MAXN][MAXN];

int solve(int lo, int hi)
{
	if (lo > hi) return 0;
	if ((hi - lo + 1) % 2) return oo;
	
	int & val = memo[lo][hi];
	if (val != -1) return val;
	
	val = (S[lo] != '(') + solve(lo + 1, hi - 1) + (S[hi] != ')');
	for (int k = lo + 1; k < hi; k += 2)
	      val = min(val, solve(lo, k) + solve(k + 1, hi));
	      
	return val;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	cin >> S;

	int ans = solve(0, S.size() - 1);
	if (ans != oo)
	      cout << ans << endl;
	else
	      cout << "NO" << endl;

	return 0;
}
