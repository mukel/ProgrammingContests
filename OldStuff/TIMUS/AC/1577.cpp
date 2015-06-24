/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1577. E-mail
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int64;


#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

const int
	MAXN = 2001;
	
const int
	MOD = (int)1e9 + 7;
	
char A[MAXN];
char B[MAXN];
short int dp[MAXN][MAXN];
int64 ways[MAXN][MAXN];

int main()
{
	scanf( "%s", A + 1 );
	scanf( "%s", B + 1 );
	
	int lenA = strlen(A + 1);
	int lenB = strlen(B + 1);
	
	dp[0][0] = 0;
	ways[0][0] = 1;
	
	FOR(i, 1, lenA)
	{
		dp[i][0] = i;
		ways[i][0] = 1;
	}
	
	FOR(j, 1, lenB)
	{
		dp[0][j] = j;
		ways[0][j] = 1;
	}

	FOR(i, 1, lenA)
	FOR(j, 1, lenB)
	{
		if (A[i] == B[j])
		{
			dp[i][j] = dp[i - 1][j - 1] + 1;
			ways[i][j] = ways[i - 1][j - 1];
		}
		else
		{
		      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
		      if (dp[i - 1][j] <= dp[i][j - 1])
		            ways[i][j] = (ways[i][j] + ways[i - 1][j]) % MOD;
		      if (dp[i][j - 1] <= dp[i - 1][j])
		            ways[i][j] = (ways[i][j] + ways[i][j - 1]) % MOD;
		}
	}

	cout << ways[lenA][lenB] << endl;

	return 0;
}
