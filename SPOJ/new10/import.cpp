/*
Alfonso2 Peterssen (mukel)
SPOJ #869 "Galactic Import"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	ALPHA = 30,
	oo = (int)1e9;

int V;
int G[ALPHA][ALPHA];
double val[ALPHA];

int main() {

	while (1) {
		if ( scanf( "%d", &V ) != 1 ) break ;
		
		REP( i, ALPHA )
		REP( j, ALPHA )
		      if ( i != j ) G[i][j] = oo;
		REP( i, ALPHA ) val[i] = 0;
		
		REP( i, V ) {
			char src[10], line[100];
			double cost;
			scanf( "%s %lf %s", &src, &cost, &line );
			int u = src[0] - 'A';
			val[u] = cost;
			for ( int j = 0; line[j]; j++ ) {
				int v = (line[j] == '*') ? 26 : line[j] - 'A';
				G[u][v] = 1;
			}
		}
		
		REP( k, ALPHA ) 
 		REP( i, ALPHA )
  		REP( j, ALPHA )
  		      G[i][j] = min( G[i][j], G[i][k] + G[k][j] );
  		      
		double best = -oo;
		char city;
		REP( i, ALPHA ) {
			if ( i == 26 || G[i][26] == oo ) continue ;
			double cost = val[i];
			REP( j, G[i][26] - 1 )
			      cost *= 0.95;
			if ( cost > best ) {
			      best = cost;
			      city = i + 'A';
			}
		}
		
		printf( "Import from %c\n", city );
	}

	return 0;
}
