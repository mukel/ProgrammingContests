// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

const int
    MAXV = 1 << 17;

int V;
vector< int > G[MAXV];
int goal[MAXV];
int init[MAXV];
vector< int > ans;

void dfs(int u, int from, bool flip, bool ignoreLevel)
{
    if (!ignoreLevel)
    {
        if (flip)
            init[u] = !init[u];
        
        if (init[u] != goal[u]) {
            ans.push_back(u);
            flip = !flip;
        }
    }
    
    for (int v: G[u]) if (v != from)
        dfs(v, u, flip, !ignoreLevel);
}

int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V;
    
    for (int i = 0; i < V - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int i = 0; i < V; ++i)
        cin >> init[i];
    
    for (int i = 0; i < V; ++i)
        cin >> goal[i];
    
    dfs(0, -1, false, false);
    
    for (int u: G[0])
        dfs(u, 0, false, false);
    
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int x : ans)
        cout << (x + 1) << "\n";

    return 0;
}