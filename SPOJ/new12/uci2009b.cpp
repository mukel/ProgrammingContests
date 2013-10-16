/*
Alfonso2 Peterssen
SPOJ #4523 "Binomial Coefficients"
6 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1 << 10;
	
int N, P;
int prime[MAXN];
bool mark[MAXN];

int countPrime(int n, int p)
{
	int ans = 0, powp = p;
	while (powp <= n)
	{
		ans += n / powp;
		powp *= p;
	}
	
	return ans;
}

int main()
{
	for (int i = 2; i < MAXN; i++)
	      if (!mark[i])
	      {
			prime[P++] = i;
	            for (int j = 2 * i; j < MAXN; j += i)
	                  mark[j] = true;
		}

	int T;
	for (scanf( "%d", &T ); T--;)
	{
		scanf( "%d", &N );
		if (N == 0)
		{
			printf( "1\n" );
			continue ;
		}

		for (int i = 0; i <= N; i++)
		{

			bool printCoeff = false;
			for (int j = 0; j < P && prime[j] <= N; j++)
			{
				int p = prime[j];
				int powp = countPrime(N, p) - countPrime(i, p) - countPrime(N - i, p);
				if (powp >= 1)
				{
					if (printCoeff) printf( "x" );
					printf( "%d", p );
					printCoeff = true;
				}
				if (powp >= 2) printf( "^%d", powp );
			}
			
			if (printCoeff) printf( "x" );

			// B^i, A^(N-i)
			if (N - i >= 1) printf( "A" );
			if (N - i >= 2) printf( "^%d", N - i );
			
			if (i >= 1) printf( "B" );
			if (i >= 2) printf( "^%d", i );
			
			if (i < N) printf( "+" );
		}
		
		printf( "\n" );
	}

	return 0;
}
