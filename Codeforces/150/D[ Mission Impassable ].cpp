#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int
    MAXN = 155,
    INF = (int)1e9;

string S;
int N;
int remCost[MAXN];
int memo[MAXN][MAXN][MAXN];
int dp[MAXN];

int getPalin(int lo, int hi, int p)
{
    if (p < 0) return -INF;
    if (hi - lo + 1 < p)
        return -INF;

    if (lo > hi)
    {
        if (p == 0) return 0;
        return -INF;
    }

    if (lo == hi)
    {
        if (p == 1) return 0;
        if (p == 0) if (remCost[1] != -1) return remCost[1];
        return -INF;
    }

    int& ret = memo[lo][hi][p];
    if (ret != -1)
        return ret;

    ret = -INF;

    if (p == 0)
    {
        for (int k = 1; k <= (hi - lo + 1); ++k)
            if (remCost[k] != -1)
                ret = max(ret, getPalin(lo, hi, k) + remCost[k]);
        return ret;
    }

    if (S[lo] == S[hi])
        ret = max(ret, getPalin(lo + 1, hi - 1, p - 2));

    for (int k = lo; k < hi; ++k)
    {
        ret = max(ret, getPalin(lo, k, 0) + getPalin(k + 1, hi, p));
        ret = max(ret, getPalin(lo, k, p) + getPalin(k + 1, hi, 0));
    }

    return ret;
}

int main()
{
    memset(memo, -1, sizeof(memo));

    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> remCost[i];

    cin >> S;

    for (int r = 0; r < (int)S.size(); ++r)
    {
        if (r) dp[r] = dp[r - 1];

        for (int l = 0; l <= r; ++l)
        {
            if (l)
                dp[r] = max(dp[r], dp[l - 1] + getPalin(l, r, 0));
            else
                dp[r] = max(dp[r], getPalin(l, r, 0));
        }
    }

    cout << dp[S.size() - 1] << endl;

    return 0;
}
