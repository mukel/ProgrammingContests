#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 17;

int N;
int x[MAXN];
int y[MAXN];
unordered_map< int, vector< int > > samex, samey;

namespace std
{

template <>
struct hash<std::pair<int, int> > {
public:
        size_t operator()(std::pair<int, int> x) const throw() {
             size_t h = x.first * 33333 + x.second;
             return h;
        }
};
}
unordered_set< pair< int, int > > P;

inline bool contains(pair< int, int > p)
{
    return P.find(p) != P.end();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int SQRTN = (int)sqrt(N) + 5;
    
    P.reserve(N);
    samex.reserve(N);
    samey.reserve(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i] >> y[i];
        P.insert( {x[i], y[i]} );
        samex[ x[i] ].push_back( y[i] );
    }
    
    long long ans = 0;
    for (const auto& p : samex)
    {
        int n = p.second.size();
        
        int x = p.first;
        
        if (n < SQRTN){
            for (int i = 0; i < n; ++i)
            {
                int y1 = p.second[i];
                for (int j = i + 1; j < n; ++j)
                {
                    int y2 = p.second[j];
                    int dy = y1- y2;//abs(y1 - y2);
                    if (contains({x + dy, y1}) && contains({x + dy, y2})) ans++;
                    if (contains({x - dy, y1}) && contains({x - dy, y2})) ans++;
                }
                
                P.erase( { x, y1 } );
            }
        }
    }

    for (auto p : P)
        samey[ p.second ].push_back(p.first);

    for (const auto& p : samey)
    {
        int n = p.second.size();
        int y = p.first;

        //if (n < SQRTN){
            for (int i = 0; i < n; ++i)
            {
                int x1 = p.second[i];
                for (int j = i + 1; j < n; ++j)
                {
                    int x2 = p.second[j];
                    int dx = x1 - x2;//abs(y1 - y2);
                    if (contains({x1, y + dx}) && contains({x2, y + dx})) ans++;
                    if (contains({x1, y - dx}) && contains({x2, y - dx})) ans++;
                }
                P.erase( { x1, y } );
            }
        //}
    }
    
    assert(P.empty());
    
    cout << ans << endl;
    
    return 0;
    
}
