#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;
vector< int > t[2];
long long sum[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    bool last = false;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        long long a;
        cin >> a;
        last = (a < 0);
        t[last].push_back(abs(a));
        sum[last] += abs(a);
    }

    if (sum[0] > sum[1] || (sum[0] == sum[1] && t[0] > t[1]) || (sum[0] == sum[1] && t[0] == t[1] && !last) )
        cout << "first" << endl;
    else
        cout << "second" << endl;
    
    return 0;
}