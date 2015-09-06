#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int N, X;
struct candy
{
    int h, m;
};
vector< candy > candies[2];

bool byHeight(const candy & a, const candy & b)
{
    return a.h < b.h;
}

struct massCmp
{
    bool operator () (const candy & a, const candy & b) const
    {
        return a.m < b.m;
    }
};

int solve(vector< candy > f, vector< candy > d)
{
    sort(f.begin(), f.end(), byHeight);
    sort(d.begin(), d.end(), byHeight);
    
    int posf = 0;
    int posd = 0;
    int curX = X;
    
    multiset< candy, massCmp > setD, setF;
    
    for (int i = 0; i < f.size() + d.size(); ++i)
    {
        if (i % 2 == 0)
        {
            while (posf < f.size() && f[posf].h <= curX)
                setF.insert(f[posf++]);
            if (setF.empty())
                return i;
            auto it = setF.end();
            --it;
            curX += it->m;
            setF.erase(it);
        } else {
            while (posd < d.size() && d[posd].h <= curX)
                setD.insert(d[posd++]);
            if (setD.empty())
                return i;
            auto it = setD.end();
            --it;
            curX += it->m;
            setD.erase(it);
        }
    }
    
    return f.size() + d.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> X;
    for (int i = 0; i < N; ++i)
    {
        int t, h, m;
        cin >> t >> h >> m;
        candies[t].push_back({h, m});
    }
    
    int ans = solve(candies[0], candies[1]);
    ans = max(ans, solve(candies[1], candies[0]));
    cout << ans << endl;

    return 0;
}