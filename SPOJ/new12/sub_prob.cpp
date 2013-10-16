/*
Alfonso2 Peterssen
SPOJ #6898 "Substring Problem"
8 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long int64;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	ALPHA = 256,
	MAXN = 1 << 17;

struct PMA
{
	PMA* next[ALPHA];
	PMA* fail;
	vector< int > words;
	bool mark;
	PMA()
	{
		fill(next, next + ALPHA, (PMA*)0);
		fail = 0;
		mark = false;
	}
};

PMA* root;
char S[MAXN];
char buff[MAXN];
bool subst[MAXN];

void insert(char* s, int id)
{
	PMA* r = root;
	for (int i = 0; s[i]; i++)
	{
		char ch = s[i];
		if (!r->next[ch]) r->next[ch] = new PMA();
		r = r->next[ch];
	}
	r->words.push_back(id);
}

void BFS()
{
	queue< PMA* > Q;
	REP(i, ALPHA)
		if (root->next[i])
		{
			root->next[i]->fail = root;
			Q.push(root->next[i]);
    		} else
		    root->next[i] = root;

	while (!Q.empty())
	{
		PMA* r = Q.front();
		Q.pop();
		for (int i = 0; i < ALPHA; i++)
		      if (r->next[i])
			{
				PMA* x = r->fail;
				while (!x->next[i]) x = x->fail;
				x = x->next[i];
				r->next[i]->fail = x;
				Q.push(r->next[i]);
			}
	}
}

void search(char* s)
{
	root->mark = true;
	PMA* r = root;
	for (int i = 0; s[i]; i++)
	{
		char ch = s[i];
		while (!r->next[ch]) r = r->fail;
		r = r->next[ch];
		for (PMA* t = r; !t->mark; t->mark = true, t = t->fail)
			REP(j, t->words.size())
				subst[ t->words[j] ] = 1;
	}
}

int main()
{
	scanf( "%s", &S );
	int N;
	scanf( "%d", &N );
	
	root = new PMA();
	REP(i, N)
	{
		scanf( "%s", &buff );
		insert(buff, i);
	}
	
	BFS();
	search(S);
	
	REP(i, N)
		printf( subst[i] ? "Y\n" : "N\n" );

	return 0;
}
