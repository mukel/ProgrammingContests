// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

const int
    MAXR = 2001;
int R, C;
string board[MAXR];
char deg[MAXR][MAXR];

typedef pair<int, int> par;

vector<par> pos[5];

const int
    offset[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}}; // ESWN

void not_unique() {
    cout << "Not unique" << endl;
    exit(0);
}

void calc_deg() {
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == &#39;.&#39;) {
                if (i + 1 < R && board[i + 1][j] == &#39;.&#39;) {
                    deg[i][j]++;
                    deg[i + 1][j]++;
                }
                if (j + 1 < C && board[i][j + 1] == &#39;.&#39;) {
                    deg[i][j]++;
                    deg[i][j + 1]++;
                }
            }   
}

int main() {
    
    ios_base::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> board[i];

    calc_deg();

    queue<par> Q;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) if (board[i][j] == &#39;.&#39;) {
            if (!deg[i][j]) not_unique();
            if (deg[i][j] == 1) {
                Q.push({i, j});
            }
        }
    
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        int r = p.first;
        int c = p.second;
        if (board[r][c] == &#39;.&#39;) {
            for (int k = 0; k < 4; ++k) {
                int nr = r + offset[k][0];
                int nc = c + offset[k][1];
                if (nr < 0 || nr >= R) continue ;
                if (nc < 0 || nc >= C) continue ;
                if (board[nr][nc] == &#39;.&#39;) {

                    board[r][c]   = "<^>v"[k]; // ESWN
                    board[nr][nc] = ">v<^"[k];

                    for (int m = 0; m < 4; ++m) {
                        int mr = nr + offset[m][0];
                        int mc = nc + offset[m][1];
                        if (mr < 0 || mr >= R) continue ;
                        if (mc < 0 || mc >= C) continue ;
                        if (board[mr][mc] == &#39;.&#39;) {
                            deg[mr][mc]--;
                            if (deg[mr][mc] == 1)
                                Q.push({mr, mc});
                        }
                    }                   
                    deg[r][c]--;
                    deg[nr][nc]--;
                    break;
                }
            }
        }       
    }

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == &#39;.&#39;) {
                not_unique();
            }

    for (int i = 0; i < R; ++i)
        cout << board[i] << &#39;\n&#39;;

    return 0;
}
