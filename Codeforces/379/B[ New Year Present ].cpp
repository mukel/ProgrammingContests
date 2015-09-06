// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

int N;
int money[1 << 10];

void P() { cout << "P"; }
void L() { cout << "L"; }
void R() { cout << "R"; }

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i : range(N)) cin >> money[i];

    for (int i: range(N))
    {
        while (money[i] > 0)
        {
            P();
            money[i]--;
            if (i + 1 < N)
            {
                R();
                L();
            } else { L(); R(); }
        }
        if (i + 1 < N)
            R();
    }

    return 0;
}