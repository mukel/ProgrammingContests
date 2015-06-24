/*
Alfonso2 Peterssen (mukel)
SPOJ #1705 "The Game of Efil"
19 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int mov[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int F, C, K;

int main() {

	int test = 0;
	while (1) {
		test++;
		scanf( "%d %d", &F, &C );
		if ( !F && !C ) break ;

		int target = 0;
		
		scanf( "%d", &K );
		REP( i, K ) {
			int x, y;
			scanf( "%d %d", &x, &y );
			target |= 1 << (x * C + y);
		}
		
		int ans = 0;
		REP( ancest, (1 << (F * C)) ) {
			int board = 0;
			REP( x, F )
  			REP( y, C ) {
				int neigh = 0;
				REP( i, 8 ) {
					int nx = ( x + mov[i][0] ) % F;
					if ( nx < 0 ) nx += F;
    					int ny = ( y + mov[i][1] ) % C;
					if ( ny < 0 ) ny += C;
    					if ( ancest & (1 << (nx * C + ny)) )
    					      neigh++;
				}
				bool ocup = ( ancest & (1 << (x * C + y)) );
				if ( (neigh == 2 || neigh == 3) && ocup )
					board |= 1 << (x * C + y);
				if ( neigh == 3 && !ocup )
					board |= 1 << (x * C + y);
			}
			if ( board == target )
			      ans++;
		}

		printf( "Case %d: ", test );
		if ( !ans )
		      printf( "Garden of Eden.\n" );
		else
		      printf( "%d possible ancestors.\n", ans );
	}

	return 0;
}
