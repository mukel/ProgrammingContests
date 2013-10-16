/*
Alfonso2 Peterssen
SPOJ #4070 "Two Professors"
6 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#include <cstring>
#include <cstdlib>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

#include <iostream>
using namespace std;
struct IO{
#define S inline IO& operator
#define P return*this
#define O(vt)S<<(register vt v){if(v<0){p('-');v=-v;}int i=0;do t[i++]=(v%10)+'0';while(v/=10);while(i)p(t[--i]);P;}
#define J(vt)S>>(vt&v){if(sb()){v=0;bool n=(*ip=='-');if(*ip=='-'||*ip=='+')ip++;char ch;while((ch=g())>' '){v*=10;v+=ch-'0';}if(n)v=-v;}P;}
const static int BL=1<<20;bool f;char t[BL],ib[BL],*ip,*ie,ob[BL],*op,*oe;void fb(){ie=ib+fread(ib,1,sizeof(ib),stdin);ip=ib;if(ie==ib)*ip='\0';}char g(){if(ip>=ie)fb();return*ip++;}bool sb(){for(;;){if(ip>=ie)fb();if(!*ip){f=true;return 0;}if(*ip>' ')return 1;ip++;}}void ff(){fwrite(ob,1,op-ob,stdout);op=ob;}IO(){f=false;fb();op=ob;oe=ob+sizeof(ob);}~IO(){ff();}S>>(char&v){if(!(v=g()))f=true;P;}S>>(char*b){if(sb())while((*b=g())>' ')b++;*b='\0';P;}S>>(string&s){if(*this>>t)s=string(t);P;}S<<(char v){p(v);P;}S<<(const char*b){while(*b)p(*b++);P;}S<<(const string&s){P<<s.c_str();}operator bool(){return!f;}void p(char v){if(op>=oe)ff();*op++=v;}O(int)O(unsigned int)O(long long)O(unsigned long long)J(int)J(unsigned int)J(long long)J(unsigned long long)
#undef S
#undef P
#undef O
#undef J
#define cin io
#define cout io
#define endl ('\n')
}io;


const int
	MAXN = 1 << 17;

int N, ans;
int roomCount[MAXN];
int room[MAXN];
int boss[MAXN];
int from[MAXN];
int busyRooms[MAXN];
struct event
{
	int pos, id, isStart;
	bool operator < (const event& e) const
	{
		if (pos != e.pos) return pos < e.pos;
		return isStart < e.isStart;
	}
} events[MAXN * 2];

bool canUniquelyReach(int a, int b)
{
	while (1)
	{
		if (a == b)
		      return true;
		      
		if (ans - busyRooms[a] > 1)
			break;

		a = from[a];
		if (a < 0) break;
	}
	
	return false;
}

int main()
{
	int T;
	for (cin >> T; T--;)
	{
		int E = 0;
		
		cin >> N;
		REP(i, N)
		{
			int start, end;
			cin >> start >> end;
			
			events[E++] = (event){start, i, 1};
			events[E++] = (event){end, i, 0};
			
			boss[i] = -1;
		}

		queue< int > Q;
		sort(events, events + E);

		ans = 0;
		for (int i = 0, j; i < E; i = j)
		{
			int currBusy = ans - Q.size();
			for (j = i; j < E && events[j].pos == events[i].pos; j++)
			{
				if (events[j].isStart)
				{
					if (Q.empty())
						Q.push(ans++);

					int prof = events[j].id;

					busyRooms[prof] = currBusy;
					room[prof] = Q.front();
					from[prof] = boss[Q.front()];
					boss[Q.front()] = prof;
				
					Q.pop();
				}
				else
				{
					currBusy--;
					Q.push(room[ events[j].id ]);
				}
			}
		}
		
		if (room[0] == room[1])
		{
			if (canUniquelyReach(0, 1) || canUniquelyReach(1, 0))
			      ans++;
		}
		
		printf( "%d\n", ans );
	}

	return 0;
}
