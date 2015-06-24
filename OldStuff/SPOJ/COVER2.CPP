/*
Alfonso Alfonso Peterssen
17 - 10 - 2007
SPOJ #1448 "3D Cover"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 201

int T, N, i, j, k, lastz;
int area;
long long vol;
int x, y, z, r;
int loX, loY, hiX, hiY;

int sortx[ 2 * MAXN ],
    sorty[ 2 * MAXN ];

int mark[MAXN][MAXN];

struct event {
  int z, x, y, r;
  signed char flag;

  bool operator < ( const event &e ) const {
    return z < e.z;
  }
} ls[ 2 * MAXN ];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      scanf( "%d %d %d %d", &x, &y, &z, &r );
      sortx[i] = x - r; sortx[N + i] = x + r;
      sorty[i] = y - r; sorty[N + i] = y + r;
      ls[i] = ( event ) { z - r, x, y, r, 1 };
      ls[N + i] = ( event ) { z + r, x, y, r, -1 };
    }

    /* Init */
    area = vol = 0;

    sort( ls, ls + 2 * N );
    sort( sortx, sortx + 2 * N );
    sort( sorty, sorty + 2 * N );

    lastz = ls[0].z;
    for ( i = 0; i < 2 * N; i++ ) {

      r = ls[i].r;

      x = ls[i].x - r,
      y = ls[i].y - r;
      for ( loX = 0; x != sortx[loX]; loX++ );
      for ( loY = 0; y != sorty[loY]; loY++ );

      x = ls[i].x + r,
      y = ls[i].y + r;
      for ( hiX = 2 * N - 1; x != sortx[hiX]; hiX-- );
      for ( hiY = 2 * N - 1; y != sorty[hiY]; hiY-- );

      vol += area * ( ls[i].z - lastz );
      lastz = ls[i].z;

      for ( j = loX; j < hiX; j++ )
        for ( k = loY; k < hiY; k++ ) {

          int box = ( sortx[j + 1] - sortx[j] ) *
                    ( sorty[k + 1] - sorty[k] );

          if ( mark[j][k] == 1 && ls[i].flag == -1 ) area -= box;
          if ( mark[j][k] == 0 && ls[i].flag == 1 )  area += box;

          mark[j][k] += ls[i].flag;
        }
    }

    printf( "%lld\n", vol ) ;
  }

  return 0;
}
