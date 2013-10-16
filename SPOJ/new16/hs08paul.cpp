/*
Alfonso2 Peterssen(mukel)
SPOJ #4164 "A conjecture of Paul Erdos"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXN = (int)1e7 + 1;
	
bitset< MAXN > mark;
vector< int > ans;

bool isPrime(int x)
{
	if (x == 2 || x == 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;
	if (x < 2) return false;
	
	return !mark[x];
}

int main()
{
	// fast sieve
	for (int k = 1, i, i2; ; ++k)
	{
		i = 6 * k - 1;
		i2 = i << 1;

		if (i * i >= MAXN) break;

		if (!mark[i])
			for (int j = i * i; j < MAXN; j += i2)
			      mark[j] = true;

		i = 6 * k + 1;
		i2 = i << 1;

		if (!mark[i])
			for (int j = i * i; j < MAXN; j += i2)
			      mark[j] = true;
	}
	                  
	for (int y = 1, y4; (y4 = y*y*y*y) < MAXN; ++y)
		for (int x = 1, p; (p = x*x + y4) < MAXN; ++x)
		      if (isPrime(p))
				ans.push_back(p);
				
	sort(ALL(ans));
	ans.erase(unique(ALL(ans)), ans.end());

	int T; for (scanf( "%d", &T ); T--;)
	{
		int n; scanf( "%d", &n );
		printf( "%d\n", upper_bound(ALL(ans), n) - ans.begin() );
	}

	return 0;
}
