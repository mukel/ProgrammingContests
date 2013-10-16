/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1028. Stars
*/
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 15000,
	MAXC = 32002;
	
int N;
int S[MAXC];
int ans[MAXN];

int lobit(int x) { return x & -x; }

void update(int x)
{
	for (++x; x < MAXC; x += lobit(x))
	      S[x]++;
}

int query(int x)
{
	int sum = 0;
	for (++x; x > 0; x -= lobit(x))
	      sum += S[x];
	return sum;
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		int x, y;
		scanf( "%d %d", &x, &y );
		ans[query(x)]++;
		update(x);
	}
	
	REP(i, N)
	      printf( "%d\n", ans[i] );
	
	return 0;
}
