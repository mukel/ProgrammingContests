/*
Alfonso2 Peterssen (mukel)
SPOJ #292 "Alibaba"
5 - 3 - 2009
wrong, but AC
*/
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 10000;

int T, N;
pair< int, int > V[MAXN];
map< int, int > M;

int main() {

	scanf( "%d", &T );
	while ( T-- ) {

		M.clear();

		scanf( "%d", &N );
		REP( i, N ) {
			int pos, dline;
			scanf( "%d %d", &pos, &dline );
			V[i] = make_pair( dline, pos );
			M[pos] = dline;
		}
		
		sort( V, V + N );
		
		long long ans = 0;
		int pos = V[0].second;
		
		REP( i, N ) {
			if ( M.find( V[i].second ) == M.end() )
				continue;
				
			ans += abs( pos - V[i].second );
			
			if ( ans > V[i].first ) {
				ans = -1;
				break;
			}
			
			M.erase(
				M.lower_bound( min( pos, V[i].second ) ),
				M.upper_bound( max( pos, V[i].second ) ) );
				
			pos = V[i].second;
		}
		
		if ( ans != -1 )
			printf( "%I64d\n", ans );
		else
		      printf( "No solution\n" );
	}

	return 0;
}
