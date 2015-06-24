/*
Alfonso2 Peterssen(mukel)
SPOJ #3639 "Lucky Numbers"
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

typedef pair< int, int > par;

const int
	MAXN = 203,
	MAXS = 10000;

int curMark;
int myPow10[MAXN];
int mark[MAXN][MAXS];
par from[MAXN][MAXS];

void print(int len, int mod)
{
	if (len <= 0) return ;
	if (from[len][mod].first == 6)
	{
		print(len - 1, from[len][mod].second);
		printf( "6" );
	}
	else
	if (from[len][mod].first == 8)
	{
		printf( "8" );
		print(len - 1, from[len][mod].second);
	}
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		curMark++;
		int s; scanf( "%d", &s );

		myPow10[0] = 1;
		FOR(i, 1, 200) myPow10[i] = (myPow10[i - 1] * 10) % s;

		bool found = false;

		queue< par > Q;
		for (Q.push(MP(0, 0)); !Q.empty(); Q.pop())
		{
			par top = Q.front();
			if (top.first > 200) break;

			if (top.first && !top.second)
			{
				found = true;
				print(top.first, 0);
				break;
			}

			int len = top.first + 1;
			int n6 = (top.second * 10 + 6) % s;
			int n8 = (8 * myPow10[top.first] + top.second) % s;

			if (mark[len][n6] != curMark)
			{
				mark[len][n6] = curMark;
				from[len][n6] = MP(6, top.second);
				Q.push(MP(len, n6));
			} else
			      if (from[len][n6].first == 8)
					from[len][n6] = MP(6, top.second);

			if (mark[len][n8] != curMark)
			{
				mark[len][n8] = curMark;
				from[len][n8] = MP(8, top.second);
				Q.push(MP(len, n8));
			}
		}

		if (!found) printf( "-1" );
		
		printf( "\n" );
	}

	return 0;
}
