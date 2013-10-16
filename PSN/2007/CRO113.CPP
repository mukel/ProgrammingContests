/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #113 "Petice"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define digit ( N / pot % 10 )

long long N, F, pot = 1;

  int fives( long long x ) {
    int cnt = 0;
    for ( ; x; x /= 10 )
      if ( x % 10 == 5 ) cnt++;
    return cnt;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> F;

  for ( N++; fives( N ) < F; pot *= 10 ) {
    if ( digit > 5 ) N += pot * ( 10 - digit );
    if ( fives( N ) >= F ) break;
    N += pot * ( 5 - digit );
  }

  fout << N << endl;

  return 0;
}

/*
113þ Petice.                                              Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Escriba un  programa que,  dado los  enteros N  y K,  encuentre el m s
peque¤o entero m s grande  que N cuya representaci¢n  decimal contiene
como m¡nimo K ocurrencias de d¡gitos 5.

Entrada

La primera y £nica l¡nea del fichero de entrada PETICE.IN contiene dos
enteros N y K, 1 <= N <= 10^15, 1 <= K <= 15.

Salida

La primera y £nica l¡nea  del fichero de salida PETICE.OUT debe
contener un simple entero -el n£mero m s peque¤o  a partir de la
descripci¢n del la tarea.
Nota: use el tipo entero de 64-bit.
      (int64 en Pascal, long long en C/C++).

Ejemplos de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PETICE.IN ³     ³ PETICE.IN ³      ³ PETICE.IN         ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 99 1      ³     ³ 595 2     ³      ³ 123456789012345 3 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PETICE.OUT ³    ³ PETICE.OUT ³     ³ PETICE.OUT       ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 105        ³    ³ 655        ³     ³ 123456789012355  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ    ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
