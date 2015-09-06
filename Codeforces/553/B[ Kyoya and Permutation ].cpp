#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int N;
int64 K;
int64 fib[60];

int main() {
    ios_base::sync_with_stdio(0);
    
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < 60; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    cin >> N >> K;
    
    int curFib = N;
    for (int i = 1; i <= N;)
        if (K <= fib[curFib - 1]) {
            cout << i << " ";
            i++;
            curFib--;
        } else {            
            K -= fib[curFib - 1];
            cout << i+1 << " " << i << " ";
            i += 2 ;
            curFib -= 2;
        }

    return 0;
}
