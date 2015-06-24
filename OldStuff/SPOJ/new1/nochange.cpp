/*
Alfonso2 Peterssen
SPOJ #1847 "No Change"
10 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

typedef pair< int, int > par;

const int
	MAXC = 6,
	MAXN = 100001;

int N, C;
int value[MAXC];
int dp[MAXN];

int main() {

	scanf( "%d %d", &N, &C );
	FORD( i, C, 1 )
		scanf( "%d", &value[i] );
	
	memset( dp, -1, sizeof( dp ) );
	dp[0] = 0;
	
	FOR( i, 1, C ) {

		set< par > S;
		FOR( j, 0, N )
		      if ( dp[j] != -1 ) {
				int kk = j + value[i] * dp[j];
				if ( kk <= N )
					S.insert( make_pair( dp[j], kk ) );
			}
			
		memset( dp, -1, sizeof( dp ) );
		while ( !S.empty() ) {
			par top = *S.begin();
			S.erase( S.begin() );
			if ( dp[top.second] == -1 ) {
				dp[top.second] = top.first;
				int kk = top.second + value[i];
				if ( kk <= N )
					S.insert( make_pair( top.first + 1, kk ) );
			}
		}
	}
	
	if ( dp[N] != -1 )
	      printf( "YES\n" );
	else
	      printf( "NO\n" );

	return 0;
}
