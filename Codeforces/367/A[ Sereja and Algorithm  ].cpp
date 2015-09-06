// Alfonso2 Peterssen (mukel)
#include <iostream>
#include <cstdio>
#include <algorithm>

#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)

const int
    MAXN = 1 << 17;

char S[MAXN];
vector< int > pos[3];

int query(int x, int lo, int hi)
{
    return upper_bound(ALL(pos[x]), hi) - lower_bound(ALL(pos[x]), lo);
}

int main()
{
    cin >> S;
    
    for (int i = 0; S[i]; ++i)
        pos[ S[i] - &#39;x&#39; ].push_back(i);
    
    int T;
    cin >> T;
    while (T--)
    {
        int lo, hi;
        cin >> lo >> hi;
        --lo;
        --hi;
        int ans = 0;
        
        int cnt[3];
        REP(i, 3)
            cnt[i] = query(i, lo, hi);
            
        sort(cnt, cnt + 3);
        
        if ((hi - lo + 1 < 3) or
        (cnt[0] == cnt[1] && cnt[1] == cnt[2]) or
        (cnt[0] == cnt[1] && cnt[2] == cnt[1] + 1) or
        (cnt[1] == cnt[2] && cnt[1] == cnt[0] + 1))
            printf( "YES\n" );
        else
            printf( "NO\n");
    }
    
    return 0;
}