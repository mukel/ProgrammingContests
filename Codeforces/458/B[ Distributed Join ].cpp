#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int
    MAXN = 1 << 17;
    
int A, B;
unsigned long long a[MAXN];
unsigned long long b[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A;
    cin >> B;
    for (int i = 1; i <= A; ++i)
        cin >> a[i];
    sort(a + 1, a + A + 1);

    for (int i = 1; i <= B; ++i)
        cin >> b[i];
    sort(b + 1, b + B + 1);
    
    for (int i = 1; i <= A; ++i)
        a[i] += a[i -1];

    for (int i = 1; i <= B; ++i)
        b[i] += b[i - 1];
        
    unsigned long long ans =  0x7FFFFFFFFFFFFFFFULL;

    for (int i = B - 1; i >= 0; --i)
    {
        unsigned long long clusters = (B - i);
        unsigned long long t = a[A] * clusters + b[i];
        if (t < ans)
            ans = t;
    }
    
    for (int i = A - 1; i >= 0; --i)
    {
        unsigned long long clusters = (A - i);
        unsigned long long t = b[B] * clusters + a[i];
        //cout << "A " << clusters << " " << t << endl;
        if (t < ans)
            ans = t;
    }
    
    cout << ans << endl;

    return 0;
}