/*
Alfonso2 Peterssen (mukel)
SPOJ #2940 "Untitled Problem II"
25 - 8 - 2009
O( sqrt( N ) * lg( N ) ) for each query, but very fast
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#define DBG( x ) cout << #x << " = " << x << endl << flush;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXN = 1 << 16,
	MAXSQRTN = 1 << 8;

//int TEST;
int N, totalBlocks;
int sqrtN;
int id[MAXN];

int start[MAXSQRTN], end[MAXSQRTN];
bool memo[MAXSQRTN];
int best[MAXSQRTN];
int64 deltaS[MAXSQRTN], deltaB[MAXSQRTN];

int64 B[MAXN];

int cant[MAXSQRTN];
int hull[MAXN];

inline int64 cross( int64 x1, int64 y1, int64 x2, int64 y2 ) {
	return (x1 * y2) - (x2 * y1);
}

void makeHull( int blk ) {
	memo[blk] = false;
	int& top = cant[blk];

	top = start[blk];

	for ( int i = start[blk]; i <= end[blk]; i++ ) {
		B[i] += deltaS[blk] * (int64)(i - start[blk] + 1) + deltaB[blk];

		while ( top - start[blk] > 1 ) {
			int i2 = hull[top - 2], i1 = hull[top - 1];
			if ( cross( i1 - i2, B[i1] - B[i2], i - i2, B[i] - B[i2] ) < 0 ) break ;
		      top--;
		}

		hull[top++] = i;
	}

	deltaS[blk] = 0;
	deltaB[blk] = 0;
}

void add( int blk, int64 dS, int64 dB ) {
	deltaS[blk] += dS;
	deltaB[blk] += dB;
	if ( dS != 0 )
		memo[blk] = false;
}

int64 eval( int idx ) {
	int blk = id[idx];
	return B[idx] + deltaS[blk] * (idx - start[blk] + 1) + deltaB[blk];
}

int64 getMax( int blk ) {

	/*int64 ans = -(int64)1e20;
	for ( int i = start[blk]; i <= end[blk]; i++ )
	      ans = max( ans, eval( i ) );
	return ans;
	*/
//	makeHull(blk );

	if ( memo[blk] )
		return eval( best[blk] );

	int lo = start[blk], hi = cant[blk] - 1;
	int limit = hi;

	int64 kk = -(int64)1e20;
	int top;

	while ( lo < hi ) {
		int mid = ( lo + hi ) / 2;
 		if ( eval( hull[mid + 1] ) > eval( hull[mid] ) )
			lo = mid + 1;
		else
		      hi = mid;
	}

	memo[blk] = true;
	best[blk] = hull[lo];

	assert( best[blk] >= start[blk] );
	assert( best[blk] <= end[blk] );


	//if ( TEST ) cout << "getMax() " << best[blk] << " -> " << eval( best[blk] ) << endl;

	return eval( best[blk] );
}

void init() {
	totalBlocks = 0;
	sqrtN = (int)sqrt( N ) + 1;
	for ( int i = 0; /*i < sqrtN*/; i++ ) {
		start[i] = i * sqrtN;
		end[i] = min( start[i] + sqrtN - 1, N - 1 );

		for ( int j = start[i]; j <= end[i]; j++ )
			id[j] = i;

		//if ( TEST ) cout << "block " << i << " " << start[i] << " -> " << end[i] << endl;
		memo[i] = false;
		deltaS[i] = 0;
		deltaB[i] = 0;

		makeHull( i );

		// ...
		totalBlocks++;
		if ( end[i] >= N - 1 )
		      break ;
	}
}

void update( int lo, int hi, int64 val ) {

	int idlo = id[lo];
	int idhi = id[hi];

	if ( idlo == idhi ) {
		int64 offset = 0;
		for ( int i = lo; i <= hi; i++ ) {
			offset += val;
			B[i] += offset;
		}

		for ( int i = hi + 1; i <= end[idhi]; i++ )
		      B[i] += offset;

		for ( int i = idhi + 1; i < totalBlocks; i++ )
		      add( i, 0, offset );

		makeHull( idlo );

		return ;
	}

	int64 offset = 0;
	for ( int i = lo; i <= end[idlo]; i++ ) {
		offset += val;
		B[i] += offset;
	}
	makeHull( idlo );

	for ( int i = idlo + 1; i < idhi; i++ ) {
		add( i, val, offset );
		offset += (end[i] - start[i] + 1) * val;
	}

	for ( int i = start[idhi]; i <= hi; i++ ) {
		offset += val;
		B[i] += offset;
	}

	for ( int i = hi + 1; i <= end[idhi]; i++ ) {
		B[i] += offset;
	}
	makeHull( idhi );

	for ( int i = idhi + 1; i < totalBlocks; i++ )
		add( i, 0, offset );

}

int64 query( int lo, int hi ) {

	//if ( TEST ) cout << "query " << lo << " " << hi << endl;

	int64 ans = -(int64)1e17;

	int idlo = id[lo];
	int idhi = id[hi];

	//DBG( idlo );
	//DBG( idhi );

	if ( idlo == idhi ) {
		for ( int i = lo; i <= hi; i++ )
		      ans = max( ans, eval(i) );
		return ans;
	}

	for ( int i = lo; i <= end[idlo]; i++ ) {
		ans = max( ans, eval(i) );
	}

	for ( int i = idlo + 1; i < idhi; i++ ) {
		ans = max( ans, getMax( i ) );
	}

	for ( int i = start[idhi]; i <= hi; i++ ) {
		ans = max( ans, eval(i) );
	}

	return ans;
}

#define nextChar() getchar()
/* Fast IO */
inline int nextInt() {
	int res = 0;
	char ch; bool neg = false;
	while ( ( ch = nextChar() ) == '\n' || ch == ' ' );

	if ( ch == '-' ) { neg = true; ch = nextChar(); }
	do {
		res *= 10;
		res += ( ch - '0' );
	} while ( ( ch = nextChar() ) >= '0' );
	if ( neg ) res = -res;
	return res;
}

int main() {

	//TEST = 0;

	//scanf( "%d", &N );
	N = nextInt();
	REP( i, N ) {
		#warning Set I64d or lld
		int tmp = nextInt();
		//scanf( "%I64d", &B[i] );
		B[i] = tmp;
		if ( i > 0 )
			B[i] += B[i - 1];
	}

	init();

		/*if ( TEST ) {
			cout << "B -> ";
			REP( i, N )
				cout << eval( i ) << " ";
			cout << endl;
		}
		*/

	int Q = nextInt();
	while ( Q-- ) {
		int op, lo, hi;
		op = nextInt();
		lo = nextInt();
		hi = nextInt();
		//scanf( "%d %d %d", &op, &lo, &hi );
		lo--; hi--;
		if ( op == 0 ) {
			int val = nextInt();
			//scanf( "%d", &val );
			update( lo, hi, val );
		} else {
			//cout << lo << " " << hi << endl;
			printf( "%I64lld\n", query( lo, hi ) );
		}

/*
		if ( TEST ) {
			cout << "B -> ";
			REP( i, N )
				cout << eval( i ) << " ";
			cout << endl;
		}
 */
	}

	return 0;
}

