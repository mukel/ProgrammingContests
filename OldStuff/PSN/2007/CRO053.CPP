/*
Alfonso Alfonso Peterssen
12 - 7 - 2007
PSN 2007 #53 "Alineamiento Balanceado"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 50001

int N, i, j, k, sol;
int t1[MAXN * 2], t2[MAXN * 2];
int *lo = t1, *hi = t2;

struct cow {
  int pos, color;
  bool operator < ( const cow &x ) const {
    return pos < x.pos;
  }
} ls[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].color >> ls[i].pos;
    
  sort( ls, ls + N );

  lo += N; hi += N;
  for ( i = 0; i < N; i++ ) {
    if ( ls[i].color == 1 ) j++; else j--;
    if ( !lo[j] ) lo[j] = i + 1;
    hi[j] = i;
  }

  for ( i = -N; i < N; i++ )
    if ( hi[i] > lo[i] )
      sol >?= ls[ hi[i] ].pos - ls[ lo[i] ].pos;

  fout << sol << endl;

  return 0;
}

/*
53þ Alineamiento Balanceado.                              Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero  Juan ha  decidido tomar  un retrato  familiar de  algunas
(posiblemente  todas)  de sus  vacas.  Con el  prop¢sito  de tomar  el
retrato, GJ ha organizado todas las N (1 <= N <= 50,000) vacas en  una
l¡nea  recta. Cada  vaca est   rotulada con  su coordenada  x  (rango:
0..1,000,000,000) en la l¡nea y tambi‚n con su raza (0 ¢ 1).

A trav‚s de los a¤os GJ ha hecho algunas cosas locas, y esta actividad
no es la excepci¢n. El sacar¡a foto de un grupo de vacas, y ese  grupo
debe estar ïbalanceadoï. Un grupo contiguo de vacas est   ïbalanceadoï
si contiene el  mismo n£mero de  vacas de cada  una de las  dos razas.
Determine  la  expansi¢n  m s  ancha  de  vacas  que  entrar n  en una
fotograf¡a

La longitud de un grupo balanceado  es la diferencia de los valores  x
entre las vacas m s a-la-izquierda y m s a-la-derecha en el grupo.  Al
menos una vaca de cada raza aparece en la entrada, y ninguna de  vacas
comparten la misma coordenada x.

NOMBRE DEL PROBLEMA: balance

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero: N.

- L¡neas 2..N+1: Cada l¡nea contiene dos enteros separados por espacio
que   describen  una   sola  vaca   conteniendo  respectivamente:   un
identficador de raza y una coordenada x.


ENTRADA EJEMPLO (archivo balance.in):

7
0 11
1 10
1 25
1 12
1 4
0 13
1 22

DETALLES DE LA ENTRADA:

Hay 7 vacas, cinco de raza 1 y dos de raza 0 organizadas de esta manera:

            1                 1  0  1  0                          1        1
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25


FORMATO DE SALIDA:

- L¡nea 1: Un solo entero especificando el tama¤o del grupo balanceado
       m s grande de vacas.

SALIDA EJEMPLO (archivo balance.out):

11

DETALLES DE LA SALIDA:

Las vacas #1 (en 11), #4 (en 12),  #6 (en 13), y #7 (en 22) forman  un
grupo contiguo balanceado ocupando 22-11=11 unidades de longitud en la
l¡nea num‚rica:


                                 <------ grupo balanceado -------->
            1                 1  0  1  0                          1        1
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/
