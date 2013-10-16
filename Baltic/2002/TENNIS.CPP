/*
Alfonso Alfonso Peterssen
17 - 3 - 2008
Baltic 2002 Task "Tennis"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000;

typedef pair< int, int > par;

int n, i, j, k;
int games_left;
int games[MAXN];
int to_push[MAXN];
priority_queue< par > Q;
vector< int > sol[MAXN];

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", &games[i] );
        if ( games[i])
            Q.push( make_pair( games[i], i ) );
    }

    while ( !Q.empty() ) {

        games_left = Q.top().first;
        i = Q.top().second;
        Q.pop();

        if ( Q.size() < games_left ) {
            printf( "NO SCHEDULE\n" );
            fflush( stdout );
            return 0;
        }

        for ( k = 0; k < games_left; k++ ) {
            j = Q.top().second; Q.pop();
            games[j]--;
            to_push[k] = j;
            sol[i].push_back( j );
            sol[j].push_back( i );
        }

        for ( k = 0; k < games_left; k++ ) {
            i = to_push[k];
            if ( games[i] > 0 )
                Q.push( make_pair( games[i], i ) );
        }
    }

    printf( "SCHEDULE\n" );
    for ( i = 0; i < n; i++ )
        for ( j = 0; j < sol[i].size(); j++ ) {
            printf( "%d", sol[i][j] + 1 );
            printf( j + 1 == sol[i].size() ? "\n" : " " );
        }

    fflush( stdout );

    return 0;
}
