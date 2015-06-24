/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OCT Silver "Propina"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 20

int N, salary, debt, i, j, weeks;

struct coin {

  int value, cant;

  bool operator < ( const coin &x ) const {
    return value < x.value;
  }

} ls[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> salary;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].value >> ls[i].cant;

  sort( ls, ls + N );

  for (;;) {

    debt = salary;

    for ( i = N - 1; i >= 0; i-- )
      while ( ls[i].cant && ls[i].value <= debt ) {
        ls[i].cant--;
        debt -= ls[i].value;
      }

    if ( debt )
      for ( i = 0; i < N; i++ )
        if ( ls[i].cant && ls[i].value >= debt ) {
          ls[i].cant--;
          debt -= ls[i].value;
          break;
        }

    if ( debt > 0 ) break;
    else weeks++;
  }

  fout << weeks << endl;

  return 0;
}

/*
Problema 7: Propina [Brian Dean, 2004]


Como recompensa por producción lechera, el Granjero Juan (GJ)ha
decidido comenzar a pagarle a Bessie, la vaca, una pequeña propina. GJ
tiene un conjunto de monedas en N (1 <= N <= 20)  denominaciones
diferentes, donde cada denominación de moneda divide exactamente la
siguiente denominación más grande. (por ejemplo, monedas de 1 centavo,
monedas de 5 centavos, monedas de 10 centavos, y monedas de 50
centavos). Usando el conjunto dado de monedas, a él le gustaría
pagarle a Bessie al menos una cantidad dada de dinero C (1 <= C <=
100,000,000) cada semana. Por favor ayudele a calcular el màximo
número de semanas en que él puede pagarle a Bessie.

NOMBRE DEL PROBLEMA: allow

FORMATO DE ENTRADA:

* Lìnea 1: Dos enteros separados por espacio: N y C

* Lìneas 2..N+1: Cada lìnea corresponde a una denominación de monedas
        y contiene dos enteros: el valor V V (1 <= V <= 100,000,000)
        de la denominación, y el número de monedas B (1 <= B <=
        1,000,000) de esta denominación que tiene el Granjero Juan en
        posesión.

ENTRADA EJEMPLO (archivo allow.in):

3 6
10 1
1 100
5 120

DETALLES DE LA ENTRADA:

GJ quisiera pagarle a Bessie 6 centavos por semana. El tiene 100
monedas de 1 centavo, 120 de 5 centavos, 1 moneda de 10 centavos.

FORMATO DE SALIDA:

*Lìnea 1: Un solo entero que es el número de semanas en las que el
        Granjero Juan puede pagarle a Bessie al menos C como
        propina.

SALIDA EJEMPLO (archivo allow.out):

111

DETALLES DE LA SALIDA:

GJ Puede pagarle a Bessie con la moneda de 10 centavos por 1 semana,
luego pagarle a Bessie con dos monedas de 5 centavos por 10 semanas y
luego pagarle a Bessie con una moneda de 1 centavo y una moneda de 5
centavos por 100 semanas.
*/
