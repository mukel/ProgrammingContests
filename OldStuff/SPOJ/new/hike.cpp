/*
Alfonso2 Peterssen
SPOJ #402 "Hike on a Graph"
5 - 9 - 2008
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 50,
	oo = (int)1e9;

int N;
int a, b, c;
char color[MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];
struct triple {
	int a, b, c;
};

int main() {

	for (;;) {

		memset( dist, -1, sizeof( dist ) );

		
		cin >> N; if ( !N ) break;
		
		cin >> a >> b >> c;
		a--; b--; c--;
		
		REP( i, N )
		REP( j, N )
		      cin >> color[i][j];
		
		dist[a][b][c] = 0;
		
		queue< triple > Q;
		Q.push( (triple){ a, b, c } );
		
		for ( ; !Q.empty(); Q.pop() ) {
			a = Q.front().a;
			b = Q.front().b;
			c = Q.front().c;
			if ( a == b && b == c ) {
				cout << dist[a][b][c] << endl;
				break;
			}
			/* move a */
			REP( i, N )
				if ( color[a][i] == color[b][c] && dist[i][b][c] == -1 ) {
					dist[i][b][c] = dist[a][b][c] + 1;
					Q.push( (triple){ i, b, c } );
				}
			/* move b */
			REP( i, N )
				if ( color[b][i] == color[a][c] && dist[a][i][c] == -1 ) {
					dist[a][i][c] = dist[a][b][c] + 1;
					Q.push( (triple){ a, i, c } );
				}
			/* move c */
			REP( i, N )
				if ( color[c][i] == color[a][b] && dist[a][b][i] == -1 ) {
					dist[a][b][i] = dist[a][b][c] + 1;
					Q.push( (triple){ a, b, i } );
				}
		}
		
		if ( a != b || b != c )
			cout << "impossible" << endl;
	}
	
	return 0;
}
