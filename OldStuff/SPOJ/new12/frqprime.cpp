/*
Alfonso2 Peterssen
SPOJ #5978 "Frequent Prime Ranges"
8 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int
	MAXN = 1 << 17;
	
int N, K, P;
int prime[MAXN];
bool mark[MAXN];

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
		scanf( "%d %d", &N, &K );
		if (K == 0)
		{
			printf( "%I64lld\n", (N*(int64)(N - 1)) / 2 );
			continue ;
		}
		
		int64 ans = 0;
		for (int i = 2, start = 0, end = K - 1; prime[end] <= N; i++)
		{
			ans += N - prime[end] + 1;
			while (i >= prime[start])
			      start++, end++;
		}
		
		printf( "%I64lld\n", ans );
	}


	return 0;
}
