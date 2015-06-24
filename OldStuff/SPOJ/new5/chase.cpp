/*
Alfonso Alfonso Peterssen
TASK: POINTS
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 10000;

int T, N, sol;
int x[MAXN], y[MAXN];
int P[MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		REP( i, N )
			scanf( "%d %d", &x[i], &y[i] );

		sol = 0;
		REP( i, N ) {
			int cantx = 0, cant = 0;
			for ( int j = i + 1; j < N; j++ ) {
			      int dx = x[i] - x[j];
			      if ( !dx )
					cantx++;
			      else
					P[cant++] =( ( y[i] - y[j] ) << 17 ) / dx;
			}
			if ( cantx - 1 > sol ) sol = cantx - 1;
			if ( sol > cant + cantx - 1 )
				break;
			sort( P, P + cant );
			for ( int j = 0, k; j < cant; j = k ) {
				for ( k = j + 1; k < cant && P[k] == P[j]; k++ );
				sol >?= k - j;
			}
		}

		printf( "%d\n", sol );
	}

	return 0;
}

