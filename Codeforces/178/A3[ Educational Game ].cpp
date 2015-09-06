// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

const int
    MAXN = 1 << 17;

int N;
int64 A[MAXN];
int64 answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> A[i];

    REP(i, N - 1)
    {
        answer += A[i];
        int t = 1;
        while (i + 2 * t < N) t *= 2;
        A[i + t] += A[i];
        cout << answer << "\n";
    }

    return 0;
}
