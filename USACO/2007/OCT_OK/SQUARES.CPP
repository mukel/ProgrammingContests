/*
PROG: squares
LANG: C++
ID: a2peter1
*/
#include <fstream>
using namespace std;

const int MAXB = 500;

int N, i, j, sol;

ifstream fin ( "squares.in" );
ofstream fout ( "squares.out" );

  int sqr( int x ) { return x * x; }

int main() {

  fin >> N;

  for ( i = 1; i <= MAXB; i++ )
    for ( j = i + 1; j <= MAXB; j++ )
      if ( sqr( j ) - sqr( i ) == N )
        sol++;

  fout << sol << endl;

  return 0;
}
