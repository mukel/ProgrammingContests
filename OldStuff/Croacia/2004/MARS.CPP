/*
Alfonso Alfonso Peterssen
20 - 11 - 2007
COI 2004 National2 Senior "MARS"
*/
#include <cstring>
#include <iostream>
using namespace std;

const int MAXLEN = 1000;

int len, sz, i, j, k, cost;
string st;
int ls[MAXLEN], ls_sz; // divisors
int log10[MAXLEN + 1];
int dp[MAXLEN][MAXLEN];
int from[MAXLEN][MAXLEN];

    void print( int i, int j ) {

        if ( i == j ) {
            cout << st[i];
            return;
        }

        if ( from[i][j] >= 0 ) {
            print( i, from[i][j] );
            print( from[i][j] + 1, j );
        } else {
            cout << '(';
            print( i, i - from[i][j] - 1 );
            cout << ')' << ( j - i + 1) / ( -from[i][j] );
        }
    }

int main() {

    cin >> st;
    len = st.size();

    /* Init */
    for ( i = 0; i <= len; i++ ) {
        log10[i] = ( i > 9 ) + ( i > 99 ) + ( i > 999 );
        if ( i < len ) dp[i][i] = 1;
    }

    /* DP */
    for ( sz = 1; sz < len; sz++ ) {

        /* Get Divisors */
        ls_sz = 0;
        for ( i = 1; i <= sz; i++ )
            if ( ( sz + 1 ) % i == 0 ) ls[ls_sz++] = i;

        for ( i = 0; i < len - sz; i++ ) {

            j = i + sz;

            dp[i][j] = 1000000000;

            /* Concatenate */
            for ( k = i; k < j; k++ ) {
                int cost = dp[i][k] + dp[k + 1][j];
                if ( cost < dp[i][j] ) {
                    dp[i][j] = cost;
                    from[i][j] = k;
                }
            }

            /* Factorize */
            for ( k = 0; k < ls_sz; k++ ) {

                int f = ( sz + 1 ) / ls[k];
                int cost = dp[i][i + ls[k] - 1] + log10[f] + 3;
                if ( cost >= dp[i][j] ) break;

                int x;
                for ( x = 0; x + ls[k] <= sz; x++ )
                     if( st[ i + x ] != st[ i + x + ls[k] ] ) break;

                if ( x + ls[k] > sz ) {
                    dp[i][j] = cost;
                    from[i][j] = -ls[k];
                    break;
                }
            }
        }
    }

//    cout << dp[0][len - 1] << endl;
    print( 0, len - 1 ); cout << endl;

    return 0;
}

