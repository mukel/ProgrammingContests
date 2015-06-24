/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
COCI 2007 Contest 1 "PEG"
*/
#include <cstdio>

const int
  MAXF = 10,
  mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

#define valid( x, y ) \
  ( x >= 0 && x < 7 && y >= 0 && y < 7 )

int i, j, k, x, y, sol;
char board[MAXF][MAXF];

int main() {

  for ( i = 0; i < 7; i++ )
    gets( board[i] );

  for ( i = 0; i < 7; i++ )
    for ( j = 0; j < 7; j++ )
      if ( board[i][j] == 'o' )
        for ( k = 0; k < 4; k++ ) {
          x = i + mov[k][0];
          y = j + mov[k][1];
          if ( valid( x, y ) && board[x][y] == 'o' ) {
            x += mov[k][0];
            y += mov[k][1];
            if ( valid( x, y ) && board[x][y] == '.' )
              sol++;
          }
        }

  printf( "%d\n", sol );

  return 0;
}
