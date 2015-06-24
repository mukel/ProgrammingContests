/*
Alfonso2 Peterssen (mukel)
SPOJ #3407 "Candy"
17 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )

const int MAXC = 1 << 17;

int F, C;
int dc[MAXC], df[MAXC];

int main() {

	while (1) {
		scanf( "%d %d", &F, &C );
		if ( !F && !C ) break ;
		
		FOR( i, 1, F ) {
			FOR( j, 1, C ) {
				int val;
				scanf( "%d", &val );
				
				dc[j] = dc[j - 1];
				if ( j > 1 )
					dc[j] = max( dc[j], dc[j - 2] + val );
				else
					dc[j] = max( dc[j], val );
			}
			
			df[i] = df[i - 1];
			if ( i > 1 )
				df[i] = max( df[i], df[i - 2] + dc[C] );
			else
				df[i] = max( df[i], dc[C] );
		}
		
		printf( "%d\n", df[F] );
	}

	return 0;
}
