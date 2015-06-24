/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1586. Threeprime Numbers
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXP = 1000,
	MAXN = 10001;
	
const int64
	MOD = 1000000009LL;

bool mark[MAXP];
int P;
vector< int > primes[100];
int64 dp[MAXN][100];
int64 ans[MAXN];

int main()
{
	for (int i = 2; i < MAXP; i++)
	      if (!mark[i])
	      {
			if (i >= 100)
			{
				primes[i % 100].push_back(i);

				dp[3][i % 100]++;
				ans[3]++;
			}
				
			for (int j = 2 * i; j < MAXP; j += i)
			      mark[j] = true;
		}
		
	for (int i = 4; i < MAXN; i++)
		REP(j, 100)
		{
			REP(k, primes[j].size())
			{
				int x = primes[j][k];
				dp[i][j] = (dp[i][j] + dp[i - 1][x / 10]) % MOD;
			}
			ans[i] = (ans[i] + dp[i][j]) % MOD;;
		}

	int N;
	scanf( "%d", &N );
	cout << ans[N] % MOD << endl;
	
	return 0;
}
