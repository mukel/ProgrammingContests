/*
Alfonso2 Peterssen
SPOJ #383 "European railroad tracks"
8 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 10;

int T, N;
int cant;
int sol[MAXN];
int rail[MAXN];
int S[MAXN], size;

void comb( int used ) {

	if ( size >= cant )
	      return ;

	REP( i, N )
	      if ( !( ( used >> i ) & 1 ) ) {
			REP( j, size )
			REP( k, size )
			      if ( S[j] - S[k] == rail[i] ) {
				      used |= ( 1 << i );
				      goto found;
				}
			found:;
		}

	if ( __builtin_popcount( used ) == N ) {
		cant = 0;
		REP( i, size )
			sol[cant++] = S[i];
		return ;
	}
		
	if ( size == 5 ) return ; // ...

	REP( i, N )
	      if ( !( ( used >> i ) & 1 ) )
			REP( j, size ) {
				int val1 = S[j] + rail[i];
				int val2 = S[j] - rail[i];
				S[size++] = val1; comb( used ); size--;
				S[size++] = val2; comb( used ); size--;
			}
}

int main() {

	scanf( "%d", &T );
	REP( t, T ) {
		scanf( "%d", &N );
		REP( i, N ) scanf( "%d", &rail[i] );
		
		size = 0;
		S[size++] = 0;
		S[size++] = rail[0];

		cant = N + 2;
		comb( 1 ); // first is used
		
		sort( sol, sol + cant );
		printf( "Scenario #%d\n", t + 1 );
		printf( "%d: ", cant );
		REP( i, cant )
		      printf( i < cant - 1 ? "%d " : "%d\n", sol[i] - sol[0] );
		printf( "\n" );
	}

	return 0;
}
