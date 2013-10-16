/*
Alfonso2 Peterssen (mukel)
24 - 1 - 2009
SPOJ #3505 "Prime Number Theorem"
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )
	
const int
	MAXP = (int)1e8 + 1,
	MAXQ = 1000;

int Q;
int last, next;
int cant;
pair< int, int > queries[MAXQ];
bitset< MAXP > mark;
double ans[MAXQ];

int main() {

	// prime sieve
	for ( int i = 6, j; i * i < MAXP; i += 6 ) {
		j = i - 1;
		if ( !mark[j] ) {
			int j2 = 2 * j;
			for ( int k = j * j; k < MAXP; k += j2 )
			      mark[k] = true;
		}
		j = i + 1;
		if ( !mark[j] ) {
			int j2 = 2 * j;
			for ( int k = j * j; k < MAXP; k += j2 )
			      mark[k] = true;
		}
	}

	for ( int x; scanf( "%d", &x ) && x; Q++ )
		queries[Q] = make_pair( x, Q );

	sort( queries, queries + Q );
	
	last = 1;
	REP( i, Q ) {
		next = queries[i].first;
		if ( next < 4 )
			cant = next - 1;
		else {
			FOR( i, last + 1, next )
			      if ( (i & 1) && (i % 3) && !mark[i] )
			            cant++;
		}
		last = next;
		ans[ queries[i].second ] = fabs(cant - next / log(next)) / cant;
	}
	
	REP( i, Q )
	      printf( "%.1lf\n", ans[i] * 100. );
	
	return 0;
}
