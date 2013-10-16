/*
Alfonso2 Peterssen
29 - 5 - 2008
USACO OPEN08 Silver "Carros Vacunos"
*/
#include <cstdio>
#include <set>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int N, M, D, L;
int val, sol;
multiset< int > S;
multiset< int >::iterator it;

int main() {

    freopen( "cowcar.in", "r", stdin );
    freopen( "cowcar.out", "w", stdout );

    scanf( "%d %d %d %d", &N, &M, &D, &L );
    REP( i, N ) {
         scanf( "%d", &val );
         S.insert( val );
    }

    REP( i, M ) {
         int cant = 0;
         for (;;) {
            it = S.lower_bound( L + ( D * cant ) );
            if ( it == S.end() )
                break;
            S.erase( it );
            cant++;
         }
         sol += cant;
    }

    printf( "%d\n", sol );

    return 0;
}
