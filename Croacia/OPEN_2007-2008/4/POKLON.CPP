/*
Alfonso Alfonso Peterssen
TASK: POKLON
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, i, j, k;
vector< int > ls, lis, last;
vector< pair< int, int > > vec;

    bool start_cmp( const int &i, const int &j ) {
        if ( vec[i].first != vec[j].first ) return vec[i].first < vec[j].first;
        return vec[i].second > vec[j].second;
    }
    
    bool end_cmp( const int &i, const int &j ) {
        if ( vec[i].second != vec[j].second ) return vec[i].second > vec[j].second;
        return vec[i].first == vec[j].first; // distinct
    }

    void print( int x ) {
        if ( x == -1 ) return;
        print( last[x] );
        printf( "%d %d\n", vec[x].first, vec[x].second );
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        int a, b;
        scanf( "%d %d", &a, &b );
        vec.push_back( make_pair( a, b ) );
        ls.push_back( i );
    }
    
    sort( ls.begin(), ls.end(), start_cmp );

    /* LIS */
    last.resize( N );
    for ( i = 0; i < ls.size(); i++ ) {
        vector< int >::iterator it = upper_bound( lis.begin(), lis.end(), ls[i], end_cmp );
        last[ ls[i] ] = ( it != lis.begin() ) ? (*( it - 1 )) : -1;
        if ( it != lis.end() )
             *it = ls[i];
        else lis.push_back( ls[i] );
    }
    
    printf( "%d\n", lis.size() );
    print( lis.back() );
    
    return 0;
}
