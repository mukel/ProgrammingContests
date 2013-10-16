/*
Alfonso2 Peterssen (mukel)
SPOJ "MERGSORT"
19 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

const int MAXN = 1 << 17;

int N, vals[MAXN], tmp[MAXN];

void msort( int a[], int N ) {
	if ( N < 2 ) return ;
	msort( a, N/2 ); msort( a + N/2, N - N/2 );
	std::merge( a, a + N/2, a + N/2, a + N, tmp );
	for (int i = 0; i < N; i++)
		a[i] = tmp[i];
}

int main() {

	while ( scanf( "%d", &vals[N] ) == 1 ) N++;
	msort( vals, N );
	for (int i = 0; i < N; i++)
		printf( "%d ", vals[i] );

	return 0;
}
