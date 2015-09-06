// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    

const int
    MAXN = 2005;
    
int N;
int d[MAXN][MAXN];
int best[MAXN];
int from[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

int final[MAXN][MAXN];

void no() {
    cout << "NO" << endl;
    exit(0);
}

int src;

void dfs(int u)
{
    mark[u] = true;
    for (int v: G[u]) if (!mark[v]) {
        final[src][v] = final[src][u] + d[u][v];
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
        cin >> d[i][j];
    }
    
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
    {
        if (i == j) {
            if (d[i][j] != 0) no();
        }
        else {
            if (d[i][j] == 0 || d[i][j] != d[j][i]) no();
        }
    }

    from[0] = -1;
    fill(best, best + N, (int)2e9 + 1);
    best[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        int k = -1;
        for (int j = 0; j < N; ++j)
        if (!mark[j] && (k < 0 || best[j] < best[k]))
            k = j;
        mark[k] = true;
        for (int j = 0; j < N; ++j) if (!mark[j])
            if (d[k][j] < best[j]) {
                best[j] = d[k][j];
                from[j] = k;
            }
    }

    for (int i = 0; i < N; ++i)
        if (from[i] >= 0) {
            int j = from[i];
            G[i].push_back(j);
            G[j].push_back(i);
        }

    for (int i = 0; i < N; ++i) {
        memset(mark, 0, sizeof(mark));
        src = i;
        dfs(i);
    }

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
        if (final[i][j] != d[i][j])
            no();
    
    cout << "YES" << endl;
    
    return 0;
}