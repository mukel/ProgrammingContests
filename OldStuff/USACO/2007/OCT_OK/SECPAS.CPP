/*
PROG: secpas
LANG: C++
ID: a2peter1
*/
#include <fstream>
using namespace std;

const int MAXN = 20001;

int N, i, j, k, sol;
int sqr[MAXN];
bool is_root[MAXN];

ifstream fin ( "secpas.in" );
ofstream fout ( "secpas.out" );

int main() {

  /* Init */
  for ( i = 0; i <= 101; i++ ) {
    is_root[i * i] = true;
    sqr[i] = i * i;
  }

  fin >> N;

  for ( i = 0; sqr[i] <= N; i++ )
    for ( j = 0; sqr[i] + sqr[j] <= N; j++ )
      for ( k = 0; sqr[i] + sqr[j] + sqr[k] <= N; k++ )
        if ( is_root[ N - sqr[i] - sqr[j] - sqr[k] ] )
          sol++;

  fout << sol << endl;

  return 0;
}
