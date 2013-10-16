/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #17 "Arithmetica v1.3"
*/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cctype>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	ERROR = (1 << 30) + 1;

struct varInfo
{
	int evalState;
	string def;
};
map< string, varInfo > vars;

int evalVar(string varName);
int evalExpr(const string & expr, int & pos);
int evalTerm(const string & expr, int & pos);

int evalTerm(const string & expr, int & pos)
{
	if (pos >= expr.size()) return ERROR;
	if (expr[pos] == '(')
	{
		pos++;
		int result = evalExpr(expr, pos);
		if (pos >= expr.size() || expr[pos] != ')') return ERROR;
		pos++;
		return result;
	} else
	if (expr[pos] == '-')
	{
		pos++;
		int result = evalTerm(expr, pos);
		if (result != ERROR) result = -result;
		return result;
	} else
	if (isdigit(expr[pos]))
	{
		int result = 0;
		while (pos < expr.size() && isdigit(expr[pos]))
		{
		      result = result * 10 + (expr[pos] - '0');
		      pos++;
		}
		return result;
	} else
	if (isalpha(expr[pos]))
	{
		string varName;
		while (pos < expr.size() && isalpha(expr[pos]))
		{
			varName = varName + expr[pos];
			pos++;
		}
		return evalVar(varName);
	}
	
	return ERROR;
}

int evalExpr(const string & expr, int & pos)
{
	int result = evalTerm(expr, pos);
	if (result == ERROR) return ERROR;
	
	while (pos < expr.size() && strchr("+-*", expr[pos]))
	{
		char op = expr[pos]; pos++;
		int other = evalTerm(expr, pos);
		if (other == ERROR) return ERROR;
		switch (op)
		{
			case '+' : result += other; break;
			case '-' : result -= other; break;
			case '*' : result *= other; break;
		}
	}
	
	//if (pos < expr.size()) return ERROR;
	
	return result;
}

int evalVar(string varName)
{
	if (!vars.count(varName)) return ERROR;
	
	if (!vars[varName].evalState) // undone
	{
            vars[varName].evalState = 1;  // doing
		int pos = 0;
		int result = evalExpr(vars[varName].def, pos);
            vars[varName].evalState = 0;  // undone

            return result;
	} else
		return ERROR;
}

int main()
{
	int n;
	for (cin >> n; n--;)
	{
            string expr;
		cin >> expr;
		
		int pos = expr.find(':');
		if (pos != expr.npos)
		{
			string varName = expr.substr(0, pos);
			
			vars[varName].evalState = 0;
			vars[varName].def = expr.substr(pos + 2);
		}
		else
		{
			int result = evalVar(expr);
			if (result == ERROR)
			      cout << "error" << endl;
			else
			      cout << result << endl;
		}
	}

	return 0;
}
