#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[100];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
        
    int g = a[0];
    for (int i = 1; i < N; ++i)
        g = gcd(g, a[i]);
        
    int m = *max_element(a, a + N);
        
    int ans = m / g - N;
    
    cout << (ans % 2 == 1 ? "Alice" : "Bob");
        
    return 0;
}
