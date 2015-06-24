/*
Alfonso Alfonso Peterssen
11 - 7 - 2007
PSN 2007 #138 "Grad"
*/
#include <fstream>
#include <cmath>
using namespace std;

#define problem "d"
#define MAXV 100

int V, G, D, i, j, k;
int C[MAXV][MAXV];
int X[MAXV], Y[MAXV], R[MAXV];

  inline double dist( int i, int j ) {
    int x = X[i] - X[j], y = Y[i] - Y[j];
    return sqrt( x * x + y * y );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> X[0] >> k;
  X[0] /= 2;

  fin >> G;
  for ( i = 1; i <= G; i++ )
    fin >> X[i] >> Y[i] >> R[i];

  fin >> D;
  V = G + D + 1;
  for ( i = G + 1; i < V; i++ )
    fin >> X[i] >> Y[i];

  for ( i = 0; i < V; i++ )
    for ( j = 0; j < V; j++ )
      C[i][j] = ( dist( i, j ) <= R[i] + R[j] );

  /* Warshall */
  for ( k = 0; k < V; k++ )
  for ( i = 0; i < V; i++ )
  for ( j = 0; j < V; j++ )
    C[i][j] |= C[i][k] && C[k][j];

  for ( i = G + 1; i < V; i++ )
    fout << ( ( C[0][i] ) ? "DA" : "NE" ) << endl;

  return 0;
}

/*
138þ Grad.                                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un sitio de  construcci¢n es definido  como un sistema  de coordenadas
rectangulares con caras paralelas a  los ejes de coordenadas, con  una
esquina en (0, 0) y la esquina opuesta en (X, Y). La entrada al  sitio
est  en  el medio  del lado  de abajo.  Hay N  gr£as en  el sito de la
construcci¢n. Cada  gr£a es  situada en  un punto  del sitio,  y puede
rotar 360 grados y el alcance  m ximo  es conocido para cada gr£a.  El
cami¢n descarga  un pesado  equipamiento  en  la entrada  del sitio  y
despu‚s  el  equipamiento  es  llevado  a  trav‚s  del  sitio  por una
secuencia de movimientos de las gr£a. En cada paso, una gr£a recoge el
equipamiento y  lo lleva  a cualquier  punto del  alcance m ximo de la
gr£a.

Escriba un programa que, dada la lista de K destinaciones  dentro  del
sitio,  determine  para cada  destinaci¢n   si es  posible   llevar el
equipamiento a esta destinaci¢n.

Ver figura GRAD.JPG

Entrada

La primera l¡nea del fichero de entrada GRAD.IN contiene dos enteros X
e Y,  2 <=  X, Y  <= 200,  X son  dados. La  pr¢xima l¡nea contiene un
entero N, 1 <= N <= 50, el n£mero m ximo de gr£as.

Cada una de las  siguientes N l¡neas contiene  tres enteros A, B  y C,
(A, B) es la posici¢n de la gr£a, y C es el m ximo alcance, 0 <= A  <=
X, 0 <= B <= Y, 0 <= C <= 200.

La pr¢xima l¡nea  contiene  un entero  K, 3 <=  K <= 30,  el n£mero de
destinatarios.  Cada  una de  las  siguientes N  l¡neas  contienen dos
enteros D y E - (D, E)  es la posici¢n de uno de los  destinatarios, 0
<= D <= X, 0 <= E <= Y.

Salida

El fichero de salida GRAD.OUT debe contener K l¡neas. Cada una de ella
debe contener la  palabra 'DA' o  'NE', 'DA' significa  que es posible
entregar el equipamiento para  esta destinaci¢n, y 'NE'  significa que
no es posible.

Ejemplos de Entrada y Salida:

 Ejemplo #1          Ejemplo #2          Ejemplo #3
ÚÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄ¿
³ GRAD.IN ³          ³ GRAD.IN ³        ³ GRAD.IN ³
ÃÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄ´
³ 4 4     ³          ³ 6 10    ³        ³ 8 5     ³
³ 2       ³          ³ 3       ³        ³ 4       ³
³ 2 1 1   ³          ³ 3 3 2   ³        ³ 2 1 3   ³
³ 2 3 1   ³          ³ 6 0 3   ³        ³ 4 5 1   ³
³ 4       ³          ³ 0 8 5   ³        ³ 6 4 1   ³
³ 2 2     ³          ³ 5       ³        ³ 5 2 2   ³
³ 3 2     ³          ³ 4 1     ³        ³ 5       ³
³ 1 2     ³          ³ 2 4     ³        ³ 0 2     ³
³ 2 3     ³          ³ 4 10    ³        ³ 0 3     ³
ÀÄÄÄÄÄÄÄÄÄÙ          ³ 5 10    ³        ³ 4 4     ³
ÚÄÄÄÄÄÄÄÄÄÄ¿         ³ 5 9     ³        ³ 7 4     ³
³ GRAD.OUT ³         ÀÄÄÄÄÄÄÄÄÄÙ        ³ 7 5     ³
ÃÄÄÄÄÄÄÄÄÄÄ´         ÚÄÄÄÄÄÄÄÄÄÄ¿       ÀÄÄÄÄÄÄÄÄÄÙ
³ DA       ³         ³ GRAD.OUT ³       ÚÄÄÄÄÄÄÄÄÄÄ¿
³ NE       ³         ÃÄÄÄÄÄÄÄÄÄÄ´       ³ GRAD.OUT ³
³ NE       ³         ³ DA       ³       ÃÄÄÄÄÄÄÄÄÄÄ´
³ DA       ³         ³ DA       ³       ³ DA       ³
ÀÄÄÄÄÄÄÄÄÄÄÙ         ³ DA       ³       ³ DA       ³
                     ³ NE       ³       ³ NE       ³
                     ³ NE       ³       ³ DA       ³
                     ÀÄÄÄÄÄÄÄÄÄÄÙ       ³ NE       ³
                                        ÀÄÄÄÄÄÄÄÄÄÄÙ
*/
