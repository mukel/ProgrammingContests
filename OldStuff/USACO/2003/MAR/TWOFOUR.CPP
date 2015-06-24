/*
Alfonso2 Peterssen
4 - 6 - 2008
USACP MAR03 "TwoFour"
*/
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

struct state {
    int freq[5], owns;
    bool operator < ( const state &s ) const {
        if ( owns != s.owns ) return owns < s.owns;
        return lexicographical_compare( freq, freq + 5, s.freq, s.freq + 5 );
    }
};

int N, Q, pile;
map< state, int > answer;

int parse( int x ) {
    if ( x == 1 ) return 1; // Tie
    if ( x == 3 ) return 2; // I win
    return 3; // Shit, i'm a looser
}

void update( int &target, int value ) {
    if ( target == 0 || target == 3 ||
       ( target == 1 && value == 2 ) )
        target = value;
}

int solve( state s ) {

    if ( s.freq[2] == N ) {
        if ( 2 * s.owns < N ) return 3;
        if ( 2 * s.owns > N ) return 2;
        return 1;
    }

    if ( answer[s] != 0 )
        return answer[s];
        
    REP( i, 3 )
        for ( int j = i + 2; j < 5; j++ ) {
            state t = s;
            t.owns = t.freq[2] - t.owns;
            t.freq[i]--; t.freq[i + 1]++;
            t.freq[j]--; t.freq[j - 1]++;
            if ( i == 2 || j == 2 )
                t.owns--;
            if ( t.freq[i] < 0 || t.freq[j] < 0 || t.owns < 0 )
                continue;
            update( answer[s], parse( solve( t ) ) );
        }

    return answer[s];
}

int main() {

    scanf( "%d %d", &N, &Q );
    while ( Q-- ) {
        state start;
        memset( start.freq, 0, sizeof( start.freq ) );
        
        REP( i, N ) {
            scanf( "%d", &pile );
            start.freq[pile]++;
        }
        
        start.owns = start.freq[2] / 2;
        printf( "%d\n", solve( start ) - 1 );
    }
    
    printf( "%d\n", answer.size() );

    return 0;
}
