#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 200;

int N, K;
int a[MAXN];
int inCnt, outCnt;
int in[MAXN];
int out[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    
    
    int ans = -1000000000;
    
    for (int lo = 0; lo < N; ++lo)
    for (int hi = lo; hi < N; ++hi)
    {
        inCnt = 0;

        int sum = 0;
        for (int i = lo; i <= hi; ++i) {
            in[inCnt++] = a[i];
            sum += a[i];
        }

        sort(in, in + inCnt);
        
        outCnt = 0;
        
        for (int i = 0; i < lo; ++i) out[outCnt++] = a[i];
        for (int i = hi + 1; i < N; ++i) out[outCnt++] = a[i];
        
        sort(out, out + outCnt);
        reverse(out, out + outCnt);
        
        
        ans = max(ans, sum);
        for (int k = 0; k < K && k < inCnt && k < outCnt; ++k)
        {
            sum = sum - in[k] + out[k];
            ans = max(ans, sum);
        }
        
    }
    
    cout << ans << endl;
    
    
    return 0;
    
}