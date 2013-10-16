/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
SPOJ #1282 "How many Islands"
*/
#include <cstdio>
#include <queue>
using namespace std;

const int MAXF = 300;
const int mov[8][2] =
  { {-1,-1}, {-1,0}, {-1,1}, {0,-1},
    {0,1}, {1,-1}, {1,0}, {1,1} };

int T, F, C, i, j, k, sol;
char mat[MAXF][MAXF];
typedef struct {
  int x, y;
} point;
queue< point > Q;

int main() {
	
	for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d %d", &F, &C );
    for ( i = 0; i < F; i++ )
      scanf( "%s", &mat[i] );
      
    sol = 0;
    for ( i = 0; i < F; i++ )
      for ( j = 0; j < C; j++ )
        if ( mat[i][j] == '#' ) {
          sol++;
          for ( Q.push( ( point ) { i, j } ); !Q.empty(); Q.pop() ) {
            point p = Q.front();
            for ( k = 0; k < 8; k++ ) {
              int nx = p.x + mov[k][0],
                  ny = p.y + mov[k][1];
              if ( nx >= 0 && nx < F && ny >= 0 && ny < C && mat[nx][ny] == '#' ) {
                  mat[nx][ny] = '.';
                  Q.push( ( point ) { nx, ny } );
              }
            }
          }
        }
		
		printf( "%d\n", sol );
	}
	
	return 0;
}
