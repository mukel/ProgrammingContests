/*
Alfonso Alfonso Peterssen
12 - 7 - 2007
PSN 2007 #134 "El Trovador"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 101

int V, E, songs, cnt, sol;
bool bard;
int ls[MAXV];
bool mark[MAXV][MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  int i, j, k;

  fin >> V >> E;
  for ( i = 0; i < E; i++ ) {
    fin >> cnt;
    for ( j = 0; j < cnt; j++ ) {
      fin >> ls[j];
      if ( ls[j] == 1 ) bard = true;
    }

    if ( bard ) {
      songs++;
      bard = false;
      mark[1][songs] = true;
      for ( j = 0; j < cnt; j++ )
        mark[ ls[j] ][songs] = true;
    }
    else {
      for ( j = 0; j < cnt; j++ )
        for ( k = 1; k <= songs; k++ )
          mark[1][k] |= mark[ ls[j] ][k];

      for ( j = 0; j < cnt; j++ )
        for ( k = 1; k <= songs; k++ )
          mark[ ls[j] ][k] = mark[1][k];
    }

  }

  for ( i = 1; i <= V; i++ ) {
    for ( j = 1; j <= songs; j++ )
      if ( !mark[i][j] ) break;
    if ( j > songs ) fout << i << endl;
  }

  return 0;
}

/*
134þ El Trovador.                                         Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Cada tarde los aldeanos de una  peque¤a villa se juntan al rededor  de
una gran fogata y cantan canciones.

Un sobresaliente miembro de la comunidad es el trovador.  Cada  tarde,
si el trovador est  presente, el canta una  Teodora canci¢n nueva  que
ning£n aldeano halla escuchado antes, y no otra canci¢n es cantada esa
noche. En  el caso  que el  trovador no  est  presente,   otro aldeano
canta sin ‚l intercambiado todas las canciones que ellos conocen.

Dada una lista  de aldeanos presentes  por E tardes  consecutivas,  la
salida debe tener todos los  aldeanos que conocen todas las  canciones
durante ese periodo.

Entrada

La primera l¡nea del fichero de entrada BARD.IN contiene  un entero N,
1 <= N <= 100, el n£mero de aldeanos. Los aldeanos son enumerados de 1
hasta N. El aldeano n£mero 1 es el trovador. La segunda l¡nea contiene
un entero E, 1 <= E <= 50, el n£mero de tardes. Las pr¢ximas E  l¡neas
contiene  la  lista de  los aldeanos  presente en  cada una  de las  E
tardes. Cada l¡nea  comienza con un entero positivo K, 2 <= K <= N, el
n£mero  de  aldeanos  presentes  esa  tarde,  seguido  por  K  enteros
positivos separados por espacios representando los aldeanos.

No aldeanos  aparecer n dos  veces en  una noche  y el trovador deber 
aparecer una vez para todas las noches.

Salida

La  salida ser   hcia el  fichero BARD.OUT  el cual  tendr  todos  los
aldeanos que conocen todas  las canciones, incluyendo al  trovador, un
entero por l¡nea en orden accedente.

Ejemplos de Entrada y Salida:

 Ejemplo #1         Ejemplo #1          Ejemplo #1
ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ BARD.IN  ³       ³ BARD.IN   ³       ³ BARD.IN   ³
ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 4        ³       ³ 8         ³       ³ 5         ³
³ 3        ³       ³ 5         ³       ³ 3         ³
³ 2 1 2    ³       ³ 4 1 3 5 4 ³       ³ 2 1 3     ³
³ 3 2 3 4  ³       ³ 2 5 6     ³       ³ 2 2 1     ³
³ 3 4 2 1  ³       ³ 3 6 7 8   ³       ³ 4 2 1 4 5 ³
ÀÄÄÄÄÄÄÄÄÄÄÙ       ³ 2 6 2     ³       ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄ¿       ³ 4 2 6 8 1 ³       ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ BARD.OUT ³       ÀÄÄÄÄÄÄÄÄÄÄÄÙ       ³ BARD.OUT  ³
ÃÄÄÄÄÄÄÄÄÄÄ´       ÚÄÄÄÄÄÄÄÄÄÄÄ¿       ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 1        ³       ³ BARD.OUT  ³       ³ 1         ³
³ 2        ³       ÃÄÄÄÄÄÄÄÄÄÄÄ´       ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4        ³       ³ 1         ³
ÀÄÄÄÄÄÄÄÄÄÄÙ       ³ 2         ³
                   ³ 6         ³
                   ³ 8         ³
                   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
*/
