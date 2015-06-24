/*
Alfonso2 Peterssen
SPOJ #6219 "Edit distance"
6 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int
	MAXL = 1 << 11;

int dp[MAXL][MAXL];
char sa[MAXL];
char sb[MAXL];

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%s", sa+1 ); int A = strlen(sa+1);
		scanf( "%s", sb+1 ); int B = strlen(sb+1);

		for (int i = 1; i <= A; i++)
		      dp[i][0] = i;
		
		for (int j = 1; j <= B; j++)
		      dp[0][j] = j;
		
		for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
		{
			if (sa[i] == sb[j])
			      dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
		}
		
		printf( "%d\n", dp[A][B] );
	}

	return 0;
}
