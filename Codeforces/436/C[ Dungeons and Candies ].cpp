#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int
    MAXN = 1 << 10,
    MAXC = 11;

int R, C, N, W;
char board[MAXN][MAXC][MAXC];
int cost[MAXN][MAXN];
bool mark[MAXN];
int dist[MAXN];
int from[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> N >>  W;
    for (int i = 0; i < N; ++i)
    {
        for (int r = 0; r < R; ++r)
            cin >> board[i][r];
    }
    
    for (int i = 0; i < N; ++i)
    {
        int best = R * C;
        int bestIndex = i;
        
        for (int j = 0; j < i; ++j)
        {
            register int dif = 0;
            for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                dif += board[i][r][c] != board[j][r][c];

            cost[i][j] = cost[j][i] = min(R * C,  dif * W);
        }
    }
    
    for (int i = 0; i < N; ++i)
    {
        dist[i] = R * C;
        from[i] = -1;
    }

    vector< pair< int, int > > edges;
    
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int best = -1;
        for (int j = 0; j < N; ++j) if (!mark[j])
            if (best < 0 || dist[j] < dist[best])
                best = j;
                
        edges.push_back({best + 1, (from[best] < 0) ? 0 : (from[best] + 1)});
                
        mark[best] = true;
        ans += dist[best];
                
        for (int j = 0; j < N; ++j) if (!mark[j])
        {
            int t = cost[best][j];
            if (t < dist[j])
            {
                dist[j] = t;
                from[j] = best;
            }
        }
    }
    
    cout << ans << endl;
    for (int i = 0; i < edges.size(); ++i)
        cout << edges[i].first << " " << edges[i].second << &#39;\n&#39;;
    
    return 0;
}