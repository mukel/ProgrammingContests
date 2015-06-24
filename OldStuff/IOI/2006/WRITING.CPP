/*
Alfonso2 Peterssen
17 - 6 - 2008
IOI 2006 "DECIPHERING THE MAYAN WRITING"
*/
#include <cstdio>

const int MAXLEN = 3000001;

int n, m;
int diff, sol;
char ch;
char freq[0x100];
char st[MAXLEN];

int main() {

    scanf( "%*d %*d\n" );
    for ( ; ( ch = getchar() ) != '\n'; n++ ) {
        if ( freq[ch] == 0 ) diff++;
        freq[ch]++;
    }

    for ( ; ( st[m] = getchar() ) != '\n'; m++ ) {
        ch = st[m];
        if ( freq[ch] == 0 ) diff++;
        freq[ch]--;
        if ( freq[ch] == 0 ) diff--;
        if ( m >= n ) {
            ch = st[m - n];
            if ( freq[ch] == 0 ) diff++;
            freq[ch]++;
            if ( freq[ch] == 0 ) diff--;
        }
        if ( diff == 0 )
            sol++;
    }

    printf( "%d\n", sol );

    return 0;
}
