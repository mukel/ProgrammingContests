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

int N, M, K;
int c[MAXN];
vector< int > pos[MAXN];
int ans;

bool ok(int lo, int hi, int id)
{
	int cnt = upper_bound(ALL(pos[id]), hi) - lower_bound(ALL(pos[id]), lo);
	bool r = (hi - lo + 1) - cnt <= K;
	if (r) ans = max(ans, cnt);
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;

	REP(i, N)
	{
		cin >> c[i];
		pos[ c[i] ].push_back(i);
	}

	REP(i, N)
	{
		int lo = i, hi = N - 1;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (ok(i, mid, c[i])) lo = mid + 1;
			else hi = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}
