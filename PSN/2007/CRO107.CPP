/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #107 "Jard¡n de Flores"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 10001

int N, M, i, j, used;
bool mark[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;
  
  for ( ; M; M-- )
    for ( fin >> i >> j; i <= N; i += j )
      if ( !mark[i] ) {
        mark[i] = true;
        used++;
      }
  
  fout << N - used << endl;

  return 0;
}

/*
107þ Jard¡n de Flores.                                    Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Imagine la sorpresa de Betsy  cuando ella rode¢ el establo  y encontr¢
que le Granjero  Juan ha construido  un invernadero secreto  que ahora
tiene flores maravillosas. Su mente  corri¢ r pidamente y se llen¢  de
visiones de un florido jard¡n en su peque¤a mente bovina.

“Yo pienso  que har‚  una larga  fila de  F (7  <= F <= 10,000) flores
contra la  cerca”, ella  pens¢. “Plantar‚  rosas en  cada tercer hoyo,
begonias en cada s‚ptimo hoyo que a£n est‚n disponibles, y  margaritas
en cada cuarto  hoyo que a£n  est‚ disponible.” Betsy  pensaba cu ntos
hoyos abiertos quedar¡an. Ella se dio cuenta que el n£mero  depender¡a
en cual hoyo  ella comenzar¡a a  plantar cuando ella  intentara llenar
cada eN‚simo hoyo con una clase de flores.

Ayude a Betsy a saber cuantos hoyos abiertos quedaran. Lea un conjunto
de K (1  <= K <=  100) descriptores de  plantaciones, cada uno  de los
cuales dice una ubicaci¢n inicial L (1 <= L <= F) -- L=1 es la primera
flor -- y un intervalo I (1 <= I <= F) para plantar flores. Deduzca el
n£mero de hoyos vac¡os que permanecer n libres despu‚s de plantar todo
el conjunto.

Si Betsy sigui¢ su visi¢n original, ella podr¡a especificar la plantaci¢n
como sigue:

      30 3     [30 hoyos en total; 3 clases de flores]
      1 3      [comenzar en el hoyo 1 y plantar rosas cada tercer hoyo]
      3 7      [comenzar en el hoyo 3 y plantar begonias cada s‚ptimo
hoyo]
      1 4      [comenzar en el hoyo 1 y plantar margaritas cada cuarto
hoyo]

Por lo tanto, el jard¡n vac¡o se ver¡a como esto:

. . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
Luego, despu‚s de plantar las rosas:
     R . . R . . R . . R . . R . . R . . R . . R . . R . . R . .
Luego, despu‚s de plantar las begonias:
     R . B R . . R . . R . . R . . R B . R . . R . B R . . R . .
Luego, despu‚s de plantar las margaritas:
     R . B R M . R . M R . . R . . R B . R . M R . B R . . R M .

Quedan 13 hoyos vac¡os despu‚s de la plantaci¢n

NOMBRE DEL PROBLEMA: flowers

FORMATO DE ENTRADA:

* L¡nea 1: Dos enteros separados por espacio: N y K.

*L¡neas 2..K+1: La l¡nea j contiene dos enteros separados por  espacio
que especifican la plantaci¢n de una clase de flor: L_j y I_j

ENTRADA EJEMPLO (archivo flowers.in):

30 3
1 3
3 7
1 4

DETALLES DE LA ENTRADA

Como en el texto del problema

FORMATO DE SALIDA:

* L¡nea 1: Una sola l¡nea con un solo entero que es el n£mero de hoyos
que permanecen vac¡os despu‚s de completar la plantaci¢n.

SALIDA EJEMPLO (archivo flowers.out):

13

DETALLE DE LA SALIDA

Como en el texto
*/
