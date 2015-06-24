/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #021 "Fraction"
*/
#include <iostream>

using namespace std;

int pos;
string expr;
struct kk {
    int lo, hi, delta;
} sol;

bool sign( char ch ) {
    return ch == '+' || ch == '-' || ch == '*';
}

kk GetExpr();

kk GetTerm() {

    int lo, hi, delta;
    lo = hi = delta = 0;

    if ( expr[pos] == '{' ) {
        pos++; // skip {
        kk num = GetExpr();
        pos++; // skip }
        pos++; // skip /
        pos++; // skip {
        kk den = GetExpr();
        pos++; // skip }
        hi >?= num.lo + num.hi;
        lo >?= den.lo + den.hi;
        delta = ( num.delta >? den.delta ) + 2;
    } else
        while ( pos < expr.size() && expr[pos] != '}' && !sign( expr[pos] ) ) {
            pos++;
            delta++;
        }

    return (kk){ lo, hi + 1, delta };
}

kk GetExpr() {
    int lo, hi, delta;
    lo = hi = delta = 0;
    for (;;) {
        kk term = GetTerm();
        hi >?= term.hi;
        lo >?= term.lo;
        delta += term.delta;
        if ( pos < expr.size() && sign( expr[pos] ) ) {
            pos++; // skip sign
            delta++; // add sign
        } else
            break;
    }
    return (kk){ lo, hi, delta };
}

int main() {

    cin >> expr;
    sol = GetExpr();
    cout << sol.delta << " "
         << sol.lo + sol.hi << endl;

    return 0;
}
