/*
Alfonso2 Peterssen(mukel)
Codeforces Beta Round #88
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)

int main()
{
	int a, b, mod;

	scanf( "%d %d %d", &a, &b, &mod );
	
	FOR(s1, 0, min(a, mod - 1))
	if ((mod - (s1 * (int64)1e9) % mod) % mod > b)
	{
	      printf( "1 %09d", s1 );
		return 0;
	}

	printf( "2\n" );

	return 0;
}

