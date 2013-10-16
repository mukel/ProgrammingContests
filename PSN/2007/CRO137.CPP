/*
Alfonso Alfonso Peterssen
12 - 7 - 2007
PSN 2007 #137 "Pruge"
*/
#include <fstream>
using namespace std;

#define problem "d"

long long sol;
int X1, X2, Y1, Y2, i, j;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> X1 >> Y1 >> X2 >> Y2;

  for ( i = X1 | 1; i < X2; i += 2 ) {
    j = min( i, Y2 ) - Y1;
    if ( j > 0 ) sol += j;
  }

  for ( i = Y1 | 1; i < Y2; i += 2 ) {
    j = min( i + 1, X2 ) - X1;
    if ( j > 0 ) sol += j;
  }

  fout << sol << endl;

  return 0;
}

/*
137þ Pruge.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un modelo compuesto por rayas oscuras (son descritas en la figura de
abajo). Intervalos enteros en el primer cuadrante del sistema de
coordenadas rectangulares.
Escriba un programa que encuentre el n£mero total de cuadrados oscuros
dentro de  un rect ngulo dado.

                   
                   ÃÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄ¿
                   ³±±³±±³±±³±±³±±³±±³±±³±±³
                   ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                   ³  ³  ³  ³  ³  ³  ³  ³±±³
                   ÃÄÄÅÄÄÉÍÍØÍÍØÍÍØÍÍØÍÍ»ÄÄ´
                   ³±±³±±º±±³±±³±±³±±³  º±±³
                   ÃÄÄÅÄÄ×ÄÄÅÄÄÅÄÄÅÄÄÅÄÄ×ÄÄ´
                   ³  ³  º  ³  ³  ³±±³  º±±³
                   ÃÄÄÅÄÄ×ÄÄÅÄÄÅÄÄÅÄÄÅÄÄ×ÄÄ´
                   ³±±³±±º±±³±±³  ³±±³  º±±³
                   ÃÄÄÅÄÄÈÍÍØÍÍØÍÍØÍÍØÍÍ¼ÄÄ´
                   ³  ³  ³  ³±±³  ³±±³  ³±±³
                   ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                   ³±±³±±³  ³±±³  ³±±³  ³±±³
                   ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
                   ³  ³±±³  ³±±³  ³±±³  ³±±³
                ÄÄÄÅÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÁÄÄÄÄÄÄ
                   ³

Entrada

La primera  y £nica  l¡nea del  fichero de  entrada PRUGE.IN  contiene
cuatro enteros X1, Y1, X2,  Y2 -las coordenadas del rect ngulo con  la
esquina inferior izquierda (X1, Y1) y la esquina superior derecha (X2,
Y2). 0 <= X1 < X2 <= 1 000 000, 0 <= Y1 < Y2 <= 1 000 000.

Salida

La primera y £nica l¡nea del fichero de salida PRUGE.OUT debe contener
un simple entero  -el  n£mero  total  de cuadrados oscuros  dentro del
rect ngulo dado. Nota: use el tipo entero de 64-bit (int64 en  Pascal,
long long en C/C++).

Ejemplos de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄ¿
³ PRUGE.IN ³        ³ PRUGE.IN  ³         ³ PRUGE.IN ³
ÃÄÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄ´
³ 2 3 7 6  ³        ³ 0 4 2 104 ³         ³ 4 1 7 50 ³
ÀÄÄÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÄÄÄÙ         ÀÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PRUGE.OUT ³       ³ PRUGE.OUT ³         ³ PRUGE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 8         ³       ³ 100       ³         ³ 72        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÙ         ÀÄÄÄÄÄÄÄÄÄÄÄÙ
*/
