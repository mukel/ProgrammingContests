/*
Alfonso2 Peterssen
18 - 4 - 2008
TASK: ACRONYM
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int
    MAXS = 101,
    MAXN = 151;
    
#define DEBUG false
//true
    
int T, S, N, i, j, k;
string abr, next_abr;
string insig[MAXS];
string words[MAXN];

int __ways[MAXN][MAXN][MAXN];
int __dp[MAXN][MAXN];

#define ways( i, j, k ) __ways[i][(j) + 1][(k) + 1]
#define dp( i, j ) __dp[(i) + 1][(j) + 1]

void solve() {

    int i, j, k;
    
    /* Initial DP */
    memset( __ways, 0, sizeof( __ways ) );
    for ( i = 0; i < N; i++ ) {
        string &st = words[i];
        for ( j = 0; j < abr.size(); j++ )
            ways( i, j, j - 1 ) = 1;
            
        for ( j = 0; j < st.size(); j++ ) {
            int a, b;
            for ( a = 0; a < abr.size(); a++ )
            for ( b = abr.size() - 1; b >= a; b-- )
                if ( st[j] == abr[b] )
                    ways( i, a, b ) += ways( i, a, b - 1 );
        }
    }
    
    if ( DEBUG )
        for ( i = 0; i < abr.size(); i++ )
        for ( j = i; j < abr.size(); j++ )
            cout << i << " " << j << " -> " << ways( 0, i, j ) << endl;
    
    /* Main DP */
    dp( -1, -1 ) = 1;
    for ( i = 0; i < N; i++ )
        for ( j = i; j < abr.size(); j++ ) {
            dp( i, j ) = 0;
            for ( k = j - 1; k >= i - 1; k-- )
                dp( i, j ) += dp( i - 1, k ) * ways( i, k + 1, j );
        }
    
    /* to_upper */
    for ( i = 0; i < abr.size(); i++ )
        abr[i] = abr[i] - ( 'a' - 'A' );
        
    printf( "%s %d\n", abr.c_str(), dp( N - 1, abr.size() - 1 ) );
    fflush( stdout );
}

int main() {

    #warning READ FROM FILES!!!
    freopen( "acronym.in", "r", stdin );
    freopen( "acronym.out", "w", stdout );

    cin >> S;
    for ( i = 0; i < S; i++ )
        cin >> insig[i];
    sort( insig, insig + S );
    
    while ( ++T ) {
        if ( T == 1 )
             cin >> abr;
        else abr = next_abr;

        N = 0;
        for (;;) {
            cin >> words[N];
            
            /* Fuck -> last test case */
            if ( words[N] == "CASE" && abr == "LAST" )
                exit( 0 ); // suicide
            
            if ( words[N][0] >= 'A' && words[N][0] <= 'Z' ) {
                next_abr = words[N];
                break;
            }
            if ( !binary_search( insig, insig + S, words[N] ) )
                N++;
        }

        /* to_lower */
        for ( i = 0; i < abr.size(); i++ )
            abr[i] = abr[i] - ( 'A' - 'a' );
            
        solve();
    }

    fflush( stdout );

    return 0;
}
