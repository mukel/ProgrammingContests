// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

typedef long long int64;    


string s;
int p;
int n;
bool tolerable(string s)
{
    for (int i = 0; i < n; ++i)
    {
        if (s[i] >= &#39;a&#39; + p) return false;
        if (i - 1 >= 0 && s[i] == s[i - 1])
            return false;
        if (i - 2 >= 0 && s[i] == s[i - 2])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p;
    cin >> s;

    for (int i = n - 1; i >= 0; --i) {
        
        for (int j = 0; j < p; ++j) {
            s[i]++;
            if (s[i] >= &#39;a&#39; + p) break;
            if (i - 1 >= 0 && s[i] == s[i - 1])
                continue;
            if (i - 2 >= 0 && s[i] == s[i - 2])
                continue;
            break;
        }
        
        if (s[i] < &#39;a&#39; + p) {
            // rebuild
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = 0; k < p; ++k)
                {
                    char ch = &#39;a&#39; + k;
                    s[j] = ch;
                    if (j - 1 >= 0 && s[j] == s[j - 1])
                        continue;
                    if (j - 2 >= 0 && s[j] == s[j - 2])
                        continue;
                    break;
                }
            }
            break;
        }
    }
    
    if (tolerable(s))
        cout << s << endl;
    else cout << "NO" << endl;

    return 0;
}