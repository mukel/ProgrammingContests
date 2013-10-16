/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Bronze "Palindrome"
*/
#include <fstream>
#include <cstring>
using namespace std;

#define problem "d"

int i;
string st, sol;

  void check( int i, int j ) {

    while ( i >= 0 && j < st.size() &&
            st[i] == st[j] ) i--, j++;

    if ( j - i > sol.size() )
      sol = st.substr( i + 1, j - i - 1 );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> st;

  for ( i = 0; i < st.size(); i++ ) {
    check( i, i );
    check( i, i + 1 );
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 12: Palindrome [Tradicional, 2004]

Un palindrome es una serie de dígitos (o de letras, si usted quiere)
que se leen lo mismo hacia delante y hacia atrás. El número 12344321
es un palíndrome, así como 12321 y 3. El número 2468 no es un
palíndrome.

Lea un número de hasta 75 dígitos del archivo de entrad y encuentre el
palíndrome más grande que ocurre en este número. El palíndrome estará
en cualquier parte y podrá  de dos dígitos hasta todos los dígitos del
número y se garantiza que será único.

NOMBRE DEL PROBLEMA: pal

FORMATO DE ENTRADA:

* Línea 1: Un solo número de hasta 75 dígitos de longitud

ENTRADA EJEMPLO (archivo pal.in):

82910341234565432158735

FORMATO DE SALIDA

* Línea 1: El palíndrome mas grande que se encuentre en cualquier
    lugar en el número.

SALIDA EJEMPLO (archivo pal.out):

12345654321

DETALLES DE LA SALIDA:

8291034-->12345654321<--58735
*/
