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
	MAXN = 100,
	MAXM = 100;

int N, M, K;
int a[MAXN][MAXM];
int b[MAXN][MAXM];
int c[MAXN][MAXM];
int best;

int main()
{
	cin >> N >> M >> K;
	REP(i, N)
	{
		string planet;
		cin >> planet;
		REP(j, M)
			cin >> a[i][j] >> b[i][j] >> c[i][j];
	}

	REP(p1, N)
	REP(p2, N) if (p1 != p2)
	{
		vector< pair< int, int > > kk;
		REP(i, M)
		{
			int dif = b[p2][i] - a[p1][i];
			if (dif > 0)
				kk.push_back(make_pair(dif, c[p1][i]));
		}

		sort(ALL(kk));
		reverse(ALL(kk));

		int cnt = 0, t = 0;
		REP(i, SZ(kk))
		{
			int take = min(K - cnt, kk[i].second);
			t += take * kk[i].first;
			cnt += take;
		}

		best = max(best, t);
	}

	cout << best << endl;

	return 0;
}
