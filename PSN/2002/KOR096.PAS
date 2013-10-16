{koder: A^2P}
{PSN 2002 #96 "Juego de Postes"}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,j,p,f    : integer;
   S,min        : longint;
   m            : array[1..3000] of longint;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     readln(fin,N);
     for i:=1 to N do
     begin
          readln(fin,j);
          m[i] := m[i-1] + j;
     end;{for}

     {solve}
     min := MaxLongint;
     for i:=1 to N-1 do
         for j:=i+1 to N do
         begin
              S := abs(m[j] - m[i]);
              if (S < min) or ((S = min) and ( j-i > f-p )) then
              begin
                   min := S; p := i; f := j;
              end;{then}
         end;{for}

     {dprint}
     write(fout,p+1,' ',f,' ',min);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
96ş  Juego con Postes                                      Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  campesino tiene una larga cerca hecha de postes y railes. Cada uno
de  los  N  (1  <=  N <= 3000) postes de cercas tiene un cartel con un
n£mero  en  el  rango  de -1000 a 1000. Algunos postes pueden tener el
mismo n£mero en su cartel como otros postes. Mientras comen, los hijos
del  campesino  adoptan un juego. El muchacho quien pueda encontrar la
'mejor suma de cerca' comer  helado de postre.

Para  ganar  el juego, el muchacho ganador tendr  que encontrar el m s
largo  conjunto  de postes contiguos cuya suma tenga el valor absoluto
m s peque¤o. Ayuda a determinar la suma ganadora.

Entrada

El fichero de entrada POSTES.IN tiene la siguiente estructura:

L¡nea        1:    una    l¡nea    con    un    entero    simple:    N
L¡nea  2..N+1:  Cada  l¡nea  contiene  una  etiqueta de poste. l¡nea 2
              contiene el valor del poste con secuencia n£mero 1, etc.

Salida

La  salida  ser   hacia el fichero POSTES.OUT con una simple l¡nea con
tres n£meros:
- el n£mero de secuencia de un poste que es el primero para ser
  sumado.
- el n£mero de secuencia de un poste que es el £ltimo para ser
  sumado, y
- el valor absuluto de las etiquetas de aquellos postes. Si hay m s de
  una  secuencia  y  tienen  la misma 'mejor suma de cerca' y la misma
  longitud  m xima,  reporte  la secuencia con la primera secuencia de
  n£mero m s peque¤o.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ POSTES.IN ³  ³ POSTES.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 6         ³  ³ 4 6 0      ³
³ 5         ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 10        ³
³ -5        ³
³ -6        ³
³ 2         ³
³ 4         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}