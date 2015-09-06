// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
/* inclusive */template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e + 1);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

string S;

int solve(int h)
{
    if (h == 0) return 1;
    int pos = h - 1;
    while (S[h] == &#39;0&#39;) h--, pos -= 2;
    if (pos < 0) return 1;
    if (pos > 0) return solve(h - 1) + 1;
    if (S[0] >= S[h])
        return solve(h - 1) + 1;
    else
        return 1;
}


int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    cout << solve(S.size() - 1) << endl;

    return 0;
}
