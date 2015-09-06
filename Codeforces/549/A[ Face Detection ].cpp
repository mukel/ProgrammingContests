#include <bits/stdc++.h>
using namespace std;

int R, C;
string board[100];
int ans; 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> board[i];
        
    for (int i = 0; i + 1 < R; ++i)
    for (int j = 0; j + 1 < C; ++j) {
        string s = "####";
        s[0] = board[i][j];
        s[1] = board[i + 1][j];
        s[2] = board[i][j + 1];
        s[3] = board[i + 1][j + 1];
        sort(s.begin(), s.end());
        if (s == "acef")
            ans++;      
    }
    
    cout << ans << endl;
    
    
    return 0;
}
