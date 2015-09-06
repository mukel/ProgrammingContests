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

int H, M, N;
set< int > freePos[MAXH];
map< int, int > idPos;
int64 ans;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> H >> M >> N;

	REP(i, H)
		freePos[i % M].insert(i);

	REP(i, N)
	{
		char op; cin >> op;

		if (op == &#39;+&#39;)
		{
			int id, hash; cin >> id >> hash;

			set< int >::iterator it = freePos[hash % M].lower_bound(hash);

			if (it != freePos[hash % M].end())
			{
				ans += (*it - hash) / M;
				idPos[id] = *it;
				freePos[hash % M].erase(it);
			}
			else
			{
				int t = hash;
				while (1)
				{
					int mul = (H - t + (M - 1)) / M;
					int nextT = t + mul * M;
					ans += (nextT - t) / M;
					t = nextT - H;

					set< int >::iterator it = freePos[t].begin();
					if (it != freePos[t].end())
					{
						ans += (*it - t) / M;
						idPos[id] = *it;
						freePos[t].erase(it);
						break;
					}
				}
			}
		}
		else
		if (op == &#39;-&#39;)
		{
			int id; cin >> id;
			int p = idPos[id];
			freePos[ p % M ].insert(p);
		}
	}

	cout << ans << endl;

	return 0;
}
