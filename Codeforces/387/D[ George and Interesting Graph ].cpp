// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/* inclusive */template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e + 1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

const int
    MAXV = 505;

int V, E;
int center;
int M[MAXV][MAXV];
vector< int > G[MAXV];

int curMark;
int mark[MAXV];
int from[MAXV];

bool dfs(int u)
{
    if (mark[u] == curMark)
        return false;

    mark[u] = curMark;

    for (int v: G[u]) if (v != center)
        if (from[v] < 0 || dfs(from[v]))
        {
            from[v] = u;
            return true;
        }

    return false;
}

int solve()
{
    int used = 0;

    memset(from, -1, sizeof(from));

    for (int u: range(V)) if (u != center)
    {
        curMark++;
        if (dfs(u)) used++;
    }

    int toAdd = 0;
    int toRemove = 0;

    for (int u: range(V))
    {
        if (!M[u][center]) toAdd++;

        if (u != center)
        {
            if (!M[center][u]) toAdd++;

            for (int v: range(V)) if (v != center)
                if (M[u][v] && from[v] != u) toRemove++;
        }
    }

    //cout << toAdd << " " << toRemove << " "<< used << endl;

    return toAdd + toRemove + V - 1 - used;
}

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (int i: range(E))
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        M[u][v] = true;
        G[u].push_back(v);
    }

/*
    center = 2;
    cout << solve() << endl;
    return 0;
*/
    int ans = 1000000;
    for (center = 0; center < V; ++center)
    {
        ans = min(ans, solve());
    }

    cout << ans << endl;

    return 0;
}
