// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    

int p[8][3];

inline long long dot(int a[], int b[], int c[]) {
    long long x = (a[0] - b[0]) * (long long)(c[0] - b[0]);
    long long y = (a[1] - b[1]) * (long long)(c[1] - b[1]);
    long long z = (a[2] - b[2]) * (long long)(c[2] - b[2]); 
    return x + y + z;
}

inline long long sqr(int x)
{
    return x * (long long)x;
}

inline long long dist(int a[], int b[])
{
    return sqr(a[0] - b[0]) + sqr(a[1] - b[1]) + sqr(a[2] - b[2]);
}

int cnt;
long long vals[64];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> p[i][j];

        sort(p[i], p[i] + 3);
    }
    
    do { do { do { do { do { do { do {
    //do {
        
        int diag = 0;
        for (int i = 0; i < 8; ++i) {
            
            for (int j = 0; j < 8; ++j) if (j != i) {
                bool ok = true;
                for (int k = 0; k < 8; ++k) if (k != i && k != j)
                {
                    if (dot(p[i], p[k], p[j]) != 0) {
                        ok = false;
                        break;
                    }   
                }
                if (ok) {
                    diag++;
                    break;
                }
            }
            
            if (diag <= i)
                break;
        }
        
        if (diag == 8)
        {   
            cnt = 0;
            for (int i = 0; i < 8; ++i)
            for (int j = i + 1; j < 8; ++j)
                vals[cnt++] = dist(p[i], p[j]);

            sort(vals, vals + cnt);
            cnt = unique(vals, vals + cnt) - vals;
            
            if (cnt == 3)
            {
                cout << "YES" << endl;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 3; j++)
                        cout << p[i][j] << " ";
                    cout << endl;
                }
                
                return 0;
            }
        }
        
    //} while (next_permutation(p[0], p[0] + 3));
    } while (next_permutation(p[1], p[1] + 3));
    } while (next_permutation(p[2], p[2] + 3));
    } while (next_permutation(p[3], p[3] + 3));
    } while (next_permutation(p[4], p[4] + 3));
    } while (next_permutation(p[5], p[5] + 3));
    } while (next_permutation(p[6], p[6] + 3));
    } while (next_permutation(p[7], p[7] + 3));
    
    cout << "NO" << endl;

    return 0;
}