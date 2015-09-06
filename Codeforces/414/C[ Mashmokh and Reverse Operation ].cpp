#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 20,
    MAXL = 1 << MAXN;

int N, L, Q;
int a[MAXL];
int tmp[MAXL]; // merge tmp

long long totalInv[MAXN+1];
long long maxInv[MAXN+1];
long long revInv[MAXN+1];

long long query()
{
    long long ans = 0;
    for (int i = 1; i <= N; ++i)
        ans += totalInv[i];
    return ans;
}

void build(int lo, int hi, int total)
{
    if (lo == hi) return ;
    
    int mid = (lo + hi) / 2;
    
    build(lo, mid, total - 1);
    build(mid + 1, hi, total - 1);
    
    // merge
    
    {
        
        int l = lo, r = mid + 1;
        long long inv = 0;
        for (int pos = lo; pos <= hi; ++pos)
        {
            if (r > hi) tmp[pos] = a[l++]; // 0 inversion
            else
            if (l > mid) tmp[pos] = a[r++]; // 0 inversion
            else
            if (a[r] <= a[l]) tmp[pos] = a[r++]; // 0 inversion
            else {
                tmp[pos] = a[l++];
                inv += (hi - r + 1);
            }
        }
    
        revInv[total] += inv;
        maxInv[total] += inv;
    }
    
    int l = lo, r = mid + 1;
    long long inv = 0;
    for (int pos = lo; pos <= hi; ++pos)
    {
        if (r > hi) tmp[pos] = a[l++]; // 0 inversion
        else
        if (l > mid) tmp[pos] = a[r++]; // 0 inversion
        else
        if (a[l] <= a[r]) tmp[pos] = a[l++]; // 0 inversion
        else {
            tmp[pos] = a[r++];
            inv += (mid - l + 1);
        }
    }
    
    for (int i = lo; i <= hi; ++i)
        a[i] = tmp[i];
        
    long long dif = 1;
    for (int i = lo; i < hi; ++i)
        if (a[i] != a[i + 1])
            dif++;
    
    totalInv[total] += inv;
    
    maxInv[total] += inv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    L = (1 << N);
    for (int i = 0; i < L; ++i)
        cin >> a[i];
        
    build(0, L - 1, N);
    
    //cout << "-> " << query() << endl;

    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int q; cin >> q;
        
        //long long arrLen = 1 << q;
        //long long cnt = 1 << (N - q);
        
        //cout << "::-->> "<< arrLen << " " << cnt << endl;
        
        //long long singleInv = arrLen * (arrLen - 1) / 2;
        //long long t = cnt * singleInv;
    /*  
        cout << "###" << endl;
        for (int i = 1; i <= N; ++i)
            cout << totalInv[i] << " ";
        cout << "###" << endl;
*/
        for (int j = q; j >= 1; --j)
            totalInv[j] = maxInv[j] - totalInv[j];
    
        cout << query() << endl;
    }

    return 0;
}
