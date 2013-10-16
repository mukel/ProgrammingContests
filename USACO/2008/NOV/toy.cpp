/*
Alfonso2 Peterssen (mukel)
23 - 12 - 2008
USACO DEC07 "Toys"
*/
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, int > elem;

const int
	MAXN = 100000,
	oo = (int)1e9;

int N, delta1, delta2, cost1, cost2, price;
int sum;
int sol = oo;
int need[MAXN];

int calc( int toys ) {

	int value = toys * price;

	deque< elem > Q;
	Q.push_back( make_pair( -oo, toys ) );
	
	REP( i, N ) {
		if ( i >= delta2 )
			Q.push_back( make_pair( i - delta2, need[i - delta2] ) );

		int now = need[i];
		
		while ( now && !Q.empty() && i >= Q.front().first + delta1 ) {
			elem& e = Q.front();
			int used = min( now, e.second );
			now -= used;
			if ( e.first >= 0 )
				value += used * cost1;
			if ( !( e.second -= used ) )
				Q.pop_front();
		}
		
		while ( now && !Q.empty() ) {
			elem& e = Q.back();
			int used = min( now, e.second );
			now -= used;
			if ( e.first >= 0 )
				value += used * cost2;
			if ( !( e.second -= used ) )
				Q.pop_back();
		}
		
		if ( now )
			return oo;
	}
    	
	return value;
}

int main() {

	scanf( "%d %d %d %d %d %d", &N, &delta1, &delta2, &cost1, &cost2, &price );
	REP( i, N ) {
	      scanf( "%d", &need[i] );
	      sum += need[i];
	}
	
	if ( cost2 < cost1 ) {
		swap( cost1, cost2 );
		swap( delta1, delta2 );
	}
	
	if ( delta1 < delta2 ) delta2 = delta1;

	int lo = need[0], hi = sum;
	
	while ( lo <= hi ) {
		int mid = lo + ( hi - lo ) / 2;
		int val1 = calc( mid );
		int val2 = calc( mid + 1 );
		
		if ( val1 >= val2 )
		      lo = mid + 1;
		else
		      hi = mid - 1;
		      
		sol = min( sol, min( val1, val2 ) );
	}

	printf( "%d\n", sol );

	return 0;
}

