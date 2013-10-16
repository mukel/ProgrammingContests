/*
Alfonso2 Peterssen
SPOJ #972 "Birthday"
30 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 50000;

int N;
int sum, sol;
int pos[MAXN];
deque< int > L, R;

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
	      scanf( "%d", &pos[i] );
	      pos[i]--;
	}

/*	int best = (int)1e9;
	REP( i, N ) {
		int kk = 0;
		REP( j, N ) {
			int left = abs( pos[j] - (j+i)%N );
			kk += min( left, N - left );
		}
		best = min( best, kk );
	}
	printf( "solution = %d\n", best );*/
	      
	REP( i, N ) {
		int left = abs( pos[i] - i );
		if ( pos[i] < i ) left = N - left;
		if ( left <= N - left ) {
		      sum += left;
		      L.push_back( left );
		}
		else {
		      sum += N - left;
			R.push_back( N - left );
		}
	}
	
	sort( ALL( L ) );
	sort( ALL( R ) );
	
	sol = sum;
	REP( i, N ) {
		while ( !R.empty() && R.back() + i > N / 2 ) {
			R.pop_back();
			L.push_back( ( N - 1 ) / 2 + i );
			sum -= (1 + !(N&1));
		}
		while ( !L.empty() && L.front() - i < 0 ) {
			L.pop_front();
			R.push_front( 1 - i );
			sum += 2;
		}
		sol = min( sol, sum );
		sum += R.size();
		sum -= L.size();
	}
	
	printf( "%d\n", sol );

	return 0;
}
