/*
Alfonso2 Peterssen
SPOJ #1865 "Making Waves"
1 - 10 - 2008
*/
#include <cstdio>
#include <cmath>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
const int MAXN = 1000;
const double EPSILON = 1e-5;

int T, N;
int frq1, frq2;
double sig[MAXN];

double value( int frq1, int frq2, int step ) {
	return
		sin( M_PI / 180. * step * frq1 / (double)N ) +
		sin( M_PI / 180. * step * frq2 / (double)N );
}

int main() {

	while ( ++T ) {
		scanf( "%d", &N ); if ( !N ) break;
		
		REP( i, N )
			scanf( "%lf", &sig[i] );
			
		for ( frq1 = 400; frq1 < 600; frq1++ )
		for ( frq2 = frq1; frq2 <= 600; frq2++ ) {
			int k;
			for ( k = 0; k < N; k++ )
				if ( fabs( value( frq1, frq2, k + 1 ) - sig[k] ) > EPSILON )
					break;
			if ( k == N ) {
				printf( "Case %d, f1 = %d, f2 = %d\n", T, frq1, frq2 );
				goto next_case;
			}
		}
		
		next_case:;
	}

	return 0;
}
