// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

const int
    MAXC = 1 << 10;

int R, C;
int a[MAXC][MAXC];

int upRight[MAXC][MAXC];
int upLeft[MAXC][MAXC];
int downRight[MAXC][MAXC];
int downLeft[MAXC][MAXC];

int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;  
    for (int i = 1; i <= R; ++i)
    for (int j = 1; j <= C; ++j)
        cin >> a[i][j];
    
    for (int i = 1; i <= R; ++i)
    for (int j = 1; j <= C; ++j)
        downRight[i][j] = max(downRight[i - 1][j], downRight[i][j - 1]) + a[i][j];
    
    for (int i = R; i >= 1; --i)
    for (int j = 1; j <= C; ++j)
        upRight[i][j] = max(upRight[i + 1][j], upRight[i][j - 1]) + a[i][j];
    
    for (int i = 1; i <= R; ++i)
    for (int j = C; j >= 1; --j)
        downLeft[i][j] = max(downLeft[i - 1][j], downLeft[i][j + 1]) + a[i][j];
    
    for (int i = R; i >= 1; --i)
    for (int j = C; j >= 1; --j)
        upLeft[i][j] = max(upLeft[i + 1][j], upLeft[i][j + 1]) + a[i][j];
    
    int ans = 0;
    for (int i = 2; i < R; ++i)
    for (int j = 2; j < C; ++j)
    {
        int r0 = i - 1;
        int c0 = j;
        
        int r1 = i + 1;
        int c1 = j;
        
        int r2 = i;
        int c2 = j - 1;
        
        int r3 = i;
        int c3 = j + 1;
        
        int t1 = downRight[r0][c0] + upLeft[r1][c1];
        int t2 = upRight[r2][c2] + downLeft[r3][c3];
        ans = max(ans, t1 + t2);
        
        t1 = downRight[r2][c2] + upLeft[r3][c3];
        t2 = upRight[r1][c1] + downLeft[r0][c0];
        ans = max(ans, t1 + t2);
    }
    
    cout << ans << endl;
    
    return 0;
}