#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int64 MOD = 1000000007;

const int
    MAXV = 1 << 17;
    
int V, E;
int data[MAXV];
int components;
vector<int> hate[MAXV];
vector<int> love[MAXV];

int findSet(int x) {
    return data[x] < 0 ? x : data[x] = findSet(data[x]);
}

int getSize(int x) {
    return -data[findSet(x)];
}

void join(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v)
        return ;        
        
        
    components--;

    if (getSize(u) > getSize(v))
        swap(u, v);     
        
    data[u] += data[v];
    data[v] = u;
}

int mark[MAXV][2];
int curMark;

void dfs(int u, int x) {    
    if (mark[u][1 - x] == curMark) {
        cout << 0 << endl;
        exit(0);
    }
    if (mark[u][x] == curMark)
        return ;
    mark[u][x] = curMark;   
    for (int v : love[u]) dfs(v, x);
    for (int v : hate[u]) dfs(v, 1 - x);
}

int main() {
    ios_base::sync_with_stdio(0);
    
    memset(data, -1, sizeof(data));
    
    cin >> V >> E;
    
    components = V;
    
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        if (w == 0) {
            hate[u].push_back(v);
            hate[v].push_back(u);
        } else {
            love[u].push_back(v);
            love[v].push_back(u);
        }
        join(u, v);
    }

    // search for cycles with odd number of hate relations
    for (int i = 0; i < V; ++i) if (data[i] < 0) {
        curMark++;
        dfs(i, 0);
    }
    
    int64 result = 1;
    for (int i = 0; i < components - 1; ++i)
        result = 2 * result % MOD;
        
    cout << result << endl;     
    
    return 0;
}
