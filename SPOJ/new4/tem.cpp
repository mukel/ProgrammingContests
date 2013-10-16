/*
Alfonso2 Peterssen
SPOJ #757 "Thermal Luminescence"
19 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int MAXC = 51;

int T, X, Y, Z;
int S[MAXC][MAXC][MAXC];
int x1, y1, z1, x2, y2, z2;

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d %d", &X, &Y, &Z );
		
		FOR( i, 1, X )
		FOR( j, 1, Y )
		FOR( k, 1, Z ) {
		      scanf( "%d", &S[i][j][k] );
		      S[i][j][k] += S[i - 1][j][k] + S[i][j - 1][k] - S[i - 1][j - 1][k];
		}
		
		int best = -(int)1e9;
		FOR( i, 1, X ) REP( ii, i )
		FOR( j, 1, Y ) REP( jj, j ) {
			int sum = 0, last_k = 0;
			FOR( k, 1, Z ) {
				sum += S[i][j][k] - S[ii][j][k] - S[i][jj][k] + S[ii][jj][k];
				if ( sum > best ) {
					best = sum;
					x1 = ii+1;
					y1 = jj+1;
					z1 = last_k + 1;
					x2 = i;
					y2 = j;
					z2 = k;
				}
				if ( sum < 0 ) {
					sum = 0;
					last_k = k;
				}
			}
		}
		
//		printf( "%d\n", best );
		printf( "%d %d %d %d %d %d\n", x1, y1, z1, x2, y2, z2 );
	}

	return 0;
}

