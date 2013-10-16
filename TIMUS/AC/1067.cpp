/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1067. Disk Tree
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int N;

class trie : public map< string, trie > {} root;


vector< string > split(string s)
{
	vector< string > ans;
	for (int pos = 0; (pos = s.find('\\')) != s.npos;)
	{
		ans.push_back(s.substr(0, pos));
		s = s.substr(pos + 1);
		
	}
	ans.push_back(s);
	return ans;
}

void traverse(trie& r, string blanks = "")
{
	for (auto it = r.begin(); it != r.end(); ++it)
	{
		cout << blanks << (*it).first << endl;
		traverse((*it).second, blanks + " ");
	}
}


//char buff[100];

int main()
{
	cin >> N;
	REP(i, N)
	{
		string line;
		cin >> line;
		
		trie* r = &root;
		vector< string > tok = split(line);
		REP(i, tok.size())
			r = &((*r)[ tok[i] ]);

	}
	
	traverse(root);
	
	return 0;
}

