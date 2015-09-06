#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
    
    int seq[N];
    
    for (int i = 0; i < N; ++i)
        cin >> seq[i];
        
    sort(seq, seq + N);
        
    int maxCount = 0;
    for (int i = 0, j; i < N; i = j) {
        for (j = i + 1; j < N && seq[j] == seq[i]; ++j);
        maxCount = max(maxCount, j - i);
    }
    
    printf( (maxCount > (N+1)/2) ? "NO\n" : "YES\n" );
    
    return 0;
}