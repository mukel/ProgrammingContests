/*
Alfonso2 Peterssen
SPOJ #1868 "Making Money"
4 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int T, C;
double M, I;

int main() {

	while( ++T ) {

		scanf( "%lf %lf %d", &M, &I, &C );
		
		if ( M == 0. && I == 0. && C == 0 )
		      break;
		      
		double final = M;
		REP( i, C ) {
			double kk = ( final * I / C / 100. );
			kk = (int)(kk * 100);
			kk /= 100;
			final += kk;
		}
		
		printf( "Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n", T, M, I, C, final );
	}

	return 0;
}
