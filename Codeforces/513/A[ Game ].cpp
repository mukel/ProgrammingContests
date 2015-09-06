#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    if (n1 <= n2)
        cout << "Second" << endl;
    else
        cout << "First" << endl;

    return 0;
}
