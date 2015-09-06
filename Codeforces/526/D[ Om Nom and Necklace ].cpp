#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 20;

int N, K;
char S[MAXN];
int pre[MAXN];
bool ans[MAXN];
int delta[MAXN];

void z_func(char* s, int n, int *z) {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

int zf[MAXN];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> N >> K;
    cin >> (S + 1);

    int j = 0;
    for (int i = 2; i <= N; i++) {
        while (j && S[j + 1] != S[i])
            j = pre[j];
        if (S[j + 1] == S[i])
            j++;
        pre[i] = j;
    }


    z_func(S + 1, N, zf + 1);

    for (int i = 1; i <= N; ++i) {

        int j = pre[i];
        int cnt = i / (i - j);
        int size = i - j;
        if (i % size == 0) {
            if (cnt % K == 0) {
                int maxP = zf[i + 1];
                int maxA = i / K;
                maxA = min(maxA, maxP);
                ++delta[i];
                --delta[i + maxA + 1];
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += delta[i];
        if (sum) cout << &#39;1&#39;; else cout << &#39;0&#39;;
    }
    cout << endl;

    return 0;
}
