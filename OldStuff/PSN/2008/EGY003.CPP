/*
Alfonso Alfonso Peterssen
TASK: SAILS
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100000,
    MAXH = 100000;

typedef pair< int, int > par;

int N, i, limit;
int height, sails;
int pos, next, last;
long long sol, x;
par poles[MAXN];
int T[MAXH + 1];

int lobit( int x ) { return x & -x; }

void update( int x, int amount ) {
    for ( ; x <= limit; x += lobit( x ) )
        T[x] += amount;
}

int query( int x ) {
    int sum = 0;
    for ( ; x > 0; x -= lobit( x ) )
        sum += T[x];
    return sum;
}

int find_last( int pos, int lo, int hi ) {
    int target = query( pos );
    while ( lo <= hi ) {
        int mid = ( lo + hi ) / 2;
        if ( query( mid ) == target )
             hi = mid - 1;
        else lo = mid + 1;
    }
    return hi + 1;
}

int find_next( int pos, int lo, int hi ) {
    int target = query( pos );
    while ( lo <= hi ) {
        int mid = ( lo + hi ) / 2;
        if ( query( mid ) == target )
             lo = mid + 1;
        else hi = mid - 1;
    }
    return lo - 1;
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d", &poles[i].first, &poles[i].second );

    sort( poles, poles + N );
    
    limit = poles[N - 1].first;
    
    for ( i = 0; i < N; i++ ) {
        height = poles[i].first;
        sails  = poles[i].second;
        
        pos = height - sails + 1;
        last = find_last( pos, 1, pos );
        next = find_next( pos, pos, height );
        
        update( next + 1, 1 );
        update( height + 1, -1 );
        update( last, 1 );
        update( last + next - pos + 1, -1 );
    }

    for ( i = 1; i <= limit; i++ )
        if ( ( x = query( i ) ) > 0 )
            sol += x * ( x - 1 ) / 2;

    printf( "%I64d\n", sol );
    
    fflush( stdout );

    return 0;
}
