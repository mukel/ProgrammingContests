/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2149 "Biased Standings"
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, i, j;
long long sol;
char st[100000];

int main() {
  
    for ( scanf( "%d", &T ); T; T-- ) {

        vector< pair< int, int > > ls;

        scanf( "%d", &N );
        for ( i = 0; i < N; i++ ) {
            scanf( "%s %d", &st, &j );
            ls.push_back( make_pair( --j, i ) );
        }
        
        sort( ls.begin(), ls.end() );
        
        sol = 0;
        for ( i = 0; i < N; i++ )
            sol += abs( i - ls[i].first );
        
        printf( "%lld\n", sol );
    }
    
    return 0;
}
