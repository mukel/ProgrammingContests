/*
Alfonso Alfonso Peterssen
10 - 11 - 2007
SPOJ #1296 "4 values whose sum is 0"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 4000;

int N, S, i, j;
long long sol;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int seq[MAXN * MAXN];

int main() {

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d %d %d %d", &A[i], &B[i], &C[i], &D[i] );

  for ( i = 0; i < N; i++ )
    for ( j = 0; j < N; j++ )
      seq[S++] = A[i] + B[j] ;

  sort( seq, seq + S );

  for ( i = 0; i < N; i++ )
    for ( j = 0; j < N; j++ )
      sol += upper_bound( seq, seq + S, -( C[i] + D[j] ) ) -
             lower_bound( seq, seq + S, -( C[i] + D[j] ) );

  printf( "%lld\n", sol );

  return 0;
}
