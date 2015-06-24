/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long int64;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) for ( int i = (e); i >= (s); i-- )

#define FOREACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++ )

#define ALL( c ) (c).begin(), (c).end()

int N;
list< int > L;
vector< int > V[3];

int cant;
int ans[10000];

void noSolution() {
	printf( "impossible\n" );
	exit( 0 );
}

bool check() {
	int val = 0;
	FOREACH( it, L )
		ans[cant++] = *it;
	FOR( i, 1, cant - 1) {
		if ( (ans[i] + ans[i - 1]) % 3 == 0 )
		      return false;
	}
		
	return true;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int val;
		scanf( "%d", &val );
		V[val % 3].push_back( val );
	}

	L.insert( L.end(), ALL( V[1] ) );
	if ( V[0].size() > 0 ) {
		L.insert( L.end(), V[0].back() );
		V[0].pop_back();
	}
	L.insert( L.end(), ALL( V[2] ) );

	int val = 1;
	FOREACH( it, L ) {
		if ( V[0].empty() ) break;
		
		if ( (*it) % 3 && val % 3 ) {
		      L.insert( it, V[0].back() );
			V[0].pop_back();
		}
		val = *it;
	}
	
	if ( V[0].size() > 0 ) {
	      L.insert( L.end(), V[0].back() );
	      V[0].pop_back();
	}
	
	
	if ( V[0].size() > 0 ||	!check() )
	      noSolution();
	
	REP( i, cant )
	      printf( "%d ", ans[i] );
	      
	printf( "\n" );

	return 0;
}
