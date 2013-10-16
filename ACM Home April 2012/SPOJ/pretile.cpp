// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).begin()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).begin(); ++it)

const int
	MAXN = 1 << 17;

int N;
char S[MAXN];
int pref[MAXN];

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%s", S );

		N = strlen(S);

		pref[0] = N;
		for (int i = 1, end = 0, f; i < N; i++ )
			// end = f + pref[f]
			if (i < end && pref[i - f] != end - i) pref[i] = min(pref[i - f], end - i);
			else
			{
				end = max(end, i);
				f = i;
				while (S[end] == S[end - f]) ++end;
				pref[i] = end - f;
			}

		long long ans = 0;
		REP(i, N) ans += pref[i] + i;

		cout << ans << endl;
	}

	return 0;
}
