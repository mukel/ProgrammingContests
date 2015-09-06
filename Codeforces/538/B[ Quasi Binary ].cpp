#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = (int)1e6 + 5;

int N;
vector<int> nums;

void gen(int x) {
    if (x > MAXN) return ;
    nums.push_back(x);
    gen(x * 10);
    gen(x * 10 + 1);
}



int from[MAXN];
int dp[MAXN];

void rec(int n) {
    if (n == 0) return ;
    rec(n - from[n]);
    cout << from[n] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    gen(1);

    sort(nums.begin(), nums.end());

    for (int i = 1; i < MAXN; ++i) {
        dp[i] = i + 1;
        for (int j = 0; j < nums.size(); ++j) {
            int prev = i - nums[j];
            if (prev < 0) break;
            int t = dp[prev] + 1;
            if (t < dp[i]){
                dp[i] = t;
                from[i] = nums[j];
            }
        }
    }

    cin >> N;
    cout << dp[N] << endl;
    rec(N);


    return 0;
}
