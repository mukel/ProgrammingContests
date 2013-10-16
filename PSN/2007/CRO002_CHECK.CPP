/*
Alfonso Alfonso Peterssen
Pyramid Checker
check <model_output> <your_output>
*/
#include <cstdio>
#include <cstdlib>

int T, x1, x2, y1, y2, u1, u2, v1, v2;

int main( int argc, char* argv[] ) {

  FILE *fmodel = fopen( argv[1], "r" ),
       *fout = fopen( argv[2], "r" );

  fscanf( fout, "%d %d %d %d", &x1, &y1, &x2, &y2 );

  for ( fscanf( fmodel, "%d", &T ); T; T-- ) {

    fscanf( fmodel, "%d %d %d %d", &u1, &v1, &u2, &v2 );

    if ( x1 == u1 && x2 == u2 && y1 == v1 && y2 == v2 ) {
      printf( "Ok!!!\n" );
      exit( 0 );
    }
  }

  printf( "Wrong!!!\n" );

  return 0;
}
