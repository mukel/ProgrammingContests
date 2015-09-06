#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
#define endl (&#39;\n&#39;)

const int
    MAXN = 1 << 18;
    
int N;
char A[MAXN];
char B[MAXN];

void normalize(char* s, int n) {
    if (n % 2 == 1)
        return ;
    int mid = n / 2;
    normalize(s, mid);
    normalize(s + mid, mid);
    int cmp = memcmp(s, s + mid, mid);
    if (cmp > 0) {
        for (int i = 0; i < mid; ++i)
            swap(s[i], s[i + mid]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef LOCAL
        cin.tie(0);
    #endif
    
    cin >> A >> B;
    N = strlen(A);
    
    normalize(A, N);
    normalize(B, N);

    cout << ((strcmp(A, B) == 0) ? "YES" : "NO") << endl;
    
    return 0;
}
