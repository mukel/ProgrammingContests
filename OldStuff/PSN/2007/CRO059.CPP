/*
Alfonso Alfonso Peterssen
1 - 8 - 2007
PSN 2007 #59 "Latín Bovino"
*/
#include <cstdio>

#define problem "d"

int T;
char st[50];

  bool is_vowel( char c ) {
    return ( c == 'a' ) || ( c == 'e' ) ||
           ( c == 'i' ) || ( c == 'o' ) ||
           ( c == 'u' );
  }

int main () {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  for ( scanf( "%d", &T ); T; T-- ) {
    scanf( "%s\n", &st );
    if ( is_vowel( st[0] ) )
         printf( "%scow\n", st );
    else printf( "%s%cow\n", st + 1, st[0] );
  }

  return 0;
}

/*
59ş Lat¡n Bovino.                                         Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las vacas  han o¡do  que los  cerdos usan  un lenguaje secreto llamado
"Lat¡n Cerdo" cuando ellos quieren comunicarse entre ellos, sin que el
Granjero Juan  sea capaz  de comprender  lo que  ellos est n diciendo.
Pensando que esto  es una idea  excelente, ellas inventaron  su propia
versi¢n, apropiadamente llamada Lat¡n Bovino.

Convertir una palabra  en ingl‚s a  Lat¡n Bovino es  algo simple. Para
palabras que comienzan con  una vocal ('a', 'e',  'i', 'o' o 'u'),  se
a¤ade "cow" al final de  la palabra; por ejemplo 'udder'  se convierte
en  'uddercow'.  Para palabras  que  no comiencen  con  una vocal,  la
primera letra se mueve  al final de la  palabra, y se a¤ade  'ow'; por
ejemplo 'farmer' se  converite en 'armerfow'.  Por lo tanto  'the cows
escape at dawn' se convierte  en 'hetow owscow esapecow atcow  awdow'.
Las vacas creen fervientemente que GJ no entender  este subterfugio.

Las vacas nunca han sido conocidas como linguistas entusiastas, por lo
tanto ellas encuentran esta traducci¢n bastante tediosa y por lo tanto
le piden a usted que escriba un programa que tomar  palabras sueltas y
las traducir  en  Lat¡n Bovino. Ellas  le dar n a  usted N (1  <= N <=
100) palabras para traducir; las longitudes de las palabras est n de 3
a 40 letras.

NOMBRE DEL PROBLEMA: latin

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero: N.

- L¡neas 2..N+1: Una palabra por l¡nea.

ENTRADA EJEMPLO (archivo latin.in):

5
udder
farmer
milk
aaa
zzz

FORMATO DE SALIDA:

- L¡neas 1..N: Las traducciones a Lat¡n Bovino de las palabras dadas.

SALIDA EJEMPLO (archivo latin.out):

uddercow
armerfow
ilkmow
aaacow
zzzow
*/
