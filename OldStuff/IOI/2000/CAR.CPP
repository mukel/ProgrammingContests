/*
Alfonso2 Peterssen
8 - 6 - 2008
IOI 2000 "Car Parking"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cassert>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;

const int MAXN = 20000;

int N, C, W;
int car[MAXN];
int freq[MAXN];
int next[MAXN];
bool mark[MAXN];
vector< vector< par > > rounds;
list< int > L;

int main() {

    scanf( "%d %d %d", &N, &C, &W );
    REP( i, N ) {
        scanf( "%d", &car[i] );
        car[i]--;
        freq[ car[i] ]++;
        L.push_back( i );
    }

    partial_sum( freq, freq + C, freq );
    REP( i, N )
        next[i] = --freq[ car[i] ] ;

    for (;;) {
        vector< par > swaps;
        for ( list< int >::iterator it = L.begin(); it != L.end(); it++ ) {
            if ( mark[(*it)] || (*it) == next[(*it)] ) {
                list< int >::iterator tmp = it;
                it++;
                L.erase( tmp );
                continue;
            }
            int j = (*it);
            while ( swaps.size() < W - 1 && !mark[ next[j] ] ) {
                swaps.push_back( par( j + 1, next[j] + 1 ) );
                mark[ next[j] ] = true;
                j = next[j];
            }
            if ( swaps.size() == W - 1 && j != (*it) ) {
                swaps.push_back( par( j + 1, (*it) + 1 ) );
                swap( next[(*it)], next[j] );
            }
            if ( swaps.size() >= W - 1 )
                break;
        }
        if ( swaps.size() == 0 )
            break;
        rounds.push_back( swaps );
    }
    
    assert( rounds.size() <= ( N + ( W - 1 ) - 1) / ( W - 1 ) );

    printf( "%d\n", rounds.size() );
    REP( i, rounds.size() ) {
        printf( "%d", rounds[i].size() );
        REP( j, rounds[i].size() )
            printf( " %d %d", rounds[i][j].first, rounds[i][j].second );
        printf( "\n" );
    }

    return 0;
}
