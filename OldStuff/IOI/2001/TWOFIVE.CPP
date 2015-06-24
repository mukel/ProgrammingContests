/*
Alfonso2 Peterssen
14 - 6 - 2008
IOI 2001 "TwoFive"
*/
#include <cstdio>
#include <cstring>

#define REPD( i, n ) \
    for ( i = (n) - 1; i >= 0; i-- )

const int MAXL = 26;

int N;
char W[MAXL];
int dp[6][6][6][6][6];
int s[6];
int x[MAXL];
int y[MAXL];
bool used[MAXL];

int count() {

    memset( dp, 0, sizeof( dp ) );
    dp[5][5][5][5][5] = 1;

    s[0] = 5;
    REPD( s[1], 6 )
    REPD( s[2], 6 )
    REPD( s[3], 6 )
    REPD( s[4], 6 )
    REPD( s[5], 6 ) {

        int ch = s[1]+s[2]+s[3]+s[4]+s[5];
        int &val = dp[s[1]][s[2]][s[3]][s[4]][s[5]];

        if ( used[ch] ) {
            if ( s[ x[ch] ] < s[ x[ch] - 1 ] && s[ x[ch] ] + 1 == y[ch] ) {
                s[ x[ch] ]++;
                val = dp[s[1]][s[2]][s[3]][s[4]][s[5]];
                s[ x[ch] ]--;
            }
        } else
            for ( int i = 1; i <= 5; i++ )
                if ( s[i] < s[i - 1] ) {
                    s[i]++;
                    val += dp[s[1]][s[2]][s[3]][s[4]][s[5]];
                    s[i]--;
                }
    }

    return dp[0][0][0][0][0];
}

int main() {

    if ( getchar() == 'W' ) {

        scanf( "%s", &W );
        for ( int i = 1; i < 6; i++ )
        for ( int j = 1; j < 6; j++ )
        for ( int k = 0; k < 25; k++ ) {
            if ( used[k] ) continue;
            used[k] = true;
            x[k] = i;
            y[k] = j;
            if ( W[(i-1)*5+j-1] == k + 'A' )
                break;
            N += count();
            used[k] = false;
        }

        printf( "%d\n", N + 1 );

    } else {

        scanf( "%d", &N ); N--;
        for ( int i = 1; i < 6; i++ )
        for ( int j = 1; j < 6; j++ )
        for ( int k = 0; k < 25; k++ ) {
            if ( used[k] ) continue;
            used[k] = true;
            x[k] = i;
            y[k] = j;
            int cnt = count();
            if ( cnt > N ) {
                W[(i-1)*5+j-1] = k + 'A';
                break;
            }
            N -= cnt;
            used[k] = false;
        }

        printf( "%s\n", W );
    }

    return 0;
}
