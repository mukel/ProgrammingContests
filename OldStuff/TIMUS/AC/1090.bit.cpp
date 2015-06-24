/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1090. In the army now
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 10000,
	MAXK = 20;
	
int N, K;
int vals[MAXN];
int ans[MAXK];

int S[MAXN + 1];
	
int lobit(int x) { return x & -x; }
	
void update(int x)
{
     	for (; x <= N; x += lobit(x))
		S[x]++;
}
	
int query(int x)
{
	int sum = 0;
	for (; x > 0; x -= lobit(x))
		sum += S[x];
	return sum;
}

int countInv()
{
	memset(S, 0, sizeof(S));

	int swaps = 0;
	REP(i, N)
	{
		swaps += query(vals[i]);
		update(vals[i]);
	}
	
	return swaps;
}

int main()
{
	scanf( "%d %d", &N, &K );
	REP(i, K)
	{
		REP(j, N) scanf( "%d", &vals[j] );
		ans[i] = countInv();
	}
	
	printf( "%d\n", min_element(ans, ans + K) - ans + 1 );

	return 0;
}
