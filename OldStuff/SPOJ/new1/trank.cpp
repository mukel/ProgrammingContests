/*
Alfonso2 Peterssen
SPOJ #399 "Team Rankings"
4 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 200;

int N;
char sol[6];
char rank[MAXN][6];
int pos[MAXN][6];

int dist( int i, int j ) {
	int sum = 0;
	REP( a, 5 )
	REP( b, 5 )
		if ( pos[i][a] < pos[i][b] && pos[j][a] > pos[j][b] )
		      sum++;
	return sum;
}

int main() {

	while ( scanf( "%d", &N ) && N ) {

		REP( i, N ) {
		      scanf( "%s", &rank[i] );
		      REP( j, 5 )
		            pos[i][ rank[i][j] - 'A' ] = j;
		}

		REP( i, 5 )
			rank[N][i] = i + 'A';
			
		int best = (int)1e9;
		do {
		      REP( i, 5 )
		            pos[N][ rank[N][i] - 'A' ] = i;
			int value = 0;
		      REP( i, N )
				value += dist( i, N );
			if ( value < best ) {
			      best = value;
			      strcpy( sol, rank[N] );
			}
		} while ( next_permutation( rank[N], rank[N] + 5 ) );

		printf( "%s is the median ranking with value %d.\n", sol, best );
	}

	return 0;
}
