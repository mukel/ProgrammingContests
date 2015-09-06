/*
Alfonso2 Peterssen(mukel)
Yandex Open 2011 - Qualification 1
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

const int MAXN = 1 << 18;

int N, M;
int cant[MAXN];
int __cant[MAXN];
int ans[MAXN];
int idx[100];

bool check(int x)
{
	return ans[(x - 1 + N) % N] != ans[x] && ans[x] != ans[(x + 1) % N];
}

int main()
{
	scanf( "%d %d", &N, &M );
	REP(i, M)
	{
		scanf( "%d", &__cant[i] );
		idx[i] = i;
	}
	

		
	REP(t, 40)
	{
		random_shuffle(idx, idx + M);
		REP(i, M) cant[i] = __cant[i];
		
	int best = 0;
//	REP(__i, M) { int i = idx[__i]; if (cant[i] > cant[best]) best = i;}
	
	best = rand() % M;
	ans[0] = best; cant[best]--;
	
	REP(i, N) if (i)
	{
		int best = -1;
		REP(__j, M)
		{
			int j = idx[__j];
		if (j != ans[i - 1] && (best < 0 || cant[j] > cant[best]))
		if (i != N - 1 || (i == N - 1 && j != ans[0]))
		      best = j;
		}
		      
		if (best < 0 && i == N - 1)
		{
			REP(j, M) if (cant[j])
			REP(k, N)
			{
				ans[N - 1] = j;
				swap(ans[k], ans[N - 1]);
				if (check(k) && check(N - 1))
				{
					goto ok;
				}
				swap(ans[k], ans[N - 1]);
			}
		}

		if (best < 0 || !cant[best]) goto nextCase;
		
		cant[best]--;
		ans[i] = best;
	}
	
	goto ok;
	
	nextCase:;
}

		printf( "-1\n" );
		return 0;
	
	ok:;
	
	REP(i, N)
	      printf( "%d ", ans[i] + 1 );

	return 0;
}
