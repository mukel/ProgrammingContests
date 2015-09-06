// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

int A, B;

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    int a = A, b = 0, answer = 0;
    while (1)
    {
        answer += a;
        b += a;
        a = (b / B);
        b -= B * (b / B);
        if (a == 0 && b < B) break;
    }

    cout << answer << endl;

    return 0;
}