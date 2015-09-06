// Alfonso2 Peterssen
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int   
    MAXN = 5005;
    
int N;
int p[MAXN];
int sum[MAXN][MAXN];

int qLessThan(int x, int lo, int hi)
{
    if (lo > hi)
        return 0;
    
    return sum[x][hi] - sum[x][lo - 1];
}

int qGreaterEqThan(int x, int lo, int hi)
{
    if (lo > hi)
        return 0;
        
    return (hi - lo + 1) - qLessThan(x, lo, hi);
}

int main()
{
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
        cin >> p[i];
        
    for (int i = 0; i < N; ++i)
            for (int j = 1; j <= N; ++j)
                sum[i][j] = sum[i][j - 1] + (p[j] < i);
                
    int ans = 1 << 20, cnt = 0;
                
    for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j)
    {
        // swap i and j
        
        int li = qLessThan(p[i], i + 1, j - 1);
        int gi = qGreaterEqThan(p[i], i + 1, j - 1);
        
        int lj = qLessThan(p[j], i + 1, j - 1);
        int gj = qGreaterEqThan(p[j], i + 1, j - 1);
        
        int inv = (gi - li) + (lj - gj) + (p[i] < p[j]) - (p[i] > p[j]);
        
        //cout << i << " " << j << " " << inv << endl;
        
        if (inv < ans)
        {
            ans = inv;
            cnt = 0;
        }
        
        if (inv == ans)
            cnt++;
    }
    
    for (int i = N; i >= 1; --i)
        ans += qLessThan(p[i], i + 1, N);
    
    cout << ans << " " << cnt << endl;

    return 0;
}

