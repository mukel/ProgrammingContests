// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

#define SZ(c) ((int)(c).size())
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

string line;

int cnt;
map< string, int > __id;

int getId(string & s)
{
	if (!__id[s]) return __id[s] = ++cnt;
	return __id[s];
}

struct node
{
	int id;
	vector< node* > childs;
	node(int id) : id(id) {}
};

node * root;
stack< node* > S;
struct state
{
	node * cur;
	int pos;
};
int query[205];

int main()
{
	cin.sync_with_stdio(false);
	getline(cin, line);
	S.push(root = new node(-1));

	for (int pos = 0; pos < SZ(line);)
	{
		pos++; // skip <
		if (line[pos] == '/') // close tag
		{
			pos++; // skip /
			while (isalpha(line[pos])) pos++;
			S.pop();
		}
		else
		{
			string tag;
			while (isalpha(line[pos])) tag += line[pos++];
			if (line[pos]=='>')
			{
				node * r = new node(getId(tag));
				S.top()->childs.push_back(r);
				S.push(r);
			}
			else
			{
				pos++; // skip /
				node * r = new node(getId(tag));
				S.top()->childs.push_back(r);
			}
		}
		pos++; // skip >
	}

	int T; for (cin >> T; T--;)
	{
		while (getline(cin, line), line.empty());
		stringstream ss(line);

		int n = 0;
		for (string tok; ss >> tok;)
			query[n++] = getId(tok);

		int answer = 0;
		queue< state > Q;
		for (Q.push((state){root, 0}); !Q.empty(); Q.pop())
		{
			node * topCur = Q.front().cur;
			int topPos = Q.front().pos;

			if (topPos == n)
				answer++, topPos--;

			REP(i, SZ(topCur->childs))
			{
				node * v = topCur->childs[i];
				Q.push((state){v, topPos + (v->id == query[topPos])});
			}
		}

		printf( "%d\n", answer );
	}

	return 0;
}
