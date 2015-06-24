/*
Alfonso2 Peterssen (mukel)
COCI 2012 Contest #4
Task: BROJ
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

typedef long long int64;

const int
      MAXS = 13698633,
      BILLION = (int)1e9;

int N, P;

int cnt;
int vals[MAXS/2];

int pCount;
int prime[MAXS / 10];

bitset< MAXS > mark;

void sieve(int upper)
{
	for (int i = 6; i * i < upper; i += 6)
	{
		int k = i - 1;
		if (!mark[k])
		{
			int k2 = k << 1;
			for (int j = k * k; j < upper; j += k2)
				mark[j] = true;
  		}
		k = i + 1;
		if (!mark[k])
		{
			int k2 = k << 1;
			for (int j = k * k; j < upper; j += k2)
				mark[j] = true;
		}
	}

	if (2 < upper) prime[pCount++] = 2;
	if (3 < upper) prime[pCount++] = 3;

	for (int i = 6; i < upper; i += 6)
	{
		if (!mark[i - 1]) prime[pCount++] = i - 1;
		if (i + 1 < upper && !mark[i + 1]) prime[pCount++] = i + 1;
	}
}

void comb(int64 x, int pos)
{
	vals[cnt++] = x;
	for (int64 nxt = x * (int64)prime[pos]; nxt <= BILLION; ++pos)
		comb(next, pos);
}

int main()
{
	scanf( "%d %d", &N, &P );

	if (P >= 73)
	{
		sieve(MAXS);

		int posP = find(prime, prime + pCount, P) - prime;
		comb(P, posP);

		if (cnt < N)
			printf( "0\n" );
		else
		{
			nth_element(vals, vals + (N - 1), vals + cnt);
			printf( "%d\n", vals[N - 1] );
		}
	}
	else
	{
		sieve(P);

		int lo = 1;
		int hi = BILLION + 1;

		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (calc(mid, P) < N)
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		if (lo > BILLION)
			printf( "0\n" );
		else
			printf( "%d\n", lo );
	}

	return 0;
}
