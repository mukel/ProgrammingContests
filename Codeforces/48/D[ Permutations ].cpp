/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>

#include <cstdlib>
#include <cstring>
#include <complex>
#include <cmath>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)

typedef long long int64;

const int MAXN = 1 << 17;

int N;
pair< int, int > elems[MAXN];
int cnt[MAXN];
int ans[MAXN];

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x;
		scanf( "%d", &x );
		elems[i] = make_pair(x, i);
		cnt[x]++;
	}
	
	for (int i = 2; i < MAXN; i++)
		if (cnt[i] > cnt[i - 1])
		{
			printf( "-1\n" );
			return 0;
		}
		
	sort(elems, elems + N);

	for (int i = 0, j; i < N; i = j)
	{
		int lvl = 0;
		for (j = i; j < N && elems[j].first == elems[i].first; j++)
			ans[ elems[j].second ] = ++lvl;
	}
	
	printf( "%d\n", *max_element(ans, ans + N) );
	REP(i, N)
		printf( "%d ", ans[i] );
	
      return 0;
}
