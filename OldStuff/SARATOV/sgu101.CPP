/*
Alfonso Alfonso Peterssen
10 - 2 - 2008
Saratov #101 "Domino"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int
    MAXV = 7,
    MAXE = 100;

int E, i, u, v, odds, src;
bool used[MAXE];
int degree[MAXV];
vector< pair< int, int > > G[MAXV];
vector< pair< int, char > > path;

    void eulerize( int node ) {
        for ( int i = 0; i < G[node].size(); i++ ) {
            int id = abs( G[node][i].second ) - 1;
            if ( !used[id] ) {
                used[id] = true;
                eulerize( G[node][i].first );
                char sign = G[node][i].second > 0 ? '+' : '-';
                path.push_back( make_pair( id, sign ) );
            }
        }
    }

int main() {

    scanf( "%d", &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u ,&v );
        G[u].push_back( make_pair( v, i + 1 ) );
        G[v].push_back( make_pair( u, -( i + 1 ) ) );
        degree[u]++;
        degree[v]++;
    }

    for ( i = 0; i < MAXV; i++ ) {
        odds += ( degree[i] & 1 );
        if ( ( degree[i] & 1 ) || degree[src] == 0 )
            src = i;
    }

    if ( !odds || odds == 2 ) {

        eulerize( src );
        if ( path.size() == E ) {
            reverse( path.begin(), path.end() );
            for ( i = 0; i < E; i++ )
                printf( "%d %c\n", path[i].first + 1, path[i].second );
            return 0;
        }
    }

    printf( "No solution\n" );

    return 0;
}
