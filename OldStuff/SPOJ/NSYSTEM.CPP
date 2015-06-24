/*
Alfonso Alfonso Peterssen
20 - 10 - 2007
SPOJ #1699 "Numeral System"
*/
#include <iostream>
using namespace std;

#define number( ch ) \
  ( ( ch ) == 'm' ? 1000 : \
  ( ( ch ) == 'c' ? 100 :  \
  ( ( ch ) == 'x' ? 10 : 1 ) ) )

#define letter( num ) \
  ( ( num ) == 0 ? 'i' : \
  ( ( num ) == 1 ? 'x' : \
  ( ( num ) == 2 ? 'c' : 'm' ) ) )

int T;
string st1, st2;

  int value( string &st ) {

    int i, dig, res = 0;

    for ( i = 0; i < st.size(); i++ ) {
      if ( st[i] <= '9' ) {
        dig = st[i] - '0'; i++;
      } else dig = 1;
      res += dig * number( st[i] );
    }

    return res;
  }

  string str( int x ) {

    string res;

    for ( int len = 0; x; x /= 10, len++ ) {
      if ( x % 10 > 0 )
        res = letter( len ) + res;
      if ( x % 10 > 1 )
        res = ( char )( ( x % 10 ) + '0' ) + res;
    }

    return res;
  }

int main() {

  for ( cin >> T; T; T-- ) {
    cin >> st1 >> st2;
    cout << str( value( st1 ) + value( st2 ) ) << endl;
  }

  return 0;
}
