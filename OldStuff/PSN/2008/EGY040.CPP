/*
Alfonso Alfonso Peterssen
TASK: LGAME
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 40000;
const int value[] =
    {2,5,4,4,1,6,5,5,1,7,6,3,5,
     2,3,5,7,2,1,2,4,6,6,7,5,7};

typedef pair< int, int > par;

#define ALL( c ) (c).begin(), (c).end()

int N, i, j, x, y;
int limit, max_cost;
string target, st;
string words[MAXN];
vector< par > sol;

int cost_of( const string &st ) {
    int cost = 0;
    for ( int i = 0; i < st.size(); i++ )
        cost += value[ st[i] - 'a' ];
    return cost;
}

void update( int cost, const par &p ) {
    if ( cost > max_cost ) {
        max_cost = cost;
        sol.clear();
    }
    if ( cost == max_cost )
        sol.push_back( p );
}

int main() {

    freopen( "INPUT.TXT", "r", stdin );
    cin >> target;

    freopen( "WORDS.TXT", "r", stdin );
    while ( cin >> words[N] && words[N] != "." )
        N++;

    limit = 1 << target.size();
    for ( i = 0; i < limit; i++ ) {

        st = "";
        for ( j = 0; j < target.size(); j++ )
            if ( i & ( 1 << j ) )
                st = st + target[j];

        sort( ALL( st ) );

        do {

            /* one word */
            x = lower_bound( words, words + N, st ) - words;
            if ( words[x] == st )
                update( cost_of( st ), make_pair( x, -1 ) );

            /* two words */
            for ( j = 1; j < st.size(); j++ ) {
                string a = st.substr( 0, j );
                string b = st.substr( j , st.size() - j );
                x = lower_bound( words, words + N, a ) - words;
                y = lower_bound( words, words + N, b ) - words;
                if ( words[x] == a && words[y] == b )
                    update( cost_of( a + b ), make_pair( x <? y, x >? y ) );
            }

        } while ( next_permutation( ALL( st ) ) );
    }

    freopen( "OUTPUT.TXT", "w", stdout );
    cout << max_cost << endl;

    sort( ALL( sol ) );
    sol.erase( unique( ALL( sol ) ), sol.end() );

    for ( i = 0; i < sol.size(); i++ ) {
        cout << words[ sol[i].first ];
        if ( sol[i].second != -1 )
            cout << " " << words[ sol[i].second ];
        cout << endl;
    }

    return 0;
}
