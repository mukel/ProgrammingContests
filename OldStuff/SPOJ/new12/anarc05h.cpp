/*
Alfonso2 Peterssen
SPOJ #4564 "Chop Ahoy! Revisited!"
7 - 8 - 2010
*/
#include <cstdio>
//#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	MAXN = 1 << 7;

int64 dp[MAXN][MAXN];
char buff[MAXN];
int S[MAXN];

int main()
{
	for (int test = 1;; test++)
	{
		scanf( "%s", &buff );
		if (buff[0] == 'b')
		      break;
		      
		int N = strlen(buff);
		REP(i, N)
		{
			dp[1][i + 1] = 1;
			S[i + 1] = S[i] + buff[i] - '0';
		}
			
		for (int i = 2; i <= N; i++)
			for (int j = i; j <= N; j++)
			{
				dp[i][j] = 0;
			      for (int k = i - 1; k > 0; k--)
			      {
					if (S[i - 1] - S[k - 1] > S[j] - S[i - 1])
					      break;
					dp[i][j] += dp[k][i - 1];
				}
			}
				
		int64 ans = 0;
		for (int i = 1; i <= N; i++)
		      ans += dp[i][N];
		      
		printf( "%d. %I64lld\n", test, ans );
	}

	return 0;
}
