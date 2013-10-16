/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
PSN 2007 #32 "Bus"
*/
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

#define MAXN 50

int N, i, j, k, sol;
int pos[MAXN], sz[MAXN];
int ls[MAXN][MAXN];
bitset< MAXN > know[MAXN];
bool ok;

int main() {

  for (;;) {

    scanf( "%d", &N );
    if ( !N ) break;

    for ( i = 0; i < N; i++ ) {
      scanf( "%d", &sz[i] );
      for ( j = 0; j < sz[i]; j++ )
        scanf( "%d", &ls[i][j] );
    }

    /* Init */
    memset( pos, 0, sizeof( pos ) );
    for ( i = 0; i < N; i++ )
      for ( j = 0; j < N; j++ )
      know[i][j] = false;

    for ( i = 0; i < N; i++ )
      know[i][i] = true;

    ok = false;
    for ( sol = 0; sol < 200000; sol++ ) {

      for ( j = 0; j < N; j++ )
        for ( k = j + 1; k < N; k++ )
          if ( ls[j][ pos[j] ] == ls[k][ pos[k] ] ) {
            know[j] |= know[k];
            know[k] |= know[j];
          }

      /* FIX */
      for ( i = 0; i < N; i++ )
        if ( ++pos[i] == sz[i] )
          pos[i] = 0;

      for ( i = 0; i < N; i++ )
        for ( j = 0; j < N; j++ )
          if ( !know[i][j] ) {
            i = N + 2;
            break;
          }

      if ( i == N ) {
        ok = true;
        break;
      }

    }

    if ( ok )
         printf( "%d\n", sol );
    else printf( "NUNCA\n" );
  }

  return 0;
}

/*
32þ Bus.                                                  Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  ciudad de  Buscelona (como  su nombre  lo indica)  tiene un   gran
sistema de  transporte por  omnibus. Todos  los omnibus tienen  lineas
circulares.  A   los  choferes   de  omnibus   les  gusta   conversar.
Afortunadamente la  mayoria de  las lineas  de omnubus  tienen algunas
paradas en comun. Si un chofer de omnibus se encuentra a un colega  en
una parada de omnibus ellos conversan un poco e intercambian todas las
noticias que ellos conocen. La operacion de los omnibus est  altamente
sincronizada. El  tiempo necesario  para acceder  de una  parada a  la
proxima  parada  es siempre  exactamente  1 minuto.

Cada  ma¤ana cada chofer de omnibus tiene algunas importantes noticias
que solamente  el conoce. Cuando un chofer encuentra a   un colega  ‚l
le dira todas  las noticias que ‚l conoce. Si dos choferes de  omnibus
comparten la   misma estacion  de comienzo,  ellos intercambiaran  sus
noticias alli (antes de que  ellos comiencen a trabajar). Note  que el
intercambio de noticias y las paradas no toma tiempo.

Entrada

La primera  linea del  fichero de  entrada BUS.IN  contiene el n£mero
de  lineas de  omnibus n  (0  <   n <  50).  Las  siguientes n  lineas
comienzan con un n£mero s (0 <  s  < 50) indicando las paradas de  una
linea  de omnibus.  En la  misma linea  apareceran despues  s n£meros
representando  cada estacion  de omnibus.  Un omnibus  comienza en  la
primera estacion.  Cuando un  omnibus alcanza  la ultima  estacion, el
omnibus se dirigira a la  primera estacion otra vez. Hay  muchos casos
de  prueba separados  por una  linea en  blanco. Los  daos de  entrada
terminan cuando n=0.

Salida

Para cada  caso de  prueba usted   debe escribir  hacia el  fichero de
salida BUS.OUT el tiempo en minutos  el cual toma hasta  que todos los
choferes de omnibus  conocen todas las noticias. Si esto nunca sucede,
su programa debe escribir la  palabra "NUNCA" (sin comillas)

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ BUS.IN    ³ ³ BUS.OUT   ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³ ³ 12        ³
³ 3 1 2 3   ³ ³ NUNCA     ³
³ 3 2 3 1   ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4 2 3 4 5 ³
³           ³
³ 2         ³
³ 2 1 2     ³
³ 2 5 8     ³
³           ³
³ 0         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
*/
