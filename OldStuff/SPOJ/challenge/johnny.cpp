/*
Alfonso2 Peterssen
SPOJ #127 "Johnny Goes Shopping"
30 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( register int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )
	
const int
	MAXN = 10000,
	PROB = 96,
	LIMIT = 6000000;

typedef long long int64;
typedef pair< int64, int > par;

int N;
int64 sum, best;
par val[MAXN];
vector< par > L, R, sol;

void both() {
	if ( L.empty() || R.empty() ) return ;
	int a = rand() % L.size();
	int b = rand() % R.size();
	bool opt = abs( sum + 2 * L[a].first - 2 * R[b].first ) < abs( sum );
	if ( opt ) {
		if ( rand() % 100 < PROB ) {
			sum = sum + 2 * L[a].first - 2 * R[b].first;
			swap( L[a], R[b] );
		}
	} else
		if ( rand() % 100 > PROB ) {
			sum = sum + 2 * L[a].first - 2 * R[b].first;
			swap( L[a], R[b] );
		}
}

void toL() {
	if ( R.empty() ) return ;
	int b = rand() % R.size();
	bool opt = abs( sum - 2 * R[b].first ) < abs( sum );
	if ( opt ) {
		if ( rand() % 100 < PROB ) {
			sum = sum - 2 * R[b].first;
			swap( R[b], R.back() );
			L.push_back( R.back() );
			R.pop_back();
		}
	} else
		if ( rand() % 100 > PROB ) {
			sum = sum - 2 * R[b].first;
			swap( R[b], R.back() );
			L.push_back( R.back() );
			R.pop_back();
		}
}

void toR() {
	if ( L.empty() ) return ;
	int a = rand() % L.size();
	bool opt = abs( sum + 2 * L[a].first ) < abs( sum );
	if ( opt ) {
		if ( rand() % 100 < PROB ) {
			sum = sum + 2 * L[a].first;
			swap( L[a], L.back() );
			R.push_back( L.back() );
			L.pop_back();
		}
	} else
		if ( rand() % 100 > PROB ) {
			sum = sum + 2 * L[a].first;
			swap( L[a], L.back() );
			R.push_back( L.back() );
			L.pop_back();
		}
}

int main() {

	srand( time( 0 ) );
	scanf( "%d", &N );
	REP( i, N ) {
	      scanf( "%lld", &val[i].first );
	      val[i].second = i;
	}

	sort( val, val + N );
	REPD( i, N ) {
		if ( sum > 0 ) {
			sum -= val[i].first;
			L.push_back( val[i] );
		} else {
	            sum += val[i].first;
			R.push_back( val[i] );
		}
	}

	sol = L;
	best = sum;
	
	REP( i, LIMIT ) {
		if ( sum == 0 ) break;
		int rnd = rand() % 100;
		if ( rnd < 18 ) toL(); else
		if ( rnd < 36 ) toR(); else
			both();
		if ( abs( sum ) < abs( best ) ) {
			best = sum;
			sol = L;
		}
	}

	REP( i, sol.size() )
	      printf( "%d\n", sol[i].second + 1 );

	return 0;
}
