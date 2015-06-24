/*
Alfonso2 Peterssen
SPOJ #2126 "Panel"
8 - 10 - 2008 Che :-(
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int
	MAXN = 50,
	PROB = 90,
	LIMIT = 200000;

int T, N;
int mat[MAXN][MAXN];
int nowF[MAXN];
int nowC[MAXN];
int bestF[MAXN];
int bestC[MAXN];

int main() {

	srand( time( 0 ) );

	int on = 0;
	int best = (int)1e9;
	
	scanf( "%d", &N );
	REP( i, N )
	REP( j, N ) {
	      scanf( "%d", &mat[i][j] );
	      on += mat[i][j];
	}

	memset( nowF, 0, sizeof( nowF ) );
	memset( nowC, 0, sizeof( nowC ) );

	REP( i, LIMIT ) {
		int x = rand() % N;
		if ( rand() % 2 ) {
			// rows
			int cant = 0;
			REP( j, N ) if ( mat[x][j] ) cant++;
			bool opt = cant > N - cant;
			if ( opt ) {
				if ( rand() % 100 < PROB ) {
					on -= cant;
					on += N - cant;
					REP( j, N ) mat[x][j] ^= 1;
					nowF[x] ^= 1;
				}
			} else
			if ( rand() % 100 > PROB ) {
				on -= cant;
				on += N - cant;
				REP( j, N ) mat[x][j] ^= 1;
				nowF[x] ^= 1;
			}
		} else {
			// columns
			int cant = 0;
			REP( j, N ) if ( mat[j][x] ) cant++;
			bool opt = cant > N - cant;
			if ( opt ) {
				if ( rand() % 100 < PROB ) {
					on -= cant;
					on += N - cant;
					REP( j, N ) mat[j][x] ^= 1;
					nowC[x] ^= 1;
				}
			} else
			if ( rand() % 100 > PROB ) {
				on -= cant;
				on += N - cant;
				REP( j, N ) mat[j][x] ^= 1;
				nowC[x] ^= 1;
			}
		}

		if ( on < best ) {
			best = on;
			REP( i, N ) {
				bestF[i] = nowF[i];
				bestC[i] = nowC[i];
			}
		}
	}
		
	printf( "%d\n", best );
	REP( i, N ) printf( "%d\n", bestF[i] );
	REP( i, N ) printf( "%d\n", bestC[i] );

	return 0;
}
