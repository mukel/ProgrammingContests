/*
Alfonso2 Peterssen
CPSPc 2004 "Cakes"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
		for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;
typedef pair< int, int > cake;

int N;
int64 cook_time, diff;
cake c;
vector< cake > lo, hi;

bool lo_cmp( const cake &a, const cake &b ) {
	return a.first < b.first;
}

bool hi_cmp( const cake &a, const cake &b ) {
	return a.second > b.second;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%d %d", &c.first, &c.second );
		cook_time += c.first;
		if ( c.first < c.second )
			lo.push_back( c );
		else
			hi.push_back( c );
	}

	sort( ALL( lo ), lo_cmp );
	REP( i, lo.size() )
		diff = max( diff - lo[i].first, 0LL ) + lo[i].second;
	sort( ALL( hi ), hi_cmp );
	REP( i, hi.size() )
		diff = max( diff - hi[i].first, 0LL ) + hi[i].second;

	printf( "%I64d\n", cook_time + diff );

	return 0;
}
