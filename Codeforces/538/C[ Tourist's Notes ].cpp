#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 18;

int D, N;

int d[MAXN];
int h[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> D >> N;
    for (int i = 0; i < N; ++i) {
        cin >> d[i] >> h[i];
    }

    int ans = h[0] + (d[0] - 1);
    for (int i = 1; i < N; ++i) {
        int dh = h[i] - h[i - 1];
        int dd = d[i] - d[i - 1];
        if (dd < abs(dh)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        int diff = dd - abs(dh);
        ans = max(ans, max(h[i], h[i - 1]) + diff / 2);
    }

    ans = max(ans, h[N - 1] + (D - d[N - 1]));

    cout << ans << endl;

    return 0;
}
