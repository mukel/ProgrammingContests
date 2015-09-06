// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    

const int
    MAXN = 1000005;
    
int N;
bool mark[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 2; i < MAXN; ++i)
    if (!mark[i]) {
        for (int j = 2 * i; j < MAXN; j += i)
            mark[j] = true;
    }
    
    for (int i = 4; i < N; ++i)
    if (mark[i] && N - i > 3 && mark[N - i])
    {
        cout << i << " " << N - i << endl;
        return 0;
    }
    

    return 0;
}