/*
Alfonso Alfonso Peterssen
24 - 12 - 2007
PSN 2007 #43 "Construyendo Un Nuevo Establo"
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int
    oo = 1000000000,
    mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int N, i, j, k, cost, places;
int x1, x2, y1, y2;

    void find_median( vector< int > ls, int &lo, int &hi ) {
        sort( ls.begin(), ls.end() );
        lo = ls[ ( ls.size() - 1 ) / 2 ];
        hi = ls[ ls.size() / 2 ];
    }

int main() {

    freopen( "d.in", "r", stdin );
    freopen( "d.out", "w", stdout );

    cin >> N;

    vector< int > x( N ), y( N );

    for ( i = 0; i < N; i++ )
        cin >> x[i] >> y[i];

    find_median( x, x1, x2 );
    find_median( y, y1, y2 );

    places = ( x2 - x1 + 1 ) * ( y2 - y1 + 1 );

    for ( i = 0; i < N; i++ ) {
        cost += abs( x[i] - x1 ) + abs( y[i] - y1 );
        if ( x[i] >= x1 && x[i] <= x2 &&
             y[i] >= y1 && y[i] <= y2 )
             places--;
    }

    if ( places == 0 ) {
        cost = oo;
        for ( i = 0; i < 4; i++ ) {
            int candy = 0;
            for ( j = 0; j < N; j++ )
                candy += abs( x1 + mov[i][0] - x[j] ) +
                         abs( y1 + mov[i][1] - y[j] );
            if ( candy == cost )
                places++;
            else if ( candy < cost ) {
                cost = candy;
                places = 1;
            }
        }
    }

    cout << cost << " " << places << endl;

    return 0;
}

/*
43þ Construyendo Un Nuevo Establo.                        Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Despu‚s de  hacer econom¡as  y ahorrar  por a¤os,  el Granjero Juan ha
decidido construir  un nuevo  establo. El  quiere que  el establo  sea
altamente accesible, y conoce las coordenadas de los lugares de pasteo
de todas las N  (2 <= N <=  10,000) vacas. Cada lugar  de pastoreo con
coordenadas enteras (X_i, Y_i) (-10,000  <= X_i, Y_i <= 10,0000).  Las
vacas  hambrientas  nunca  pastean  en  lugares  que  sean  adyacentes
vertical u horizontalmente.

El establo debe ser puesto en coordenadas enteras y no puede estar  en
ning£n lugar de pasteo.  La inconveniencia del establo  para cualquier
vaca est  dada por la f¢rmula de distancia Manhattan  |X-X_i|+|Y-Y_i|,
donde (X, Y) y (X_i, Y_i) son las coordenadas del establo y del  lugar
de pasteo de la vaca respectivamente. ¿D¢nde deber¡a ser construido el
establo con el prop¢sito de  minimizar la suma de las  inconveniencias
para todas las vacas?

NOMBRE DEL PROBLEMA: newbarn

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero N.

- L¡neas 2..N+1: La l¡nea i+1 contiene dos enteros separados por
      espacio que son las coordenadas (X_i, y_i) del lugar de pasteo
      de la vaca i.

ENTRADA EJEMPLO (archivo newbarn.in):

4
1 -3
0 1
-2 1
1 -1

DETALLES DE LA ENTRADA:

El campo contiene 4 vacas con lugares de pasteo en los lugares (1, -
3), (0, 1), (-2, 1), y (1, -1).

FORMATO DE LA SALIDA:

- L¡nea 1: Dos enteros separados por espacio: la inconveniencia m¡nima
para el establo  y el n£mero  de lugares en  los que el  Granjero Juan
puede construir el establo para conseguir este m¡nimo.

SALIDA EJEMPLO (archivo newbarn.out):

10 4

DETALLES DE LA SALIDA:

La inconveniencia m¡nima es 10, y hay 4 lugares donde el Granjero Juan
puede construir el establo para lograr esto: (0, -1), (0, 0), (1, 0) y
(1, 1).
*/
