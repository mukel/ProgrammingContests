// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 18;

int N;
int P[MAXN];
int Q[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	REP(i, N)
	{
		int x;
		cin >> x;
		--x;
		P[i] = x;
	}

	REP(i, N)
	{
		int x;
		cin >> x;
		--x;
		Q[x] = i;
	}

	REP(i, N) P[i] = Q[ P[i] ];

	set< int > S;

	int ans = N;
	REP(i, N)
	{
		set< int >::iterator it = S.upper_bound(P[i]);
		if (it != S.end())
		{
			ans = i;
			break;
		}
		S.insert(P[i]);
	}

	cout << N - ans << endl;

	return 0;
}
