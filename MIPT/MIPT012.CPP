/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #012 "Correct dictionary"
Cycle Detection -> CLRS
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXW = 20001;

int N, W, i, cnt;
bool has_cycle;
int mark[MAXW];
string word, st;
map< string, int > id;
vector< string > G[MAXW];

    void dfs( int node ) {
        if ( mark[node] == 1 ) has_cycle = true;
        if ( mark[node] ) return ;
        mark[node] = 1;
        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = id[ G[node][i] ];
            if ( next ) dfs( next );
        }
        mark[node] = 2;
    }

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ ) {
        cin >> word >> cnt;
        if ( id[word] ) has_cycle = true;
        id[word] = ++W;
        while ( cnt-- ) {
            cin >> st;
            G[W].push_back( st );
        }
    }

    for ( i = 1; !has_cycle && i <= W; i++ )
        if ( !mark[i] )
            dfs( i );

    if ( has_cycle ) cout << "NOT ";
    cout << "CORRECT" << endl;

    return 0;
}
