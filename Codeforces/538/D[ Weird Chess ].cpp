#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 60;

int N;
char board[MAXN][MAXN];
char ans[2 * MAXN][2 * MAXN];

int S[2 * MAXN][2 * MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
        if (board[i][j] == &#39;o&#39;) {
            for (int a = 0; a < N; ++a)
            for (int b = 0; b < N; ++b) {
                if (board[a][b] == &#39;.&#39;)
                    S[a - i + N][b - j + N] = 1; // no attack
            }
        }
    }

    for (int a = 0; a < N; ++a)
    for (int b = 0; b < N; ++b) if (board[a][b] == &#39;x&#39;) {

        bool found = false;

        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) if (board[i][j] == &#39;o&#39;)
            if (!S[a - i + N][b - j + N]) {
                found = true;
                goto skip;
            }
        skip:;
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for (int i = -(N-1); i < N; ++i)
    for (int j = -(N-1); j < N; ++j) if (S[i + N][j + N])
        ans[i + N - 1][j + N - 1] = &#39;.&#39;;
    else
        ans[i + N - 1][j + N - 1] = &#39;x&#39;;

    ans[N-1][N-1] = &#39;o&#39;;
    for (int i = 0; i < 2*N-1; ++i)
        cout << ans[i] << endl;


    return 0;
}
