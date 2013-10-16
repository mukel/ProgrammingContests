/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #108 "Conteo de Vacas"
*/
#include <fstream>
using namespace std;

#define problem "d"

int N, L, sol;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> L;

  for ( ; N; N-- )
    for ( int x = ++sol; x; x /= 10 )
      if ( x % 10 == L ) x = ++sol * 10;

  fout << sol << endl;

  return 0;
}

/*
108þ Conteo de Vacas.                                     Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  quiere rotular sus  N (1 <=  N <= 1,000,000)  vacas,
pero a las vacas no les gusta tener el d¡gito L (0 <= L <= 9)  escrito
en ellas, por lo tanto ‚l evita usarlo.

Si las vacas est n rotuladas con el conjunto m s peque¤o de N  enteros
positivos que no tienen el d¡gito L, Cu l es el n£mero m s grande que
el Granjero Juan tiene que escribir en cualquier vaca?

NOMBRE DEL PROBLEMA: count

FORMATO DE ENTRADA:

* L¡nea 1: Dos enteros separados por espacio: N y L.

ENTRADA EJEMPLO (archivo count.in):

10 1

DETALLES DE LA ENTRADA:

El Granjero Juan tiene 10 vacas y necesita rotularlas sin usar el d¡gito
1.

FORMATO DE SALIDA:

* L¡nea 1: Un solo entero que es el n£mero m s grande que el Granjero
Juan tiene que escribir en cualquier vaca.

SALIDA EJEMPLO (archivo count.out):

22

DETALLES DE LA SALIDA:

Los 10 n£meros m s peque¤os que ‚l puede usar son: 2, 3, 4, 5, 6, 7, 8,
9, 20, y 22.
*/
