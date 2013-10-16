/*
Alfonso Alfonso Peterssen
2 - 7 - 2007
PSN 2007 #44 "Ordenamiento de Vacas"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 10000

int N, i, j, cnt, sol;
pair< int, int > ls[MAXN];
bool mark[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].first, ls[i].second = i;

  sort( ls, ls + N );

  for ( i = 0; i < N; i++ )
    if ( !mark[i] && ls[i].second != i ) {
      j = i; cnt = 0;
      while ( ls[j].second != i ) {
        j = ls[j].second;
        mark[j] = true;
        sol += ls[j].first;
        cnt++;
      }
      sol += min( cnt * ls[i].first,
                  ls[0].first * ( cnt + 2 ) + 2 * ls[i].first );
    }

  fout << sol << endl;

  return 0;
}

/*
44þ Ordenamiento de Vacas.                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N (1 <= N <= 10,000) vacas del Granjero Juan est n alineadas  para
ser orde¤adas en la tarde. Cada vaca tiene un nivel de “mal humor”  en
el rango 1...100,000.  Debido a que  las vacas con  mal humor son  m s
propensas a da¤ar el equipo de orde¤o de GJ, GJ quisiera reordenar las
vacas  en  la  l¡nea  de  tal  manera  que  est‚n  alineadas  en orden
ascendente de  mal humor.  Durante este  proceso, los  lugares de  dos
vacas   cualesquiera   (no  necesariamente   adyacentes)   pueden  ser
intercambiados. Desde que las vacas mal humoradas son m s dif¡ciles de
mover, le  toma a  GJ X+Y  unidades de  tiempo intercambiar  dos vacas
cuyos niveles de mal humor sean X y Y.

Ayude a GJ  a calcular el tiempo m¡nimo requerido para reordenar a las
vacas.

NOMBRE DEL PROBLEMA: csort

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero : N.

- L¡neas 2..N+1: Cada l¡nea contiene un solo entero: la l¡nea i+1
      describe el mal humor de la vaca i.

ENTRADA EJEMPLO (archivo csort.in)

3
2
3
1

DETALLES DE LA ENTRADA:

Tres vacas est n en la l¡nea con niveles de mal humor de
respectivamente 2, 3, y 1.

FORMATO DE SALIDA:

- L¡nea 1: Una sola l¡nea con el tiempo m¡nimo requerido para
      reordenar las vacas en orden creciente de mal humor.

EJEMPLO DE SALIDA (archivo csort.out):

7

DETALLES DE LA SALIDA:

2 3 1 : Orden inicial.
2 1 3 : Despu‚s de intercambiar las vacas con mal humor 3 y 1
        (tiempo=1+3=4).
1 2 3 : Despu‚s de intercambiar las vacas con mal humor 1 y 2
        (tiempo=2+1=3).
*/
