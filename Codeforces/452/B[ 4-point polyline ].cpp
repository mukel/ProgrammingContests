#include <bits/stdc++.h>
using namespace std;

int n, m;

struct point {
    int x, y;
};

bool operator == (point a, point b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator != (point a, point b)
{
    return !(a == b);
}

typedef vector<point> candidate;

inline double distance(point p1, point p2)
{
    double px = p1.x - p2.x;
    double py = p1.y - p2.y;
    return sqrt(px*px + py*py);
}

double score(candidate c) {
    double s = 0;
    
    for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j)
        if (c[i] == c[j]) return -1; 
    
    for (int i = 0; i < 4; ++i)
        if (c[i].x < 0 or c[i].x > n or c[i].y < 0 or c[i].y > m)
            return -1;
    
    for (int i = 1; i < 4; ++i)
        s += distance(c[i - 1], c[i]);
        
    return s;
}

bool scoreCmp(candidate a, candidate b)
{
    return score(a) < score(b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    vector<int> cn = {
        0,1,2,n,n-1,n-2
    };
    
    vector<int> cm = {
        0,1,2,m,m-1,m-2
    };
    
    cn.erase(unique(cn.begin(), cn.end()), cn.end());   
    cm.erase(unique(cm.begin(), cm.end()), cm.end());
    
    vector<point> p;
    for (int x : cn)
    for (int y : cm) {
        if (x >= 0 && x <= n && y >= 0 && y <= m)
            p.push_back({x,y});
    }
    
    double bestScore = -1;
    vector<point> ans;
        
    for (auto p1 : p)
    for (auto p2 : p) if (p1 != p2)
    for (auto p3 : p) if (p3 != p1 && p3 != p2)
    for (auto p4 : p) if (p4 != p1 && p4 != p2 && p4 != p3)
    {
        double s = distance(p1,p2) + distance(p2,p3) + distance(p3,p4);
        if (s > bestScore) {
            ans = vector<point>{p1, p2, p3, p4};
            bestScore = s;
        }
    }
    
    for (auto p : ans)
        cout << p.x << " " << p.y << endl;
    
    return 0;
}
