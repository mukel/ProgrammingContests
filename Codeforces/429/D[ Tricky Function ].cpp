// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;


typedef complex< long long > point;
#define xx real()
#define yy imag()

const int
    MAXN = 1 << 17;

int N;
int a[MAXN];
point pX[MAXN];


inline long long sqr(long long n)
{
    return (n) * (long long)n;
}


inline long long distSquared(const point & a, const point & b)
{
    return sqr(a.xx - b.xx) + sqr(a.yy - b.yy);
}

struct cmpX
{
    bool operator () (const point & a, const point & b)
    {
        return (a.xx != b.xx) ? a.xx < b.xx : a.yy < b.yy;
    }
};

struct cmpY
{
    bool operator () (const point & a, const point & b)
    {
        return (a.yy != b.yy) ? a.yy < b.yy : a.xx < b.xx;
    }
};

set< point, cmpY > pY;

const long long INF = (long long)(2e18);

int main(int argc, char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
        pX[i] = point(i, a[i]);
    }
    
    sort(pX, pX + N, cmpX());

    long long minDistSquared = INF;
    
    for (int i = 1; i < N; ++i)
        minDistSquared = min(minDistSquared, distSquared(pX[i], pX[i - 1]));

    double minDist = sqrt(minDistSquared);
    
    int xBound = 0;
    for (int i = 0; i < N; ++i)
    {
        while (pX[i].xx - pX[xBound].xx > minDist)
            pY.erase(pX[xBound++]);
        int cnt = 0;
        auto it = pY.lower_bound(point(-INF, (long long)(pX[i].yy - minDist)));
        for (; it != pY.end() && it->yy - pX[i].yy < minDist; ++it)
            minDistSquared = min(minDistSquared, distSquared(*it, pX[i]));
        minDist = sqrt(minDistSquared);
        pY.insert(pX[i]);
    
    }
    
    cout << minDistSquared << endl;
    
    return 0;
}