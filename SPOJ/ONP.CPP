/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #4 "Transform the Expression"
*/
#include <iostream>
#include <cstring>
using namespace std;

int T, pos;
string expr, sol;

  void eval() {
    char sign, ch;
    while ( ( ch = expr[ ++pos ] ) != ')' )
      if ( ch == '(' ) eval();
      else if ( ch >= 'a' && ch <= 'z' ) cout << ch;
      else sign = ch;
    cout << sign;
  }

int main() {

  for ( cin >> T; T; T-- ) {
    cin >> expr;
    pos = 0;
    sol.clear();
    eval();
    cout << endl;
  }

  return 0;
}
