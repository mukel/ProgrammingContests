/*
Alfonso2 Peterssen
9 - 5 - 2008
IOI 2004 Day2 Task "Empodia"
*/
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 1100000;

typedef pair< int, int > par;

int N, E, cant;
int i, j, a, b;
int seq[MAXN];
int ans[MAXN];
int last[MAXN];
int next[MAXN];
int empodio[MAXN];
bool deleted[MAXN];
stack< int > S;
par vals[MAXN];
par events[MAXN];

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d", &seq[i] );

    for ( i = 0; i < N; last[i] = j, i++ )
        for ( j = i - 1; j >= 0 && seq[j] < seq[i]; j = last[j] );

    for ( i = N - 1; i >= 0; next[i] = j, i-- )
        for ( j = i + 1; j < N && seq[j] > seq[i]; j = next[j] );

    for ( i = 0; i < N; i++ )
        vals[i] = par( seq[i] - i, i );

    /* Find all empodios */
    sort( vals, vals + N );
    for ( i = 0; i < N; i++ ) {
        a = vals[i].second;
        for ( j = i + 1; j < N &&
              vals[i].first == vals[j].first; j++ ) {
            b = vals[j].second;
            if ( next[a] <= b ) break;
            if ( last[b] < a && next[a] > b ) {
                empodio[b] = a;
                events[E++] = par( a, +(i+1) );
                events[E++] = par( b, -(i+1) );
                break;
            }
        }
    }

    /* Find inner intervals */
    sort( events, events + E );
    for ( i = 0; i < E; i++ ) {
        int id = events[i].second;
        if ( id > 0 ) S.push( abs(id) );
        if ( id < 0 && !deleted[ abs(id) ] ) {
            while ( !S.empty() ) {
                deleted[ S.top() ] = true;
                S.pop();
            }
            ans[cant++] = events[i].first;
        }
    }

    printf( "%d\n", cant );
    for ( i = 0; i < cant; i++ )
        printf( "%d %d\n", empodio[ ans[i] ] + 1, ans[i] + 1 );

    return 0;
}
