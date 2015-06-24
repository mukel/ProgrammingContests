/*
Alfonso Alfonso Peterssen
3 - 2 - 2008
Saratov #180 "Inversions"
*/
#include <cstdio>
#include <cstring>

const int MAXN = 1 << 16 + 2;

int N, i;
long long inversions;
int vec[MAXN], tmp[MAXN];

    void merge_sort( int lo, int hi ) {

        if ( lo >= hi )
            return ;

        int mid = ( lo + hi ) / 2;

        merge_sort( lo, mid );
        merge_sort( mid + 1, hi );

        int i = lo, j = mid + 1, k;
        for ( k = 0; k < hi - lo + 1; k++ )
            if ( i <= mid && ( j > hi || vec[i] <= vec[j] ) )
                tmp[k] = vec[i++];
            else {
                tmp[k] = vec[j++];
                inversions += mid - i + 1;
            }

        memcpy( vec + lo, tmp, 4 * k );
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d", &vec[i] );

    merge_sort( 0, N - 1 );

    printf( "%I64d\n", inversions );

    return 0;
}
