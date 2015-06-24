/*
Alfonso2 Peterssen
15 - 5 - 2008
Saratov #243 "Broken Chessboard"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int
    MAXC = 20,
    MAXP = 26,
    MAXN = 10;

const int mov[4][2] =
    {{-1,0},{0,-1},{0,1},{1,0}};

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int N;
int startX, startY;
char board[MAXC + 1][MAXC + 1];
char tmp[MAXC + 1][MAXC + 1];
bool mark[MAXC][MAXC];
bool used[MAXP];
int sol[MAXN][MAXN];

struct point {
    int x, y;
    point() {}
    point( int x, int y ) : x( x ), y( y ) {}
    bool operator < ( const point &p ) const {
        if ( x != p.x ) return x < p.x;
        return y < p.y;
    }
};

struct piece {
    vector< point > V;
    int id;
    piece() {}
    piece( vector< point > V, int id ) : V( V ), id( id ) {
        sort( V.begin(), V.end() );
    }
    bool operator < ( const piece &p ) const {
        if ( id != p.id ) return id < p.id;
        if ( V.size() != (p.V).size() ) return V.size() < (p.V).size();
        return V < p.V;
    }
};

bool operator == ( const piece &a, const piece &b ) {
    return !( a < b || b < a );
}

vector< piece > ls;

void dfs( int x, int y, vector< point > &vec ) {
    mark[x][y] = true;
    vec.push_back( point( x - startX, y - startY ) );
    REP( i, 4 ) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if ( nx < 0 || nx >= MAXC ||
             ny < 0 || ny >= MAXC )
             continue;
        if ( !mark[nx][ny] &&
             board[nx][ny] == board[x][y] )
             dfs( nx, ny, vec );
    }
}

void comb( int x, int y ) {

    if ( y == N ) {
        y = 0; x++;
        if ( x == N ) {
            REP( i, N )
            REP( j, N )
                printf( j < N - 1 ? "%c" : "%c\n", (char)sol[i][j] + 'A' );
            fflush( stdout );
            exit( 0 );
        }
    }

    if ( sol[x][y] != -1 ) {
        comb( x, y + 1 );
        return ;
    }

    REP( i, ls.size() ) {
        if ( used[ ls[i].id ] )
            continue;

        bool ok = true;
        vector< point > &V = ls[i].V;
        REP( j, V.size() ) {
            int nx = x + V[j].x;
            int ny = y + V[j].y;
            if ( nx < 0 || nx >= N ||
                 ny < 0 || ny >= N ||
                 sol[nx][ny] != -1 ) {
                 ok = false;
                 break;
                }
        }

        if ( ok ) {
            used[ ls[i].id ] = true;
            REP( j, V.size() )
                sol[ x + V[j].x ][ y + V[j].y ] = ls[i].id;
            comb( x, y + 1 );
            used[ ls[i].id ] = false;
            REP( j, V.size() )
                sol[ x + V[j].x ][ y + V[j].y ] = -1;
        }
    }
}

int main() {

    scanf( "%d", &N );
    REP( i, MAXC )
        scanf( "%s", &board[i] );

    /* Init */
    REP( i, 4 ) {
        memset( mark, 0, sizeof( mark ) );
        REP( j, MAXC )
        REP( k, MAXC )
            if ( board[j][k] != '.' && !mark[j][k] ) {
                vector< point > vec;
                startX = j;
                startY = k;
                dfs( j, k, vec );
                ls.push_back( piece( vec, board[j][k] - 'A' ) );
            }
        /* Rotate 90 */
        REP( j, MAXC )
        REP( k, MAXC )
            tmp[j][k] = board[k][MAXC - j - 1];
        memcpy( board, tmp, sizeof( board ) );
    }

    /* Erase Duplicates */
    sort( ls.begin(), ls.end() );
    ls.erase( unique( ls.begin(), ls.end() ), ls.end() );
    
    memset( sol, -1, sizeof( sol ) );
    comb( 0, 0 );

    printf( "NO BOARD\n" );

    return 0;
}
