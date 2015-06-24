/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1183. Brackets sequence
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
const int
	MAXN = 105;

int N;
char S[MAXN];
int dp[MAXN][MAXN];
int from[MAXN][MAXN];

void print(int lo, int hi)
{
	if (lo > hi) return ;
	if (lo == hi)
	{
		if (S[lo] == '(' || S[lo] == ')')
			printf( "()" );
		else
		      printf( "[]" );
		return ;
	}
	
	if (from[lo][hi] == -1)
	{
		printf( "%c", S[lo] );
		print(lo + 1, hi - 1);
		printf( "%c", S[hi] );
		return ;
	}
	
	if (from[lo][hi] == -2)
	{
		print(lo, lo);
		print(lo + 1, hi - 1);
		print(hi, hi);
		return ;
	}
	
	print(lo, from[lo][hi]);
	print(from[lo][hi] + 1, hi);
}

int main()
{
	scanf( "%s", &S );
	N = strlen(S);
	
	for (int sz = 0; sz < N; sz++)
	{
		for (int lo = 0; lo < N; lo++)
		{
			int hi = lo + sz;
			if (hi >= N) break ;
			
			if (sz == 0)
			{
				dp[lo][hi] = 1;
				continue ;
			}

			if ((S[lo] == '(' && S[hi] == ')') || (S[lo] == '[' && S[hi] == ']'))
			{
				dp[lo][hi] = dp[lo + 1][hi - 1];
				from[lo][hi] = -1;
			}
			else
			{
				dp[lo][hi] = dp[lo + 1][hi - 1] + 2;
				from[lo][hi] = -2;
			}

			for (int k = lo; k < hi; k++)
			{
				int tmp = dp[lo][k] + dp[k + 1][hi];
				if (tmp < dp[lo][hi])
				{
					dp[lo][hi] = tmp;
					from[lo][hi] = k;
				}
			}
		}
	}
	
	print(0, N - 1);
	printf( "\n" );

	return 0;
}
