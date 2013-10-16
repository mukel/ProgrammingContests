/*
Alfonso Alfonso Peterssen
20 - 11 - 2007
COI 2004 National2 Senior "MARS"
This runs in 2.84s
Official solutions takes 4.27s
*/
#include <cstring>
#include <iostream>
using namespace std;

const int MAXLEN = 1000;

int len, sz, i, j, k, cost;
string st;
int log10[MAXLEN + 1];
int dp[MAXLEN][MAXLEN];
int from[MAXLEN][MAXLEN];

/* String Factorization */
int pre[MAXLEN];
int fact[MAXLEN][MAXLEN];

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
            cout << ')' << ( j - i + 1 ) / -from[i][j];
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

    /* String Factorization */
    for ( k = 0; k < len; k++ ) {

        fact[k][k] = 1;

        /* Something like KMP */
        j = 0;
        for ( i = k + 1; i < len; i++ ) {
            while ( j && st[k + j] != st[i] )
                j = pre[j];

            if ( st[ k + j ] == st[i] ) j++;

            int ln = i - k + 1;
            pre[ln] = j;

            if ( j && ln % ( ln - j ) == 0 )
                 fact[k][i] = ln - j;
            else fact[k][i] = -1;
        }
    }

    /* DP */
    for ( sz = 1; sz < len; sz++ )
        for ( i = 0; i < len - sz; i++ ) {

            j = i + sz;

            /* Factorize */
            if ( ( k = fact[i][j] ) != -1 ) {
                dp[i][j] = dp[i][i + k - 1] + log10[ ( sz + 1 ) / k ] + 3;;
                from[i][j] = -k;
            } else dp[i][j] = 1000000000;

            /* Concatenate */
            for ( k = i; k < j; k++ ) {
                int cost = dp[i][k] + dp[k + 1][j];
                if ( cost < dp[i][j] ) {
                    dp[i][j] = cost;
                    from[i][j] = k;
                }
            }

        }

//    cout << dp[0][len - 1] << endl;
    print( 0, len - 1 ); cout << endl;

    return 0;
}

