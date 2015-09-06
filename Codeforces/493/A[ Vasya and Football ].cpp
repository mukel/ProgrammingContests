#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map< int, bool > alreadyRed[2], alreadyYellow[2];
map< int, int > redTime[2];

struct state {

    string team;
    int minute;
    int player;
};

bool operator < (const state& a, const state & b)
{
    return a.minute < b.minute;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string T1, T2;
    cin >> T1 >> T2;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int minute, num;
        string team, card;
        cin >> minute >> team >> num >> card;

        if (!alreadyRed[team == "a"].count(num)) {
                
            if (!alreadyRed[team == "a"].count(num))
            if (alreadyYellow[team == "a"].count(num) || card == "r") {
                alreadyRed[team == "a"][num] = true;
                redTime[team == "a"][num] = minute;
            }
            
            if (!alreadyYellow[team == "a"].count(num) && card == "y")
                alreadyYellow[team == "a"][num] = true;
        }
    }

    vector< state > V;
    for (int i = 0; i < 2; ++i)
        for (map< int, int >::iterator it = redTime[i].begin(); it != redTime[i].end(); ++it) {
            state x;
            if (i == 0) x.team = T1; else x.team = T2;
            x.minute = it->second;
            x.player = it->first;
            V.push_back(x);
        }

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); ++i) {
        cout << V[i].team << " " << V[i].player << " " << V[i].minute << endl;
    }

    return 0;
}