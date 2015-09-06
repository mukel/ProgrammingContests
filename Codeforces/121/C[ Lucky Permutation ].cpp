/*
	Alfonso2 Peterssen(mukel)
	Codeforces Beta Round #91 (Div. 1 Only)
*/
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

int N, K;

vector< int64 > L;

int64 l, r;

int64 fact[15];

void dfs(int64 x, int64 l, int64 r)
{
	if (x >= l && x <= r) L.push_back(x);
	if (x > r) return ;

	dfs(x * 10 + 4, l, r);
	dfs(x * 10 + 7, l, r);
}

bool mark[20];
int perm[20];

bool lucky(int64 x)
{
	if (!x) return false;
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7)
		      return false;
		x /= 10;
	}
	
	return true;
}

int main()
{
	fact[0] = 1;
	REP(i, 15) if (i) fact[i] = fact[i - 1] * i;
	
	cin >> N >> K;
	
	if (N < 13 && K > fact[N])
	{
		printf( "-1\n" );
		return 0;
	}
	
	int pend = 1;
	while (K > fact[pend]) ++pend;
	
	REP(i, pend) perm[i] = i;
	
	//cout << "pend: " << pend << endl;
	
	K--;
	for (int i = 0; i < pend; ++i)
	{
		int cnt = 0;
		REP(j, pend) if (!mark[j])
		{
			cnt++;
			if (cnt * fact[pend - i - 1] > K)
			{
				//printf( "-> %d ", j );
				K -= (cnt-1) * fact[pend - i - 1];
				perm[i] = j;
				mark[j] = true;
				break;
			}
		}
	}
	
/*
	REP(i, pend)
	      printf( "%d ", perm[i] );
	printf( "\n" );
	*/

	int ans = 0;
	for (int i = N - pend + 1; i <= N; ++i)
		if (lucky(i))
		{
			int x = perm[i - (N - pend + 1)] + N - pend + 1;
			if (lucky(x))
		      	ans++;
		}
	
	dfs(0, 1, N - pend);
	ans += L.size();
	
	cout << ans << endl;

	return 0;
}
