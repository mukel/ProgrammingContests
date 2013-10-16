#include <cstdio>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

const int
	MAXQ = 500005;

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
} io;

int Q;
int a[MAXQ];
int b[MAXQ];
bool op[MAXQ];

int C;
int coo[2 * MAXQ];

unordered_map< int, int > id;

struct Treap
{
	Treap * child[2];
	int key, prior, cnt, sz;
	Treap() {}
	Treap(int key)
		: key(key), prior((rand() << 15) | rand()), cnt(1), sz(1)
	{
		child[0] = child[1] = 0;
	}
};

void update(Treap * x)
{
	x->sz = x->cnt;
	if (x->child[0]) x->sz += x->child[0]->sz;
	if (x->child[1]) x->sz += x->child[1]->sz;
}

void rotate(Treap *& x, int dir)
{
	Treap * t = x->child[dir];
	x->child[dir] = t->child[1 - dir];
	t->child[1 - dir] = x;
	update(x);
	update(t);
	x = t;
}

void insert(Treap *& x, int val)
{
	if (!x)
	{
		x = new Treap(val);
		return ;
	}

	if (val == x->key)
	{
		x->cnt++;
		x->sz++;
		return ;
	}

	int dir = !(val < x->key);
	insert(x->child[dir], val);
	if (x->child[dir]->prior > x->prior)
		rotate(x, dir);

	update(x);
}

int queryLessEq(Treap * x, int val)
{
	if (!x) return 0;

	if (val == x->key)
	{
		int r = x->cnt;
		if (x->child[0])
			r += x->child[0]->sz;
		return r;
	}

	if (val < x->key)
		return queryLessEq(x->child[0], val);
	else
	{
		int k = x->sz;
		if (x->child[1]) k -= x->child[1]->sz;
		return queryLessEq(x->child[1], val) + k;
	}
}

Treap * T[2 * MAXQ];

void update(int a, int b)
{
	for (; b > 0; b -= (b & -b))
	{
		insert(T[b], a);
	}
}

int query(int a, int b)
{
	int r = 0;
	for (; b <= C; b += (b & -b))
	{
		if (T[b])
			r += queryLessEq(T[b], a);
	}
	return r;
}

int main()
{

	cin >> Q;

	for (int i = 0; i < Q; ++i)
	{
		char __op[5];
		cin >> __op >> a[i] >> b[i];
		//scanf( "%s %d %d", __op, &a[i], &b[i] );
		op[i] = (__op[0] == '+');
		coo[C++] = a[i];
		coo[C++] = b[i];
	}

	sort(coo, coo + C);
	C = unique(coo, coo + C) - coo;
	for (int i = 0; i < C; ++i) id[ coo[i] ] = i+1;

	for (int i = 0; i < Q; ++i)
	{
		a[i] = id[a[i]];
		b[i] = id[b[i]];
	}

	for (int i = 0; i < Q; ++i)
	{
		if (op[i]) update(a[i], b[i]);
		else cout << query(a[i], b[i]) << "\n"; //printf( "%d\n", query(a[i], b[i]) );
	}

	return 0;
}
