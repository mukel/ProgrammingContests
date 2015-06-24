/*
Alfonso Alfonso Peterssen
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const string pot[15] =
{ "2(0)",
  "2",
  "2(2)",
  "2(2+2(0))",
  "2(2(2))",
  "2(2(2)+2(0))",
  "2(2(2)+2)",
  "2(2(2)+2+2(0))",
  "2(2(2+2(0)))",
  "2(2(2+2(0))+2(0))",
  "2(2(2+2(0))+2)",
  "2(2(2+2(0))+2+2(0))",
  "2(2(2+2(0))+2(2))",
  "2(2(2+2(0))+2(2)+2(0))",
  "2(2(2+2(0))+2(2)+2)" };

int main() {

  int x, y;
  cin >> x; y = x;
  
  string sol;
  
  for ( int i = 0; x; i++, x /= 2 )
    if ( x & 1 ) {
      if ( sol == "" )
           sol = pot[i];
      else sol = pot[i] + "+" + sol;
    }

  cout << y << "=" << sol << endl;
  
  return 0;
}
