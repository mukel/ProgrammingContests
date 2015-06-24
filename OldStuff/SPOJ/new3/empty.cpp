/*
Alfonso2 Peterssen
SPOJ #199 "Empty Cuboids"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;

const int
	MAXN = 5001,
	MAXC = 1000000;

int T, N;
int idx[MAXN];
int idy[MAXN];
int solx, soly, solz;
bool used[MAXN];
struct point {
	int x, y, z;
} P[MAXN];

bool x_cmp( const int& i, const int& j ) {
	if ( P[i].x != P[j].x )
		return P[i].x < P[j].x;
      return P[i].z < P[j].z;
}

bool y_cmp( const int& i, const int& j ) {
	if ( P[i].y != P[j].y )
		return P[i].y < P[j].y;
      return P[i].z < P[j].z;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		REP( i, N ) {
			int x, y, z;
			scanf( "%d %d %d", &x, &y, &z );
			P[i] = (point){ x, y, z };
			idx[i] = i;
			idy[i] = i;
		}
		
		idx[N] = N;
		idy[N] = N;
		P[N] = (point){ MAXC, MAXC, MAXC };
		N++;
		
		sort( idx, idx + N, x_cmp );
		sort( idy, idy + N, y_cmp );
		
		memset( used, 0, sizeof( used ) );
		
		int64 best = -1;
		REP( i, N ) {
			used[ idx[i] ] = true;
			int lowerz = MAXC;
			REP( j, N )
			if ( used[ idy[j] ] ) {
				int64 vol = (int64)P[ idx[i] ].x * P[ idy[j] ].y * lowerz;
				if ( vol > best ) {
					solx = P[ idx[i] ].x;
					soly = P[ idy[j] ].y;
					solz = lowerz;
					best = vol;
				}
				if ( P[ idy[j] ].x < P[ idx[i] ].x )
					lowerz = min( lowerz, P[ idy[j] ].z );
			}
		}
		
		printf( "%d %d %d\n", solx, soly, solz );
	}

	return 0;
}

