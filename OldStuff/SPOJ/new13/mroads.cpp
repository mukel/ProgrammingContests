/*
Alfonso2 Peterssen
SPOJ #4483 "Roads Repair"
13 - 8 - 2010
*/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cstring>

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
	MAXV = 1 << 17;

int V, K, E;
int first[MAXV];
int minCost[MAXV];
int maxCost[MAXV];
bool notLeaf[MAXV];
struct edge
{
	int v, a, b, next;
} edges[2 * MAXV];

void preDfs(int u = 0, int from = -1, int currMaxCost = 0, int currMinCost = 0)
{
	for (int e = first[u]; e != -1; e = edges[e].next)
	{
		int v = edges[e].v;
	      if (v == from) continue ;
	      notLeaf[u] = true;

	      preDfs(v, u, currMaxCost + edges[e].a, currMinCost + edges[e].b);
	      
	      maxCost[u] = max(maxCost[u], maxCost[v]);
		minCost[u] = max(minCost[u], minCost[v]);
	}
	
	if (!notLeaf[u])
	{
		maxCost[u] += currMaxCost;
		minCost[u] += currMinCost;
	}
}

int totalMoney, targetDist;
void dfs(int u = 0, int from = -1, int currMoney = 0)
{
	for (int e = first[u]; e != -1; e = edges[e].next)
	{
		int v = edges[e].v;
		if (v == from) continue ;

		if (maxCost[v] - currMoney <= targetDist)
		      continue ;

		int delta = edges[e].a - edges[e].b;
		int need = maxCost[v] - currMoney - targetDist;

		if (need > delta)
		{
			totalMoney += delta;
			dfs(v, u, currMoney + delta);
		} else
		      totalMoney += need;
	}
}

int getMoney(int dist)
{
	if (dist < minCost[0]) return (int)1e9; // impossible
	if (dist >= maxCost[0]) return 0; // no cost
	
	targetDist = dist;
	totalMoney = 0;
	dfs();
	return totalMoney;
}

int main()
{
	memset(first, -1, sizeof(first));

	cin >> V >> K;
	REP(i, V - 1)
	{
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		u--; v--;
		edges[E] = (edge){v, a, b, first[u]}; first[u] = E++;
		edges[E] = (edge){u, a, b, first[v]}; first[v] = E++;
	}
	
	preDfs(0);
	
	int lo = minCost[0];
	int hi = maxCost[0];
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (getMoney(mid) > K)
		      lo = mid + 1;
		else
		      hi = mid - 1;

	}
	
	cout << hi + 1 << endl;

	return 0;
}
