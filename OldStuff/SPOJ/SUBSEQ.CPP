/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2150 "Counting Subsequences"
*/
#include <cstdio>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int T, N, i, j, k, sol;
vector< int > ls;

int main() {
  
    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        ls.clear();
        sol = 0;

        scanf( "%d", &N );
        for ( i = 0; i < N; i++ ) {
            scanf( "%d", &j );
            ls.push_back( j );
        }
        
        partial_sum( ls.begin(), ls.end(), ls.begin() );
        
        map< int, int > cant;
        cant[0] = 1;
        for ( i = 0; i < N; i++ ) {
            sol += cant[ ls[i] - 47 ];
            cant[ ls[i] ]++;
        }
        
        printf( "%d\n", sol );

    }
    
    return 0;
}
