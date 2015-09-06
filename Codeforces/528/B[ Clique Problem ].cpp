#include <bits/stdc++.h>
using namespace std;

const int
    MAXN = 1 << 18;
    
typedef pair<int, int> par;

int N;
par p[2 * MAXN];
vector<int> coords;
int fen[2 * MAXN];

int lobit(int x) { return x & -x; }

int queryMax(int x) {
    int r = 0;
    while (x > 0) {
        r = max(r, fen[x]);
        x -= lobit(x);
    }
    return r;
}

void update(int x, int value) {
    while (x < 2*MAXN) {
        fen[x] = max(fen[x], value);
        x += lobit(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    coords.reserve(2 * N);
    for (int i = 0; i < N; ++i) {
        int x, w;
        cin >> x >> w;
        p[i] = {x, w};
        coords.push_back(x - w);
        coords.push_back(x + w);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    map<int, int> pos;
    //pos.reserve(2 * N);
    for (int i = 0; i < (int)coords.size(); ++i) {
        pos[ coords[i] ] = i + 1;
    }

    sort(p, p + N);

    int answer = 1;
    for (int i = 0; i < N; ++i) {
        int xi = p[i].first;
        int wi = p[i].second;
        int q = queryMax(pos[xi - wi]);
        //cerr << "(" << xi << ", " << wi << ") q = " << q << endl;
        answer = max(answer, q + 1);
        update(pos[xi + wi], q + 1);
    }

    cout << answer << endl;
    
    return 0;
}
