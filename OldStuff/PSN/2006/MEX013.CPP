/*
Alfonso Alfonso Peterssen
3 - 11 - 2007
PSN 2006 #13 "Fermat vs Pitagoras"
*/
#include <cstdio>

const int MAXN = 1000;

int N, i, j, k, x, y, z;
int mark[MAXN + 1];
int sol1[MAXN], sol2[MAXN];

  int gcd( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
  }

int main() {

  for ( i = 1; i <= MAXN; i++ )
    mark[i] = MAXN + 1;

  for ( i = 1; i <= MAXN; i++ )
    for ( j = ( i & 1 ) + 1; j < i; j += 2 ) {

      if ( ( z = i * i + j * j ) > MAXN ) break;

      if ( gcd( i, j ) == 1 ) {

        sol1[z]++;

        x = i * i - j * j;
        y = 2 * i * j;

        for ( k = 1; k * z <= MAXN; k++ ) {
          mark[k * x] <?= k * z;
          mark[k * y] <?= k * z;
          mark[k * z] <?= k * z;
	      }
	    }
    }

  for ( i = 1; i <= MAXN; i++ ) {
    sol1[i] += sol1[i - 1];
    for ( j = 1; j <= i; j++ )
      if ( mark[j] > i )
        sol2[i]++;
  }

  while ( scanf( "%d", &N ) != EOF )
    printf( "%d %d\n", sol1[N], sol2[N] );

  return 0;
}


