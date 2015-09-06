#include <bits/stdc++.h>
using namespace std;

int N, K;
bool M[1000][1000];


void no_solution()
{
    cout << -1 << endl;
    exit(0);
}

int main() {

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int step = 1;
    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < N; ++j)
            M[j][(j + step) % N] = true;

        step++;
    }

    vector< pair< int, int > > ans;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (M[i][j]) ans.push_back( make_pair(i, j) );

            if (M[i][j] && M[j][i])
                no_solution();
        }

    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << (ans[i].first + 1) << " " << (ans[i].second + 1) << "\n";

    return 0;
}
