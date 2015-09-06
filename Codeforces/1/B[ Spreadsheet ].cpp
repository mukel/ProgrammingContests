// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

int Q;
string line;
int row, col;
char buf[100];

int main()
{
    ios_base::sync_with_stdio(false);

    for (cin >> Q; Q--;)
    {
        cin >> line;
        if (sscanf( line.c_str(), "R%dC%d", &row, &col ) == 2)
        {
            string ans;
            while (col > 0)
            {
                col--;
                ans += (char)(&#39;A&#39; + col % 26);
                col /= 26;
            }
            reverse(ALL(ans));
            cout << ans << row << "\n";
        }
        else
        {
            sscanf( line.c_str(), "%[A-Z]%d", &buf, &row );
            col = 0;
            for (int i = 0; buf[i]; ++i)
                col = col * 26 + (buf[i] - &#39;A&#39; + 1);
            cout << "R" << row << "C" << col << "\n";
        }
    }



    return 0;
}
