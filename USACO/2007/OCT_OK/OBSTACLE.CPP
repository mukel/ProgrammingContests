/*
PROG: obstacle
LANG: C++
ID: a2peter1
*/
#include <cstdio>

const int
  MAXN = 200,
  oo = 10000000,
  mv[4][2] = {{-1, 0}, {0, 1},{0, -1},{1, 0}};

int N, i, j, k, sol;
int tarX, tarY;
char mat[MAXN][MAXN];
int cost[MAXN][MAXN][4];

int a, b;
int sz[2];
int qX[2][ 5 * MAXN ],
    qY[2][ 5 * MAXN ],
    dir[2][ 5 * MAXN ];

int main() {

  for ( i = 0; i < MAXN; i++ )
    for ( j = 0; j < MAXN; j++ )
      for ( k = 0; k < 4; k++ )
        cost[i][j][k] = oo;

  freopen( "obstacle.in", "r", stdin );
  freopen( "obstacle.out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf( "%s", &mat[i] );
    for ( j = 0; j < N; j++ )
      if ( mat[i][j] == 'B' ) {
        sz[a] = 4;
        for ( k = 0; k < 4; k++ ) {
          qX[a][k] = i;
          qY[a][k] = j;
          dir[a][k] = k;
          cost[i][j][k] = 0;
        }
      } else
      if ( mat[i][j] == 'A' ) {
        tarX = i; tarY = j;
      }
  }

  /* BFS */
  b = 1;
  while ( sz[a] ) {

    a ^= 1; b ^= 1; sz[a] = 0;

    for ( i = 0; i < sz[b]; i++ )
      for ( j = 0; j < 4; j++ ) {

        int nx = qX[b][i] + mv[j][0],
            ny = qY[b][i] + mv[j][1];

        int tmp = cost[ qX[b][i] ][ qY[b][i] ][ dir[b][i] ];

        if ( j != dir[b][i] ) tmp++;

        if ( nx >= 0 && nx < N && ny >= 0 && ny < N )
          if ( mat[nx][ny] != 'x' && tmp < cost[nx][ny][j] ) {
            cost[nx][ny][j] = tmp;
            qX[a][ sz[a] ] = nx;
            qY[a][ sz[a] ] = ny;
            dir[a][ sz[a] ] = j;
            sz[a]++;
          }
      }
  }

  sol = oo;
  for ( i = 0; i < 4; i++ )
    sol <?= cost[tarX][tarY][i];

  printf( "%d\n", sol );

  return 0;
}
