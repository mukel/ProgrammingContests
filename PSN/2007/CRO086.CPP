/*
Alfonso Alfonso Peterssen
20 - 6 - 2007
PSN 2007 #86 "Los contrabandistas"
*/
#include <fstream>
#include <vector>
#include <set>
using namespace std;

#define MAXN 5000
#define oo 1000000000

#define problem "d"
#define tr( v, it ) for ( typeof( v.begin() ) it = v.begin(); it != v.end(); it++ )

typedef pair< long long, int > pii;
typedef vector< vector< pii > > graph;

int N, M, i, sol;
int value[MAXN];
graph G1( MAXN ), G2( MAXN );
vector< int > D1( MAXN, oo ), D2( MAXN, oo );

  void dijkstra( graph &G, vector< int > &D ) {
    set< pii > Q; D[0] = 0;
    Q.insert( pii ( 0, 0 ) ); //Insert Gold
    do {
      pii top = *Q.begin();
      int v = top.second;
      Q.erase( Q.begin() );
      tr( G[v], it ) {
        int cost = it->first, v2 = it->second;
        if ( D[v] + cost < D[v2]) {
          if ( D[v2] != oo ) Q.erase( Q.find( pii ( D[v2], v2 ) ) );
          D[v2] = D[v] + cost;
          Q.insert( pii ( D[v2], v2 ) );
        }
      }
    } while ( !Q.empty() );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) fin >> value[i];
  G1.resize( N ); G2.resize( N );

  fin >> M;
  for ( i = 0; i < M; i++ ) {
    int a, b, cost;
    fin >> a >> b >> cost; a--; b--;
    G1[a].push_back( pii ( cost, b ) );
    G2[b].push_back( pii ( cost, a ) );
  }

  dijkstra( G1, D1 );
  dijkstra( G2, D2 );

  sol = value[0] / 2;
  for ( i = 1; i < N; i++ )
    sol <?= D1[i] + D2[i] + value[i] / 2;

  fout << sol << endl;

  return 0;
}

/*
86þ Los contrabandistas.                                  Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Byteotia es famosa por sus  ricos dep¢sitos de oro. Por  consiguiente,
durante muchos  a¤os all¡  floreci¢ la  venta de  ese metal  al vecino
reino  de   Bitland.  Desgraciadamente,   el  d‚ficit   creciente  del
presupuesto  nacional  oblig¢ al  rey  de Bitland  a  introducir altas
tarifas   en   los   metales   y   minerales.   Los  comerciantes  que
cruzan la frontera  tienen que  pagar impuestos  de 50%  del valor  de
la   carga  transportada.   Los   comerciantes  de   Byteotian   est n
amenazados con la  ruina.   Afortunadamente,   los    alquimistas   de
Byteotian   han desarrollado  maneras de transformar   algunos metales
en otro.  La  idea de los  comerciantes es  usar  los conocimientos de
los   alquimistas  para  transformar  oro  en  alg£n  metal  barato, y
a continuaci¢n, despu‚s  de  cruzar la  frontera  y  pagar la  peque¤a
tarifa, transformarlo  de nuevo  en  oro.  Fatalmente, los alquimistas
no  pueden  transformar   cualquier  metal  en   otro  arbitrariamente
escogido. Por consiguiente, puede pasar que el proceso  de  obtener un
metal   a  partir   del   oro   tiene    que  ser   una    cadena   de
transformaciones  que  producen  un  metal  diferente  en  cada  fase.
Los  alquimistas demandan  una alta  retribuci¢n  por   sus  servicios.
Ellos han fijados un  precio para  transformar  1  kg de  un  metal  A
en  un   metal   B  para  cada  transformaci¢n   que     ellos  puedan
realizar.   Los    comerciantes reflexionan  de  que  forma  debe  ser
transportado   el oro   al cruzar  la frontera  y cual   secuencia  de
procesos  alquimicos  deben  ser aplicados  para  lograr  la m s  alta
ganancia.

Tarea

Ayude  a la econom¡a de Byteotian! Escriba un programa que:

- Lea la tabla  de precios para todos  los metales y  precios  para las
  transformaciones  ofrecidas por los alquimistas.

- Determine una secuencia de metales m1, m2, ..., mk tal que:

    * m1 = mk es oro,

    * para cada i = 2,3,...,k los alquimistas son capaces de obtener
      el metal m(i) a partir del metal m(i-1), y

    * el costo de ejecuci¢n  de la secuencia completa de los  procesos
      alquimicos    para  1    kg    de    oro,  aumentado    por   el
      impuesto pagado en  la frontera  (50% del   precio de  1 kg  del
      metal  m s barato  de m(i),  para  i  =  1,  2,  ...,  k) es  el
      m s  peque¤o  posible.  Nosotros   asumimos   que   durante   el
      proceso  de alquimia el  peso de los metales no se altera.

-  Escriba   en  la   salida   el  costo   de   ejecutar la  secuencia
   determinada   de   los   procesos  alquimicos   aumentado   por  el
   impuesto pagado en  la frontera.

Entrada

En la  primera l¡nea del  fichero de entrada PRZ.IN  existe  un entero
positivo n denotando el n£mero de diferentes metales, 1 <= n <=  5000.
En la (k+1)-‚sima  l¡neas, para  1  <=  k <=  n, existe un  entero par
no negativo pk: el  precio de  1  kg  del  k-‚simo metal,  0 <= pk  <=
10^9. Nosotros  asumimos que  el oro  tiene el  n£mero 1.  En la l¡nea
(n+2)-‚sima  existe  un entero   no   negativo m  igual  al n£mero  de
procesos  de  transformaci¢n  que  los   alquimistas  son  capaces  de
realizar,  0   <= m   <= 100000.  En cada   una de  las  siguientes  m
l¡neas   existen  tres   enteros  positivos,  separados   por espacios
simples,  describiendo   consecutivos procesos  de  transformaci¢n. Un
triplo de n£meros a, b, c denota que los alquimistas est n capacitados
para obtener  el b-‚simo metal a partir del  a-‚simo metal,  y   ellos
exigen  c bytealers  (moneda de Byteotian)   para transformar 1  kg de
material,  1 <=  a, b  <= n,  0 <=  c <=  10000. Un   par ordenado  de
n£meros  a y b  pueden aparecer a  lo sumo una  vez en el fichero.

Salida

Su programa debe  imprimir el resultado  en el fichero  PRZ.OUT. En la
primera l¡nea usted debe de escribir un entero - el costo de ejecuci¢n
de los procesos alquimicos determinado por su  programa aumentado
por el impuesto pagado en la frontera.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄ¿
³ PRZ.IN ³   ³ PRZ.OUT ³
ÃÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄ´
³ 4      ³   ³ 60      ³
³ 200    ³   ÀÄÄÄÄÄÄÄÄÄÙ
³ 100    ³
³ 40     ³
³ 2      ³
³ 6      ³
³ 1 2 10 ³
³ 1 3 5  ³
³ 2 1 25 ³
³ 3 2 10 ³
³ 3 4 5  ³
³ 4 1 50 ³
ÀÄÄÄÄÄÄÄÄÙ
*/
