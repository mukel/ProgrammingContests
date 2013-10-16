/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2150 "Anti-Blot System"
*/
#include <cstdio>
#include <cstring>

const int MAXL = 20;

int T, a, b, c;
char s1[MAXL], s2[MAXL], s3[MAXL];

#define damaged( x ) ( strstr( x, "machula" ) != NULL )

int main() {
  
    for ( scanf( "%d", &T ); T; T-- ) {
        a = b = c = 0;
        scanf( "%s + %s = %s", s1, s2, s3 );
        sscanf( s1, "%d", &a );
        sscanf( s2, "%d", &b );
        sscanf( s3, "%d", &c );
        if ( damaged( s1 ) ) a = c - b;
        if ( damaged( s2 ) ) b = c - a;
        if ( damaged( s3 ) ) c = a + b;
        printf( "%d + %d = %d\n", a, b, c );
    }
}
