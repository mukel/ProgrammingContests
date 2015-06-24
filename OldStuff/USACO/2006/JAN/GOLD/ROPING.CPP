/*
Alfonso Alfonso Peterssen
22 - 12 - 2007
USACO 2006 JAN Gold "Encordando los Campos"
*/
#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

const long double
    EPSILON = 1e-9;

const int
    MAXN = 150,
    MAXC = 100;

typedef long long int64;
typedef complex< int64 > point;

    int64 cross( const point &A, const point &B ) {
        return imag( conj( A ) * B );
    }

    int64 dot( const point &A, const point &B ) {
        return real( conj( A ) * B );
    }

    long double dist( const point &A, const point &B ) {
        return sqrtl( norm( A - B ) );
    }

    long double dist2segment( point &A, point &B, point &C ) {
        if ( dot( B - A, C - A ) <= 0 ) return dist( A, C );
        if ( dot( A - B, C - B ) <= 0 ) return dist( B, C );
        return abs( cross( B - A, C - A ) / dist( A, B ) );
    }

int N, C, R, i, j, k, h;
int dp[MAXN][MAXN];
bool rope[MAXN][MAXN];
point ls[MAXN], circle[MAXN];

int main() {

    cin >> N >> C >> R;

    for ( i = 0; i < N; i++ )
        cin >> ls[i].real() >> ls[i].imag();

    for ( i = 0; i < C; i++ )
        cin >> circle[i].real() >> circle[i].imag();

    /* Find convex-hull */
    for ( i = 0; i < N; i++ )
        if ( imag( ls[i] ) < imag( ls[0] ) ||
           ( imag( ls[i] ) == imag( ls[0] ) && real( ls[i] ) < real( ls[0] ) ) )
           swap( ls[0], ls[i] );

    for ( i = 1; i < N; i++ )
        for ( j = i + 1; j < N; j++ )
            if ( cross( ls[i] - ls[0], ls[j] - ls[0] ) > 0 )
                swap( ls[i], ls[j] );

    /* Find valid ropes */
    for ( i = 0; i < N; i++ )
        for ( j = i + 2; j < N; j++ ) {
            rope[i][j] = true;
            for ( k = 0; k < C; k++ )
                if ( dist2segment( ls[i], ls[j], circle[k] ) - R < EPSILON ) {
                    rope[i][j] = false;
                    break;
                }
        }

    rope[0][N - 1] = false;

    /* DP */
    for ( h = 2; h < N; h++ )
        for ( i = 0; i < N - h; i++ ) {
            j = i + h;
            for ( k = i + 1; k < j; k++ )
                dp[i][j] >?= dp[i][k] + dp[k][j];

            if ( rope[i][j] ) dp[i][j]++;
        }

    cout << dp[0][N - 1] << endl;

    return 0;
}

/*
Problema 2: Encordando los Campos [Hal Burch, 2004]

El Granjero Juan (GJ) tiene algo de naturaleza de artista: él
frecuentemente construye grandes trabajos de arte en su granja.
GJ quiere construir hoy un “campo web” gigante.  El campo de GJ
es un polígono convexo grande con cercas alrededor del borde y
con postes de cercas en cada una de N esquinas (1 <= N <= 150).
Para construir su campo web, GJ quiere tirar tantas cuerdas como
sea posible en líneas rectas entre pares de postes de cercas no
adyacente de tal manera que no se crucen dos cuerdas.

Hay solamente una complicación: El campo de GJ no es utilizable
totalmente. Algunos extraterrestres diabólicos han creado un total de
G (1 <= G <= 100) círculos de grano en el campo, todos de radio R (1
<= R <= 100,000). GJ tiene miedo de molestar a los extraterrestres, y
por lo tanto no quiere que las cuerdas pasen a través, o aún toquen el
borde de un circulo de grano. Note que a pesar que el centro de todos
los círculos están dentro del campo, un radio grande puede extenderse
fuera del campo, y tanto cercas como postes pueden estar dentro de un
circulo de grano.

Dadas las ubicaciones de los postes de cercas y los círculos,
determine el máximo número de cuerdas que GJ puede usar para crear su
campo web.

Todos los postes de cerca de GJ y todos los centros de los círculos
tienen coordenadas enteras X y Y, cada una de las cuales está en el
rango 0...1,000,000.

NOMBRE DEL PROBLEMA: roping

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por espacios: N, G y R.

* Líneas 2..N+1: Cada línea contiene dos enteros separados por espacio
       que son X, Y la posición de un poste de cerca en el borde del
       campo de GJ.

* Líneas N+2..N+G+1: Cada línea contiene dos enteros separados por
       espacio que son X, Y la posición del centro de un círculo
       dentro del campo de GJ.

ENTRADA EJEMPLO (archivo roping.in)

5 3 1
6 10
10 7
9 1
2 0
0 3
2 2
5 6
8 3

DETALLES DE LA ENTRADA

Un campo pentagonal, en el cual todas las cuerdas posibles están
bloqueadas por círculos de grano, excepto para la cuerda entre los
postes de cerca 2 y 4.


FORMATO DE SALIDA:

* Línea 1: Un solo entero que es el número más grande de cuerdas que
GJ
       puede usar para su creación artística.

EJEMPLO DE SALIDA (archivo roping.out):

1
*/
