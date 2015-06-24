/*
Alfonso Alfonso Peterssen
20 - 10 - 2007
SPOJ #1702 "Cleaning Robot"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int
  oo = 1000000000,
  MAXF = 100,
  MAXS = 12;

const int mv[4][2] =
  {{-1, 0}, {0, 1},{0, -1},{1, 0}};

int F, C, S, i, j, k, sol;

char mat[MAXF][MAXF];

int tupple[MAXS];
int dist[MAXS][MAXS];
int x[MAXS], y[MAXS];

bool mark[MAXF][MAXF];

int sz[2];
int qX[2][ 5 * MAXF ],
    qY[2][ 5 * MAXF ];

  void bfs( int id ) {

    int a = 0, b = 1;
    int i, j, depth = 0;

    memset( mark, 0, sizeof( mark ) );
    mark[ x[id] ][ y[id] ] = true;

    sz[a] = 0;
    qX[a][ sz[a] ] = x[id];
    qY[a][ sz[a] ] = y[id];
    sz[a]++;

    while ( sz[a] ) {

      depth++;
      a ^= 1; b ^= 1; sz[a] = 0;

      for ( i = 0; i < sz[b]; i++ )
        for ( j = 0; j < 4; j++ ) {

          int nx = qX[b][i] + mv[j][0],
              ny = qY[b][i] + mv[j][1];

          if ( nx >= 0 && nx < F && ny >= 0 && ny < C )
            if ( !mark[nx][ny] && mat[nx][ny] != 'x' ) {

              if ( mat[nx][ny] <= S )
                dist[id][ mat[nx][ny] ] = depth;

              mark[nx][ny] = true;
              qX[a][ sz[a] ] = nx;
              qY[a][ sz[a] ] = ny;
              sz[a]++;
            }
        }
    }
  }

int main() {

  for (;;) {

    /* Init */
    S = 0;
    for ( i = 0; i < MAXS; i++ )
      for ( j = 0; j < MAXS; j++ )
        dist[i][j] = -1;

    scanf( "%d %d", &C, &F );
    if ( !C && !F ) break;

    for ( i = 0; i < F; i++ ) {
      scanf( "%s", &mat[i] );
      for ( j = 0; j < C; j++ )
        if ( mat[i][j] == 'o' ) {
          mat[i][j] = 0;
          x[0] = i;
          y[0] = j;
        }
        else if ( mat[i][j] == '*' ) {
          mat[i][j] = ++S;
          x[S] = i;
          y[S] = j;
        }
    }

    for ( i = 0; i <= S; i++ )
      bfs( i );

    /* Check */
    sol = 0;
    for ( i = 0; i <= S; i++ )
      for ( j = i + 1; j <= S; j++ )
        if ( dist[i][j] == -1  || dist[j][i] == -1 ) sol = -1;

    if ( sol == -1 ) {
      printf( "-1\n" );
      continue;
    }

    if ( S == 0 ) {
      printf( "0\n" );
      continue;
    }

    /* Solve */
    for ( i = 0; i < S; i++ )
      tupple[i] = i + 1;

    sol = oo;
    do {

      int path = dist[0][ tupple[0] ];

      for ( i = 0; i < S - 1; i++ )
        path += dist[ tupple[i] ][ tupple[i + 1] ];

      sol <?= path;

    } while ( next_permutation( tupple, tupple + S ) );

    printf( "%d\n", sol );
  }

  return 0;
}
