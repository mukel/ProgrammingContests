/*
Alfonso2 Peterssen
12 - 4 - 2008
TASK: PRINCEZA
*/
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int MAXLEN = 100010;

int N, K;
int x, y;
int curx, cury;
char jumps[MAXLEN];

struct plant {
    int x, y;
};

struct sum_cmp {
    bool operator () ( const plant &a, const plant &b ) { return ( a.x + a.y ) < ( b.x + b.y ); }
};

struct dif_cmp {
    bool operator () ( const plant &a, const plant &b ) { return ( a.x - a.y ) < ( b.x - b.y ); }
};

map< int, set< plant, dif_cmp > > S;
map< int, set< plant, sum_cmp > > D;

typedef set< plant, sum_cmp > sum_set;
typedef set< plant, dif_cmp > dif_set;

void remove( int x, int y ) {
    dif_set &A = S[x + y];
    sum_set &B = D[x - y];
    A.erase( A.find( (plant){ x, y } ) );
    B.erase( B.find( (plant){ x, y } ) );
}

int main() {

    scanf( "%d %d", &N, &K );
    scanf( "%s", &jumps );
    for ( int i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        if ( i == 0 ) {
            curx = x;
            cury = y;
        }
        S[x + y].insert( (plant){ x, y } );
        D[x - y].insert( (plant){ x, y } );
    }

    for ( int i = 0; i < K; i++ ) {

        if ( jumps[i] == 'A' ) {
            sum_set &A = D[curx - cury];
            sum_set::iterator it = A.find( (plant){ curx, cury } );
            it++;
            if ( it != A.end() ) {
                remove( curx, cury );
                curx = (*it).x;
                cury = (*it).y;
            }
        }

        if ( jumps[i] == 'B' ) {
            dif_set &A = S[curx + cury];
            dif_set::iterator it = A.find( (plant){ curx, cury } );
            it++;
            if ( it != A.end() ) {
                remove( curx, cury );
                curx = (*it).x;
                cury = (*it).y;
            }
        }

        if ( jumps[i] == 'C' ) {
            dif_set &A = S[curx + cury];
            dif_set::iterator it = A.find( (plant){ curx, cury } );
            if ( it != A.begin() ) {
                it--;
                remove( curx, cury );
                curx = (*it).x;
                cury = (*it).y;
            }
        }

        if ( jumps[i] == 'D' ) {
            sum_set &A = D[curx - cury];
            sum_set::iterator it = A.find( (plant){ curx, cury } );
            if ( it != A.begin() ) {
                it--;
                remove( curx, cury );
                curx = (*it).x;
                cury = (*it).y;
            }
        }
    }

    printf( "%d %d\n", curx, cury );

    return 0;
}


