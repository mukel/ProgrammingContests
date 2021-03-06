/*
Alfonso Alfonso Peterssen
7 - 8 - 2007
USACO 2005 DEC Gold "Patrones de Vacas"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXP 25001
#define MAXT 100001
#define ALPHA 26

int T, P, S, i, j, sol;
int pat[MAXP], text[MAXT];
int pos[MAXT], pre[MAXP];
int frqP[MAXP][ALPHA], frqT[MAXT][ALPHA];

  void update( int *f1, int *f2, int value ) {
    for ( int i = 1; i <= S; i++ )
      f1[i] = f2[i];
    f1[value]++;
  }

  bool match( int len, int end, int a, int b ) {

    int idx1[ALPHA], cnt1 = 0,
        idx2[ALPHA], cnt2 = 0;

    for ( int i = 1; i <= S; i++ ) {
      if ( frqP[len][i] ) cnt1++;
      if ( frqT[end][i] - frqT[end - len][i] ) cnt2++;
      idx1[i] = cnt1;
      idx2[i] = cnt2;
    }

    return ( cnt1 == cnt2 ) &&
           ( idx1[a] == idx2[b] );
  }

ifstream fin( problem ".in" );
ofstream fout( problem ".out" );

int main() {

  fin >> T >> P >> S;
  for ( i = 1; i <= T; i++ )
    fin >> text[i];

  for ( i = 1; i <= P; i++ )
    fin >> pat[i];

  /* Preprocess */
  j = 0;
  for ( i = 1; i <= P; i++ ) {

    update( frqP[i], frqP[i - 1], pat[i] );
    update( frqT[i], frqT[i - 1], pat[i] );

    if ( i == 1 ) continue;
    while ( j && !match( j + 1, i, pat[j + 1], pat[i] ) )
      j = pre[j];

    j++;
    pre[i] = j;
  }

  /* Search */
  j = 0;
  for ( i = 1; i <= T; i++ ) {

    update( frqT[i], frqT[i - 1], text[i] );

    while ( j && !match( j + 1, i, pat[j + 1], text[i] ) )
      j = pre[j];

    j++;
    if ( j == P ) {
      pos[sol++] = i - P + 1;
      j = pre[j];
    }
  }

  fout << sol << endl;
  for ( i = 0; i < sol; i++ )
    fout << pos[i] << endl;

  return 0;
}

/*
Problema 1: Patrones de Vacas [Brian Dean, 2005]

A los miembros de un subgrupo importante de K (1 <= K <= 25,000) de
las vacas del Granjero Juan (GJ) les gusta meterse en problemas.
Cuando son puestas en una fila, estas revoltosas se mantienen juntas
en un orden particular. Con la finalidad de ubicar a estas revoltosas,
GJ ha alineado sus N (1 <= N <= 100,000) vacas. Las vacas desfilar�n
frente a GJ entrando al establo, permaneciendo en orden. GJ necesita
su colaboraci�n para ubicar bloques sospechosos de K vacas dentro de
esta alineaci�n que podr�an estar potencialmente formados por las
vacas revoltosas.

GJ identifica a sus vacas por el n�mero de manchas 1..S en el lomo de
cada vaca (1 <= S <= 25). Aunque no es un m�todo perfecto, sirve para
su prop�sito. GJ no recuerda el n�mero exacto de manchas de cada vaca
en el grupo de revoltosas. El puede, sin embargo, recordar cu�les
vacas en el grupo tienen el mismo n�mero de manchas, y cu�l de
cualquier par de vacas tiene m�s manchas (si tienen diferente n�mero
de manchas). El describe tal patr�n como una secuencia de K rangos en
el rango 1..S. Por ejemplo, considere esta secuencia:

  1 4 4 3 2 1

En este ejemplo, GJ est� buscando una secuencia consecutiva de 6 vacas
entre sus N vacas alineadas. Las vacas #1 y #6 de esta secuencia
tienen el mismo n�mero de manchas (a pesar que este n�mero no es
necesariamente 1) y ellas tienen el menor n�mero de manchas de las
vacas #1... #6 (al estar marcadas como '1'). La vaca #5 tiene el
segundo n�mero mas peque�o de manchas, diferente al de todas las otras
vacas #1... #6. Las vacas #2 y #3 tienen el mismo n�mero de manchas, y
este n�mero es el mayor de todas las vacas #1... #6.

Si el conteo real de manchas de alguna secuencia de vacas es:

5 6 2 10 10 7 3 2 9

Entonces �nicamente la subsecuencia 2 10 10 7 3 2  coincide con el
patr�n dado antes por GJ.

Por favor ayude a GJ a ubicar todas las subsecuencias de tama�o k en
su alineaci�n de vacas que coincidan con su patr�n especificado.


NOMBRE DEL PROBLEMA: cpattern

FORMATO DE ENTRADA:

* L�nea 1: Tres enteros N, K y S separados por espacios.

* L�neas 2..N+1: La l�nea i+1 describe el n�mero de manchas de la vaca
         i.

* L�neas N+2..N+K+i: La l�nea i+N+1 describe el rango patr�n de la
        vaca i.

ENTRADA EJEMPLO (archivo cpattern.in):

9 6 10
5
6
2
10
10
7
3
2
9
1
4
4
3
2
1

DETALLES DE LA ENTRADA:

La entrada ejemplo corresponde al ejemplo dado en el enunciado del
problema.

FORMATO DE SALIDA:

* L�nea 1: El n�mero de �ndices, B, en los cuales hay coincidencia con
        el patr�n.

* L�neas 2..B+1: Un �ndice (en el rango 1..N) el cual es la ubicaci�n
        inicial de una coincidencia del patr�n.

SALIDA EJEMPLO (archivo cpattern.out):

1
3

DETALLES DE LA SALIDA:

Hay solo una coincidencia, en la posici�n 3 dentro de la alineaci�n de
N vacas de GJ.
*/
