/*
Alfonso2 Peterssen
SPOJ #2826 "Round-Robin Scheduling"
29 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;
typedef pair< int, int > task;

const int
	MAXN = 60000;

int N;
int S[MAXN];
task T[MAXN];
int64 sol[MAXN];

int lobit( int x ) { return x & -x; }

void add( int x, int amount ) {
	for ( x++; x < MAXN; x += lobit( x ) )
	      S[x] += amount;
}

int query( int x ) {
	int sum = 0;
	for ( x++; x > 0; x -= lobit( x ) )
	      sum += S[x];
	return sum;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%d", &T[i].first );
		T[i].second = i;
	}
	
	sort( T, T + N );
	REP( i, N )
		add( i, 1 );
	
	int64 now = 0, rounds = 1;
	
	int pos = 0;
	REP( i, N ) {
		int diff = abs( query( T[i].second ) - query( pos ) );
		if ( pos > T[i].second ) {
			now += (N - i) - diff;
			rounds++;
		} else
			now += diff;
		pos = T[i].second;
		now += (N - i) * (T[i].first - rounds);
		rounds = T[i].first;
		sol[ T[i].second ] = now + 1;
		add( T[i].second, -1 );
	}
	
	REP( i, N )
	      printf( "%lld\n", sol[i] );

	return 0;
}
