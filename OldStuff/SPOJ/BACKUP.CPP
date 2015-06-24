/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
SPOJ #1553 "Backup Files"
*/
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 100000;

typedef pair< int, int > par;

int t, n, k, i, sol;
int pos, val, l, r;
int cost[MAXN];
int next[MAXN], last[MAXN];
multiset< par > Q;

int main() {

    scanf( "%d", &t );
    while ( t-- ) {

        Q.clear();
        sol = 0;

        scanf( "%d %d", &n, &k );
        for ( i = 0; i < n; i++ )
            scanf( "%d", &cost[i] );

        for ( i = 0; i < n - 1; i++ ) {
            cost[i] = cost[i + 1] - cost[i];
            Q.insert( make_pair( cost[i], i ) );
            next[i] = i + 1;
            last[i] = i - 1;
        }
        
        last[0] = next[n - 2] = -1;
        
        while ( k-- ) {

            pos = ( *Q.begin() ).second;
            Q.erase( Q.begin() );
            
            sol += cost[pos];
            
            l = last[pos];
            r = next[pos];
                       
            if ( l != -1 ) {
                Q.erase( Q.find( make_pair( cost[l], l ) ) );
                if ( last[l] != -1 ) next[ last[l] ] = pos;
                last[pos] = last[l];
            }
            
            if ( r != -1 ) {
                Q.erase( Q.find( make_pair( cost[r], r ) ) );
                if ( next[r] != -1 ) last[ next[r] ] = pos;
                next[pos] = next[r];
            }

            if ( l != -1 && r != -1 ) {
                cost[pos] = cost[l] + cost[r] - cost[pos];
                Q.insert( make_pair( cost[pos], pos ) );
            }
            
            if ( l == -1 || r == -1 ) {
               cost[pos] = ( 1 << 30 );
               Q.insert( make_pair( cost[pos], pos ) );
            }

        }

        printf( "%d\n", sol );
    }

    return 0;
}
