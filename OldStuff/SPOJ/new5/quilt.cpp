/*
Alfonso2 Peterssen
SPOJ #1003 "Little Quilt"
25 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef vector< char > array;
typedef vector< array > matrix;

const int MAXLEN = 100000;

int N, pos;
char expr[MAXLEN];
matrix A, B;

matrix sew( matrix& A, matrix& B ) {
	if ( A.size() != B.size() )
		return matrix();
	matrix C = A;
	REP( i, B.size() )
		C[i].insert( C[i].end(), B[i].begin(), B[i].end() );
	return C;
}

matrix turn( matrix& A ) {
	if ( A.empty() ) return matrix();
	matrix C( A[0].size(), array( A.size() ) );
	REP( i, A.size() )
	REP( j, A[i].size() ) {
	      char& ch = C[j][A.size() - i - 1];
	      ch = A[i][j];
	      if ( ch == '/' ) ch = '\\'; else
	      if ( ch == '\\' ) ch = '/'; else
	      if ( ch == '|' ) ch = '-'; else
	      if ( ch == '-' ) ch = '|';
	}
	return C;
}

void print( matrix& A ) {
	REP( i, A.size() ) {
		REP( j, A[i].size() )
		      printf( "%c", A[i][j] );
		printf( "\n" );
	}
}

matrix eval() {
	if ( expr[pos] == 'A' ) { pos++; return A; }
	if ( expr[pos] == 'B' ) { pos++; return B; }
	if ( expr[pos] == 's' ) {
		pos += 4; // skip sew(
		matrix X = eval();
		pos++; // skip ,
		matrix Y = eval();
		pos++; // skip )
		return sew( X, Y );
	}
	if ( expr[pos] == 't' ) {
		pos += 5; // skip turn(
		matrix X = eval();
		pos++; // skip )
		return turn( X );
	}
}

int main() {

	A = matrix( 2, array( 2, '/' ) ); A[1][1] = '+';
	B = matrix( 2, array( 2, '-' ) );
	
	REP( tc, tc + 1 ) { // loop till overflow
	
		int len = 0; char ch;
		while ( scanf( "%c", &ch ) != EOF && ch != ';' )
			if ( ch != ' ' && ch != '\n' )
			      expr[len++] = ch;

		if ( !len ) break;
		
		pos = 0;
		matrix sol = eval();
		
		printf( "Quilt %d:\n", tc + 1 );
		if ( sol.empty() )
		      printf( "error\n" );
		else
		      print( sol );
	}

	return 0;
}
