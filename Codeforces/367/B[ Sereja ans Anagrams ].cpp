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
    MAXN = 1 << 18;

int N, M, P;
int A[MAXN];
int B[MAXN];
vector< int > S[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M >> P;
    REP(i, N)
    {
        cin >> A[i];
        S[i % P].push_back(A[i]);
    }

    map< int, int > inB;

    REP(i, M)
    {
        cin >> B[i];
        ++inB[ B[i] ];
    }
    
    vector< int > ans;
    
    REP(i, P)
        if (SZ(S[i]) >= M)
        {
            int matches = 0;
            
            // process sequence
            map< int, int > cnt;
            
            REP(j, SZ(S[i]))
            {
                // add
                {
                    int x = S[i][j];
                    int xinb = inB[x];
                
                    // add
                    ++cnt[x];
                    if (cnt[x] == xinb) // one step closer
                        matches += xinb;
                    else
                        if (cnt[x] - 1 == xinb)
                            matches -= xinb; // too far
                }
                
                // remove
                if (j >= M)
                {
                    int x = S[i][j - M];
                    int xinb = inB[x];
                    
                    --cnt[x];
                    if (cnt[x] == xinb) // one step closer
                        matches += xinb;
                    else
                        if (cnt[x] + 1 == xinb)
                            matches -= xinb; // too far
                }

                if (j >= M - 1 && matches == M)
                {
                    ans.push_back(i + (j - M + 1) * (int64)P);
                }
            }
            

            
        }
        
    sort(ALL(ans));
        
    cout << SZ(ans) << "\n";
    REP(i, SZ(ans))
        cout << ans[i] + 1 << " ";
        
    return 0;
}