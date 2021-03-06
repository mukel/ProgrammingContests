/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2007 FEB Bronze "Compre Uno Obtenga Uno Gratis"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "buyfree"
#define MAXN 10000

int N, M, i, j, k, sol;
int ls1[MAXN], ls2[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;
  for ( i = 0; i < N; i++ ) fin >> ls1[i];
  for ( i = 0; i < M; i++ ) fin >> ls2[i];

  sort( ls1, ls1 + N );
  sort( ls2, ls2 + M );
  
  i = N; j = M;
  while ( --i >= 0 )
    while ( --j >= 0 )
      if ( ls2[j] < ls1[i] ) {
        sol++;
        break;
      }

  fout << sol + N << endl;

  return 0;
}

/*
Problema 13: Compre Uno Obtenga Uno Gratis [Jeffrey Wang, 2007]

El Granjero Juan ha descubierto que el Internet est� comprando fardos de
heno en l�nea cuando �l ha descubierto una oferta especial. �Por cada
fardo de heno de tama�o A (1 <= A <= 1,000,000) que el compre, �l puede
obtener un fardo de heno de tama�o B (1 <= B < A) gratis!

La oferta, sin embargo, tiene sus restricciones: el fardo m�s grande debe
ser de alta calidad y el m�s chico debe ser de baja calidad. GJ, siempre
un tipo frugal y econ�mico, no se preocupa: cualquier calidad de heno le
sirve en tanto �l ahorre alg�n dinero.

Dada una lista de los tama�os de N (1 <=  N <= 10,000) fardos de alta
calidad y M(1 <= M <= 10,000) fardos de baja calidad, encuentre el n�mero
m�ximo de fardos que el Granjero Juan puede comprar. El puede comprar
fardos de alta calidad sin obtener los fardos gratis de baja calidad,
pero �l no puede comparar fardos de baja calidad (esto es, �l debe
obtenerlos gratis en la oferta).

NOMBRE DEL PROBLEMA: buyfree

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio: N y M

* L�neas 2..N+1: La l�nea i+1 contiene un solo entero el cual es el
      tama�o del i-�simo fardo de alta calidad.

* L�neas 2..N+M+1: La l�nea i+N+1 contiene un solo entero el cual es el
      tama�o del i-�simo fardo de baja calidad.

Entrada Ejemplo (archivo buyfree.in):

3 4
6
1
3
1
5
3
4

DETALLES DE LA ENTRADA:

Hay 3 fardos de calidad alta, con tama�os 6, 1, y 3, y 4 fardos de baja
calidad, con tama�os 1, 5, 3, y 4.

FORMATO DE SALIDA:

* L�nea 1: El n�mero total m�ximo de fardos que el Granjero Juan puede
      obtener.

ARCHIVO EJEMPLO (archivo buyfree.out):

5

DETALLES DE LA SALIDA:

Obviamente, el Granjero Juan puede comprar todos los fardos de alta
calidad. Cuando �l compra el fardo de alta calidad de tama�o 6, �l puede
obtener cualquier fardo de baja calidad gratis (por decir, el fardo de
tama�o 3). Cuando �l compra el fardo de alta calidad de tama�o 3, �l
puede obtener el fardo de tama�o 1 de baja calidad. Cuando �l compra el
fardo de alta calidad de tama�o 1, sin embargo, �l no puede obtener
gratis ning�n fardo de baja calidad (desde que el tama�o debe ser
estrictamente menor). El total, no importando cuan inteligente es GJ,
viene a ser 5 fardos.
*/
