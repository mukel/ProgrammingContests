/*
Alfonso2 Peterssen
SPOJ #7001 "Visible Lattice Points"
5 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = 1000001,
	MAXS = 7;
	
int64 etf[MAXN];
int size[MAXN];
int primes[MAXN][MAXS];
bool mark[MAXN];
int64 ans[MAXN];

inline int64 sqr(int x)
{
	return x * (int64)x;
}

int64 combAns;
int combN, combSize;
void comb(int currProd, int currPos, int currTaken)
{
	if (currTaken & 1)
	      combAns += sqr(combN / currProd);
	else
	      combAns -= sqr(combN / currProd);
	      
	while (currPos < combSize)
	{
	      comb(currProd * primes[combN][currPos], currPos + 1, currTaken + 1);
	      currPos++;
	}
}

int64 incExc(int n)
{
	combN = n;
	combSize = size[n];
	combAns = sqr(n);
	comb(1, 0, 0);
	return combAns;
}

int main()
{
	for (int i = 2; i < MAXN; i++)
	      etf[i] = i;

	for (int i = 2; i < MAXN; i++)
	      if (!mark[i])
	      {
			etf[i] = i - 1;
			primes[i][ size[i]++ ] = i;
			for (int j = 2 * i; j < MAXN; j += i)
			{
				mark[j] = true;
			      primes[j][ size[j]++ ] = i;
			      etf[j] = etf[j] * (i - 1) / i;
			}
		}
		
	ans[1] = 7;
	for (int i = 2; i < MAXN; i++)
	{
		ans[i] = ans[i - 1];
		ans[i] += 3 * etf[i];
		int64 x = sqr(i) - incExc(i);
		ans[i] += 3 * x;
	}

	int T;
	for (scanf( "%d", &T ); T--;)
	{
		int N;
		scanf( "%d", &N );
		
		/*
		int ans = 0;
		REP(i, N+1)
		REP(j, N+1)
		REP(k, N+1)
		      if (__gcd(i, __gcd(j, k)) == 1)
		            ans++;
			printf( "%d\n", ans );
		continue ;
		*/
		
		printf( "%I64lld\n", ans[N] );
	}

	return 0;
}
