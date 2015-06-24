/*
Alfonso Alfonso Peterssen
19 - 6 - 2007
PSN 2007 #85 "Chocolate"
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define problem "d"
#define all(v) v.rbegin(), v.rend()
#define tr( v ) for ( typeof( v.begin() ) it = v.begin(); it != v.end(); it++ )

typedef pair< int, int > pii;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int N, M, i, j, sol, cnt[2] = { 1, 1 };
vector< pii > v;

int main() {  
  fin >> N >> M;
  for ( i = 0; i < N - 1; i++ ) {
    fin >> j;
    v.push_back( pii ( j, 0 ) );
  }
  for ( i = 0; i < M - 1; i++ ) {
    fin >> j;
    v.push_back( pii ( j, 1 ) );
  }
  
  sort( all(v) );
  tr( v ) sol += it->first * cnt[!it->second], cnt[it->second]++;
  
  fout << sol << endl;
  return 0;
}

/*
85þ Chocolate.                                            Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 

A nosotros nos  dan una barra  de chocolate compuesta  por m*n  piezas
cuadradas.  Uno  debe  dividir  la  barra  de  chocolate  en cuadrados
simples. Partes de la barra  de chocolate pueden dividirse a  lo largo
de las  l¡neas verticales   y horizontales  como est n   indicadas por
las l¡neas divisorias en  la figura de  abajo. Una simple  divisi¢n de
una parte   de la   barra de   chocolate a   lo largo   de  una  l¡nea
elegida vertical u  horizontal divide   esa parte  en dos  partes  m s
peque¤as. Cada divisi¢n de  una parte de  la barra de  chocolate tiene
un costo expresado por un entero positivo. Este costo no depende   del
tama¤o de   la   parte  que est    siendo dividida  sino que solamente
depende de la l¡nea que la divide  a lo  largo. Perm¡tanos denotar los
costos de divisi¢n a lo  largo de l¡neas  verticales consecutivas  con
x1,x2,...,xm-1 y a lo largo de l¡neas horizontales con y1,y2,...,yn-1.
El costo de  divisi¢n de la  barra entera en  cuadrados simples es  la
suma de las sucesivas divisiones. Usted debe calcular el costo  m¡nimo
de  dividir toda la  barra de chocolate en cuadrados simples.

             x1      x2      x3      x4      x5
             |       |       |       |       |
     ÚÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ¿
     ³ ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ ³
     ³ ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ ³
     ³ ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ ³
 y1 ÄÅ Ä Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÃÄ Ä
     ³ ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ ³
     ³ ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ ³
     ³ ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ ³
 y2 ÄÅ Ä Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÃÄ Ä
     ³ ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ ³
     ³ ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ ³
     ³ ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ ³
 y3 ÄÅ Ä Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä Ä ÅÄÄ Ä ÄÄÅÄ Ä
     ³ ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ | ÚÄÄÄ¿ ³
     ³ ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ | ³   ³ ³
     ³ ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ | ÀÄÄÄÙ ³
     ÀÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÙ
             |       |       |       |       |

Por   ejemplo,   si  nosotros    dividimos   la  barra  de   chocolate
presentada   en  la   figura  primero  a   lo  largo  de   las  l¡neas
horizontales, y a continuaci¢n cada  una de las partes obtenidas  a lo
largo de  l¡neas  verticales entonces  el  costo de  estas  divisiones
ser : y1 + y2 + y3 + 4 * (x1 + x2 + x3 + x4 + x5).

Tarea

Escriba un programa que: 
- lea los n£meros x1, x2, ..., xm-1 y y1, y2, ..., yn-1,
- calcule el m¡nimo costo de dividir todo la barra de chocolate en
  cuadrados simples,
- escriba el resultado.

Entrada

En  la primera  l¡nea del  fichero de  entrada CZE.IN  aparecer n  dos
enteros positivos m y n separados por  un espacio, 2 <= m, n <=  1000.
En las sucesivas m-1 l¡neas aparecer n los n£meros x1, x2,  ..., xm-1,
uno  por  l¡nea,  1  <=  xi  <=  1000.  En  las  sucesivas n-1  l¡neas
aparecer n los n£meros y1,y2,...,yn-1, uno por l¡nea, 1 <= yi <= 1000. 

Salida

Usted  debe  escribir  el  resultado  hacia  el  fichero  CZE.OUT.  En
la primera  y £nica  l¡nea del  fichero su  programa debe  escribir un
simple    entero   - el  costo m¡nimo   de   dividir   la   barra   de
chocolate  en cuadrados simples.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄ¿
³ CZE.IN  ³   ³ CZE.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄ´
³ 6 4     ³   ³ 42      ³
³ 2       ³   ÀÄÄÄÄÄÄÄÄÄÙ
³ 1       ³
³ 3       ³
³ 1       ³
³ 4       ³
³ 4       ³
³ 1       ³
³ 2       ³
ÀÄÄÄÄÄÄÄÄÄÙ
*/
