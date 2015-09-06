#include <bits/stdc++.h>
using namespace std;

const int
    MAXK = 1 << 12;

int N;
int a[MAXK];
int ans;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 2; i <= (1 << (N+1)) - 1; ++i)
        cin >> a[i];

    for (int i = (1 << N) - 1; i >= 1; --i) {
        a[i] += max(a[2 * i], a[2 * i + 1]);
        ans += abs(a[2 * i] - a[2 * i + 1]);
    }

    cout << ans << endl;

    return 0;
}
