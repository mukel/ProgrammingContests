/*
Alfonso2 Peterssen
9 - 5 - 2007
IOI 2007 Task "Pairs"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int B, N, D, M;
long long sol;
struct point {
    int a, b, c, d;
    bool operator < ( const point &p  ) const {
        if ( a != p.a ) return a < p.a;
        if ( b != p.b ) return b < p.b;
        if ( c != p.c ) return c < p.c;
        return d < p.d;
    }
} vec[MAXN];

void solve1() {
    int i, j, x;
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &x );
        vec[i] = (point){ x };
    }
    sort( vec, vec + N );
    for ( i = j = 0; i < N; i++ ) {
        while ( vec[i].a - vec[j].a > D ) j++;
        sol += i - j;
    }
}

const int LIMIT2 = 2 * 75000 + 1;
int T2[LIMIT2];

int lobit( int x ) { return x & -x; }

int query2( int x ) {
    int sum = 0;
    for ( ; x > 0; x -= lobit( x ) )
        sum += T2[x];
    return sum;
}

int query2( int x1, int x2 ) {
    x1--;
    x1 >?= 0; x2 <?= LIMIT2 - 1;
    return query2( x2 ) - query2( x1 );
}

void update2( int x, int amount ) {
    for ( ; x < LIMIT2; x += lobit( x ) )
        T2[x] += amount;
}

void solve2() {
    int i, j, x, y;
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        vec[i] = (point){ x - y, x + y };
    }
    sort( vec, vec + N );
    for ( i = j = 0; i < N; i++ ) {
        while ( vec[i].a - vec[j].a > D ) {
            update2( vec[j].b, -1 );
            j++;
        }
        sol += query2( vec[i].b - D,
                       vec[i].b + D );
        update2( vec[i].b, +1 );
    }
}

const int LIMIT3 = 4 * 75 + 1;
int T3[LIMIT3][LIMIT3][LIMIT3];

int query3( int x, int y, int z ) {
    int sum = 0;
    for ( int i = x; i > 0; i -= lobit( i ) )
    for ( int j = y; j > 0; j -= lobit( j ) )
    for ( int k = z; k > 0; k -= lobit( k ) )
        sum += T3[i][j][k];
    return sum;
}

int query3( int x1, int y1, int z1, int x2, int y2, int z2 ) {
    //printf( "query %d %d %d -> %d %d %d\n", x1, y1, z1, x2, y2, z2 );
    x1--; y1--; z1--;
    x1 >?= 0; x2 <?= LIMIT3 - 1;
    y1 >?= 0; y2 <?= LIMIT3 - 1;
    z1 >?= 0; z2 <?= LIMIT3 - 1;
    return ( query3( x2, y2, z2 ) ) -
           ( query3( x1, y2, z2 ) + query3( x2, y1, z2 ) + query3( x2, y2, z1 ) ) +
           ( query3( x1, y1, z2 ) + query3( x1, y2, z1 ) + query3( x2, y1, z1 ) ) -
           ( query3( x1, y1, z1 ) );
}

void update3( int x, int y, int z, int amount ) {
    //printf( "update %d %d %d -> %d\n", x, y, z, amount );
    for ( int i = x; i < LIMIT3; i += lobit( i ) )
    for ( int j = y; j < LIMIT3; j += lobit( j ) )
    for ( int k = z; k < LIMIT3; k += lobit( k ) )
        T3[i][j][k] += amount;
}

void solve3() {
    int i, j, x, y, z;
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d %d", &x, &y, &z );
        vec[i] = (point)
            { x+y+z + 150, x+y-z + 150,
              x-y+z + 150, x-y-z + 150 };
    }
    sort( vec, vec + N );
    for ( i = j = 0; i < N; i++ ) {
        while ( vec[i].a - vec[j].a > D ) {
            update3( vec[j].b, vec[j].c, vec[j].d, -1 );
            j++;
        }
        sol += query3( vec[i].b - D, vec[i].c - D, vec[i].d - D,
                       vec[i].b + D, vec[i].c + D, vec[i].d + D );
        update3( vec[i].b, vec[i].c, vec[i].d, +1 );
    }
}

int main() {

    scanf( "%d %d %d %d", &B, &N, &D, &M );

    if ( B == 1 ) solve1();
    if ( B == 2 ) solve2();
    if ( B == 3 ) solve3();

    printf( "%I64d\n", sol );

    return 0;
}
