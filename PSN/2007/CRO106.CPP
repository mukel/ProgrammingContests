/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #106 "Solitario Vacuno"
*/
#include <fstream>
#include <cassert>
using namespace std;

#define problem "d"
#define MAXN 8

const
  char *card = "A23456789TJQK";

int N, i, j;
int value[256];
int C[MAXN][MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( i = 0; i < 13; i++ )
    value[ card[i] ] = i + 1;

  fin >> N;
  
  for ( i = N; i; i-- )
    for ( j = 1; j <= N; j++ ) {
      char c1, c2;
      fin >> c1 >> c2;
      C[i][j] = value[c1];
    }
    
  for ( i = 1; i <= N; i++ )
    for ( j = 1; j <= N; j++ )
      C[i][j] += max( C[i - 1][j], C[i][j - 1] );

  fout << C[N][N] << endl;

  return 0;
}

/*
106þ Solitario Vacuno.                                      Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El fin del verano  en la granja es  un tiempo lento, muy  lento. Betsy
tiene poco que hacer aparte de jugar solitario. Por razones evidentes,
el solitario vacuno no es tan  desafiante como un n£mero de juegos  de
solitario jugado por humanos.

El solitario vacuno es jugado usando un arreglo N x N (3 <= N <= 7) de
cartas   normales   con  cuatro   palos   (Tr‚boles(C),  Diamantes(D),
Corazones(H), y  Espadas(S)) de  13 cartas  (As, 2,  3, 4,...,  10(T),
Sota(J),  Reina(Q),  Rey(K)).  Las   cartas  son  nombradas  con   dos
caracteres: su valor (A, 2, 3, 4,...,9, T, J, Q, K) seguido de su palo
(C, D, H, S). Aqu¡ hay un arreglo t¡pico cuando N=4:

     8S AD 3C AC     (Ocho de Espadas, As de Diamantes, etc.)
     8C 4H QD QS
     5D 9H KC 7H
     TC QC AS 2D

Para  jugar este  juego de  solitario, Betsy  comienza en  la esquina
inferior izquierda (TC) y procede usando exactamente 2*N-2 movimientos
de 'derecha' o 'arriba' para la esquina superior derecha. A trav‚s del
camino ella acumula puntos  por cada carta (el  As vale 1 punto,  el 2
vale 2 puntos,..., el 9 vale 9 puntos, la T vale 10 puntos, J vale 11,
Q  vale  12,  y K  vale  13)  conforme va  haciendo  el  recorrido. Su
prop¢sito es obtener el m s alto puntaje.

Si el camino  de Betsy hubiera  sido TC-QC-AS-2C-7H-QS-AC, su  puntaje
habr¡a  sido  10+12+1+2+7+12+1=45.  Si  ella  hubiera  tomado  el lado
izquierdo  y  luego hacia  arriba  (TC-5D-8C-8S-AD-3C-AC), su  puntaje
habr¡a sido 10+5+8+8+1+3+1=36, no tan bueno como con la otra ruta.  El
mejor puntaje para este  arreglo es 69 puntos  TC-QC-9H-KC-QD-QS-AC =>
10+12+9+13+12+12+1).

Betsy quiere conocer el mejor  puntaje que ella puede obtener.  Una de
las vacas sabias una vez le  dijo a ella algo acerca de  “trabajar del
final hacia el comienzo”,  pero ella no entendi¢  lo que esta vaca  le
dec¡a.

NOMBRE DEL PROBLEMA: solitair

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero N.

* L¡neas 2..N+1: La l¡nea i+1 tiene una lista de las cartas de la fila
i (la fila 1 es la fila superior) usando N nombres de cartas separadas
por espacio organizados en el orden obvio.

ENTRADA EJEMPLO (archivo solitair.in):

4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D

FORMATO DE SALIDA:

* L¡nea 1: Una sola l¡nea con un entero que es el mejor puntaje posible
que Betsy puede obtener.

SALIDA EJEMPLO (archivo solitair.out):

69
*/
