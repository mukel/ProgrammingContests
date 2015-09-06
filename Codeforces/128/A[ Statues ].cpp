/*
	Alfonso2 Peterssen(mukel)
	Codeforces Round 94
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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)((c).size()))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

const int
	mov[9][2] = {{0,0},{-1,0},{0,-1},{0,1},{1,0}, {-1,-1},{-1,1},{1,-1},{1,1}};

string mat[8];
vector< pair< int, int > > S;

struct state
{
	int t, x, y;
};
bool mark[8][8][1000];

int main()
{
	REP(i, 8)
	{
		cin >> mat[i];
		REP(j, 8)
		      if (mat[i][j] == &#39;S&#39;)
		            S.push_back(make_pair(i, j));
	}
	
	queue< state > Q;
	Q.push((state){0, 7, 0});
	
	while (!Q.empty())
	{
		state top = Q.front();
		Q.pop();
		
		if (top.t >= 1000) break;
		
		if (top.x == 0 && top.y == 7)
		{
			puts( "WIN" );
			exit(0);
		}
		
		bool occ = false;
		REP(i, SZ(S))
			if (S[i].first + top.t == top.x && S[i].second == top.y)
			{
				occ = true;
				break ;
			}
			
		if (occ) continue ;
		
		REP(i, 9)
		{
			int nx = top.x + mov[i][0];
			int ny = top.y + mov[i][1];
			
			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
			      continue ;
			      
			bool occ = false;
			REP(i, SZ(S))
				if (S[i].first + top.t == nx && S[i].second == ny)
				{
					occ = true;
					break ;
				}
				
			if (occ) continue ;
			
			if (mark[nx][ny][ top.t + 1])
			      continue ;
			      
			mark[nx][ny][ top.t + 1] = true;
			Q.push((state){top.t + 1, nx, ny});
		}
	}
	
	puts( "LOSE" );

	return 0;
}
