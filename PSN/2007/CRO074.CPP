/*
Alfonso Alfonso Peterssen
19 - 6 - 2007
PSN 2007 #74 "Kaos"
*/
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define problem "d"
#define MAXLEN 100
#define MAXN 100000
#define all( v ) v.begin(), v.end()
#define tr( v ) for ( typeof ( v.begin() ) it = v.begin(); it != v.end(); it++ )

int N;
string st;
long long sol;
vector< pair< string, int > > v;

struct {
  int t[MAXN + 1];
  inline int lobit( int x ) { return x & -x; }
  int operator ()( int a, int b ) {
    int sum = 0;
    for (    ; b; b -= lobit(b) ) sum += t[b];
    for ( a--; a; a -= lobit(a) ) sum -= t[a];
    return sum;
  }

  void update( int a ) {
    for ( ; a <= N; a += lobit(a) ) t[a]++;
  }
} ABI;

int main() {
  ifstream fin ( problem ".in" );
  ofstream fout ( problem ".out" );
    
  fin >> N;
  for ( int i = 0; i < N; i++ ) {
    fin >> st;
    v.push_back( pair< string, int > ( st, 0 ) );
  }

  sort( all( v ) );
  tr ( v ) {
     reverse( all( it->first ) );
     it->second = it - v.begin() + 1;
  }
  sort( all( v ) );

  tr( v ) {
    sol += ABI( it->second + 1, N );
    ABI.update( it->second );
  }

  fout << sol << endl;

  return 0;
}

/*
74þ Kaos.                                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Al  peque¤o Lovro  le gusta   jugar juegos  con palabras. Durante  las
£ltimas semanas ‚l se dio cuenta que algunas palabras no son similares
entre si.

Las palabras A  y B no  son similares entre  si, si la  palabra A est 
lexicograficamente  antes de la  palabra  B, pero  la palabra B'  est 
lexicograficamente  antes de  la palabra  A', donde  X' representa  la
palabra X invertida (si  X="kamen" entonces X'="nemak"). Por  ejemplo,
la palabra "lova"   y "novac" se   parecen entre si,   pero la palabra
"aron"  y  "sunce" no  se parecen  entre si.  Dado algun  conjunto  de
palabras, nosotros  definimos  el grado  de  caos de  el conjunto como
el n£mero   de pares   de diferentes  de palabras  que  no  se parecen
entre si.

Tarea

Escriba un programa  que, dado un  conjunto de palabras,  encuentre el
grado del caos para el conjunto.

Entrada

La primera linea del fichero de entrada KAOS.IN contiene un entero  N,
2 <= N <= 100000. Cada   una de las siguientes N lineas  contiene  una
palabra - una secuencia de a lo sumo 10 letras min£sculas del alfabeto
Ingles ('a'-'z'). No habr  dos palabras id‚nticas en el conjunto.

Salida

La primera  linea del  fichero de  salida KAOS.OUT  contiene un entero
simple - el grado del caos del conjunto dado de palabras.

Nota: utilice  un tipo  entero con  signo de  64-bit (int64 en Pascal,
long long ein C/C++).

Ejemplos de Entrada y Salida

Ejemplo # 1      Ejemplo # 2       Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄ¿
³ KAOS.IN  ³     ³ KAOS.IN  ³      ³ KAOS.IN  ³
ÃÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄ´
³ 2        ³     ³ 4        ³      ³ 14       ³
³ lopta    ³     ³ lova     ³      ³ branimir ³
³ kugla    ³     ³ novac    ³      ³ vladimir ³
ÀÄÄÄÄÄÄÄÄÄÄÙ     ³ aron     ³      ³ tom      ³
ÚÄÄÄÄÄÄÄÄÄÄ¿     ³ sunce    ³      ³ kruz     ³
³ KAOS.OUT ³     ÀÄÄÄÄÄÄÄÄÄÄÙ      ³ bred     ³
ÃÄÄÄÄÄÄÄÄÄÄ´     ÚÄÄÄÄÄÄÄÄÄÄ¿      ³ pit      ³
³ 0        ³     ³ KAOS.OUT ³      ³ zemlja   ³
ÀÄÄÄÄÄÄÄÄÄÄÙ     ÃÄÄÄÄÄÄÄÄÄÄ´      ³ nije     ³
                 ³ 3        ³      ³ ravna    ³
                 ÀÄÄÄÄÄÄÄÄÄÄÙ      ³ ploca    ³
                                   ³ ko       ³
                                   ³ je       ³
                                   ³ zapalio  ³
                                   ³ zito     ³
                                   ÀÄÄÄÄÄÄÄÄÄÄÙ
                                   ÚÄÄÄÄÄÄÄÄÄÄ¿
                                   ³ KAOS.OUT ³
                                   ÃÄÄÄÄÄÄÄÄÄÄ´
                                   ³ 48       ³
                                   ÀÄÄÄÄÄÄÄÄÄÄÙ
*/
