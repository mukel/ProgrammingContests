/*
Alfonso2 Peterssen
SPOJ #3033 "Help the soldier"
8 - 10 - 2008 Che :-(
this = shit
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

int N, T;
int dp[10][2000];
vector< pair< int, int > > G[10];

int main() {

	scanf( "%d %d", &N, &T );
	REP( i, N ) {
		int kind, w, q;
		scanf( "%d %d %d", &kind, &w, &q );
		G[kind].push_back( make_pair( w, q ) );
	}
	
	memset( dp, -1, sizeof( dp ) );
	dp[0][0] = (int)1e9;
	
	FOR( i, 1, 6 ) {
		REP( j, G[i].size() ) {
			int w = G[i][j].first;
			int q = G[i][j].second;
			FOR( k, w, T )
			      if ( dp[i - 1][k - w] != -1 )
				dp[i][k] = max( dp[i][k], min( dp[i - 1][k - w], q ) );
		}
	}
	
	int sol = *max_element( dp[6], dp[6] + T + 1 );
	if ( sol == -1 ) sol = 0;
	printf( "%d\n", sol );

	return 0;
}
