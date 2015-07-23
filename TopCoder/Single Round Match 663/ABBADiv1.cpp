#include<bits/stdc++.h>
using namespace std;

typedef long long int64;
#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()

map<string, bool> memo;
string target;

bool solve(string& s) {
	if (s == target) return true;
	if (s.size() <= target.size())
		return false;
	
	if (memo.find(s) != memo.end())
		return memo[s];
		
	bool r = memo[s];
	r = false;
	
	if (s[0] == 'B') {
		string t = string(s.begin() + 1, s.end());
		reverse(ALL(t));
		if (r = solve(t))
			return true;
	}
	
	if (s[s.size() - 1] == 'A') {
		string t = string(s.begin(), s.end() - 1);
		if (r = solve(t))
			return true;
	}

	return r;
}

struct ABBADiv1 {
    string canObtain(string initial, string target) {
		::target = initial;
		memo.clear();
		if (solve(target))
			return "Possible";
		else
			return "Impossible";
    }
};

// CUT begin
ifstream data("ABBADiv1.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string initial, string target, string __expected) {
    time_t startClock = clock();
    ABBADiv1 *instance = new ABBADiv1();
    string __result = instance->canObtain(initial, target);
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
        string initial;
        from_stream(initial);
        string target;
        from_stream(target);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(initial, target, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1437663843;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ABBADiv1 (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
