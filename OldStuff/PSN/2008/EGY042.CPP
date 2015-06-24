/*
Alfonso Alfonso Peterssen
TASK: RUTA
*/
#include <iostream>

using namespace std;

int sol, len, i, j, k;
string city;
int cant[256];
int path[256][256];
char a, b;

int main() {

    #warning READ FROM FILES!!!!

 //   freopen( "ruta.in", "r", stdin );
//    freopen( "ruta.out", "w", stdout );

    memset( path, 63, sizeof( path ) );
    while ( ( cin >> city ) && city != "deadend" ) {
        len = city.len();
        a = city[0];
        b = city[len - 1];
        cant[a]++;
        cant[b]++;
        path[a][b] <?= path[b][a] <?= len;
        sol += len;
    }

    for ( a = 'a'; a <= 'z' && !( cant[a] & 1 ); a++ );
    for ( b = a+1; b <= 'z' && !( cant[b] & 1 ); b++ );

    /* Floyd */
    for ( k = 'a'; k <= 'z'; k++ )
    for ( i = 'a'; i <= 'z'; i++ )
    for ( j = 'a'; j <= 'z'; j++ )
        path[i][j] <?= path[i][k] + path[k][j];

    if ( a <= 'z' && b <= 'z' )
        sol += path[a][b];

    cout << sol << endl;

    return 0;
}
