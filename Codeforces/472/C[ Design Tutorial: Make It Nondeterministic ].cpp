// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    

const int
    MAXN = 100005;
    
int N;
string a[MAXN];
string b[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }
    
    string prev = "";
    for (int i = 0; i < N; ++i)
    {
        int p;
        cin >> p;
        --p;
        if (a[p] > prev) prev = a[p];
        else
        if (b[p] > prev) prev = b[p];
        else {
            cout << "NO" << endl;
            exit(0);
        }
    }
    
    cout << "YES" << endl;
    
    return 0;
}