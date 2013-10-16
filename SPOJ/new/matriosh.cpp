/*
Alfonso2 Peterssen
SPOJ #999 "Generalized Matrioshkas"
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 1000000;

int N;
int S[MAXN];

bool check( int lo, int hi ) {

//	printf( "%d %d -> %d\n", lo, hi, abs( S[lo] ) );

	if ( S[lo] > 0 || S[hi] < 0 || -S[lo] != S[hi] )
	      return false;
	      
	if ( hi - lo == 1 )
	      return true;
	      
	int sum = 0;
	int pos = lo + 1;
	
	while ( pos < hi ) {
		bool found = false;
		int last_pos = pos, cant = 0;
	      for ( ; pos < hi; pos++ ) {
			if ( abs( S[pos] ) != abs( S[last_pos] ) )
			      continue;
			if ( S[pos] < 0 )
			      cant++;
			else
			      cant--;
			      
			if ( cant < 0 )
			      return false;
			      
			if ( cant == 0 ) {
				sum += abs( S[last_pos] );
				if ( sum >= abs( S[lo] ) )
				      return false;
				      
			      if ( !check( last_pos, pos ) )
			            return false;
			      found = true;
			      break;
			}
		}
		if ( !found )
		      return false;
		pos++;
	}
	
	return true;
}

int main() {

	for (;;) {

/*		scanf( "%d", &N ); if ( !N ) break;
		REP( i, N )
			scanf( "%d", &S[i] );
		*/
		
		N = 0;
		for (;;) {
			char ch;
			if ( scanf( "%d%c", &S[N], &ch ) == EOF )
			      exit( 0 );
			N++;
			if ( ch == '\n' )
			      break;
		}
			
		if ( N % 2 == 0 && check( 0, N - 1 ) )
			printf( ":-) Matrioshka!\n" );
		else
			printf( ":-( Try again.\n" );
	}

	return 0;
}
