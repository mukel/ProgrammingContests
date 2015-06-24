/*
Alfonso2 Peterssen
10 - 5 - 2008
POI 1997 Stage III "ALI BABA"
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const int
    MAXN = 10,
    LIMIT = 12;

struct triple {
    int x, y ,z;
    bool operator < ( const triple &t ) const {
        if ( x != t.x ) return x < t.x;
        if ( y != t.y ) return y < t.y;
        return z < t.z;
    }
    bool operator <= ( const triple &t ) const {
        return x <= t.x && y <= t.y && z <= t.z;
    }
};

int T, N;
triple ali, ses;
triple trans[MAXN][2];

int main() {

    cin >> T; while ( T-- ) {

        cin >> ali.x >> ali.y >> ali.z;
        cin >> ses.x >> ses.y >> ses.z;
        cin >> N;

        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < 2; j++ )
                cin >> trans[i][j].x >> trans[i][j].y >> trans[i][j].z;

        queue< triple > Q;
        map< triple, int > used;

        used[ali] = 1;
        bool found = false;
        for ( Q.push( ali ); !Q.empty(); Q.pop() ) {
            triple top = Q.front();
            if ( ses <= top ) {
                cout << used[top] - 1 << endl;
                found = true;
                break;
            }
            for ( int i = 0; i < N; i++ )
                if ( trans[i][0] <= top ) {
                    triple nt;
                    nt.x = top.x - trans[i][0].x + trans[i][1].x;
                    nt.y = top.y - trans[i][0].y + trans[i][1].y;
                    nt.z = top.z - trans[i][0].z + trans[i][1].z;
                    if ( nt.x > LIMIT || nt.y > LIMIT || nt.z > LIMIT )
                        continue;
                    if ( !used[nt] ) {
                        used[nt] = used[top] + 1;
                        Q.push( nt );
                    }
                }
        }
        if ( !found )
            cout << "NIE" << endl;
    }

    return 0;
}
