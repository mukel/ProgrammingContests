/*
Alfonso2 Peterssen
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

const int MAXN = 100;

int T, N , K;
int X[MAXN] , Y[MAXN];
int dist[MAXN];
bool mark[MAXN];
int sol[MAXN] , val[MAXN] , best;
int D[MAXN][MAXN];

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {
		best = INT_MAX;
		scanf( "%d %d", &N, &K );

		REP( i , N ) scanf( "%d%d" , &X[i] , &Y[i] );
		
		REP( i , N )
		      REP( j , N )
		            D[i][j] = (X[i]-X[j])*(X[i]-X[j]) +
		                        (Y[i]-Y[j])*(Y[i]-Y[j]);

		REP( i , N ){

			memset( mark , 0 , sizeof( mark ) );
			memset( dist , 63 , sizeof( dist ) );

			dist[i] = 0;
			
			REP( j , K ){
				int k = -1;
				REP( l , N )
				      if ( (!mark[l]) && ((l == -1) || (dist[l] > dist[k])) )
				            k = l;

				mark[k] = true;
				val[j] = k;
				
				REP( l , N ) if ( !mark[l] )
				      dist[l] <?= D[k][l];

			}
			
			int maxdist = *max_element( dist , dist + N );
			
			if ( maxdist < best ){
				best = maxdist;
				memcpy( sol , val , sizeof( val ) );
			}

		}

		printf( "case %d Y\n", tc + 1 );
		
		REP( i , K ) printf( (i < K - 1) ? "%d " : "%d\n" , sol[i] + 1 );
		
	}

	return 0;
}
