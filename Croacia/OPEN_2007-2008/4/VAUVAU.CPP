/*
Alfonso Alfonso Peterssen
TASK: VAUVAU
*/
#include <cstdio>

const int MAXN = 1000;

int i, j;
int cant[MAXN];
int a, b, c, d;
int p, m, g;

char *word[] = { "none", "one", "both" };

int main() {

    scanf( "%d %d %d %d", &a, &b, &c, &d );
    scanf( "%d %d %d", &p, &m, &g );
    
    for ( i = 1; i < MAXN; ) {
        for ( j = 0; j < a && i < MAXN; j++, i++ ) cant[i]++;
        for ( j = 0; j < b && i < MAXN; j++, i++ );
    }

    for ( i = 1; i < MAXN; ) {
        for ( j = 0; j < c && i < MAXN; j++, i++ ) cant[i]++;
        for ( j = 0; j < d && i < MAXN; j++, i++ );
    }
    
    printf( "%s\n", word[ cant[p] ] );
    printf( "%s\n", word[ cant[m] ] );
    printf( "%s\n", word[ cant[g] ] );
    fflush( stdout );

    return 0;
}
