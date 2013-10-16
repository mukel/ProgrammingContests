/*
Alfonso2 Peterssen
SPOJ #71 "Tree"
4 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int
	MAXV = 31,
	BASE = 10000,
	BASE_LOG = 4,
	MAXLEN = 100;

int T, V;
int root;
int size[MAXV];
int L[MAXV], R[MAXV];

struct bigint {
	int size;
	int64 T[MAXLEN];
	bigint( int64 x = 0, int size = 1 ) : size( size ) {
		memset( T, 0, sizeof( T ) );
		T[0] = x;
	}
};

bigint dp[MAXV];
bigint C[MAXV + 1][MAXV + 1];

bigint& normal( bigint& bn ) {
	int64 r = 0, t;
	REP( i, bn.size ) {
		t = bn.T[i] + r;
		bn.T[i] = t % BASE;
		r = t / BASE;
	}
	for ( ; r > 0; r /= BASE )
		bn.T[bn.size++] = r % BASE;
	while ( bn.size > 1 && bn.T[bn.size - 1] == 0 )
		bn.size--;
	return bn;
}

bigint operator + ( bigint a, bigint b ) {
	a.size = max( a.size, b.size );
	REP( i, a.size )
	      a.T[i] += b.T[i];
	return normal( a );
}

bigint operator * ( bigint a, bigint b ) {
	bigint c( 0, a.size + b.size );
	REP( i, a.size )
	REP( j, b.size )
	      c.T[i + j] += a.T[i] * b.T[j];
	return normal( c );
}

void print( bigint& bn ) {
	printf( "%lld", bn.T[bn.size - 1] );
	REPD( i, bn.size - 1 )
	      printf( /* use BASE_LOG */"%04lld", bn.T[i] );
}

int dfs( int x ) {
	size[x] = 1;
	if ( L[x] ) size[x] += dfs( L[x] );
	if ( R[x] ) size[x] += dfs( R[x] );
	if ( !L[x] && !R[x] )
		dp[x] = bigint( 1 );
	else if ( !L[x] ) dp[x] = dp[ R[x] ];
	else if ( !R[x] ) dp[x] = dp[ L[x] ];
	else {
		int szL = size[ L[x] ];
		int szR = size[ R[x] ];
		dp[x] = C[szL + szR][szL]  * dp[ L[x] ] * dp[ R[x] ];
	}
	return size[x];
}

int get_tree( int lo, int hi ) {
	int x;
	scanf( "%d", &x );
	if ( lo < x )
		L[x] = get_tree( lo, x - 1 );
	if ( x < hi )
		R[x] = get_tree( x + 1, hi );
	return x;
}

int main() {

	/* Preprocess */
	FOR( i, 0, MAXV )
		C[i][0] = bigint( 1 );
	FOR( i, 1, MAXV )
	FOR( j, 1, i )
		C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

	for ( scanf( "%d", &T ); T--; ) {

		stack< int > S;
		memset( L, 0, sizeof( L ) );
		memset( R, 0, sizeof( R ) );
		
		scanf( "%d", &V );
		
		root = get_tree( 1, V );
		
		dfs( root );
		print( dp[root] ); printf( "\n" );
	}

	return 0;
}
