/*
Alfonso Alfonso Peterssen
1 - 9 - 2007
USACO 2006 NOV Gold "Reparación de Cerca"
*/
#include <fstream>
#include <set>
using namespace std;

#define problem "d"

typedef long long int64;

int N, i, j;
int64 sol;

multiset< int64 > heap;
multiset< int64 >::iterator it;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) {
    fin >> j;
    heap.insert( j );
  }

  for ( i = 0; i < N - 1; i++ ) {

    int64 sum = 0;
    it = heap.begin(); sum += *it; heap.erase( it );
    it = heap.begin(); sum += *it; heap.erase( it );

    heap.insert( sum );
    sol += sum;
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 1: Reparación de Cerca [Richard Ho, 2006]

El Granjero Juan (GJ) quiere reparar una pequeña porción del cerco
alrededor de su campo de pasteo. El mide la cerca y encuentra que
necesita N (1 <= N <= 20,000) tablones de madera, cada uno teniendo
alguna longitud entera de Li (1 <= Li <= 50,000) unidades. El entonces
compró un solo tablero con la longitud suficientemente grande como
para partirlo en N tablones (esto es, cuya longitud es la suma de las
longitudes Li). GJ está ignorando el “desperdicio”, la longitud extra
pérdida en aserrín cuando se hace un corte; usted también debe
ignorarlo.

GJ se da cuenta tristemente que él no posee una sierra con la cual
cortar la madera, por lo tanto él va a la Granja del Granjero Don con
su tablero grande y le pide cortésmente si él le puede prestar una
sierra.

El Granjero Don, un capitalista cerrado, no le presta su sierra a GJ.
En lugar de esto se ofrece a cobrarle al Granjero Juan por cada una de
los N-1 cortes en el tablero. El costo de cortar una pieza de madera
es exactamente igual a su longitud. Cortar una plancha de longitud 21
cuesta 21 centavos.

El Granjero Don le permite entonces al Granjero Juan decidir el orden
y las posiciones donde cortar la plancha. Ayude al Granjero Juan a
determinar la mínima cantidad de dinero que puede gastar en crear los
N tablones. GJ sabe que él puede cortar el tablero en varios ordenes
diferentes lo cual resultará en diferentes costos desde que los
tableros intermedios son de longitudes diferentes.

NOMBRE DEL PROBLEMA: plank

FORMATO DE ENTRADA:

* Línea 1: Un entero N, el número de tablones.

* Líneas 2..N+1: Cada línea contiene un solo entero describiendo la
     longitud de un tablón necesitado.

ENTRADA EJEMPLO (archivo plank.in):

3
8
5
8

DETALLES DE LA ENTRADA:

El quiere cortar un tablero de longitud 21 en piezas de longitudes 8,
5, y 8.

FORMATO DE LA SALIDA:

* Línea 1: Un entero: La mínima cantidad de dinero que él debe gastar
     para hacer los N-1 cortes.

SALIDA EJEMPLO (archivo plank.out):

34

DETALLES DE LA SALIDA:

El tablero original mide 8+5+8=21. El primer corte costará 21, y
debería ser usado para cortar el tablero en piezas midiendo 13 y 8. El
segundo corte costará 13, y debería ser usado para cortar el 13 en 8 y
5. Esto costaría 21+13=34. Si en lugar de esto el 21 fuera cortado en
16 y 5, el segundo corte costaría 16 para un total de 37 (lo cual es
más que 34).
*/
