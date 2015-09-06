// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <sstream>
#include <cstdio>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)(b); i < (int)(e); ++i)

const int
    MAXN = 1 << 17;

int N, P, K;

struct order
{
    int a, b, index;
};

bool operator < (const order & f, const order & s)
{
    if (f.b != s.b) return f.b < s.b;
    return f.a > s.a;
}

order orders[MAXN];

int64 maxKa[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(0);

    cin >> N >> P >> K;

    REP(i, N)
    {
        cin >> orders[i].a >> orders[i].b;
        orders[i].index = i;
    }

    sort(orders, orders + N);

    multiset< int, greater< int > > S;
    int64 sum = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        int64 a = orders[i].a;
        sum += a;
        S.insert(a);
        if (S.size() > K)
        {
            multiset< int, greater< int > >::iterator it = S.end();
            --it;
            sum -= *it;
            S.erase(it);
        }
        maxKa[i] = sum;
    }

    int pos = P - K;
    while (pos < N && maxKa[P - K] == maxKa[pos])
        pos++;
    pos--;

    vector< pair< int, int > > O;
    for (int i = pos; i < N; ++i)
        O.push_back(make_pair(orders[i].a, orders[i].index));

    sort(ALL(O), greater< pair< int, int > >() );
    for (int i = 0; i < K; ++i)
        cout << O[i].second + 1 << " ";

    vector< pair< int, int > > D;
    for (int i = 0; i < pos; ++i)
        D.push_back(make_pair(orders[i].b, orders[i].index));

    sort(ALL(D), greater< pair< int, int > >() );

    for (int i = 0; i < P - K; ++i)
            cout << D[i].second + 1 << " ";

    return 0;
}
