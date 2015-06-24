/*
Alfonso2 Peterssen
SPOJ #3249 "Typesettin"
6 - 8 - 2010
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPD(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define ALL(c) (c).begin(), (c).end()

typedef vector< string > glyph;

const int
	MAXN = 1 << 5,
	oo = (int)1e9;
	
glyph G[MAXN];

int fartPos[MAXN];
int nearPos[MAXN];

glyph merge(glyph a, glyph b)
{
	glyph ans = a;
	REP(i, a.size())
	{
		fartPos[i] = -oo;
		REPD(j, a[i].size())
		      if (a[i][j] != '.')
		      {
				fartPos[i] = j;
				break;
			}
	}
	
	REP(i, b.size())
	{
		nearPos[i] = oo;
		REP(j, b[i].size())
		      if (b[i][j] != '.')
		      {
				nearPos[i] = j;
				break;
			}
	}
	
	int bestJoin = a[0].size() + b[0].size();
	REP(i, a.size())
	{
		int da = a[i].size() - 1 - fartPos[i];
		int db = nearPos[i];
		bestJoin = min(bestJoin, da + db - 1);
	}
	
	REP(i, a.size())
	{
		if (bestJoin <= 0)
		{
			if (bestJoin == -1)
			      ans[i].push_back('.');
			ans[i] += b[i];
		} else
		if (bestJoin <= a[i].size())
		{
			ans[i] = a[i];
			REP(j, b[i].size())
			{
				int pos = a[i].size() - bestJoin + j;
				if (pos < ans[i].size())
				{
					if (b[i][j] != '.') ans[i][pos] = b[i][j];
				}
				else
					ans[i].push_back(b[i][j]);
			}
		} else
		{
			ans[i] = b[i];
			REP(j, a[i].size())
			{
				int pos = bestJoin - a[i].size() + j;
				if (pos < ans[i].size())
				{
					if (a[i][j] != '.') ans[i][pos] = a[i][j];
				}
				else
					ans[i].push_back(a[i][j]);
			}
		}
	}
	
	return ans;
}

char buff[1 << 10];

int main()
{
	for (int test = 1;; test++)
	{
		int R;
		scanf( "%d", &R );
		if (!R) break;
		
		REP(i, MAXN)
		      G[i].clear();
		
		char ch;

		int gCount = 0;
		while (1)
		{
			scanf( "%s%c", &buff, &ch );
			G[gCount++].push_back(buff);
			if (ch != ' ') break;
		}
		
		for (int i = 1; i < R; i++)
			REP(j, gCount)
			{
				scanf( "%s", &buff );
				G[j].push_back(buff);
			}
		
		glyph ans = G[0];
		for (int i = 1; i < gCount; i++)
		      ans = merge(ans, G[i]);
		

		while (ans[0].size() > 1)
		{
			bool found = false;
			REP(j, ans.size())
			      if (ans[j][0] == '#')
					found = true;
			if (found)
			      break;

			REP(j, ans.size())
			      ans[j].erase( ans[j].begin() );
		}
		
		while (ans[0].size() > 1)
		{
			bool found = false;
			REP(j, ans.size())
			      if (ans[j][ ans[j].size() - 1 ] == '#')
					found = true;
			if (found)
			      break;

			REP(j, ans.size())
			      ans[j].erase( ans[j].end() - 1 );
		}
		
		printf( "%d\n", test );
		REP(i, ans.size())
		{
			REP(j, ans[i].size())
			{
				char ch = ans[i][j];
				printf( "%c", (ch == '#') ? ch : '.' );
			}
			printf( "\n" );
		}
	}

	return 0;
}
