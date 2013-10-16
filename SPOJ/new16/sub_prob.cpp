/*
Alfonso2 Peterssen(mukel)
SPOJ #6898 "Substring Problem"
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

#define SZ(c) ((int)(c).size())
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int
	MAXL = 1 << 17,
	MAXN = 1 << 10;

int N;
char text[MAXL];
char buf[MAXL];
bool subst[MAXN];

int root, nodes;
struct trieNode
{
	bool seen;
	int matchFail;
	vector< int > matches;
	int fail;
	map< char, int > next;
} trie[MAXL];

void insert(char * s, int wordId)
{
	int x = root;
	for (int i = 0; s[i]; ++i)
	{
		int & nxt = trie[x].next[ s[i] ];
		if (!nxt) nxt = ++nodes;
		x = nxt;
	}
	
	trie[x].matches.push_back(wordId);
}

int target(int x, char ch)
{
	while (x && !trie[x].next.count(ch))
	      x = trie[x].fail;
	      
	return x ? trie[x].next[ch] : root;
}

void bfs()
{
	trie[root].fail = 0; // nil

	queue< int > Q;
	for (Q.push(root); !Q.empty(); Q.pop())
	{
		int u = Q.front();
		for (map< char, int >::iterator it = trie[u].next.begin(); it != trie[u].next.end(); ++it)
		{
			char ch = it->first;
			int v = it->second;
			
			int f = target(trie[u].fail, ch);

			trie[v].fail = f;
			trie[v].matchFail = trie[f].matches.empty() ? trie[f].matchFail : f;
			
			Q.push(v);
		}
	}
}

void search()
{
	int x = root;
	for (int i = 0; text[i]; ++i)
	{
		x = target(x, text[i]);

		for (int t = x; t && !trie[t].seen; t = trie[t].matchFail)
		{
			trie[t].seen = true;
			REP(j, SZ(trie[t].matches))
				subst[trie[t].matches[j]] = true;
		}
	}
}

int main()
{
	root = ++nodes;

	scanf( "%s", &text );
	scanf( "%d", &N );
	REP(i, N)
	{
		scanf( "%s", &buf );
		insert(buf, i);
	}
	
	bfs();
	search();
	
	REP(i, N)
	      printf( "%s\n", subst[i] ? "Y" : "N" );

	return 0;
}
