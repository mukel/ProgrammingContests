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
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
	MAXN = 1 << 17;

typedef pair< int, int > par;

int N, M, X, Y;
par A[MAXN];
par B[MAXN];
vector< par > ans;

int main()
{
	scanf( "%d %d %d %d", &N, &M, &X, &Y );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		A[i] = make_pair(x, i);
	}
	REP(i, M)
	{
		int x;
		scanf( "%d", &x );
		B[i] = make_pair(x, i);
	}

	int cur = 0;
	REP(i, N)
	{
		while (cur < M && B[cur].first < A[i].first - X)
			cur++;

		if (cur < M && B[cur].first >= A[i].first - X && B[cur].first <= A[i].first + Y)
		{
			ans.push_back(make_pair(A[i].second, B[cur].second));
			cur++;
		}
	}

	printf( "%d\n", SZ(ans) );
	REP(i, SZ(ans))
	printf( "%d %d\n", ans[i].first + 1, ans[i].second + 1 );

	return 0;
}
