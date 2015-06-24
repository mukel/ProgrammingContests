/*
Alfonso Alfonso Peterssen
18 - 11 - 2007
SPOJ #705 "New Distinct Substrings"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXL = 60000;

int T, len, offset, i, j, k;
long long sol;
char st[MAXL + 1];
int sa[MAXL], pos[MAXL], t[MAXL];

    bool comp( const int &i, const int &j ) {
        if ( pos[i] != pos[j] ) return pos[i] < pos[j];
        if ( i + offset >= len ) return 1;
        if ( j + offset >= len ) return 0;
        return pos[i + offset] < pos[j + offset];
    }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%s", &st );
        len = strlen( st );

        for ( i = 0; i < len; i++ ) {
            sa[i] = i;
            pos[i] = st[i];
        }

        fill( t, t + len, 0 );

        for ( offset = 0; t[len - 1] != len - 1;
              offset ? offset *= 2 : offset++ ) {
            sort( sa, sa + len, comp );
            for ( i = 0; i < len - 1; i++ )
                t[i + 1] = t[i] + comp( sa[i], sa[i + 1] );
            for ( i = 0; i < len; i++ )
                pos[ sa[i] ] = t[i];
        }

        k = 0;
        sol = ( long long )len * ( len + 1 ) / 2;
        for ( i = 0; i < len; i++ ) {
            if ( pos[i] == len - 1 ) continue;
            for ( j = sa[ pos[i] + 1 ];
                  j + k < len && i + k < len && st[i + k] == st[j + k];
                  k++ );
            sol -= k;
            if ( k > 0 ) k--;
        }

        printf( "%lld\n", sol );
    }

    return 0;
}
