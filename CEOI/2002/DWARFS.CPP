/*
Alfonso2 Peterssen
CEOI 2002 "Dwarfs"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

typedef complex< double > point;
typedef pair< point, point > line;

int N;
int limit;
double x_1, y_1, x_2, y_2;
vector< point > P, H;
vector< line > S;

double cross( const point &a, const point &b ) {
    return imag( conj(a) * b );
}

double area2( const point &a, const point &b, const point &c ) {
    return cross( b - a, c - a );
}

bool point_cmp( const point &a, const point &b ) {
    return real( a ) != real( b ) ?
           real( a ) < real( b ) :
           imag( a ) < imag( b );
}

static bool angle_cmp( const line &a, const line &b ) {
    point pa( a.second - a.first );
    point pb( b.second - b.first );
    return atan2( imag( pa ), real( pa ) ) <
           atan2( imag( pb ), real( pb ) );
}

#define ADD( x ) \
    while ( H.size() > limit && \
            area2( H[ H.size() - 2 ], H[ H.size() - 1 ], x ) <= 0 ) \
            H.pop_back();

line GetCloser( const line &ln ) {
    vector< line >::iterator it = upper_bound( ALL( S ), ln, angle_cmp );
    if ( it == S.end() ) return *S.begin();
    return *it;
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%lf %lf", &x_1, &y_1 );
        P.push_back( point( x_1, y_1 ) );
    }

    sort( ALL( P ), point_cmp );
    limit = 1;
    for ( int i = 0; i < P.size(); H.push_back( P[i] ), i++ )
        ADD( P[i] );
    limit = H.size();
    for ( int i = P.size() - 2; i >= 0; H.push_back( P[i] ), i-- )
        ADD( P[i] );
    if ( !H.empty() )
        H.pop_back();

    REP( i, H.size() )
        S.push_back( line( H[i], H[(i + 1) % H.size()] ) );

    sort( ALL( S ), angle_cmp );

    while ( scanf( "%lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2 ) != EOF ) {
        if ( S.size() < 2 ) {
            printf( "GOOD\n" );
            fflush( stdout );
            continue;
        }
        point a( x_1, y_1 );
        point b( x_2, y_2 );
        line ab = GetCloser( line( a, b ) );
        line ba = GetCloser( line( b, a ) );
        if ( area2( a, b, ab.first ) *
             area2( a, b, ba.first ) < 0. )
             printf( "BAD\n" );
        else printf( "GOOD\n" );
        fflush( stdout );
    }

    return 0;
}
