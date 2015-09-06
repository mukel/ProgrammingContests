#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int
    MAXV = 100005;

int V, E, Q;
vector< pair<int, int> > edges[MAXV];
vector<int> vertices[MAXV];

vector< unordered_set<int> > colorComps;
int q1[MAXV];
int q2[MAXV];
vector<int> comp[MAXV];

namespace std {
  template <>
  struct hash< pair<int, int> >
  {
    std::size_t operator()(const pair<int, int>& k) const
    {      
      return (k.first ^ (k.second << 10));
    }
  };

}

unordered_map< pair<int, int>, int > answer;
unordered_set< pair<int, int> > queries;

#define ALL(c) (c).begin(), (c).end()

int data[MAXV];

int find(int u) {
    return (data[u] < 0) ? u : data[u] = find(data[u]);
}

int getSize(int u) {
    return -data[find(u)];
}


void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    if (getSize(u) > getSize(v))
        swap(u, v);
    data[u] += data[v];
    data[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        --c;
        
        edges[c].push_back({u, v});
        
        vertices[c].push_back(u);
        vertices[c].push_back(v);
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u > v) swap(u, v);
        q1[i] = u;
        q2[i] = v;
        queries.insert({u, v});
    }

    auto vqueries = vector<pair<int, int>>(ALL(queries));

    for (int c = 0; c < E; ++c) if (!vertices[c].empty()) {
        sort(ALL(vertices[c]));
        vertices[c].erase(unique(ALL(vertices[c])), vertices[c].end());
        
        for (int u : vertices[c]) {
            comp[u].clear();
            data[u] = -1;
        }
        
        for (auto e : edges[c])
            unite(e.first, e.second);

        for (int u : vertices[c])
            comp[ find(u) ].push_back(u);

        for (int u : vertices[c]) if (u == find(u)) {
            /*cout << "Color " << (c+1) << ": ";
            for (auto x: comp[u])
                cout << x << " ";
            cout << endl;*/
            colorComps.push_back(unordered_set<int>(ALL(comp[u])));
        }
    }

    for (auto& cc : colorComps)
    
        if (cc.size() > 250) {
            for (auto q : vqueries) {
                if (cc.count(q.first) && cc.count(q.second))                
                    ++answer[q];
            }
        } else {
            vector<int> vcc(ALL(cc));
            sort(ALL(vcc));
            for (int i = 0; i < (int)vcc.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (queries.count({vcc[j], vcc[i]}))
                    ++answer[{vcc[j], vcc[i]}];
            
        }

    for (int i = 0; i < Q; ++i)
        cout << answer[{q1[i], q2[i]}] << "\n";

    return 0;
}
