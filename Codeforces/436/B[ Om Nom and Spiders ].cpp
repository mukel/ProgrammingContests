#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int
    MAXC = 2005;

int R, C, S;
string board[MAXC];
int ans[MAXC];

bool ok(int nr, int nc)
{
    return (nr >= 0 && nr < R && nc >= 0 && nc < C);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> S;
    for (int i = 0; i < R; ++i)
        cin >> board[i];
        
    for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
    {
        int d = i;
        
        int nr = 2*d;
        int nc = j;
        if (ok(nr, nc) && board[nr][nc] == &#39;U&#39;) ans[j]++;
        
        nr = i;
        nc = j - d;
        if (ok(nr, nc) && board[nr][nc] == &#39;R&#39;) ans[j]++;
        
        nr = i;
        nc = j + d;
        if (ok(nr, nc) && board[nr][nc] == &#39;L&#39;) ans[j]++;
    }
    
    for (int i = 0; i < C; ++i)
        cout << ans[i] << " ";
    
    return 0;
}