/*
Alfonso2 Peterssen
17 - 7 - 2008
MIPT #014 "War-cry"
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    ALPHA = 0x100,
    MAXN = 101,
    MAXNODES = 10000;

int N, M, K;
int cost;
string letters;
string word;
int dp[MAXN][MAXNODES];
pair< int, int > from[MAXN][MAXNODES];

struct trie {

    int size;
    int cost[MAXNODES];
    int fail[MAXNODES];
    int next[MAXNODES][ALPHA];

    trie() : size( 1 ) {} // root = 0

    void Insert( string &st, int value ) {
        int root = 0;
        REP( i, st.size() ) {
            int &nxt = next[root][ st[i] ];
            if ( !nxt ) nxt = size++;
            root = nxt;
        }
        cost[root] += value;
    }

    int GetFail( int x, char ch ) {
        while ( x > 0 && !next[x][ch] )
            x = fail[x];
        if ( next[x][ch] )
           x = next[x][ch];
        return x;
    }

    void bfs() {
        queue< int > Q;
        for ( Q.push( 0 ); !Q.empty(); Q.pop() ) {
            int x = Q.front();
            REP( ch, ALPHA )
                if ( next[x][ch] ) {
                    int y = next[x][ch];
                    fail[y] = x ? GetFail( fail[x], ch ) : 0;
                    cost[y] += cost[ fail[y] ];
                    Q.push( y );
                }
        }
    }

} S;

void print( int i, int j ) {
    if ( i == 0 ) return ;
    print( i - 1, from[i][j].first );
    cout << letters[ from[i][j].second ];
}

int main() {

    cin >> N >> M >> K;
    cin >> letters;
    REP( i, K ) {
        cin >> word >> cost;
        S.Insert( word, cost );
    }

    S.bfs();

    memset( dp, -1, sizeof( dp ) );

    dp[0][0] = 0;

    REP( i, N )
    REP( j, S.size )
        if ( dp[i][j] != -1 )
            REP( k, letters.size() ) {
                int x = S.GetFail( j, letters[k] );
                int value = dp[i][j] + S.cost[x];
                if ( value > dp[i + 1][x] ) {
                    dp[i + 1][x] = value;
                    from[i + 1][x] = make_pair( j, k );
                }
            }

    int best = 0;
    REP( i, S.size )
        if ( dp[N][i] > dp[N][best] )
            best = i;

    cout << dp[N][best] << endl;
    print( N, best ); cout << endl;

    return 0;
}
