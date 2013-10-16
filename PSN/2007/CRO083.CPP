/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
PSN 2007 #83 "Mastermind II"
*/
#include <fstream>
#include <cstdlib>
using namespace std;

#define problem "d"
#define MAXN 9

int N;
int seq[MAXN][MAXN];
bool mark[MAXN + 1];
int A[MAXN], B[MAXN];
int pos[MAXN], sol[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

  void comb( int i ) {
    if ( i == N ) {

      /* Check */
      for ( i = 0; i < N; i++ ) {
        int a = 0, b = 0;
        for ( int j = 0; j < N; j++ ) {
          int k = seq[i][j];
          if ( mark[k] )
            if ( pos[k] == j )
                 a += k;
            else b += k;
        }
        if ( a != A[i] || b != B[i] ) return;
      }
      for ( i = 0; i < N; i++ )
        fout << sol[i] << " ";
      exit( 0 );
    }

    for ( int j = 1; j <= 9; j++ )
      if ( !mark[j] ) {
        sol[i] = j;
        pos[j] = i;
        mark[j] = true;
        comb( i + 1 );
        mark[j] = false;
      }
  }

int main() {

  fin >> N;
  for ( int i = 0; i < N; i++ ) {
    fin >> A[i] >> B[i];
    for ( int j = 0; j < N; j++ )
      fin >> seq[i][j];
  }

  comb( 0 );

  return 0;
}

/*
83ş Mastermind II.                                        Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Nosotros  consideraremos  secuencias   en  las  que   encontramos  las
siguientes condiciones:

- la longitud de la secuencia es C,
- los elementos de la secuencia son digitos en el rango de 1 a 9,
- los elementos no est n separados en la secuencia.

Una secuencia simple ser  llamada un c¢digo.

Cuando  dos c¢digos  son dados  nosotros estimamos  su  compatibilidad
d ndole dos n£meros. El primer numero (columna A en el ejemplo) es  la
suma de aquellos digitos que  aparecen en ambos codigos y  aparecen en
la  mismas posiciones  en ambas  secuencias, mientras  que el  segundo
numero (columna  B) es  la suma  de aquellos  digitos que  aparecen en
ambos codigos pero  aparecen en  diferentes posiciones.

A nosotros nos dan C codigos y sus estimaciones de compatibilidad  con
algunos codigos desconocidos. Uno debe encontrar y presentar el codigo
desconocido. Datos  de ejemplo  y un  resultado para  C=3 se presentan
debajo

    A     B              c¢digos

    4     0             4   9   7
    0     10            6   7   4
    0     5             9   4   1

  c¢digo desconocido    4   1   6

Tarea

Escriba un programa el cual:

- lea desde el fichero de entrada MAS.IN una descripci¢n del c¢digo  y
  la estimaci¢n de su compatibilidad,
- encuentre un c¢digo que re£na las condiciones del problema,
- escriba los resultados hacia el fichero de salida MAS.OUT.

Entrada

Tu programa debe  leer la descripci¢n  de la entrada  desde el fichero
MAS.IN. En la primera linea del  fichero de entrada hay un entero   C,
1 <= C <= 9. En  las  siguientes C l¡neas aparecen la  descripci¢n  de
los  c¢digos  de   los  d¡gitos  dados   y  las  estimaciones   de  su
compatibilidad con algunos c¢digos   desconocidos, uno por  l¡nea.  En
cada  una de  las l¡neas hay   C+2  enteros  no  negativos   separados
por  un espacio. El primero y el segundo numero  son la  estimaci¢n de
la   compatibilidad del  codigo (segun se explico en el ejemplo)  dado
con el  c¢digo desconocido,  y los  £ltimos  C    n£meros  son digitos
diferentes en  el rango  de 1  a 9 formando el c¢digo dado.

Salida

Tu  programa  debe  escribir  hacia  el  fichero  de  salida  MAS.OUT.
Deben aparecer C  digitos  diferentes en   el rango  1-9  formando  el
codigo encontrado, separados entre si por espacios simples.

Usted puede asumir que para los conjuntos de datos existe al menos una
soluci¢n.  Si  para   los  datos  de   entrada existen muchos  c¢digos
que  lo satisfacen,  su  programa  debe   escribir  solamente  uno  de
ellos (arbitrariamente).

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ MAS.IN      ³ ³ MAS.OUT     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3           ³ ³ 4 1 6       ³
³ 4 0 4 9 7   ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 0 10 6 7 4  ³
³ 0 5 9 4 1   ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
