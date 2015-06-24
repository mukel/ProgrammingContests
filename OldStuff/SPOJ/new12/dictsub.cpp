/*
Alfonso2 Peterssen
SPOJ #3106 "Dictionary Subsequences"
8 - 8 - 2010
*/
#include <cstdio>
//#include <iostream>

#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

const int
	ALPHA = 26,
	MAXN = 1 << 15;

vector< int > pos[ALPHA];
char buff[MAXN];

bool isSubseq(char* ptr)
{
	int currPos = 0;
	while (*ptr)
	{
		int jmp = 0;
		while (isdigit(*ptr))
		{
			jmp = jmp * 10 + (*ptr) - '0';
			ptr++;
		}
		
		char ch = (*ptr) - 'A';
		
		int firstPos = lower_bound(ALL(pos[ch]), currPos) -  pos[ch].begin();
		if (firstPos + jmp - 1 >= pos[ch].size())
		      return 0;
		      
		currPos = pos[ch][firstPos + jmp - 1] + 1;
		ptr++;
	}
	
	return 1;
}

int main()
{
	int T;
	for (scanf( "%d", &T ); T--;)
	{
		REP(i, ALPHA)
		      pos[i].clear();

		int Q;
		scanf( "%d %s", &Q, &buff );
		int n = strlen(buff);
		REP(i, n)
		      pos[ buff[i] - 'A' ].push_back(i);
		      
		while (Q--)
		{
			scanf( "%s", &buff );
			printf( isSubseq(buff) ? "YES\n" : "NO\n" );
		}
	}
	return 0;
}
