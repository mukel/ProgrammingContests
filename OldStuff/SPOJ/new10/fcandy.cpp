/*
Alfonso2 Peterssen (mukel)
SPOJ #4182 "Candy (Again)"
22 - 5 - 2009
stupid solution
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXN = 500;

int N, sum;
int C[MAXN];
int K[MAXN];
int cost[2];
int cant[2][MAXN];

int main() {

	srand( time(0) );

	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%d %d", &K[i], &C[i] );
		sum += K[i];
		REP( j, K[i] ) {
			int x = (cost[1] < cost[0]);
			cost[x] += C[i];
			cant[x][i]++;
		}
	}
	
	int val = abs( cost[1] - cost[0] );
	int ans = val;
	
	int LIMIT = max( 200000, sum * 11 );
	REP( i, LIMIT ) {
 		
 		if ( rand() % 5 ) {
			int a = rand() % N;
 			int b = rand() % N;
			if ( !cant[0][a] || !cant[1][b] ) continue ;
			int ncost = abs( (cost[0] - C[a] + C[b]) - ((cost[1] + C[a] - C[b])) );
			int prob = 90;
			if ( ncost > val ) prob = 10;
			if ( rand() % 100 < prob ) {
				cant[0][a]--;
				cant[1][a]++;
				
				cant[0][b]++;
				cant[1][b]--;
				
				cost[0] = cost[0] - C[a] + C[b];
				cost[1] = cost[1] - C[b] + C[a];
			}
		} else {
			int a = rand() % N;
			int x = rand() % 2;
			if ( !cant[x][a] ) continue ;
			int ncost = abs( (cost[x] - C[a]) - ((cost[1 - x] + C[a])) );
			int prob = 90;
			if ( ncost > val ) prob = 10;
			if ( rand() % 100 < prob ) {
				cant[x][a]--;
				cant[1 - x][a]++;
				cost[x] -= C[a];
				cost[1 - x] += C[a];
			}
		}
		
  		val = abs( cost[0] - cost[1] );
		ans = min( ans, val );
	}
	
	printf( "%d\n", ans );

	return 0;
}
