/*
Alfonso2 Peterssen(mukel)
Yandex Round 2
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int MAXC = 1 << 10;

const int
	delta[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int R, C;
int mark[MAXC][MAXC];
char mat[MAXC][MAXC];
int cnt;
bool digit[10];
bool used[1 << 20];

vector< pair<int, int> > G[1 << 20];

int main()
{
	scanf( "%d %d", &R, &C );
	
	REP(i, R)
		scanf( "%s", &mat[i] );
		
	REP(i, R)
		REP(j, C)
		{
			int x = i, y = j;
			
			if (mat[i][j] == &#39;#&#39;) continue ;
			if (mark[x][y]) continue ;

			REP(k, 4)
			{
				int nx = x + delta[k][0];
				int ny = y + delta[k][1];
				
				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				      continue ;
				      
				if (mat[nx][ny] == &#39;#&#39;) continue ;
				if (mark[nx][ny]) continue ;

				cnt++;
				
				G[cnt].push_back(MP(x,y));
				G[cnt].push_back(MP(nx,ny));
				
				mark[x][y] = cnt;
				mark[nx][ny] = cnt;
				break;
			}
		}

	REP(x, R)
	REP(y, C)
	{
		if (mat[x][y] == &#39;#&#39;) continue ;

		if (!mark[x][y])
		REP(k, 4)
		{
			int nx = x + delta[k][0];
			int ny = y + delta[k][1];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			      continue ;

			if (mat[nx][ny] == &#39;#&#39;) continue ;
			
			mark[x][y] = mark[nx][ny];
			G[ mark[x][y] ].push_back(MP(x, y));
			break;
		}
	}
	
	REP(i, R)
	REP(j, C)
	{
		REP(k, 10) digit[k] = 0;

		if (mat[i][j] == &#39;#&#39;) continue ;
		int cnt = mark[i][j];
		
		if (used[cnt]) continue ;
		
		used[cnt] = 1;
		
		REP(i, SZ(G[cnt]))
		{
			int x = G[cnt][i].first;
			int y = G[cnt][i].second;
			REP(k, 4)
			{
				int nx = x + delta[k][0];
				int ny = y + delta[k][1];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				      continue ;

				if (mat[nx][ny] == &#39;#&#39;) continue ;
				
				if (mat[nx][ny] != &#39;.&#39;)
				      digit[mat[nx][ny] - &#39;0&#39;] = true;
			}
		}

		REP(k, 10)
		      if (!digit[k])
		      {
                  	REP(i, SZ(G[cnt]))
				{
					int x = G[cnt][i].first;
					int y = G[cnt][i].second;
					mat[x][y] = k + &#39;0&#39;;
				}
				break;
			}
	}
	
	REP(i, R)
	REP(j, C) if ( mat[i][j] == &#39;.&#39; )
	{
		printf( "-1\n" );
		return 0;
	}
	
	REP(i, R)
	      printf( "%s\n", mat[i] );
	
	return 0;
}

