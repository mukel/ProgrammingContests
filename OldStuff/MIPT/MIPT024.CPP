/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #024 "Arithmetica 1.0"
*/
#include <iostream>
#include <algorithm>

using namespace std;

int pos;
string expr;

bool sign( char ch ) {
    return ch == '+' || ch == '-' || ch == '*';
}

int GetExpr();

int GetTerm() {
    int result = 0;
    if ( expr[pos] == '(' ) {
        pos++; // skip (
        result = GetExpr();
        pos++; // skip )
    } else
        while ( pos < expr.size() && expr[pos] != ')' && !sign( expr[pos] ) ) {
            result = result * 10 + expr[pos] - '0';
            pos++;
        }
    return result;
}

int GetExpr() {
    int result = GetTerm();
    for (;;)
        if ( pos < expr.size() && sign( expr[pos] ) ) {
            pos++;
            if ( expr[pos-1] == '+' ) result += GetTerm();
            if ( expr[pos-1] == '-' ) result -= GetTerm();
            if ( expr[pos-1] == '*' ) result *= GetTerm();
        } else
            break;
    return result;
}

int main() {

    cin >> expr;
    cout << GetExpr() << endl;

    return 0;
}
