/*
Alfonso Alfonso Peterssen
22 - 2 - 2008
IOI 2007 Day 0 "Robot"
*/
#include <iostream>

using namespace std;

const int MAXC = 1100;
const int delta[4][2] =
    {{-1,0},{1,0},{0,-1},{0,1}};

const string cmd[] =
    { "left", "right", "down", "up" };

int area;
bool used[2 * MAXC][2 * MAXC];

    bool move( int dir ) {
        cout << cmd[dir] << endl;
        string answer;
        cin >> answer;
        return answer == "ok";
    }

    int dfs( int x, int y, int from ) {
        area++;
        used[x][y] = true;
        for ( int i = 0; i < 4; i++ ) {
            int nx = x + delta[i][0];
            int ny = y + delta[i][1];
            if ( !used[nx][ny] && move( i ) )
                 dfs( nx, ny, i ^ 1 );
            else used[nx][ny] = true;
        }
        move( from );
    }

int main() {
    dfs( MAXC, MAXC, 0 );
    cout << area << endl;
    return 0;
}
