#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long int64;
#define endl (&#39;\n&#39;)

const double PI = atan(1)*4;

double calc(double ab, double ad, double dc) {
    const double D_120 = 120 * PI / 180;
    double ac = sqrt(dc*dc + ad*ad - 2*dc*ad* cos(D_120)); 
    double t = (dc*dc - ad*ad - ac*ac) / (-2*ad*ac);
    double dac = acos(t);
    double bac = D_120 - dac;
    return 0.5*ab*ac*sin(bac) + 0.5*ad*dc*sin(D_120);
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef LOCAL
        cin.tie(0);
    #endif
    
    double a1, a2, a3, a4 ,a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    
    double area = calc(a1, a2, a3) + calc(a4, a5, a6);
    int ans = round(area / (sqrt(3) / 4));
    cout << ans << endl;
    
    return 0;
}
