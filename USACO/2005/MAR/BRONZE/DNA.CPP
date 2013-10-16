/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Bronze "Cadenas DNA"
*/
#include <fstream>
#include <cstring>
using namespace std;

#define problem "d"
#define MAXN 100
#define MAXLEN 51

int N, i, j, k, sol;
char st[MAXN][MAXLEN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> st[i];

  for ( i = 0; i < N; i++ )
    for ( j = 0; j < N; j++ )
      if ( i != j ) {

        int len = strlen( st[i] );

        for ( k = 0; k < len; k++ )
          if ( memcmp( ( char* )st[i] + k, st[j], len - k ) == 0 ) {
            sol >?= len - k;
            break;
          }

      }

  fout << sol << endl;

  return 0;
}

/*
Problema 11: Cadenas DNA [Competencia Woburn, 2005]

El Granjero Juan ha encontrado la secuencia DNA de su vaca premiada
como productora de leche, Bessie. Las secuencias de DNA son listas
ordenadas (cadenas) conteniendo uno o más de las letras 'A', 'C', 'G',
y  'T'..

Como es usual para secuencias DNA, los resultados son un conjunto de
cadenas que son secuencias de DNA. Un par de cadenas como 'GATTA' y
'TACA' muy probablemente representan la cadena 'GATTACA' donde los
caracteres superpuestos están mezclados, ya que probablemente ellos
fueron duplicados en el proceso de secuenciación. Generalmente,
mezclar un par de cadenas involucra remover la partes superpuesta más
grande entre las dos cuando ellas son concatenadas. Note que las
superposiciones son entre el final de una cadena y el comienzo de otra
cadena, no en la mitad de una cadena. La cadena 'GATTACA' superpone a
'TTACA' completamente, mientras que las cadenas 'GATTACA' y 'TTA' no
tienen ninguna superosición.

Dado un conjunto de N (2 <= N <= 100) secuencias DNA, todas cuyas
longitudes están en el rango 1..50, encuentre e imprima la longitud de
la superposición más grande entre cualquier par de cadenas.

NOMBRE DEL PROBLEMA: dna

FORMATO DE ENTRADA:

* Línea 1: Un solo entero N

* Líneas 2..N+1: Cada línea contiene una sola subsecuencia DNA

ENTRADA EJEMPLO (archivo dna.in):

4
CGCCAC
TGTCGC
GAATGA
GAGGCGA


DETALLES DE LA ENTRADA:

Cuatro cadenas; cada una de longitudes seis y siete.

FORMATO DE SALIDA:

* Línea 1: Una sola línea que contiene la longitud de la
    superposición más grande entre cualesquiera par de cadenas (en
    cualquier orden)

SALIDA EJEMPLO (archivo dna.out):

3

DETALLES DE LA SALIDA:

CGC comienza la primera cadena y termina la segunda:
   CGCCAC
TGTCGC
Por lo tanto la superposiciòn más grande es 3
*/
