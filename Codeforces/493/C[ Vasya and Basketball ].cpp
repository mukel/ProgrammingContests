#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector< int > a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    
    sort(b.begin(), b.end());
    
    vector< int > p;
    p.push_back(0);
    p.push_back((int)2e9);
    
    p.insert(p.end(), a.begin(), a.end());
    p.insert(p.end(), b.begin(), b.end());
    
    sort(p.begin(), p.end());
    
    p.erase(unique(p.begin(), p.end()), p.end());
    
    int besta, bestb;
    int best = -(int)2e9;
    
    int ai = 0, bi = 0;
    
    for (int i = 0; i < p.size(); ++i) {
        
        while (ai < a.size() && a[ai] <= p[i]) ai++;
        while (bi < b.size() && b[bi] <= p[i]) bi++;
        
        int ascore = ai*2 + (a.size() - ai) * 3;
        
        int bscore = bi*2 + (b.size() - bi) * 3;
        
        int diff = ascore - bscore;
        if (diff > best || (diff == best && ascore > besta))
        {
            best = diff;
            besta = ascore;
            bestb = bscore;
        }
    }
    
    cout << besta << ":" << bestb << endl;
    
    return 0;
}