/*
Alfonso Alfonso Peterssen
7 - 7 - 2007
PSN 2007 #110 "Pal¡ndromo m s Barato"
*/
#include <fstream>
#include <climits>
#include <cstring>
using namespace std;

#define problem "d"
#define MAXLEN 2000

int L, len, i, j, k;
char ch;
string st;
int cost[CHAR_MAX];
int C[MAXLEN][MAXLEN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> L >> len;
  fin >> st;
  for ( i = 0; i < L; i++ ) {
    fin >> ch >> j >> k;
    cost[ch] = min( j, k );
  }

  for ( k = 1; k < len; k++ )
    for ( i = 0; i < len - k; i++ ) {
      j = i + k;
      if ( st[i] == st[j] ) C[i][j] = C[i + 1][j - 1];
      else {
        C[i][j] = min( C[i + 1][j] + cost[ st[i] ],
                       C[i][j - 1] + cost[ st[j] ] );
      }
    }

  fout << C[0][len - 1] << endl;

  return 0;
}

/*
110þ Pal¡ndromo m s Barato.                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Llevar registro de todas las vacas puede ser una tarea engorrosa, por
lo tanto el Granjero Juan ha instalado un sistema para automatizarlo.
El ha instalado en cada vaca una tarjeta electr¢nica de Identificaci¢n
que el sistema leer  conforme las vacas pasen por un esc ner. Los
contenidos de cada tarjeta de Identificaci¢n est n contenidos
realmente en una sola cadena de M (1 <= M <= 2,000) caracteres de
longitud de un alfabeto de N (1 &lt;= N &lt;= 26) s¡mbolos posibles (es
decir, las min£sculas del alfabeto romano).

Las vacas, siendo tan traviesas como son, algunas veces tratan de
enga¤ar el sistema caminando hacia atr s. Mientras que la tarjeta de
una vaca cuya Identificaci¢n sea “abcba” se leer  los mismo sin
importar en que direcci¢n ella camine, una vaca con Identificaci¢n
“abcb” puede registrarse potencialmente con dos Identificaciones
diferentes (“abcb” y “bcba”).

A GJ le gustar¡a cambiar las tarjetas de identificaci¢n de las vacas
de tal manera que se lean lo mismo no importando en que direcci¢n la
vaca camine. Por ejemplo, “abcb” puede ser cambiada a¤adi‚ndole “a” al
final para formar “abcba” de tal manera que la Identificaci¢n es
palindr¢mica (se lee lo mismo hacia delante que hacia atr s). Algunas
otras maneras de convertir la Identificaci¢n en un pal¡ndromo son
a¤adir las tres letras “bcb” al principio para producir la
Identificaci¢n “bcbabcb” o remover la letra “a” para producir “bcb”.
Uno puede a¤adir o remover caracteres en cualquier ubicaci¢n en la
cadena produciendo una cadena m s larga o m s corta que la cadena
original.

Desafortunadamente como las tarjetas de Identificaci¢n son
electr¢nicas, cada inserci¢n o borrado tiene un costo (0 <= costo <=
10,000) el cual varia dependiendo en exactamente que valor de car cter
deber ser a¤adido o borrado. Dado el contenido de la tarjeta de
Identificaci¢n de una vaca y el costo de insertar o borrar cada uno de
los caracteres del alfabeto, encuentre el costo m¡nimo de cambiar la
tarjeta de Identificaci¢n para satisfacer los requerimientos de GJ. Se
considera que una tarjeta de identificaci¢n vac¡a satisface los
requerimientos de leerse lo mismo hacia delante o hacia atr s. Solo se
a¤adir n letras con costos asociados a la cadena.

NOMBRE DEL PROBLEMA: cheappal

FORMATO DE ENTRADA:

* L¡nea 1: Dos enteros separados por enteros, N y M.

* L¡neas 2: Esta l¡nea contiene exactamente M caracteres los que
         constituyen la cadena inicial de Identificaci¢n.


* L¡neas 3..N+2: Cada l¡nea contiene tres entidades separadas por
         espacio: un car cter del alfabeto de entrada y dos enteros
         los cuales son respectivamente el costo de a¤adir y de
         borrar ese car cter.

ENTRADA EJEMPLO (archivo cheappal.in):

3 4
abcb
a 1000 1100
b 350 700
c 200 800

DETALLES DE LA ENTRADA:

La identificaci¢n es “abcb” con estos costos de operaci¢n:
   Insertar Borrar
a  1000     1100
b   350      700
c   200      800


FORMATO DE LA SALIDA:

* L¡nea 1: Una sola l¡nea con un solo entero que es el costo m¡nimo
para cambiar la Identificaci¢n dada.

SALIDA EJEMPLO (archivo cheappal.out):

900

DETALLES DE LA SALIDA:

Si insertamos una “a” al final para obtener “abcba”, el costo ser¡a
1000. Si borramos la “a” al comienzo para obtener “bcb”, el costo
ser¡a 1100. Si insertamos “bcb” al comienzo de la cadena, el costo
ser¡a 350+200+350=900, el cual es el m¡nimo.
*/

