/*
Alfonso Alfonso Peterssen
5 - 8 - 2007
USACO 2005 DEC Silver "Balanzas"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 40

int N, LIMIT, i, sol;
int W[MAXN];

  void search( int x, int v ) {
    sol >?= LIMIT - v;
    if ( x < 0 ) return;
    if ( W[x] > v )
      search( x - 1, v );
    else
    if ( W[x] + W[x - 1] < v )
      search( x - 1, v - W[x] );
    else {
      search( x - 2, v - W[x] );
      search( x - 2, v - W[x - 1] );
    }
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> LIMIT;
  for ( i = 0; i < N; i++ )
    fin >> W[i];

  search( N - 1, LIMIT );

  fout << sol << endl;

  return 0;
}

/*
Problema 8: Balanzas [Bruce Merry, Sudáfrica, 2005]

El Granjero Juan tiene una balanza para pesar las vacas. El también
tiene un conjunto de N (1 <= N <= 1000) pesas con masas conocidas
(todas las cuales entran en 31 bits) para usar en un lado de la
balanza. El pone una vaca en un lado de la balanza y luego añade pesas
al otro lado hasta que la balanza se equilibre. (GJ no puede poner
pesas en el lado de la balanza donde está la vaca, debido a que las
vacas tienden a patear las pesas en su cara siempre que ellas puedan
hacerlo.) La balanza tiene una capacidad máxima de masa y se romperá
si GJ usa más de cierta masa total C (1 <= C <= 2^30) en un lado.

Las pesas tienen la propiedad curiosa que cuando se alinean desde la
menor a la mayor, cada pesa (desde la tercera en adelante) tiene al
menos tanta como las dos previas combinadas.

GJ quiere determinar la máxima masa para la que él pueda usar sus
pesas para hacer mediciones exactas. Como la masa total no puede ser
mayor que C, él puede no ser capaz de poner todas las pesas en la
balanza.

Escriba un programa, que dada una lista de pesas y la máxima masa que
la balanza puede soportar, determinará la máxima masa legal que él
pueda pesar exactamente.

NOMBRE DEL PROBLEMA: scales

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio: N y C.

* Líneas 2..N+1: Cada línea contiene un solo entero positivo que es la
        masa de una pesa. Se garantiza que las masas vienen en orden
        no decreciente.

ENTRADA EJEMPLO (archivo scales.in):

3 15
1
10
20

DETALLES DE LA ENTRADA:

GJ tiene 3 pesos, con masas de 1, 10, y 20 unidades. El puede poner a
lo más 15 unidades en un lado de su balanza.

FORMATO DE SALIDA:

*Línea 1: Un solo entero el cual es la masa más grande que puede ser
       medida con seguridad y precisión.

SALIDA EJEMPLO (archivo scales.out):

11

DETALLES DE LA SALIDA:

Las pesas 1 y 10 son usadas para medir 11. Cualquier peso mayor que
pueda ser formado por las pesas romperá la balanza.
*/
