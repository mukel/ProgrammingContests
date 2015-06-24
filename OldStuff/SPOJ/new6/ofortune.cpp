/*
Alfonso2 Peterssen
SPOJ #1697 "Ohgas’ Fortune"
30 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int T, N;
int money, years;

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &money );
		scanf( "%d", &years );
		
		double sol = 1e-9;
		
		scanf( "%d", &N );
		REP( i, N ) {
			int kind;
			double interest, charge;
			scanf( "%d %lf %lf", &kind, &interest, &charge );
			
			double fund = money;
			
			if ( kind == 0 ) {
				double gain = 0;
				REP( i, years ) {
					gain += (int)( fund * interest );
					fund -= charge;
				}
				sol = max( sol, fund + gain );
			} else {
				REP( i, years )
					fund = fund + (int)( fund * interest ) - charge;
				sol = max( sol, fund );
			}
		}
		
		printf( "%.0lf\n", sol );
	}

	return 0;
}
