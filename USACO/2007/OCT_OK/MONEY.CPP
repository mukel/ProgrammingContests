/*
PROG: money
LANG: C++
ID: a2peter1
*/
#include <fstream>
using namespace std;

int M, C, i;
long long dp[10001], val;

ifstream fin ( "money.in" );
ofstream fout ( "money.out" );

int main() {

  dp[0] = 1;
  for ( fin >> C >> M; C; C-- ) {
    fin >> val;
    for ( i = val; i <= M; i++ )
      dp[i] += dp[i - val];
  }

  fout << dp[M] << endl;

  return 0;
}
