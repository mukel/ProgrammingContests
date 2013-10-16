/*
Alfonso2 Peterssen(mukel)
SPOJ #7600 "Milk Trading"
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

#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int64;

#define PB(x) push_back(x)
#define SZ(c) ((int)((c).size()))
#define MP(x, y) make_pair((x), (y))
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for (int i = (int)b; i <= (int)(e); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define DBG(x) cout << #x << " = " << x << endl

int n;
int64 ans;
deque< pair<int, int> > S, B;


#include <cstdio>
#include <iostream>
using namespace std;
struct IO{static const int MB = 1<<25;bool eof;char tb[MB],ib[MB+1],ob[MB],*ip,*ibe,*op,*obe;inline void fb(){ibe=ib+fread(ib,1,sizeof(ib),stdin);ip=ib;*ibe='\0';}inline char gc(){if(ip>=ibe)fb();return*ip++;}inline bool sb(){while(1){if(ip>=ibe)fb();if(!*ip){eof=1;return 0;}if(*ip>' ')return 1;ip++;}}inline operator bool(){return !eof;}inline void pc(char ch){if(op>=obe)ff();*op++=ch;}IO(){eof=0;fb();op=ob;obe=ob+sizeof(ob);}~IO(){ff();}inline void ff(){fwrite(ob,1,op-ob,stdout);op=ob;}
#define ioOp inline IO& operator
#define rt return *this
ioOp>>(char &v){if(!(v=gc()))eof=1;rt;}ioOp>>(char *buff){if(sb())while((*buff=gc())>' ')buff++;*buff='\0';rt;}ioOp>>(string &str){if(*this>>tb)str=string(tb);rt;}ioOp<<(char v){pc(v);rt;}ioOp<<(const char *buff){while(*buff)pc(*buff++);rt;}ioOp<<(const string &str){rt<<str.c_str();}
#define defOp(vt) ioOp>>(vt& v){if (sb()){v=0;bool neg=(*ip=='-');if(*ip=='-'||*ip=='+')ip++;char ch;while((ch=gc())>' '){v*=10;v+=ch-'0';}if(neg)v=-v;}rt;}
defOp(int)defOp(unsigned int)defOp(long long)defOp(unsigned long long)
#undef defOp
#define defOp(vt) ioOp<<(register vt v){if(v<0){pc('-');v=-v;}int i=0;do tb[i++]=(v%10)+'0';while(v/=10);while(i)pc(tb[--i]);rt;}
defOp(int)defOp(unsigned int)defOp(long long)defOp(unsigned long long)
#undef defOp
#undef ioOp
#undef rt
#define cin io
#define cout io
#define endl ('\n')
}io;


int main()
{
	cin >> n;
	REP(i, n)
	{
		int x; cin >> x;
		if (x < 0) // buy
		{
			x = -x;
			while (!S.empty() && x) // while there are sellers
			{
				int cnt = min(x, S.back().first);
				ans += cnt * (i - S.back().second);
				
				x -= cnt;
				S.back().first -= cnt;
				
				if (!S.back().first) S.pop_back();
			}
			if (x) B.push_back(MP(x, i));
		}
		else // sell
		{
			while (!B.empty() && x)
			{
				int cnt = min(x, B.back().first);
				ans += cnt * (i - B.back().second);
				
				x -= cnt;
				B.back().first -= cnt;

				if (!B.back().first) B.pop_back();
			}
			if (x) S.push_back(MP(x, i));
		}
	}

	cout << ans << endl;

	return 0;
}
