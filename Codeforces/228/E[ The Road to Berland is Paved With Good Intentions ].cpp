#include <bits/stdc++.h>
using namespace std;

#define ALL(c) (c).begin(), (c).end()

struct SAT2 {
    int V, discover_time, scc_count;
    vector<int> dfsnum, low, scc;
    vector<vector<int>> G;
    stack<int> S;

    SAT2(int V) :
        V(V), discover_time(0), scc_count(0),
        dfsnum(2*V), low(2*V), scc(2*V), G(2*V) {
    }

    #define NOT(x) ((x) < V ? (x) + V : (x) - V)

    void addOR(int u, int v) {      
        G[NOT(u)].push_back(v);
        G[NOT(v)].push_back(u);
    }

    void addIMPLIES(int u, int v) {
        G[u].push_back(v);
        G[NOT(v)].push_back(NOT(u));
    }

    void addEQUAL(int u, int v) {
        addIMPLIES(u, v);
        addIMPLIES(v, u);
    }

    void addXOR(int u, int v) {
        addIMPLIES(u, NOT(v));
        addIMPLIES(v, NOT(u));
        addIMPLIES(NOT(u), v);
        addIMPLIES(NOT(v), u);
    }

    void dfs(int u) {
        low[u] = dfsnum[u] = ++discover_time;       
        S.push(u);
        for (int v : G[u]) {
            if (!dfsnum[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else
                if (!scc[v])
                    low[u] = min(low[u], dfsnum[v]);
        }
        if (low[u] == dfsnum[u]) {
            for (++scc_count; !scc[u]; S.pop())
                scc[S.top()] = scc_count;
        }
    }
    
    bool solve(vector<bool>& result) {
        result.assign(V, false);
        for (int u = 0; u < V; ++u) {
            if (!dfsnum[u]) dfs(u);
            if (!dfsnum[NOT(u)]) dfs(NOT(u));
            
            if (scc[u] == scc[NOT(u)])
                return false;
            result[u] = (scc[u] < scc[NOT(u)]);
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    int V, E;
    cin >> V >> E;
    SAT2 sat2(V);   
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        if (c)
            sat2.addEQUAL(u, v);
        else
            sat2.addXOR(u, v);
    }

    vector<bool> ans;
    
    if (sat2.solve(ans)) {
        cout << count(ALL(ans), true) << endl;
        for (int i = 0; i < V; ++i)
            if (ans[i])
                cout << i+1 << " ";
    } else
        cout << "Impossible" << endl;
    
    return 0;   
}
