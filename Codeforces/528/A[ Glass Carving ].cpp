#include <bits/stdc++.h>
using namespace std;

int W, H, Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> W >> H >> Q;
    
    set<int> sw, sh;
    
    multiset<int> wdiff, hdiff;
    sw.insert(0);
    sw.insert(W);
    wdiff.insert(W);
    
    sh.insert(0);
    sh.insert(H);
    hdiff.insert(H);
    
    for (int i = 0; i < Q; ++i) {
        string op;
        int x;
        cin >> op >> x;
        if (op == "H") {
            auto next = sh.upper_bound(x);
            auto prev = next; --prev;
            int vnext = *next;
            int vprev = *prev;
            hdiff.insert(vnext - x);
            hdiff.insert(x - vprev);
            hdiff.erase(hdiff.find(vnext - vprev));
            sh.insert(x);
        } else {
            auto next = sw.upper_bound(x);
            auto prev = next; --prev;
            int vnext = *next;
            int vprev = *prev;
            wdiff.insert(vnext - x);
            wdiff.insert(x - vprev);
            wdiff.erase(wdiff.find(vnext - vprev));
            sw.insert(x);
        }
        
        auto vit = wdiff.end(); vit--;
        auto hit = hdiff.end(); hit--;
        
        //cout << *vit << " " << *hit << endl;
        
        cout << ((*hit) * (long long)(*vit)) << &#39;\n&#39;;
    }
    
    return 0;
}
