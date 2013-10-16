/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

typedef vector< int64 > array;
typedef vector< array > matrix;

const int
	MAXN = 100,
	MODULO = (int)1e9;

int T, N, P;
int B[MAXN];
int C[MAXN];

matrix M0( int N ) {
	matrix M( N, array( N, 0 ) );
	REP( i, N )
	      M[i][i] = 1;
	return M;
}

matrix operator * ( const matrix& A, const matrix& B ) {
	int N = A.size();
	matrix C( N, array( N, 0 ) );
	REP( i, N )
	REP( j, N )
	REP( k, N )
	      C[i][j] = ( C[i][j] + A[i][k] * B[k][j] ) % MODULO;
	return C;
}

matrix power( const matrix& M, int64 N ) {
	if ( N == 0 ) return M0( M.size() );
	matrix T = power( M, N / 2 );
	T = T * T;
	if ( N % 2 ) T = T * M;
	return T;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {

		scanf( "%d", &N );
		REP( i, N ) scanf( "%d", &B[i] );
		REP( i, N ) scanf( "%d", &C[i] );
		reverse( C, C + N );
		scanf( "%d", &P );
		
		matrix M( N, array( N, 0 ) );
		M[N - 1] = array( C, C + N );
		REP( i, N - 1 )
		      M[i][i + 1] = 1;
		      
		matrix V( N, array( N, 0 ) );
		REP( i, N )
		      V[i][0] = B[i];
		      
		M = power( M, P - 1 );
		M = M * V;
		
		printf( "%I64d\n", M[0][0] );
	}

	return 0;
}
