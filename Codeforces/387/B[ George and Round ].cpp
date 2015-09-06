// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/* inclusive */template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e + 1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

const int
    MAXN = 3005;

int N, M;
int dp[MAXN][MAXN];
int a[MAXN];
int b[MAXN];

int solve(int n, int m)
{
    if (m < 0)
    {
        if (n < 0) return 0;
        return n + 1;
    }

    if (n < 0) return 0;

    int & r = dp[n][m];
    if (r != -1) return r;

    r = N;
    if (a[n] <= b[m]) r = solve(n - 1, m - 1);
    r = min(r, solve(n - 1, m) + 1);

    return r;
}

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;

    for (int i : range(N)) cin >> a[i];
    for (int i : range(M)) cin >> b[i];

    cout << solve(N - 1, M - 1) << endl;

    return 0;
}
