/*
Alfonso2 Peterssen (mukel)
SPOJ #3876 "Tablica"
20 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXK = 1 << 10;

int N, K;
int X[MAXK], Y[MAXK];
int toX[MAXK], toY[MAXK];

int main() {

	scanf( "%d %d", &N, &K );
	REP( i, K ) {
		int num;
		scanf( "%d %d %d", &num, &toX[i], &toY[i] );
		num--;
		toX[i]--;
 		toY[i]--;
		X[i] = num / N;
		Y[i] = num % N;
	}
	
	REP( i, K ) {
		int x = X[i], y = Y[i];
		int dx = toX[i] - x; if ( toX[i] < x ) dx += N;
		int dy = toY[i] - y; if ( toY[i] < y ) dy += N;
		printf( "%d\n", dx + dy );
		REP( j, K )
		      if ( X[j] == x ) Y[j] = (Y[j] + dy) % N;
  		REP( j, K )
		      if ( Y[j] == toY[i] ) X[j] = (X[j] + dx) % N;
	}

	return 0;
}
