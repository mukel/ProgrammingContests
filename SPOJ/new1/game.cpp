/*
Alfonso2 Peterssen
SPOJ #385 "Game schedule required"
10 - 9 - 2008
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 1000;

int N;
int players;
string teams[MAXN];
int games[MAXN];
bool used[MAXN];
vector< int > G[MAXN];

void make_game( int u, int v ) {
	cout << teams[v] << " defeats " << teams[u] << endl;
	games[u]--;
	games[v]--;
	used[u] = true;
	used[v] = true;
	if ( players == 2 )
		cout << "Winner: " << teams[v] << endl;
}

int main() {

	for (;;) {
		cin >> N; if ( !N ) break;
		
		REP( i, N )
			cin >> teams[i];
			
		REP( i, N ) {
			games[i] = 0;
			G[i].clear();
		}
			
		sort( teams, teams + N );
			
		REP( i, N - 1 ) {
			string A, B;
			cin >> A >> B;
			int u = lower_bound( teams, teams + N, A ) - teams;
			int v = lower_bound( teams, teams + N, B ) - teams;
			games[u]++;
			games[v]++;
			G[u].push_back( v );
			G[v].push_back( u );
		}
		
		players = N;
		for ( int round = 1; ; round++ ) {
			if ( players == 1 ) break;
			cout << "Round #" << round << endl;
			
			REP( i, N ) used[i] = false;
				
			REP( i, N )
			if ( !used[i] && games[i] == 1 ) {
				int u = i;
				REP( j, G[u].size() ) {
					int v = G[u][j];
					if ( !used[v] && games[v] > 1 ) {
						make_game( u, v );
						break;
					}
				}
				
				if ( !used[u] )
				REP( j, G[u].size() ) {
					int v = G[u][j];
					if ( !used[v] && games[v] == 1 ) {
						make_game( u, v );
						break;
					}
				}
			}
			
			// Wildcard
			if ( players % 2 )
				REP( i, N )
				      if ( !used[i] && games[i] ) {
						cout << teams[i] << " advances with wildcard" << endl;
						break;
					}
			
			players = ( players + 1 ) / 2;
		}
		
		cout << endl;
	}

	return 0;
}
