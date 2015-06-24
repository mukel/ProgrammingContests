/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #42 "LCS problem"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int
	MAXN = 1 << 10;

int A, B;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

void rec(int i, int j)
{
	if (i < 1 || j < 1) return ;
	if (dp[i][j] == dp[i - 1][j - 1] + 1)
	{
		rec(i - 1, j - 1);
		printf( "%c", a[i] );
	}
	else
	{
		if (dp[i - 1][j] == dp[i][j])
			rec(i - 1, j);
		else
		      rec(i, j - 1);
	}
}

int main()
{
	cin >> (a + 1); A = strlen(a+1);
	cin >> (b + 1); B = strlen(b+1);
	
	for (int i = 1; i <= A; i++)
	for (int j = 1; j <= B; j++)
	      if (a[i] == b[j])
			dp[i][j] = dp[i - 1][j - 1] + 1;
		else
		      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	if (!dp[A][B])
		cout << "Empty" << endl;
	else
		rec(A, B);

	return 0;
}
