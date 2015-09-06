
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXM = 20000;

int N, M;
int step[MAXM];

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; ++i) cin >> step[i];

    sort(step, step + M);


    if (step[0] == 1 || step[M - 1] == N)
    {
                    cout << "NO" << endl;
                    return 0;
    }

    for (int i = 0; i < M - 2; ++i)
        if (step[i] + 1 == step[i + 1] && step[i + 1] + 1 == step[i + 2])
        {
                cout << "NO" << endl;
                return 0;
        }

    cout << "YES" << endl;

    return 0;
}
