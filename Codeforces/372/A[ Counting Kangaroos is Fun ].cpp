// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>

#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int N;
int s[1 << 20];
int ans, pos;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> s[i];

    sort(s, s + N);

    int lo = 0, hi = N/2;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        bool ok = true;

        for (int a = 0, b = N - mid; a < mid; ++a, ++b)
        {
            if (2 * s[a] > s[b])
                ok = false;
        }

        if (ok)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cout << N - (lo-1) << endl;

    return 0;
}
