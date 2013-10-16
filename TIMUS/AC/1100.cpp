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

void mergeSort(int* arr, int n)
{
	if (n < 2) return ;
	mergeSort(arr, n/2);
	mergeSort(arr + n/2, n - n/2);
	std::merge(arr, arr + n/2, arr + n/2, arr + n, tmp, myComp);
	std::copy(tmp, tmp + n, arr);
}

int main()
{
	scanf( "%d", &N );
	REP(i, N)
	{
		scanf( "%d %d", &id[i], &solved[i] );
		order[i] = i;
	}
	
	mergeSort(order, N);
	
	REP(i, N)
		printf( "%d %d\n", id[ order[i] ], solved[ order[i] ] );

	return 0;
}
