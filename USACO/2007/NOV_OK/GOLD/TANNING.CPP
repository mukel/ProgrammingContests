/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
USACO NOV07 Gold "Tanning"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2500;

int C, L, i, j, sol;
bool happy[MAXN];
struct par { int x, y; };
par lot[MAXN], cow[MAXN];

bool cow_cmp( const par &a, const par &b ) { return a.y < b.y; }
bool lot_cmp( const par &a, const par &b ) { return a.x < b.x; }

int main() {

    scanf( "%d %d", &C, &L );
    for ( i = 0; i < C; i++ )
        scanf( "%d %d", &cow[i].x, &cow[i].y );
    for ( i = 0; i < L; i++ )
        scanf( "%d %d", &lot[i].x, &lot[i].y );

    sort( cow, cow + C, cow_cmp );
    sort( lot, lot + L, lot_cmp );

    for ( i = 0; i < L; i++ )
        for ( j = 0; j < C && lot[i].y > 0; j++ )
            if ( !happy[j] )
                if ( cow[j].x <= lot[i].x &&
                     cow[j].y >= lot[i].x ) {
                    happy[j] = true;
                    lot[i].y--;
                    sol++;
                }

    printf( "%d\n", sol );

    return 0;
}
