// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/*inclusive*/template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e+1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()

int A, B;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> A >> B;
	
	for (int ax : range(A))
	for (int ay : range(A)) {
		if (ax*ax + ay*ay != A*A)
			continue ;
			
		if (ax * B % A == 0 && ay * B % A == 0)
		{
			int bx = -ay * B / A;
			int by =  ax * B / A;
			
			if (ax == 0 || ay == 0) continue ;
			if (bx == 0 || by == 0) continue ;
			
			int dx = ax - bx;
			int dy = ay - by;
			if (dx == 0 || dy == 0) continue ;
			
			printf( "YES\n0 0\n%d %d\n%d %d\n", ax, ay, bx, by);
			return 0;
		}
	}
	
	printf("NO\n");
	
	return 0;
}
