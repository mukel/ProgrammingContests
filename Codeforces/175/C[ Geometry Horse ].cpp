// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1005;

int N;
pair< int64, int64 > F[MAXN];
int curP;
int T;
int64 P[MAXN];
int64 taken;
int64 answer;

int main()
{
	cin >> N;
	REP(i, N)
	{
		int k, c;
		cin >> k >> c;
		F[i] = make_pair(c, k);
	}

	sort(F, F + N);

	cin >> T;
	REP(i, T) cin >> P[i];

	P[T++] = (int64)1e15; // sentinel

	REP(i, N)
	{
		while (F[i].second > 0)
		{
			while (taken >= P[curP]) curP++;
			int64 toTake = min(F[i].second, P[curP] - taken);
			taken += toTake;
			F[i].second -= toTake;
			answer += (curP + 1) * toTake * F[i].first;
		}
	}

	cout << answer << endl;


	return 0;
}
