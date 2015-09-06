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
#include <cassert>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXH = 1 << 18;

typedef pair< int, int > par;

int H, M, N;

map< int, int > idPos;
map< int, int > idHash;

int64 ans;

set< par > vals[MAXH];
bool mark[MAXH];

int fromSet[MAXH];
int fromPos[MAXH];

int startSize[MAXH];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> H >> M >> N;

	REP(i, M)
		if (!mark[i])
		{
			int cnt = 0;
			for (int j = i; !mark[j]; j = (j + M) % H)
			{
				mark[j] = true;
				fromSet[j] = i;
				fromPos[j] = cnt;
				vals[i].insert(make_pair(cnt, j));
				cnt++;
			}

			startSize[i] = SZ(vals[i]);
		}

	REP(i, N)
	{
		char op; cin >> op;

		if (op == &#39;+&#39;)
		{
			int id, hash; cin >> id >> hash;
			int bck = fromSet[hash];
			int pos = fromPos[hash];

			set< par >::iterator it = vals[bck].lower_bound(make_pair(pos, hash));

			if (it != vals[bck].end())
			{
				ans += it->first - pos;

				idPos[id] = it->first;
				idHash[id] = it->second;

				vals[bck].erase(it);
			}
			else
			{
				ans += startSize[bck] - pos;

				it = vals[bck].begin();
				ans += it->first;

				idPos[id] = it->first;
				idHash[id] = it->second;

				vals[bck].erase(it);
			}
		}
		else
		{
			int id; cin >> id;
			int pos = idPos[id];
			int hash = idHash[id];
			int bck = fromSet[hash];
			vals[bck].insert(make_pair(pos, hash));
		}

	}

	cout << ans << endl;

	return 0;
}
