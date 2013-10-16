{koder: A^2P}
{JDs Defectuosos}
{PSN 2000 #89 "Una Subsecuencia" }
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,j        : word;
   m            : array[0..2] of longint;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {solve}
     readln(fin,N);
     for i:=1 to N do
     begin
          readln(fin,j);
          inc(m[j mod 3]);
     end;{for}
     if m[2] > m[1] then j := m[2] - m[1]
        else j := m[1] - m[2];
     j := j mod 3;

     {dprint}
     write(fout,N - j);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
89ş Una Subsecuencia.                                       China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se desea encontrar la m s larga subsecuencia, de una secuencia dada de
enteros, cuya suma de elementos sea divisible por 3.

Escriba un programa que:

ş Lea la secuencia de enteros de un fichero texto.
ş determine la longitud de la secuencia cuya suma de elemento es
  divisible por 3.
ş escriba la respueta en un fichero de texto.

Archivo de Entrada

En la primera l¡nea se podra leer un entero n (1 ó n ó 10000). En cada
una de  las  siguientes  n  lineas  existe un elemento de la secuencia
0  ó ai ó 20000 (i = 1 .. n). La  secuencia  es  escrita a raz¢n de un
elemento por l¡nea.

Archivo de Salida
Una £nica l¡nea con la longitud de la mayor subsecuencia.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo de Entrada³³Ejemplo de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7                ³³ 5               ³
³ 10               ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 6                ³
³ 7                ³
³ 12               ³
³ 4                ³
³ 7                ³
³ 22               ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}