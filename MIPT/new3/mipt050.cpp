/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #50 "Two regular expressions"
Very cool DP
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

const int
	MAXL = 1 << 10;

int A, B;
char a[MAXL];
char b[MAXL];
int dp[MAXL][MAXL];

void rec(int i, int j)
{
	if (i < 1 || j < 1)
		return ;
	
	if (a[i] == '*' && b[j] == '*')
	{
		if (dp[i][j] == dp[i - 1][j]) rec(i - 1, j); else
		if (dp[i][j] == dp[i][j - 1]) rec(i, j - 1); else
			rec(i - 1, j - 1);
	}
	else
	if (a[i] == '*')
	{
		if (dp[i][j] == dp[i - 1][j])
			rec(i - 1, j);
		else {
			rec(i, j - 1);
			if (b[j] == '?') printf( "A" );
			else printf( "%c", b[j] );
		}
	}
	else
	if (b[j] == '*')
	{
		if (dp[i][j] == dp[i][j - 1])
			rec(i, j - 1);
		else {
			rec(i - 1, j);
			if (a[i] == '?') printf( "A" );
			else printf( "%c", a[i] );
		}
	} else
	{
		rec(i - 1, j - 1);
		if (a[i] == '?' && b[j] == '?') printf( "A" ); else
		if (a[i] == '?') printf( "%c", b[j] ); else
		if (b[j] == '?') printf( "%c", a[i] ); else
			assert(a[i] == b[j]), printf( "%c", a[i] );
	}
}

int main()
{
	scanf( "%s", a + 1 );
	scanf( "%s", b + 1 );
	A = strlen(a+1);
	B = strlen(b+1);

	memset(dp, 11, sizeof(dp));

	// assume that not exist two adjacent *
	dp[0][0] = 0;
	if (a[1] == '*') dp[1][0] = 0;
	if (b[1] == '*') dp[0][1] = 0;

	FOR(i, 1, A)
	FOR(j, 1, B)
	{
		if (a[i] == '*' && b[j] == '*') dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]); else
		if (a[i] == '*') dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + 1); else
		if (b[j] == '*') dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + 1); else
		if (a[i] == b[j] || a[i] == '?' || b[j] == '?') dp[i][j] = dp[i - 1][j - 1] + 1;
	}
	
	if (dp[A][B] > A + B)
		printf( "#\n" );
	else
	{
		//printf( "%d\n", dp[A][B] );
		rec(A, B); printf( "\n" );
	}

	return 0;
}
