/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
PSN 2007 #91 "Confusi¢n en la secuencia"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXM 10001
#define MODULO 1000000007

int N, M, i, j, a, b, t;
int C[2][MAXM];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;

  C[a = 1][0] = 1;
  for ( i = 1; i <= N; i++ ) {
    t = 0;
    a ^= 1; b ^= 1;
    for ( j = 0; j <= M; j++ ) {
      t += C[b][j];
      if ( j >= i ) t -= C[b][j - i];
      if ( t < 0 ) t += MODULO;
      C[a][j] = t %= MODULO;
    }
  }
  
  fout << C[a][M] << endl;

  return 0;
}

/*
91þ Confusi¢n en la secuencia.                            Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Considere una secuencia de N enteros donde cada entero est  entre 1  y
N apareciendo exactamente una vez.

Un  par de  n£meros en  la  secuencia  est  confuso  si el  numero  de
dicho par que aparece primero  en la  secuencia es  mas grande  que el
otro numero en dicho par.

La confusion de la secuencia es  el numero de pares confusos en  esta.
Por ejemplo, la confusi¢n de la secuencia (1, 4, 3, 2) es 3 porque hay
3 pares confusos: (4, 3), (4, 2) y (3, 2).

Escriba un programa que calcule el numero de secuencias de longitud  N
cuya confusi¢n es exactamente C.

Entrada

La primera y unica l¡nea del fichero de entrada ZBRKA.IN contiene dos enteros,
N (1 <= N <= 1000) y C (0 <= C <= 10000).

Salida

Escriba hacia el  fichero de  salida ZBRKA.OUT el numero de   secuencias
modulo 1 000 000 007.

Ejemplos de Entrada y Salida

Ejemplo # 1       Ejemplo # 2       Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ ZBRKA.IN  ³    ³ ZBRKA.IN  ³     ³ ZBRKA.IN  ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 10 1      ³    ³ 4 3       ³     ³ 9 13      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ    ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ ZBRKA.OUT ³    ³ ZBRKA.OUT ³     ³ ZBRKA.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 9         ³    ³ 6         ³     ³ 17957     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ    ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ
*/
