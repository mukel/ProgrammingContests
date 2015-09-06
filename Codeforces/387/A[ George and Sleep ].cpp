// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/* inclusive */template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e + 1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

int toInt(string s)
{
    int r = (s[0] - &#39;0&#39;) * 10 + (s[1] - &#39;0&#39;);
    r *= 60;
    r += (s[3] - &#39;0&#39;) * 10 + (s[4] - &#39;0&#39;);
    return r;
}

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int ss = toInt(s);
    int tt = toInt(t);

    //cout << ss << " " << tt << endl;

    const int MINS_PER_DAY = 60*24;

    int ans = (ss - tt) % MINS_PER_DAY;
    if (ans < 0) ans += MINS_PER_DAY;

    printf( "%02d:%02d\n", ans / 60, ans % 60 );

    return 0;
}
