// Alfonso2 Peterssen (mukel)
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long int64;

#define SZ(c) ((int)(c).size())
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, l, h) for (int i = (int)(l); i <= (int)(h); ++i)
#define FOREACH(it, c) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

typedef complex< double > point;

#define xx real()
#define yy imag()


point rotate(const point p, double angle)
{
    return p * point(cos(angle), sin(angle));
}

point rotateAt(point p, point at, double angle)
{
    return rotate(p - at, angle) + at;
}

point perp(const point p)
{
    return point(-p.yy, p.xx);
}

const double EPS = 1e-5;

point cutPoint(point p1, point p2, point q1, point q2)
{
    double a1 = p2.yy - p1.yy;
    double b1 = p1.xx - p2.xx;
    double c1 = a1 * p1.xx + b1 * p1.yy;

    double a2 = q2.yy - q1.yy;
    double b2 = q1.xx - q2.xx;
    double c2 = a2 * q1.xx + b2 * q1.yy;

    double det = a1 * b2 - a2 * b1;

    return point((b2 * c1 - b1 * c2) / det, (a1 * c2 - a2 * c1) / det);
}


double sqr(double x)
{
    return x * x;
}

double dist(point a, point b)
{
    return sqrt(sqr(a.xx - b.xx) + sqr(a.yy - b.yy));
}

point readPoint()
{
    double x, y;
    cin >> x >> y;
    return point(x, y);
}

point A, B, C;

int main()
{
    ios_base::sync_with_stdio(false);

/*
    cout << "0 0" << endl;
    cout << "1 0" << endl;
    cout << cos(M_PI/3) << " " << sin(M_PI/3) << endl;
    return 0;*/

    A = readPoint();
    B = readPoint();
    C = readPoint();

    A -= C;
    B -= C;

    point a2 = A * 0.5;
    point b2 = B * 0.5;

    point center = cutPoint(a2, a2 + perp(A), b2, b2 + perp(B));

    //cout << "center = " << center.xx << " " << center.yy << endl;

    for (int i = 3; i <= 100; ++i)
    {
        double innerAngle = 2 * M_PI / i;//M_PI * (i - 2) / i;

        int cnt = 0;
        for (int j = 1; j < i; ++j)
        {
            point p = rotateAt(point(0, 0), center, j * innerAngle);
            if (dist(p, A) < EPS) cnt++;
            if (dist(p, B) < EPS) cnt++;

        }

        if (cnt == 2)
        {
            //cout << i << endl;
            double r = dist(point(0, 0), center);
            double area = i * r * r * sin(2 * M_PI / i) / 2;
            printf( "%.12lf\n", area );
            break;
        }
    }

    return 0;
}




