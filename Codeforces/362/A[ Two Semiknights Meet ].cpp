
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M;
string board[8];

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int offset[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};

typedef pair< int, int > par;

int mark[8][8][8][8];

struct state
{
    int x1, y1, x2, y2;
};

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        vector< par > kni;

        for (int i = 0; i < 8; ++i)
        {
            cin >> board[i];
            for (int j = 0; j < 8; ++j)
                if (board[i][j] == &#39;K&#39;)
                    kni.push_back(make_pair(i, j));
        }

        memset(mark, 0, sizeof(mark));

        state start = (state){kni[0].first, kni[0].second, kni[1].first, kni[1].second};

        queue< state > Q;
        Q.push(start);

        while (!Q.empty())
        {

            state top = Q.front();
            Q.pop();


            REP(i, 4)
            REP(j, 4)
            {
                int x1 = top.x1 + 2*offset[i][0];
                int y1 = top.y1 + 2*offset[i][1];

                if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8)
                    continue ;

                int x2 = top.x2 + 2*offset[j][0];
                int y2 = top.y2 + 2*offset[j][1];

                if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8)
                    continue ;


                if (!mark[x1][y1][x2][y2])
                {
                    mark[x1][y1][x2][y2] = true;
                    Q.push((state){x1, y1, x2, y2});
                }
            }
        }
        
        

            bool canReach = false;

            REP(i, 8)
            REP(j, 8)
                if (board[i][j] != &#39;#&#39; && mark[i][j][i][j])
                    canReach = true;

            cout << (canReach ? "YES" : "NO") << endl;



    }

    return 0;
}

