/*
Alfonso2 Peterssen
27 - 3 - 2008
TASK: SHOP
*/
#include <cstdio>

const int
	MAXN = 6,
	MAXO = 100,
	MAXCODE = 1000;

#define REP( i, n ) \
	for ( i = 0; i < (n); i++ )

int N, O, i, j;
int pairs;
int a, b, c, d, e;
int cant[MAXN];
int price[MAXN];
int code[MAXCODE];
int dp[6][6][6][6][6];
int offer[MAXO][MAXN];
int offer_price[MAXO];

int main() {

	freopen( "INPUT.TXT", "r", stdin );

	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%d %d %d", &c, &cant[i], &price[i] );
		code[c] = i;
	}

	freopen( "OFFER.TXT", "r", stdin );

	scanf( "%d", &O );
	REP( i, O ) {
		scanf( "%d", &pairs );
		REP( j, pairs ) {
			scanf( "%d %d", &a, &b );
			offer[i][ code[a] ] = b;
		}
		scanf( "%d", &offer_price[i] );
	}

	REP( a, cant[0] + 1 )
	REP( b, cant[1] + 1 )
	REP( c, cant[2] + 1 )
	REP( d, cant[3] + 1 )
	REP( e, cant[4] + 1 ) {
		int &value = dp[a][b][c][d][e];
		value = ( 1 << 29 );
		if ( !a && !b && !c && !d && !e )
			value = 0;
		if ( a ) value <?= dp[a - 1][b][c][d][e] + price[0];
		if ( b ) value <?= dp[a][b - 1][c][d][e] + price[1];
		if ( c ) value <?= dp[a][b][c - 1][d][e] + price[2];
		if ( d ) value <?= dp[a][b][c][d - 1][e] + price[3];
		if ( e ) value <?= dp[a][b][c][d][e - 1] + price[4];
		REP( i, O )
			if ( offer[i][0] <= a &&
				 offer[i][1] <= b &&
				 offer[i][2] <= c &&
				 offer[i][3] <= d &&
				 offer[i][4] <= e )
				 value <?= dp[ a - offer[i][0] ]
							 [ b - offer[i][1] ]
							 [ c - offer[i][2] ]
							 [ d - offer[i][3] ]
							 [ e - offer[i][4] ] +
							 offer_price[i];
	}

	freopen( "OUTPUT.TXT", "w", stdout );
	printf( "%d\n", dp[ cant[0] ][ cant[1] ][ cant[2] ][ cant[3] ][ cant[4] ] );
	fflush( stdout );

	return 0;
}
