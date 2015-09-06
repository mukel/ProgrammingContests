#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

const int
    MAXC = 1005;
int R, C;
string s[MAXC];
bool ok[MAXC];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        cin >> s[i];
        
    for (int j = 0; j < C; ++j) {
        
        bool er = false;
        for (int i = 1; i < R; ++i)
            if (s[i][j] < s[i - 1][j] && !ok[i]) {
                er = true;
                break;
            }
    
        if (er) {
            ans++;
        } else {
            for (int i = 1; i < R; ++i)
                if (s[i][j] > s[i - 1][j])
                    ok[i] = true;
            
        }
    }
        
    cout << ans << "\n";
    
    return 0;
}
