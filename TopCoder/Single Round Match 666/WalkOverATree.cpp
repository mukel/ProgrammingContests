#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 102;

int dp[MAXN][MAXN][2];
vector<int> G[MAXN];
int L;
 
void dfs(int u) {	
	dp[u][0][0] = dp[u][0][1] = 1;
	for (int v : G[u]) {
		dfs(v);
		for (int i = L; i > 0; --i) {
			for (int j = 0; j <= i; ++j) {
				if (i - j - 2 >= 0) {
					dp[u][i][1] = max(dp[u][i][1], dp[u][j][1] + dp[v][i - j - 2][1]);
					dp[u][i][0] = max(dp[u][i][0], dp[u][j][0] + dp[v][i - j - 2][1]);
				}
				dp[u][i][0] = max(dp[u][i][0], dp[u][i][1]);				
				if (i -j - 1 >= 0)
					dp[u][i][0] = max(dp[u][i][0], dp[u][j][1] + dp[v][i - j - 1][0]);					
			}
		}
	}
}
 
struct WalkOverATree
{
    int maxNodesVisited(vector<int> parent, int L)
    {
		::L = L;
		memset(dp, 0, sizeof(dp));
		
		for (int i = 0; i < MAXN; ++i)
			G[i].clear();
		
		for (int i = 0; i < (int)parent.size(); ++i)
			G[ parent[i] ].push_back(i + 1);

		dfs(0);

		int ans = 0;
		for (int i = L; i >= 0; --i)
			ans = max(ans, max(dp[0][i][0], dp[0][i][1]));

		return ans;        
    }
};
 
// CUT begin
ifstream data("WalkOverATree.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> parent, int L, int __expected) {
    time_t startClock = clock();
    WalkOverATree *instance = new WalkOverATree();
    int __result = instance->maxNodesVisited(parent, L);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> parent;
        from_stream(parent);
        int L;
        from_stream(L);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent, L, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1440553464;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 222 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "WalkOverATree (222 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
