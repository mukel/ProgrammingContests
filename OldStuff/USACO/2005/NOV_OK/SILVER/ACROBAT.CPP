/*
Alfonso Alfonso Peterssen
11 - 8 - 2007
USACO 2005 NOV Silver "Vacas Acróbatas"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 50000
#define oo 1000000000

int N, i, sum, sol;

struct cow {

  int W, S;

  bool operator < ( const cow &x ) const {
    return S + W < x.S + x.W;
  }

} ls[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].W >> ls[i].S;

  sort( ls, ls + N );

  sol = -oo;
  for ( i = 0; i < N; i++ ) {
    sol >?= sum - ls[i].S;
    sum += ls[i].W;
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 7: Vacas Acróbatas [Brian Dean, 2004]

Las N (1 <= N <= 50,000) vacas del granjero Juan (numeradas 1..N)
están planeando escaparse e incorporarse al circo. Sus patas ungulados
les impiden caminar por la cuerda floja y balancearse en el trapecio
(y su último intento de lanzar una vaca por un cañón terminó en un
triste fracaso). Por lo tanto, ellas han decidido practicar figuras
acrobáticas.

Las vacas no son terriblemente creativas y se les ha ocurrido
únicamente una figura acrobática: pararse una encima de otra para
formar una pila vertical de alguna altura. Las vacas están tratando de
encontrar el orden en el que ellas deben ponerse en esta pila.

Cada una de las N vacas tiene asociados un peso (1 <= W_i <= 10,000) y
una fuerza (1 <= S_i <= 1,000,000,000). El riesgo de que una vaca
colapse es igual al peso combinado de todas las vacas encima de ella
(por supuesto sin incluir su propio peso) menos su fuerza (por lo
tanto una vaca más fuerte tiene menos riesgo). Su tarea es determinar
un orden de las vacas que minimice el riesgo más grande de colapsar
para cualquiera de las vacas.

NOMBRE DEL PROBLEMA: acrobat

FORMATO DE ENTRADA:

* Línea 1: Una sola línea con el entero N.

* Líneas 2..N+1: La línea i+1 describe la vaca i con dos enteros
separado
        por un espacio W_i y S_i.

ENTRADA EJEMPLO (archivo acrobat.in):

3
10 3
2 5
3 3

FORMATO DE SALIDA:

*Línea 1: Un solo entero, dando el riesgo más grande de todas las
vacas
        en cualquier ordenamiento óptimo que minimice el riesgo.

SALIDA EJEMPLO (archivo acrobat.out):

2

DETALLES DE LA SALIDA:

Ponga a la vaca con peso 10 en la base. Ella cargará a las otras dos
vacas, por lo tanto su riego de colapsar es 2+3-3=2. Las otras vacas
tienen un riego menor de colapsar.
*/
