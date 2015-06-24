/*
Alfonso Alfonso Peterssen
20 - 6 - 2007
PSN 2007 #71 "Kokos"
*/
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 10000

#define all( v ) v.begin(), v.end()

int N, M, i, j, sol;
string st;
vector< string > v1, v2;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;
  for ( i = 0; i < N; i++ ) {
    fin >> st;
    v1.push_back( st.substr( 0, M ) );
    v2.push_back( st.substr( M, M ) );
    reverse( all( v2[i] ) );
  }

  sort( all( v1 ) );
  for ( i = 0; i < N - 1; i++ ) {
    j = 0;
    while ( ( j < M ) && ( v1[i][j] == v1[i + 1][j] ) ) j++;
    sol += M - j;
  }

  sort( all( v2 ) );
  for ( i = 0; i < N - 1; i++ ) {
    j = 0;
    while ( ( j < M ) && ( v2[i][j] == v2[i + 1][j] ) ) j++;
    sol += M - j;
  }
  
  sol += 2 * M; // First string

  fout << sol << endl;

  return 0;
}

/*
71þ Kokos.                                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un conjunto  de N  palabras es  dado con  la longitud  de cada palabra
compuesta exactamente por 2K caracteres.

Un grafo  dirigido con  cada v‚rtice  conteniendo una  letra simple es
llamado un  "kokos" si, para   cada palabra en el conjunto,  existe un
camino dirigido en el  grafo tal que las  letras en los v‚rtices  a lo
largo del  camino formen  la palabra.  Adicionalmente, para  todos los
v‚rtices  en   ese  camino   tienen  que   satisfacer  las  siguientes
condiciones:

- el grado de entrada del primer  v‚rtice es 0
- el grado de entrada de los pr¢ximos K-1 v‚rtices es 1
- el grado de salida de los pr¢ximos K-1 v‚rtices es 1
- el grado de salida del £ltimo v‚rtice es 0

En otras  palabras, los  caminos pueden  ramificaese solamente  en las
primeras K letras, y ellos pueden encontrarse solamente en las £ltimas
K letras. Para un conjunto de palabras dadas, nosotros decimos que  el
"kokos" es m¡nimo si el n£mero total  de  v‚rtices es tan peque¤o como
sea posible.

Escriba un programa que encuentre el n£mero de v‚rtices en un kokos
m¡nimo.

Un ejemplo de un kokos m¡nimo (el conjunto de palabras es la
del tercer ejemplo):

      ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿
      ³ E ÃÄ³ F ÃÄ³ E ³Ä³ F ÃÄ´ F ÃÄ´ E ÃÄ¿
      ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ ³
                    ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿ ³  ÚÄÄÄ¿  ÚÄÄÄ¿
               ÚÄÄÄ³ D ÃÄ´ C ÃÄ´ F ÃÄ´ E ÃÄÅÄ´ H ÃÄ´ G ³
               ³    ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ ³  ÀÄÄÄÙ  ÀÄÄÄÙ
               ³                               ÀÄÄ¿
               ³                                  
      ÚÄÄÄ¿  ÚÄÁÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿
      ³ A ÃÄ´ B ÃÄ´ C ÃÄ´ D ³Ä´ E ÃÄ´ F ÃÄ´ G ÃÄ´ H ³
      ÀÄÂÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ
        ³    ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿    
        ÀÄÄÄ³ C ÃÄ´ B ÃÄ´ D ÃÄÄÄÄÙ
             ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ

Le puede parecer que nosotros podemos compactar el grafo as¡:

      ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿
      ³ E ÃÄ³ F ÃÄ³ E ³Ä³ F ÃÄÄÄÄ¿
      ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ    ³
                                    
                    ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿    ÚÄÄÄ¿  ÚÄÄÄ¿
               ÚÄÄÄ³ D ÃÄ´ C ÃÄ´ F ÃÄ´ E ÃÄÂÄ´ H ÃÄ´ G ³
               ³    ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ ³  ÀÄÄÄÙ  ÀÄÄÄÙ
               ³                               ÀÄÄ¿
               ³                                  
      ÚÄÄÄ¿  ÚÄÁÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿
      ³ A ÃÄ´ B ÃÄ´ C ÃÄ´ D ³Ä´ E ÃÄ´ F ÃÄ´ G ÃÄ´ H ³
      ÀÄÂÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ
        ³    ÚÄÄÄ¿  ÚÄÄÄ¿    
        ÀÄÄÄ³ C ÃÄ´ B ÃÄÄÄÄÙ
             ÀÄÄÄÙ  ÀÄÄÄÙ


Sin  embargo,  este grafo   no  es un  kokos   porque los  caminos  se
encuentran en la 4ta letra (D),  y ellos se ramifican en la  6ta letra
(E).

Entrada

La primera l¡nea  del fichero de entrada KOKOS.IN contiene dos enteros
N y K, 1 <= N <= 10 000,  1 <= K <= 100. Cada una de las  siguientes N
l¡neas contiene  una palabra  del conjunto.  Todas las  letras son  en
may£sculas del alfabeto Ingles ('A'-'Z').

Salida

La primera y £nica l¡nea del fichero de salida KOKOS.OUT debe contener
el n£mero de v‚rtices en un kokos m¡nimo.

Ejemplos de Entrada y Salida

Ejemplo #1            Ejemplo #2          Ejemplo #3

ÚÄÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄ¿
³ KOKOS.IN ³          ³ KOKOS.IN ³       ³ KOKOS.IN ³
ÃÄÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄ´
³ 2 4      ³          ³ 4 3      ³       ³ 4 4      ³
³ ABCDEFGH ³          ³ XXZZXX   ³       ³ ABCDEFGH ³
³ EFGHIJKL ³          ³ XXYYZZ   ³       ³ ACBDEFGH ³
ÀÄÄÄÄÄÄÄÄÄÄÙ          ³ AABBCZ   ³       ³ ABDCFEHG ³
                      ³ ABCZZZ   ³       ³ EFEFFEGH ³
                      ÀÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ KOKOS.OUT ³         ³ KOKOS.OUT ³      ³ KOKOS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 16        ³         ³ 18        ³      ³ 23        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ         ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ
*/
