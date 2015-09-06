// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/*inclusive*/template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e+1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

const int
    MAXLOG = 20,
    MAXV = 1 << MAXLOG;

int V, Q;
int depth[MAXV];
int lca[MAXV][MAXLOG];

void addLeaf(int parent, int u)
{
    depth[u] = depth[parent] + 1;
    lca[u][0] = parent;
    for (int i = 1; depth[u] - (1 << i) >= 0; ++i)
        lca[u][i] = lca[ lca[u][i - 1] ][i - 1];
}

int getLca(int u, int v)
{
    if (depth[v] > depth[u])
        swap(u, v);

    for (int i = MAXLOG; i >= 0; --i)
        if (depth[u] - (1 << i) >= depth[v])
            u = lca[u][i];

    if (u == v)
        return u;

    for (int i = MAXLOG; i >= 0; --i)
        if (depth[u] - (1 << i) >= 0 && lca[u][i] != lca[v][i])
        {
            u = lca[u][i];
            v = lca[v][i];
        }

    assert(lca[u][0] == lca[v][0]);
    return lca[u][0];
}

int dist(int u, int v)
{
    int z = getLca(u, v);
    return depth[u] + depth[v] - 2 * depth[z];
}

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> Q;

    for (int i: range(1, 3))
        addLeaf(0, i);

    int diameter = 2;
    int d1 = 1, d2 = 2;
    V = 4;

    for (int i: range(Q))
    {
        int v;
        cin >> v;
        --v;

        int a = V++;
        int b = V++;

        addLeaf(v, a);
        addLeaf(v, b);

        int dist1 = dist(a, d1);
        int dist2 = dist(a, d2);

        if (dist1 > diameter) { diameter = dist1; d2 = a; }
        if (dist2 > diameter) { diameter = dist2; d1 = a; }
        cout << diameter << endl;
    }

    return 0;
}
