/*
Alfonso Alfonso Peterssen
11 - 8 - 2007
USACO 2005 NOV Bronze "Asegurando el Establo"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXL 17

int L, C, i;
int freq[256], letter[2];
char sol[MAXL];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

  int is_vowel( char x ) {
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
  }

  void comb( char ch, int len ) {

    if ( len == L ) {
      if ( letter[1] > 0 && letter[0] > 1 )
        fout << sol << endl;
      return ;
    }

    for ( ;ch <= 'z'; ch++ )
      if ( freq[ch] ) {
        sol[len] = ch;
        letter[ is_vowel( ch ) ]++;
        freq[ch]--;
        comb( ch + 1, len + 1 );
        freq[ch]++;
        letter[ is_vowel( ch ) ]--;
      }
  }

int main() {

  fin >> L >> C;
  for ( i = 0; i < C; i++ ) {
    char ch;
    fin >> ch;
    freq[ch]++;
  }

  comb( 'a', 0 );

  return 0;
}

/*
Problema 11: Asegurando el Establo [Tradicional, 2005]

El Granjero Juan ha instalado un nuevo sistema de seguridad en el establo y ahora
deben dar un password válido a las vacas en el rebaño. Un password válido
consiste de L (3 <= L <= 15) letras minúsculas (del conjunto tradicional de
caracteres latinos 'a'...'z'), que tenga al menos una vocal ('a', 'e', 'i',
'o', o 'u'),al menos dos consonantes (no-vocales), y tenga los caracteres
en orden alfabético ('abc'es válido; 'bac' no lo es).

Dada la longitud deseada L junto con C caracteres en minúscula, escriba un
programa que imprima todos los passwords válidos de tamaño L que pueden ser
formados a partir de esas letras. Los passwords deben ser impresos en orden
alfabético, uno por lìnea.

NOMBRE DEL PROBLEMA: passwd

FORMATO DE ENTRADA:

* Lìnea 1: Dos enteros separados por espacio, L y C

* Lìnea 2: C caracteres en minúscula separados por espacios que son el
        conjunto de caracteres a partir del cual se construirán los
        passwords.

ENTRADA EJEMPLO (archivo passwd.in):

4 6
a t c i s w

DETALLES DE LA ENTRADA:

Passwords de tamaño 4 elegidos de seis caracteres dados.

FORMATO DE SALIDA:

* Líneas 1..?: Cada línea de salida contiene una palabra de tamaño L (sin
        espacios). Las líneas de salida deben aparecer en orden alfabético.

SALIDA EJEMPLO (archivo passwd.out):

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/
