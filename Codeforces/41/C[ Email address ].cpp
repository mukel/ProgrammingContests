/*
Alfonso2 Peterssen(mukel)
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)

string compress(string s, bool isBegin = false)
{
    int pos;
    while ((pos = s.find("dot")) != s.npos)
    {
        s.erase(s.find("dot"), 3);
        s.insert(pos, ".");
    }
    
    return s;
}

int main()
{
    string ans, email;
    cin >> email;
    
    ans = email;
    
    REP(i, email.size())
    {
        if (!i) continue ;
        if (i + 2 == email.size()) continue ;
        
        if (email[i] == &#39;a&#39; && email[i + 1] == &#39;t&#39;)
        {
            string b = compress(string(email.begin(), email.begin() + i));
            
            if (b[0] == &#39;.&#39;)
            {
                b.erase(0, 1);
                b = "dot" + b;
            }
            
            string e = compress(string(email.begin() + i + 2, email.end()));
            
            if (e[e.size() - 1] == &#39;.&#39;)
            {
                e.erase(e.size() - 1, 1);
                e = e + "dot";
            }
            
            string tmp = b + "@" + e;
            
            if (tmp.size() < ans.size())
                ans = tmp;
            else
            if (tmp.size() == ans.size() && tmp < ans)
                  ans = tmp;
        }
    }
    
    cout << ans << endl;

    return 0;
}
