/*
Alfonso Alfonso Peterssen
30 - 9 - 2007
SPOJ #1785 "Code"
*/
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define MAXN 7
#define MAXV 1000007

int N, i, j;
int pot10[MAXN];
bool mark[MAXV];

int len[MAXN];
char sol[MAXN][MAXV];

int main() {

  pot10[0] = 1;
  for ( i = 1; i < MAXN; i++ )
    pot10[i] = pot10[i - 1] * 10;

  /* Iterative DFS ( Euler Tour ) */
  for ( i = 1; i < MAXN; i++ ) {

    memset( mark, false, pot10[i] );

    mark[0] = true;

    stack< int > S;

    S.push( 0 );
    while ( !S.empty() ) {

     DO_THE_JOB:

      int x = S.top() % pot10[i - 1] * 10;
      for ( j = 0; j < 10; j++ )
        if ( !mark[ x + j ] ) {
          mark[ x + j ] = true;
          S.push( x + j );
          goto DO_THE_JOB;
        }

      sol[i][ len[i]++ ] = S.top() % 10;
      S.pop();
    }
  }

  /* Solve */
  for (;;) {

    scanf( "%d", &N );
    if ( N == 0 ) break;

    for ( i = 0; i < pot10[N] + N - 1; i++ )
      printf( "%d", sol[N][i] );

    printf( "\n" );
  }

  return 0;
}
