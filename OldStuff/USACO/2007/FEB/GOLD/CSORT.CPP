/*
Alfonso Alfonso Peterssen
2 - 7 - 2007
USACO FEB07 Gold "Ordenamiento de Vacas"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int N, i, j, cnt, sol;
pair< int, int > ls[MAXN];
bool mark[MAXN];

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ )
        cin >> ls[i].first, ls[i].second = i;

    sort( ls, ls + N );

    for ( i = 0; i < N; i++ )
        if ( !mark[i] && ls[i].second != i ) {
            j = i; cnt = 0;
            while ( ls[j].second != i ) {
                j = ls[j].second;
                mark[j] = true;
                sol += ls[j].first;
                cnt++;
            }
            sol += min( cnt * ls[i].first,
                        ls[0].first * ( cnt + 2 ) + 2 * ls[i].first );
        }

    cout << sol << endl;

    return 0;
}
