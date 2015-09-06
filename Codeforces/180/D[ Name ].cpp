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

string S, T;
int cnt[0xff];
char ans[1 << 17];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> S;
	cin >> T;

	REP(i, SZ(S))
		cnt[ S[i] ]++;

	for (int i = 0; i < min(SZ(S), SZ(T)); ++i)
	{
		if (cnt[ T[i] ])
		{
			ans[i] = T[i];
			--cnt[ T[i] ];
		}
		else
		{
			FOR(ch, T[i] + 1, &#39;z&#39;)
				if (cnt[ch])
				{
					ans[i] = ch;
					cnt[ch]--;
					int pos = i+1;
					FOR(c, &#39;a&#39;, &#39;z&#39;)
						REP(j, cnt[c])
							ans[pos++] = c;
					cout << ans << endl;
					exit(0);
				}

			//cout << "Hello " << i << endl;

			for (int j = i - 1; j >= 0; --j)
			{
				++cnt[ T[j] ];
				FOR(ch, T[j] + 1, &#39;z&#39;)
					if (cnt[ch])
					{
						ans[j] = ch;
						cnt[ch]--;
						int pos = j+1;
						FOR(c, &#39;a&#39;, &#39;z&#39;)
							REP(j, cnt[c])
								ans[pos++] = c;
						cout << ans << endl;
						exit(0);
					}
			}
			cout << -1 << endl;
			exit(0);
		}
	}

	if (SZ(S) > SZ(T))
	{
		int pos = SZ(T);
		FOR(c, &#39;a&#39;, &#39;z&#39;)
			REP(j, cnt[c])
				ans[pos++] = c;
		cout << ans << endl;
		exit(0);
	}

	for (int j = SZ(S) - 1; j >= 0; --j)
	{
		++cnt[ T[j] ];
		FOR(ch, T[j] + 1, &#39;z&#39;)
			if (cnt[ch])
			{
				ans[j] = ch;
				cnt[ch]--;
				int pos = j+1;
				FOR(c, &#39;a&#39;, &#39;z&#39;)
					REP(j, cnt[c])
						ans[pos++] = c;
				cout << ans << endl;
				exit(0);
			}
	}
	cout << -1 << endl;

	return 0;
}
