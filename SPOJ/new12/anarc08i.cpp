/*
Alfonso2 Peterssen
SPOJ #4558 "I Speak Whales"
7 - 8 - 2010
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

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


int64 sum(int n, int64 r, int64 lo, int64 hi)
{
	if (!n) return 1;
	
	int64 mid = (1LL << (n - 1));
	
	int64 ans = 0;
	
	if (r < mid) // up
	{
		if (lo < mid) // left
			ans += sum(n-1, r, lo, min(hi, mid - 1));
		if (hi >= mid) // right
			ans += sum(n-1, r, max(lo, mid) - mid, hi - mid);
	}
	else // down
	{
		if (lo < mid) // left
			ans += sum(n-1, r - mid, lo, min(hi, mid - 1));
		if (hi >= mid) // right
			ans += -sum(n-1, r - mid, max(lo, mid) - mid, hi - mid);
	}
	
	return ans;
}

int main()
{
	while (1)
	{
		int N;
		int64 R, S, E;
		cin >> N >> R >> S >> E;
		if (N < 0) break;
		
		cout << sum(N, R, S, E) << endl;
	}

	return 0;
}
