/*
Alfonso2 Peterssen
16 - 6 - 2008
IOI 2005 "Birthday"
O( n )
*/
#include <cstdio>
#include <algorithm>

using std::reverse;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 1000000;

int N, sol;
int pos[MAXN];

int cnt[MAXN];
int tmp[MAXN];

void radix_sort( int elems[], int lo, int hi ) {
    if ( lo >= hi ) return ; // nothing to sort
    for ( int i = 0; i + i <= N; i++ ) cnt[i] = 0;
    for ( int i = lo; i <= hi; i++ ) cnt[ elems[i] ]++;
    for ( int i = 1; i + i <= N; i++ ) cnt[i] += cnt[i - 1];
    for ( int i = lo; i <= hi; i++ ) tmp[ --cnt[ elems[i] ] ] = elems[i];
    for ( int i = lo; i <= hi; i++ ) elems[i] = tmp[i - lo];
}

template< typename T > struct fast_deque {
    int head, tail;
    T elems[2 * MAXN + 1];

    fast_deque() { clear(); }
    void clear() { tail = MAXN; head = tail - 1; }

    bool empty() { return tail > head; }

    T front() { return elems[tail]; }
    T back()  { return elems[head]; }

    void push_front( T x ) { elems[--tail] = x; }
    void push_back( T x )  { elems[++head] = x; }

    void pop_front() { tail++; }
    void pop_back()  { head--; }
};

fast_deque< int > L, R;

void solve() {

    L.clear();
    R.clear();

    /* Make First */
    REP( i, N ) {
        int left = abs( i - pos[i] );
        if ( i > pos[i] ) left = N - left;
        if ( left <= N - left )
             L.push_front( left );
        else R.push_back( N - left );
    }

    radix_sort( L.elems, L.tail, L.head );
    radix_sort( R.elems, R.tail, R.head );

    /* Rotate */
    REP( i, N ) {
        while ( !R.empty() && R.back() + i > N / 2 ) {
            R.pop_back();
            L.push_back( ( N - 1 ) / 2 + i );
        }
        while ( !L.empty() && L.front() - i < 0 ) {
            L.pop_front();
            R.push_front( 1 - i );
        }
        int value = 0;
        if ( !R.empty() ) value >?= R.back() + i;
        if ( !L.empty() ) value >?= L.back() - i;
        sol <?= value;
    }
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d", &pos[i] );
        pos[i]--;
    }

    sol = N;

    solve();
    reverse( pos, pos + N );
    solve();

    printf( "%d\n", sol );

    return 0;
}
