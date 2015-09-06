#include <bits/stdc++.h>
using namespace std;

int N, K;

int cost(vector<int>& p)
{
    int cost = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j) {
            int x = p[i];
            for (int k = i; k <= j; ++k)
            {
                x = min(x, p[k]);
            }
            cost += x;
        }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    vector<int> p;  
    for (int i = 0; i < N; ++i)
        p.push_back(i);

    int best = cost(p);

    vector< vector<int> > ans;

    do {
        int t = cost(p);
        if (t == best)
            ans.push_back(p);
        
    } while (next_permutation(p.begin(), p.end()));

    p = ans[K - 1];
    for (auto x : p)
        cout << x+1 << " ";
    
    return 0;
}
