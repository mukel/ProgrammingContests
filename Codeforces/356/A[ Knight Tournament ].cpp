// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>

#include <algorithm>
#include <vector>
#include <set>
#include <map>

#include <cstring>
#include <cmath>
#include <cstring>

using namespace std;

#define endl (&#39;\n&#39;)
#define SZ(c) ((int)(c).size())
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
    MAXN = 1 << 20;

int N, Q;
int ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> Q;

    set< int > S;

    for (int i = 1; i <= N; ++i)
        S.insert(i);

    REP(i, Q)
    {
        int lo, hi, winner;
        cin >> lo >> hi >> winner;

        set< int >::iterator it = S.lower_bound(lo);
        set< int >::iterator p = S.upper_bound(hi);

        while (it != p)
        {
            if (*it >= lo && *it <= hi)
                if (*it != winner)
                    ans[*it] = winner;
            ++it;
        }

        S.erase(S.lower_bound(lo), S.upper_bound(hi));
        S.insert(winner);
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << " ";

    return 0;
}
