/*
Alfonso Alfonso Peterssen
14 - 8 - 2007
USACO 2005 MAR Silver "Fabrica de Yoghurt"
*/
#include <fstream>
using namespace std;

#define problem "d"

int N, S, i, j;
int last, now, delivery;
long long sol;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> S;

  last = 123456;
  for ( i = 0; i < N; i++ ) {

    fin >> now >> delivery;

    if ( now <= S * ( i - j ) + last ) {
      j = i;
      last = now;
    }

    sol += ( S * ( i - j ) + last ) * delivery;
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 6: Fabrica de Yoghurt [Tiankai Liu, 2004]

Las vacas han comprado una fábrica de yoghurt que hace el mundialmente
famoso Yoghurt Yucky. En las siguientes N (1 <= N <= 10,0000) semanas,
el precio de la leche y de la mano de obra fluctuarán semanalmente de
tal manera que le costará a la compañía C_i (1 <= C_i <= 5,000)
centavos producir una unidad de yoghurt en la semana i. Como la
fábrica Yucky está bien diseñada, puede producir cantidades
arbitrarias de yoghurt cada semana.

Yucky Yoghurt tiene un almacén que puede almacenar yoghurt no usado
con un costo constante de S (1 <= S <= 100) centavos por unidad de
yoghurt por semana. Afortunadamente, el yoghurt no se daña. El almacén
de Yucky Yoghurt es enorme, por lo tanto puede almacenar cantidades
arbitrarias de unidades de yoghurt.

Yucky Yoghurt quiere encontrar una manera de hacer sus entregas
semanales de Y_i (0 <= Y_i <= 10,000) unidades de yoghurt a su
clientela (Y_i es la cantidad de entregas en la semana i). Ayude a
Yucky a minimizar sus costos en todo el período de N semanas. El
yoghurt producido en la semana i, así como cualquier yoghurt
almacenado, puede ser usado para cubrir la demanda de Yucky para esa
semana.

NOMBRE DEL PROLEMA: yogurt

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio, N y S.

* Líneas 2..N+1: La línea i+1 contiene dos enteros serrados por
    espacio: C_i y Y_i.

ENTRADA EJEMPLO (archivo yogurt.in):

4 5
88 200
89 400
97 300
91 500

FORMATO DE SALIDA:

* Línea 1: La línea 1 contiene un solo entero: el costo total mínimo
    de satisfacer los pedidos de yoghurt. Note que el total podría ser
    muy grande para un entero de 32 bits.

SALIDA EJEMPLO (archivo yogurt.out):

126900

DETALLES DE LA SALIDA:

En la semana 1, se producen 200 unidades de yoghurt y se entregan
todas. En la semana 2, se producen 700 unidades: se entregan 400 y se
almacenan 300. En la semana 3, se entregan las 300 unidades que fueron
almacenadas. En la semana 4, se producen y se entregan 500 unidades.
*/
