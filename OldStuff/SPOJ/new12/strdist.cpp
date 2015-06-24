/*
Alfonso2 Peterssen
SPOJ #2325 "String Distance"
6 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int
	MAXN = 1 << 17,
	MAXK = 1 << 7;
	
int A, B;
char sa[MAXN];
char sb[MAXN];

int dp[3][MAXN];

int main()
{
	scanf( "%d %d", &A, &B );
	scanf( "%s %s", sa + 1, sb + 1 );
	      
	for (int j = 1; j <= B; j++)
	      dp[0][j] = j;
	
	int i0, i1, i2;
	for (int i = 1; i <= A; i++)
	{
		i0 = i % 3;
		i1 = (i - 1) % 3;
		i2 = (i - 2 + 3) % 3;
		
		dp[i0][0] = i;
		
		int lo = max(1, i - MAXK);
		int hi = min(B, i + MAXK);
		
		for (int j = lo; j <= hi; j++)
		{
			if (sa[i] == sb[j])
			      dp[i0][j] = dp[i1][j - 1];
			else
			      dp[i0][j] = min(min(dp[i0][j - 1], dp[i1][j]), dp[i1][j - 1]) + 1;

                  if (i >= 2 && j >= 2 && sa[i] == sb[j - 1] && sa[i - 1] == sb[j])
				dp[i0][j] = min(dp[i0][j], dp[i2][j - 2] + 1);
		}
	}

	printf( "%d\n", dp[i0][B] );

	return 0;
}

