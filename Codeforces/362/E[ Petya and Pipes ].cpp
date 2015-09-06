// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long int64;

#define endl &#39;\n&#39;
#define SZ(c) ((int)((c).size()))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
    MAXV = 100,
    INF = (int)1e9;

int V, K;
int cap[MAXV][MAXV];

struct edge
{
    int u, v, cap, w, sibl;
};

typedef pair< int, int > par;

int head[MAXV];
int E;
edge edges[MAXV * MAXV * 10];

int flow[MAXV];
int from[MAXV];
int cost[MAXV];
bool inQueue[MAXV];

void add_edge(int u, int v, int cap, int w)
{
    edges[E] = (edge){u, v, cap, w, head[u]};
    head[u] = E++;

    edges[E] = (edge){v, u, 0, -w, head[v]};
    head[v] = E++;
}

par augment(int source, int sink, bool useExtra)
{
    queue< int > Q;

    fill_n(cost, V, INF);
    fill_n(inQueue, V, false);
    
    cost[source] = 0;
    flow[source] = useExtra ? 1 : INF;
    from[source] = -1;
    
    for (Q.push(source); !Q.empty(); )
    {
        int u = Q.front();
        inQueue[u] = false;
        Q.pop();
        
        for (int e = head[u]; e != -1; e = edges[e].sibl)
            if (edges[e].cap > 0)
            {
                if (!useExtra && edges[e].w != 0)
                    continue ;
                
                int v = edges[e].v;
                int w = edges[e].w;
                if (cost[u] + w < cost[v])
                {
                    cost[v] = cost[u] + w;
                    flow[v] = min(flow[u], edges[e].cap);
                    from[v] = e;
                    if (!inQueue[v]) {
                        Q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
    }
    
    if (cost[sink] == INF)
        return make_pair(0, 0);
        
    // reflow
    
    //cout << "Path => " << sink + 1 << " ";
    
    for (int e = from[sink]; e != -1; e = from[ edges[e].u ])
    {
        //cout << edges[e].u  + 1 << " ";
        edges[e].cap -= flow[sink];
        edges[e^1].cap += flow[sink];
    }
    
    //cout << endl;

    // cost, flow
    return make_pair(cost[sink], flow[sink]);
}

int main()
{
    ios::sync_with_stdio(0);    
    
    cin >> V >> K;
    
    fill_n(head, V, -1);
    
    REP(u, V)
    REP(v, V)
    {   
        int cap; cin >> cap;
        if (cap != 0)
        {
            add_edge(u, v, cap, 0);
            if (u != v)
                add_edge(u, v, INF, 1);
        }   
    }
    
    int totalCost = 0, totalFlow = 0;
    
    while (true)
    {
        par w = augment(0, V - 1, false);
        
        //int c = w.first;
        int f = w.second;
        if (f == 0)
            break;
        totalFlow += f; 
    }

    while (true)
    {
        par w = augment(0, V - 1, true);

        int c = w.first;
        int f = w.second;
        
        if (f == 0)
            break;
    
        if (totalCost + c * f > K)
            break;

        totalCost += c * f;
        totalFlow += f;
    }
    
    cout << totalFlow << endl;
    
    return 0;
}
