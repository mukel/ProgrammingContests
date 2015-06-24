/*
Alfonso2 Peterssen (mukel)
16 - 1 - 2009
SPOJ #2371 "Another Longest Increasing Subsequence Problem"
Domination Sets Algorithm
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
typedef pair< int, int > point;
typedef set< point > domset;
	
const int MAXN = 100000;

int N;
vector< domset > V;

bool dominates( const point& A, const point& B ) {
	return (A.first > B.first) && (A.second > B.second);
}

bool dominates( domset& S, const point& P ) {
	typeof( S.begin() ) it = S.lower_bound( P );
	if ( it != S.begin() ) { it--; if ( dominates( P, (*it) ) ) return true; }
	if ( it != S.begin() ) { it--; if ( dominates( P, (*it) ) ) return true; }
	return false;
}

void insert( domset& S, const point& P ) {
	typeof( S.begin() ) it = S.lower_bound( P );
	
	if ( it != S.begin() ) {
		typeof( it ) lo = it; lo--;
		if ( (*lo).second <= P.second )
		      return ;
	}
	
	while ( it != S.end() && (*it).second >= P.second )
	      S.erase( it++ );
	
	S.insert( P );
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		point P;
		scanf( "%d %d", &P.first, &P.second );
		
		int lo = 0, hi = V.size() - 1;
		while ( lo <= hi ) {
			int mid = ( lo + hi ) / 2;
			if ( dominates( V[mid], P ) )
			      lo = mid + 1;
			else
			      hi = mid - 1;
		}
		
		if ( lo == V.size() )
		      V.push_back( domset() );
		      
		insert( V[lo], P );
	}
	
	printf( "%d\n", V.size() );

	return 0;
}
