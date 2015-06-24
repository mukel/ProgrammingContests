/*
Alfonso2 Peterssen
9 - 6 - 2008
IOI 2001 "Ioiwari Game"
See USACO TwoFour
*/
#include <cstdio>
#include <cstring>

enum RESULT{ UNKNOWN = -1, WIN, TIE, LOOSE };

struct state {
    char P[7], bank;
    int sum() const {
        return P[0]+P[1]+P[2]+P[3]+P[4]+P[5]+P[6];
    }
};

int my_move, your_move;
char __answer[6][6][6][6][6][6][6][21];
char __mymove[6][6][6][6][6][6][6][21];

#define GET( c, s ) \
    (c)[(s).P[0]][(s).P[1]][(s).P[2]][(s).P[3]] \
       [(s).P[4]][(s).P[5]][(s).P[6]][(s).bank]

void make_move( state &s, int pit ) {
    s.bank = 20 - s.sum() - s.bank;
    int hand = s.P[pit];
    s.P[pit] = 0;
    for ( pit = ++pit%7; hand > 0; pit = ++pit%7 )
        if ( hand > 1 )
            if ( s.P[pit] == 5 )
                 s.P[pit]--;
            else hand--, s.P[pit]++;
        else
        if ( hand == 1 )
            if ( s.P[pit] == 0 || s.P[pit] == 5 )
                 hand--, s.bank++;
            else hand = s.P[pit] = 0;
}

int solve( const state &s ) {

    if ( s.sum() == 0 ) {
        if ( s.bank > 10 ) return WIN;
        if ( s.bank < 10 ) return LOOSE;
        return TIE;
    }

    char &ans = GET( __answer, s );
    char &mov = GET( __mymove, s );
    if ( ans != UNKNOWN )
        return ans;

    for ( int i = 0; i < 7; i++ )
        if ( s.P[i] != 0 ) {
            state next = s;
            make_move( next, i );
            int res = 2 - solve( next );
            if ( ans == UNKNOWN || res < ans ) {
                ans = res;
                mov = i;
            }
            if ( ans == WIN )
                break;
        }

    return ans;
}

int main() {

    state board;
    for ( int i = 0; i < 7; i++ )
        scanf( "%d", &board.P[i] );

    memset( __answer, -1, sizeof( __answer ) );
    for (;;) {
        if ( board.sum() == 0 ) {
            //printf( "Player1: %d\nPlayer2: %d\n", board.bank, 20 - board.bank );
            break;
        }
        solve( board );
        my_move = GET( __mymove, board );
        printf( "%d\n", my_move + 1 );
        make_move( board, my_move );

        if ( board.sum() == 0 ) {
            //printf( "Player1: %d\nPlayer2: %d\n", 20 - board.bank, board.bank );
            break;
        }
        scanf( "%d", &your_move );
        your_move--;
        make_move( board, your_move );
    }

    return 0;
}
