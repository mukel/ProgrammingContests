/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
PSN 2007 #34 "Relaciones"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int
    MAXV = 1000,
    MAXE = 10000;

int V, E, i, j, k;
int  S, S_equal, sign, sol;
int P[MAXV], P_equal[MAXV];
int deep[MAXV];

struct edge {
    int b, next;
} ls[ 3 * MAXE ], ls_equal[ 3 * MAXE ];

    int dfs( int x ) {

        if ( deep[x] != -1 )
            return deep[x];

        deep[x] = 0;

        /* non-equal */
        for ( int i = P[x]; i; i = ls[i].next )
            deep[x] >?= dfs( ls[i].b ) + 1;

        /* equal */
        for ( int i = P_equal[x]; i; i = ls_equal[i].next )
            deep[x] >?= dfs( ls_equal[i].b );

        return deep[x];
    }

int main() {

    scanf( "%d %d", &V, &E );

    /* Init */
    fill( deep, deep + V, -1 );

    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &j, &k, &sign );
        j--, k--;

        if ( sign == 0 ) {
            ls_equal[++S_equal] = ( edge ) { k, P_equal[j] };
            P_equal[j] = S_equal;

            ls_equal[++S_equal] = ( edge ) { j, P_equal[k] };
            P_equal[k] = S_equal;
            continue;
        }

        if ( sign == -1 ) swap( j, k );

        ls[++S] = ( edge ) { k, P[j] };
        P[j] = S;
    }

    for ( i = 0; i < V; i++ )
        sol >?= dfs( i );

    /* Check */
    for ( i = 0; i < V; i++ ) {

        /* non-equal */
        for ( j = P[i]; j; j = ls[j].next )
            if ( deep[i] < deep[ ls[j].b ] ) break;

        if ( j ) break;

        /* equal */
        for ( j = P_equal[i]; j; j = ls_equal[j].next )
            if ( deep[i] != deep[ ls_equal[j].b ] ) break;

        if ( j ) break;
    }

    if ( i == V ) {
        printf( "%d\n", sol );
        for ( i = 0; i < V; i++ )
            printf( "%d\n", deep[i] );
    } else
        printf( "NO\n" );

    return 0;
}

/*
34ş Relaciones.                                           Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Usted tiene un  grafo orientado, cuyos  arcos est n identificados  con
los simbolos de relaci¢n "<", ">" and "=". Para un entero no  negativo
k, un identificaci¢n k-correcto de  un grafo G es una  distribuci¢n de
v‚rtices de G en  el intervalo   [0,k] tal   que los  n£meros en   los
extremos    de cada   arco satisfacen  la  relacion  descrita  por  la
identificacion de los arcos. Nosotros  asumimos que un elemento en  el
lado izquierdo  del simbolo   de  realacion  es  un   n£mero  asignado
al  v‚rtice inicial.  Encuentre  el mas   peque¤o k  para  el  cual la
identificaci¢n  k-correcto  del grafo  G  existe o  verifique  que tal
identificacio no existe para cualquier k.

Ver fichero relats.jpg
Para el grafo en la figura el mas peque¤o k = 2.

Tarea

Escriba un  programa que:

- lea  la  descripcion  de  un  grafo  G  desde el  fichero de entrada
  RELATS.IN,
- verifique si existe un entero  k para el cual es posible identificar
  el  grafo   G    k-correctamente    y,   si    la    respuesta    es
  positiva, calcule el mas peque¤o de tal k,
- escriba el resultado hacia RELATS.OUT.

Entrada

La  primera  linea  del  fichero  de  entrada  RELATS.IN  contiene dos
enteros n y  m separados  por un  espacio en  blanco. El  n£mero n  es
el  n£mero   de v‚rtices  en G  y m  es el  n£mero de  arcos de G. Los
n£meros n y  m satisfacen  1  <=  n  <= 1000, 0 <=  m  <= 10000.   Los
v‚rtices est n numerados  con enteros de 1 a  n  y  son  identificados
por  esos  n£meros.  No  hay  arcos  paralelos  en el  grafo.  En  las
proximas  m lineas  se escribiran  tres  enteros en cada   una los que
representan al  v‚rtice  inicial  y  al  v‚rtice  final  del arco,  el
tercer valor del conjunto {-1,0,1}  y este es la identificacion  del i
-‚simo arco:  -1 representa "<",  0  representa  "="  y  1  representa
">".

Salida

Su programa debe escribir hacia el fichero de salida RELATS.OUT:

- la  palabra  NO  si una  identificaci¢n k-correcta   no existe  para
  algun  k, o

- el  m s peque¤o  entero k  para el  cual una  identificacion  exista
  y en   las proximas   n  lineas   escribir  el   valoer  asignado  a
  cada v‚rtice comenzando por el v‚rtice 1 y terminando en el  v‚rtice
  n.

Ejemplo de Entrada y de Salida

Ejemplo 1                         Ejemplo 2

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ RELATS.IN ³ ³ RELATS.OUT ³      ³ RELATS.IN ³ ³ RELATS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 4       ³ ³ 2          ³      ³ 4 4       ³ ³ 2          ³
³ 1 2 1     ³ ³ 2          ³      ³ 1 2 -1    ³ ³ 0          ³
³ 2 3 1     ³ ³ 1          ³      ³ 2 3 0     ³ ³ 1          ³
³ 2 4 1     ³ ³ 0          ³      ³ 2 4 -1    ³ ³ 1          ³
³ 3 4 0     ³ ³ 0          ³      ³ 3 4 -1    ³ ³ 2          ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ


Ejemplo 3                         Ejemplo 4

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ RELATS.IN ³ ³ RELATS.OUT ³      ³ RELATS.IN ³ ³ RELATS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 2 2       ³ ³ 1          ³      ³ 3 3       ³ ³ 0          ³
³ 1 2 -1    ³ ³ 0          ³      ³ 1 2 0     ³ ³ 0          ³
³ 2 1 1     ³ ³ 1          ³      ³ 3 2 0     ³ ³ 0          ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ      ³ 3 1 0     ³ ³ 0          ³
                                  ÀÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
*/
