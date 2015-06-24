/*
Alfonso Alfonso Peterssen
2 - 7 - 2007
IOI 2006 Day 2 Task 1
PSN 2007 #4 "El valle de Mexico"
Version Recursiva
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 2000

int V, E, i, j, k;
bool path[MAXV][MAXV];
bool R[MAXV][MAXV], L[MAXV][MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

  void print( int i, int j, int k ) {
    if ( i > j ) return;
    if ( k ) { // Left -> i
      if ( R[i + 1][j] && path[i][ j % V ] )
             print( i + 1, j, 0);
        else print( i + 1, j, 1);
      fout << i + 1 << endl;
    } else {   // Right -> j
      if ( L[i][j - 1] && path[i][ j % V ] )
             print( i, j - 1, 1 );
        else print( i, j - 1, 0 );
      fout << j + 1 << endl;
    }
  }

int main() {

  fin >> V >> E;
  for ( i = 0; i < E; i++ ) {
    fin >> j >> k;
    j--; k--;
    path[j][k] = path[k][j] = true;
  }

  for ( i = 0; i < V; i++ )
    L[i][i] = R[i][i] = path[i][i] = true;

  /* DP */
  for ( k = 1; k < V; k++ )
    for ( i = 0; i < V; i++ ) {
      j = i + k;
      L[i][j] = ( R[i + 1][j] && path[i][ j % V ] ) ||
                ( L[i + 1][j] && path[ ( i + 1 ) % V ][i] );

      R[i][j] = ( L[i][j - 1] && path[ i ][ j % V ] ) ||
                ( R[i][j - 1] && path[ ( j - 1 ) % V ][ j % V ] );
    }

  for ( i = 0; i < V; i++ )
    if ( L[i][ V + i - 1 ] || R[i][ V + i - 1 ] ) break;

  if ( i < V ) {
    j = ( L[i][ V + i - 1 ] ) ? 1 : 0;
    print( i, V + i - 1, j );
  } else fout << -1 << endl;

  return 0;
}

/*
4þ El valle de Mexico.                                    Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La Ciudad de M‚xico est  construida en un hermoso valle conocido  como
el Valle de M‚xico que, hace  muchos a¤os, era un lago. Alrededor  del
a¤o 1.300, los jefes religiosos aztecas  decretaron que el centro  del
lago  deber¡a   ser llenado  para  construir all¡,  la  capital de  su
imperio. Hoy, el lago es totalmente relleno.

Antes  de  que  los aztecas  llegaran,  c   ciudades estaban  ubicadas
alrededor  del  lago  sobre sus  orillas.  Algunas  de estas  ciudades
establecieron acuerdos comerciales. . Las mercader¡as se transportaban
usando barcos entre las ciudades que ten¡an acuerdos. Era posible unir
dos ciudades cualesquiera por un segmento de recta a trav‚s del lago.

Al  final,  los  reyes  de  las  ciudades  decidieron  organizar  este
comercio. Dise¤aron  una ruta  de comercio  que conectaba  cada ciudad
alrededor del lago. La ruta cumpl¡a con los siguientes requisitos:  •
Se puede comenzar en cualquier ciudad, visitando cada ciudad alrededor
del lado y finalmente terminar en una ciudad distinta a la cual  hab¡a
iniciado el recorrido.  •	En la  ruta  cada ciudad  debe ser visitada
exactamente  una  vez.  •	 Cada  par  de  ciudades   consecutivamente
visitadas en la ruta deben tener un acuerdo comercial. •	Cada par  de
ciudades consecutivamente  visitadas en  la ruta  deben ser conectadas
por una l¡nea  recta. Es posible  conectar cualquier dos  ciudades por
una l¡nea recta a  trav‚s del lago. •  Para evitar los choques  entre
botes, la ruta nunca debe de cruzarse as¡ mismas.

La figura  muestra el  lago y  las ciudades  alrededor del  mismo. Las
l¡neas (gruesas o finas),  representan los acuerdos comerciales  entre
ciudades. Las l¡neas gruesas representan la ruta comercial  comenzando
en la ciudad 2 y terminando en la ciudad 5.

Esta ruta  nunca se  cruza a  si misma.  No ser¡a  legal, por ejemplo,
construir una ruta que fuera desde 2 a 6  de ah¡ a 5 y de ah¡ a 1,  ya
que la ruta se cruzar¡a a si misma.

Las ciudades en  el lago est n  numeradas de 1  a c, movi‚ndose  en el
sentido de las agujas del reloj.

TAREA

Escribe un programa que, dado el n£mero de ciudades y la lista de  los
acuerdos  comerciales  existente  entre  ellas,  construya  una   ruta
comercial cumpliendo los requerimientos arriba mencionados.

RESTRICCIONES

3 = c = 1 000		Numero de ciudades alrededor del lago.

ENTRADA

Tu  programa  debe  leer la  informaci¢n  desde  el siguiente  fichero
mexico.in

mexico.in	DESCRIPTION 7 9 1 4 5 1 1 7 5 6 2 3 3 4 2 6 4 6 6 7

LINEA  1: Contiene  el entero  c
LINEA  2: Contiene  un entero  n que
representa el n£mero de acuerdos comerciales entre ciudades
PROXIMAS n LINEAS: Cada  l¡nea representa  un £nico  acuerdo comercial
entre dos ciudades. Cada l¡nea contiene dos enteros separados por un
espacio los cuales  representan  a las  dos  ciudades involucradas  en
el acuerdo comercial.

SALIDA

Tu programa deber  dejar su salida en el fichero  mexico.out

mexico.out	DESCRIPCION 2 3 4 1 7 6 5

Si es posible construir una ruta comercial, escribe c l¡neas, cada una
con un entero que representa el  orden como deben ser visitadas en  la
ruta comercial.

Si no es posible construir una ruta comercial bajo los  requerimientos
dados, debes escribir una sola l¡nea con el n£mero -1.

NOTA:  Si  existen  m s  de una  ruta  comercial  que  cumple con  los
requerimientos, cualquiera de ellas ser  considerada v lida.

PUNTUACION

Un grupo de los casos de prueba que suman 40 puntos y cumplir n con el
siguiente requerimiento:

3 <= c <= 20
*/
