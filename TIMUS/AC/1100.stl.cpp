/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1100. Final Standings
*/
#include <cstdio>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 150000;

int N;
int id[MAXN], solved[MAXN];
int order[MAXN], tmp[MAXN];

bool myComp(int i, int j) { return solved[i] > solved[j]; }

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		scanf( "%d %d", &id[i], &solved[i] );
		order[i] = i;
	}
	
	std::stable_sort(order, order + N, myComp);
	
	REP(i, N)
		printf( "%d %d\n", id[ order[i] ], solved[ order[i] ] );

	return 0;
}
