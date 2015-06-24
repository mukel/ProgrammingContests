/*
Alfonso2 Peterssen (mukel)
SPOJ #395 "Anti-prime Sequences"
5 - 3 - 2009
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) for ( int i = (b); i <= (e); i++ )

const int
	MAXN = 1001,
	MAXP = 10000;
	
int A, B, D;
int ans[MAXN];
bool used[MAXN];
bool mark[MAXP];

bool comb( int pos ) {

	if ( pos == B - A + 1 )
	      return true;
	      
	FOR( val, A, B ) {
		if ( used[val] )
		      continue;

		int sum = val;
		for ( int i = 1; i < D; i++ ) {
			if ( i > pos )
				break;
			sum += ans[pos - i];
			if ( !mark[sum] )
			      goto next_val;
		}
		
		used[val] = 1;
		ans[pos] = val;
		
		if ( comb( pos + 1 ) )
		      return true;
		      
		used[val] = 0;
		
		next_val:;
	}
	
	return false;
}

int main() {

	for ( int i = 2; i * i < MAXP; i++ )
	      if ( !mark[i] )
	            for ( int j = i * i; j < MAXP; j += i )
	                  mark[j] = true;

	for (;;) {
		scanf( "%d %d %d", &A, &B, &D );
		if ( !A && !B && !D )
			break;
			
		memset( used, 0, sizeof( used ) );
		
		if ( comb( 0 ) ) {
		      REP( i, B - A + 1 ) {
				printf( "%d", ans[i] );
				if ( i == B - A + 1 - 1 )
					printf( "\n" );
				else
					printf( "," );
			}
		} else
		      printf( "No anti-prime sequence exists.\n" );
	}

	return 0;
}
