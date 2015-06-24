/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Otro Juego de Números de Vacas"
*/
#include <fstream>
using namespace std;

#define problem "d"

int N, sol;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( fin >> N; N != 1; sol++ )
    if ( N & 1 )
         N = 3 * N + 1;
    else N /= 2;

  fout << sol << endl;

  return 0;
}

/*
Problema 1: Otro Juego de Números de Vacas [Tradicional, 2006]


Las vacas están jugando nuevamente un juego tonto de números. Bessie
está cansada de perder y quiere que usted la ayude en su trampa. En
este juego, una vaca da un número N (1 <= N <= 1,000,000). Esta es la
movida 0. Si N es impar, entonces el número N se multiplica por 3 y se
incrementa en 1. Si N es par el número es divido por 2. Cada vez que
se  multiplica o divide  el número, el puntaje aumenta en un punto. El
juego termina – y el puntaje se finaliza – cuando N se vuelve 1.

Aquí hay un ejemplo de N comenzando con 5:


        N     Valor Sig    Comentario   Puntaje
        5        16          3*5+1       1
       16         8           16/2       2
        8         4            8/2       3
        4         2            4/2       4
        2         1            2/2       5


El puntaje final es 5.

NOMBRE DEL PROBLEMA: acng

FORMATO DE ENTRADA:

* Línea 1: Un solo entero, N


ENTRADA EJEMPLO (archivo acng.in):

112

FORMATO DE SALIDA:

* Línea 1: Un solo entero que es el puntaje para este juego cuando se
       comienza con N

SALIDA EJEMPLO (archivo acng.out):

20
*/
