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

int N, M;
int T[1 << 17];
int X[1 << 17];
int ans[1 << 17];

int main()
{
	scanf( "%d %d", &N, &M );
	REP(i, N) scanf( "%d %d", &T[i], &X[i] );

	int nn = N, cur = 0;
	int totalTime = 0;
	while (nn)
	{
		int k = min(M, nn);
		nn -= k;
		vector< pair< int, int > > vals;
		REP(i, k)
		{
			vals.push_back(make_pair(X[cur], cur));
			totalTime = max(totalTime, T[cur]);
			cur++;
		}
		sort(ALL(vals));
		int lastPos = 0;
		for (int i = 0, j; i < k; i = j)
		{
			totalTime += vals[i].first - lastPos;
			for (j = i + 1; j < k && vals[j].first == vals[i].first; ++j);
			for (int z = i; z < j; ++z)
				ans[ vals[z].second ] = totalTime;
			totalTime += 1 + (j - i)/2;
			lastPos = vals[i].first;
		}
		totalTime += lastPos;
	}

	REP(i, N)
		printf( "%d ", ans[i] );

	return 0;
}
