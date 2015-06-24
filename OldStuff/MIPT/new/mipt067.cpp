/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #67 "Good permutations"
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
	MAXN = 1 << 11;

int N;
vector< int > mul[MAXN];
int ans[MAXN];
bool used[MAXN];

void srch(int n)
{
	if (!n)
	{
		FOR(i, 1, N) printf( "%d ", ans[i] );
		printf( "\n" );
		return ;
	}

	REP(i, mul[n].size())
	{
		int x = mul[n][i];
		if (used[x]) continue ;

		ans[n] = x;

		used[x] = 1;
		srch(n - 1);
		used[x] = 0;
	}
}

int main()
{
	scanf( "%d", &N );
	FOR(i, 1, N + 1)
	for (int j = i; j <= N + 1; j += i)
      	if (j != 1)
			mul[i].push_back(j);

	srch(N);

	return 0;
}
