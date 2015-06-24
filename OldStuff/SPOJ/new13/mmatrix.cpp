/*
Alfonso2 Peterssen
SPOJ #3935. "SHIFT Operator on Matrix"
15 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	MAXN = 8;

int N;
int mat[MAXN][MAXN];
int bestCost;
int val[MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];
int minValue[MAXN];

void comb(int row)
{
	if (row >= N)
	{
		bestCost = *max_element(sum[row], sum[row] + N);
		return ;
	}
	
	REP(i, N) // offset
	{
		REP(j, N)
		{
			sum[row + 1][j] = sum[row][j] + val[row][i][j];
			if (sum[row + 1][j] + minValue[row] >= bestCost)
				goto skipComb;
		}
		comb(row + 1);
		skipComb:;
	}
}

int main()
{
	while (1)
	{
		scanf( "%d", &N );
		if (N < 0) break;
		
		REP(i, N)
		REP(j, N)
		{
		      scanf( "%d", &mat[i][j] );
		      mat[i][j] += 1e4; // make it nonnegative
		}

		REP(i, N)
		REP(j, N)
		REP(k, N) // offset
			val[i][k][j] = mat[i][(j + k) % N];

		minValue[N - 1] = 0;
		for (int i = N - 2; i >= 0; i--)
		      minValue[i] = minValue[i + 1] + *min_element(mat[i+1], mat[i+1] + N);

		REP(i, N)
		REP(j, N)
			sum[i + 1][j] = sum[i][j] + mat[i][j];
			
		bestCost = *max_element(sum[N], sum[N] + N);

		comb(1); // let first row static
		
		printf( "%d\n", bestCost - N * (int)1e4 );
	}

	return 0;
}
