// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 18;

int N, Q;
long long d[MAXN];
long long h[MAXN];

inline long long dist(int lo, int hi) {
    return d[hi] - d[lo];
}

const long long INF = (long long)1e16;

struct node {
    long long maxx;
    long long maxy;
    long long best;
} T[2 * MAXN + 1];

void build(int x, int lo, int hi) {
    if (lo == hi)
    {
        T[x].maxx = 2*h[lo] - d[lo];
        T[x].maxy = 2*h[lo] + d[lo];
        T[x].best = -INF;
        return ;
    }

    int mid = (lo + hi) / 2;

    build(2 * x, lo, mid);
    build(2 * x + 1, mid + 1, hi);

    T[x].maxx = max(T[2*x].maxx, T[2*x + 1].maxx);
    T[x].maxy = max(T[2*x].maxy, T[2*x + 1].maxy);
    T[x].best = max(T[2*x].maxx + T[2*x + 1].maxy,
                    max(T[2*x].best,
                        T[2*x + 1].best));
}

inline node query(int x, int lo, int hi, int start, int end) {
    
    if (lo >= start && hi <= end)
        return T[x];

    int mid = (lo + hi) / 2;
    if (mid + 1 > end)
        return query(2*x, lo, mid, start, end);
    if (mid < start)
        return query(2*x + 1, mid + 1, hi, start, end);

    auto a = query(2*x, lo, mid, start, end);
    auto b = query(2*x + 1, mid + 1, hi, start, end);

    long long best = max(a.maxx + b.maxy, max(a.best, b.best));
    return (node){max(a.maxx, b.maxx), max(a.maxy, b.maxy), best};

    /*
    cout << "## " << start << end << endl;  
    long long r = 0;
    for (int i = start; i <= end; ++i)
        for (int j = i + 1; j <= end; ++j) {
            r = max(r, 2 * (h[i] + h[j]) + dist(i, j));
            cout << "-> dist " << dist(i, j) << endl;
        }
    return r;
    */
}

int main() {    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> d[i + 1];
        d[i + 1 + N] = d[i + 1];
    }

    for (int i = 1; i <= N; ++i)
        cin >> h[i];

    for (int i = 1; i <= N; ++i) {      
        h[i + N] = h[i];
    }

    for (int i = 1; i <= 2*N; ++i)
        d[i] += d[i - 1];
        
    build(1, 1, 2*N);   

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        
        node ans;
        if (a <= b)
            ans = query(1, 1, 2 * N, b + 1, a + N - 1);
        else
            ans = query(1, 1, 2 * N, b + 1, a - 1);
            
        cout << ans.best << &#39;\n&#39;;
    }

    return 0;
}
