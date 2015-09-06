/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #86 (Div. 1 Only)
*/

#include <cstdio>
#include <bitset>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

const int
	MAXN = (int)3e8;

int cnt;
//bitset< MAXN > mark;

int mark[MAXN/32 + 1];


	#define getBit(x) (mark[x >> 5] & (1 << (x & 31)))
	#define setBit(x) (mark[x >> 5] |= (1 << (x & 31)))


void fastSieve()
{
	for (int i = 6; (i+1) * (i+1) < MAXN; i += 6)
	{
		int a = i - 1;
		if (!getBit(a)) for (int j = a * a, a2 = a << 1; j < MAXN; j += a2) setBit(j);
		a = i + 1;
		if (!getBit(a)) for (int j = a * a, a2 = a << 1; j < MAXN; j += a2) setBit(j);
	}
}

int main()
{
	int lo, hi;
	scanf( "%d %d", &lo, &hi );
	
	fastSieve();
	/*
	// fast sieve
	for (int k = 1, i, i2; ; ++k)
	{
		i = 6 * k - 1;
		i2 = i << 1;

		if (i * i >= MAXN) break;

		if (!mark[i])
			for (int j = i * i; j < MAXN; j += i2)
			      if ((j & 3) == 1)
			      mark[j] = 1;

		i = 6 * k + 1;
		i2 = i << 1;

		//if (i * i >= MAXN) break;

		if (!mark[i])
			for (int j = i * i; j < MAXN; j += i2)
                  	if ((j & 3) == 1)
			      	mark[j] = 1;
	}
	*/

	if (lo <= 2 && 2 <= hi) cnt++;

	while (lo % 4 != 1 || lo == 1) lo++;

 /*	for (int i = lo; i <= hi; i += 4)
		if (!getBit(i) && (i % 3)) cnt++;
		*/


	/*
	int m = lo % 3;
	for (int i = lo; i <= hi; i += 4)
	{
		if (m)
		{
			if (!mark[i]) cnt++;
		}
		++m;
		if (m == 3) m = 0;
	}
	*/
	
	int m = lo % 3;
	for (int i = lo; i <= hi; i += 4)
	{
		if (m)
		{
			if (!getBit(i)) cnt++;
		}
		++m;
		if (m == 3) m = 0;
	}

	printf( "%d\n", cnt );

	return 0;
}
