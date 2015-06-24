/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #27 "Odd number"
*/
#include <cstdio>

int N, x, ans;

int main()
{
	for (scanf( "%d", &N ); N--;)
	{
		scanf( "%d", &x );
		ans ^= x;
	}
	
	printf( "%d\n", ans );

	return 0;
}
