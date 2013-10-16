/*
Alfonso2 Peterssen (mukel)
SPOJ #696 "Liar Liar"
17 - 5 - 2009
thanks to Ivan Katanic
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXN = 100,
	oo = (int)1e9;

int T, N;
char mat[MAXN][MAXN];

bool ok( int i ) { // check if i is a truth-speaker
	REP( j, N ) {

		// assumes j is what i says
		bool lies = false;
		REP( k, N )
		      if ( mat[j][k] != mat[i][k] ) {
				lies = true;
				break ;
			}
			
		if ( mat[i][j] == 'T' && lies ) return false;
 		if ( mat[i][j] == 'L' && !lies ) return false;
	}
	
	return true;
}

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {
		scanf( "%d", &N );
		REP( i, N )
		      scanf( "%s", &mat[i] );

		int lo = oo, hi = -oo;
		REP( i, N ) {
			if ( !ok(i) ) continue ;
			int liars = 0;
			REP( j, N )
			      if ( mat[i][j] == 'L' ) liars++;
			lo = min( lo, liars );
  			hi = max( hi, liars );
		}
		
		// chek if everybody lies
		REP( i, N ) mat[N][i] = 'L';
 		if ( ok( N ) ) {
			lo = min( lo, N );
	  		hi = max( hi, N );
		}
		
		if ( lo != oo )
			printf( "Class Room#%d contains atleast %d and atmost %d liars\n", tc + 1, lo, hi );
		else
			printf( "Class Room#%d is paradoxical\n", tc + 1 );
	}

	return 0;
}
