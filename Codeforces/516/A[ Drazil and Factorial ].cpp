// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

int N;
string S;
vector<int> f[10];
int cnt[10];

int main() {
    ios_base::sync_with_stdio(0);
    
    f[2] = {2};
    f[3] = {3};
    f[4] = {3, 2, 2};
    f[5] = {5};
    f[6] = {5, 3};
    f[7] = {7};
    f[8] = {7, 2, 2, 2};
    f[9] = {2, 3, 3, 7};

    cin >> N;
    cin >> S;
    for (char c : S) {
        int d =  c - &#39;0&#39;;
        if (d <= 1) continue ;
        for (int p : f[d])
            cnt[p]++;
    }

    for (int i = 9; i > 1; --i)
        for (int j = 0; j < cnt[i]; ++j)
            cout << i;

    cout << endl;

    return 0;
}
