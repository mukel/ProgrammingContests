/*
Alfonso Alfonso Petersse
26 - 12 - 2007
SPOJ #2139 "Gossipers"
*/
#include <iostream>
#include <cstring>
#include <bitset>
#include <map>

using namespace std;

const int MAXL = 100;

int V, E, i, j, k;
string name1, name2, st;
map< string, int > number;

int main() {
  
    for (;;) {

        cin >> V >> E;
        if ( !V && !E ) break;
        
        number.clear();
        bitset< 2100 > mat[V];
        
        for ( i = 0; i < V; i++ ) {
            cin >> st;
            number[st] = i;
            mat[i][i] = true;
        }
        
        for ( i = 0; i < E; i++ ) {
            cin >> name1 >> name2;
            j = number[name1];
            k = number[name2];
            mat[j] |= mat[k];
            mat[k] |= mat[j];
        }
        
        for ( i = 0; i < V; i++ )
            if ( mat[i].count() != V )
                break;
                
        printf( i == V ? "YES\n" : "NO\n" );
    }
    
    return 0;
}
