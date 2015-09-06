#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    for (int i = 1; i < N; ++i)
    for (int j = 0; j < N; ++j) {
        int cnt = 0;
        for (int k = j; k < N && s[k] == &#39;*&#39;; cnt++, k += i);
        if (cnt >= 5) {
            cout << "yes" << endl;
            exit(0);
        }
    }

    cout << "no" << endl;

    return 0;
}
