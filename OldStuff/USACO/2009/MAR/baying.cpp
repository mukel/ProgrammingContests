/*
Alfonso2 Peterssen (mukel)
USACO MAR09 "baying"
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 4000000;

int C, N;
int cant;
int64 V[MAXN];
int A[2], B[2], D[2];
int64 val[2];
int pos[2];

int main() {

	scanf( "%d %d", &C, &N );
	REP( i, 2 )
	      scanf( "%d %d %d", &A[i], &B[i], &D[i] );

	V[cant++] = C;
	while ( cant < N ) {
		REP( i, 2 )
		      val[i] = V[ pos[i] ] * A[i] / D[i] + B[i];
		int id = !(val[0] < val[1]);
		if ( val[id] != V[cant - 1] )
			V[cant++] = val[id];
		pos[id]++;
	}

	printf( "%I64d\n", V[N - 1] );

	return 0;
}
