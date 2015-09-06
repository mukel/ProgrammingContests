// Alfonso2 Peterssen (mukel)
#include <bits/stdc++.h>
using namespace std;
#define endl (&#39;\n&#39;)

template<typename T> struct number_iterator:iterator<random_access_iterator_tag, T>{T v;number_iterator(T v):v(v){}operator T&(){return v;}T operator *(){return v;}};
template<typename T> struct number_range{T b,e;number_range(T b, T e):b(b),e(e){}number_iterator<T> begin(){return b;}number_iterator<T> end(){return e;}};
template<typename T> number_range<T> range(T b,T e){return number_range<T>(b, e);}
template<typename T> number_range<T> range(T e){return number_range<T>(0, e);}

const int
    MAXK = 60;

int K, X, N, M;


long long c12[MAXK], c21[MAXK], c22[MAXK], c1[MAXK], c2[MAXK];
int start[MAXK], fin[MAXK];

string dp[103][3][3][52];

int main(int argc, char* argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> X >> N >> M;

    string letters = "ABC";

    for (auto c: letters)
    {
        string s; s += c;
        dp[1][c - &#39;A&#39;][c - &#39;A&#39;][0] = s;

        //cout << s << endl;
    }

    for (int i = 2; i <= max(N, M); ++i)
    {
        for (auto s1: range(3))
        for (auto f1: range(3))
        for (auto c: range(3))
        for (int k = 0; k <= i/2; ++k)
        {
            if (!dp[i - 1][s1][f1][k].empty())
                dp[i][s1][c][k + (f1 == 0 && c == 2)] = dp[i - 1][s1][f1][k] + (char)(c + &#39;A&#39;);
        }
    }

    //cout << dp[2][0][2][1] << endl;

    c1[1] = 1;
    c2[2] = 1;

    start[1] = 1;
    fin[1] = 1;

    start[2] = 2;
    fin[2] = 2;

    for (int i = 3; i <= K; ++i)
    {
        c1[i] = c1[i - 2] + c1[i - 1];
        c2[i] = c2[i - 2] + c2[i - 1];

        start[i] = start[i - 2];
        fin[i] = fin[i - 1];

        c12[i] = c12[i - 2] + c12[i - 1] + (fin[i - 2] == 1 && start[i - 1] == 2);
        c21[i] = c21[i - 2] + c21[i - 1] + (fin[i - 2] == 2 && start[i - 1] == 1);
        c22[i] = c22[i - 2] + c22[i - 1] + (fin[i - 2] == 2 && start[i - 1] == 2);  
    }

    for (char s1 : letters)
    for (char f1 : letters)
    {
        if (N == 1 && s1 != f1) continue ; 
        for (char s2 : letters)     
        for (char f2 : letters)
        {
            if (M == 1 && s2 != f2) continue ;

            for (int ac1: range(N/2+1))
            for (int ac2: range(M/2+1))
            {
                // suppose is possible

                if (N == 2 && s1 == &#39;A&#39; && f1 == &#39;C&#39; && ac1 != 1) continue ;
                if (M == 2 && s2 == &#39;A&#39; && f2 == &#39;C&#39; && ac2 != 1) continue ;

                long long ac = ac1 * (long long)c1[K] + ac2 * (long long)c2[K];

                ac += c12[K] * 1LL * (f1 == &#39;A&#39; && s2 == &#39;C&#39;);
                ac += c21[K] * 1LL * (f2 == &#39;A&#39; && s1 == &#39;C&#39;);
                ac += c22[K] * 1LL * (f2 == &#39;A&#39; && s2 == &#39;C&#39;);

                if (ac == X)
                {
                    //cout << s1 << ac1 << f1 << endl;
                    //cout << s2 << ac2 << f2 << endl;
                    //cout << endl;
                    
                    if (!dp[N][s1 - &#39;A&#39;][f1 - &#39;A&#39;][ac1].empty() && !dp[M][s2 - &#39;A&#39;][f2 - &#39;A&#39;][ac2].empty())
                    {
                        cout << dp[N][s1 - &#39;A&#39;][f1 - &#39;A&#39;][ac1] << endl;
                        cout << dp[M][s2 - &#39;A&#39;][f2 - &#39;A&#39;][ac2] << endl;

                        return 0;
                    }
                }
            }
        }
    }

    cout << "Happy new year!" << endl;

    return 0;
}