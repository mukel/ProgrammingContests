#include <bits/stdc++.h>
using namespace std;

const vector<string> names =
{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool match(string a, string b) {
    if (a.size() != b.size())
        return false;
        
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (b[i] != &#39;.&#39; && a[i] != b[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    string target;
    int n;
    cin >> n;
    cin >> target;
    
    for (auto s : names)
        if (match(s, target)) {
            cout << s << endl;
            return 0;
        }   
    
    return 0;
}