/*
Alfonso Alfonso Peterssen
23 - 12 - 2007
PSN 2007 #19 "Slikar"
*/
#include <cstdio>
#include <cstdlib> // exit()
#include <algorithm>
#include <queue>

using namespace std;

const int
    MAXF = 51,
    mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int F, C, i, j, k;
int fil, col;
char mat[MAXF][MAXF];
int dist[MAXF][MAXF];

struct point {
    int x, y;
    char flag;
};

queue< point > Q;

int main() {

    freopen( "d.in", "r", stdin );
    freopen( "d.out", "w", stdout );

    scanf( "%d %d", &F, &C );

    for ( i = 0; i < F; i++ ) {
        scanf( "%s", &mat[i] );
        for ( j = 0; j < C; j++ )
            if ( mat[i][j] == 'S' ) {
                fil = i;
                col = j;
            } else if ( mat[i][j] == '*' )
                Q.push( ( point ) { i, j, '*' } );
    }

    /* BFS */
    Q.push( ( point ) { fil, col, 'S' } );
    while ( !Q.empty() ) {

        point p = Q.front();
        Q.pop();

        for ( i = 0; i < 4; i++ ) {

            int nx = p.x + mov[i][0],
                ny = p.y + mov[i][1];

            if ( nx < 0 || nx >= F ||
                 ny < 0 || ny >= C ||
                 mat[nx][ny] == 'X' )
                 continue;

            if ( mat[nx][ny] != p.flag && mat[nx][ny] != '*' ) {

                if ( mat[nx][ny] == 'D' )
                    if ( p.flag == '*' )
                        continue;
                    else {
                        printf( "%d\n", dist[p.x][p.y] + 1 );
                        exit( 0 );
                    }

                mat[nx][ny] = p.flag;
                if ( p.flag == 'S' )
                    dist[nx][ny] = dist[p.x][p.y] + 1;

                Q.push( ( point ) { nx, ny, p.flag } );
            }
        }
    }

    printf( "KAKTUS\n" );

    return 0;
}

/*
19ş Slikar.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El malo emperor Cactus  tiene en su poseci¢n la Poci¢n M gina y  tiene
inundado el bosque encantado!  El   Pintor  y  los tres peque¤o erisos
ahora tienen que  retornar a la  cueva del Castor  donde ellos estar n
libre  de  riesgo antes  que  se llene  de  agua tan  r pido  como sea
posible!

El mapa del bosuqe encantado consiste de R filas y C columans.  Campos
vac¡os son representados por  '.'  caracteres,  campos inundados   por
'*'  y   rocas   pos   'X'. Adicionalmente,  la  cueva  del  Castor es
representada  por 'D'  y el  Pintor y  los  tres  peque¤os erisos  son
mostrado como por 'S'.

Cada minuto  el Pintor  y  los  tres the  three  peque¤o erisos pueden
moverse  para  los  4  campos  vecinos  (arriba,  abajo,  izquierda  o
derecha). Cada minito la inundaci¢n se expande  tambi‚n por todos  los
campos vac¡os  que tiene  al menos  una cada  en com£n  con los campos
inundados convirti‚ndose en  inundados tambi‚n. Tan  poco el agua,  el
Pintor y los tres peque¤o erisos  pueden pasar a trav‚s de las  rocas.
Naturalmente,  el Pintor y  los tres peque¤os erisos  no pueden  pasar
por los  campos inundados,  y el  agua no  puede inundar  la cueva del
castor.

Escriba un programa  que, dado un  mapa del Bosque  Encantado, de como
salida  el tiempo  m s peuqe¤o  necesitado por  el Pintor  y los  tres
peque¤o erisos llegar seguro a la cueva del Castoe.

Nota: La Pintor y los tres peque¤os erisos no pueden moverse al mismo
campo que est  cerca de ser inundado (en el mismo minuto).

Entrada

La primera l¡nea del fichero SLIKAR.IN contine dos enteros enteros,  R
y C, menores  o iguales a  50.  Las sigueintes  R l¡neas  cada  una de
ella contine C  caracteres ('.', '*',  'X', 'D' o  'S'). El mapa  debe
contener exactamente un caracter 'D' y exactamente un caracter 'S'.

Salida

El fichero de  salida SLIKAR.OUT debe  contener el tiempo  m s peque¤o
posible para qoe  el Pintor y  los tres peque¤os  erisos neceario para
llegar con seguridad a la cueva  del Castor. Si es to es  imposible la
salida debe mostra la palabra "KAKTUS" en una simple l¡nea.

Ejemplo de Entrada y Salida:

SLIKAR.IN              SLIKAR.IN               SLIKAR.IN
3 3                    3 3                     3 6
D.*                    D.*                     D...*.
...                    ...                     .X.X..
.S.                    ..S                     ....S.

SLIKAR.OUT             SLIKAR.OUT              SLIKAR.OUT
3                      KAKTUS                  8

Calificaci¢n del segundo ejemplo de prueba: El mejor de ello puede ser
ir a lo largo del borde de abajo y entonces el borde izquiedo, y puede
flooded un minuto antes de alcanzar la guardida.
*/
