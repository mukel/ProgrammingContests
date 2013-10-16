{koder: A^2P}
{PSN 2006 #1 "Extraer Subsecuencia"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
var
  fin,fout        : text;
  N,i,j,k         : word;
  c,d,last,s      : array[0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,d[i]);

  {solve}
  for i:=2 to N do
    for j:=1 to i-1 do
      if (d[i] mod d[j] = 0) and (c[j] + 1 > c[i]) then
        begin
          c[i] := c[j] + 1; last[i] := j;
        end;{then}

  {dprint}
  j := 0;
  for i:=1 to N do
    if c[i] > c[j] then j := i;
  while j <> 0 do
  begin
    inc(s[0]); s[s[0]] := d[j];
    j := last[j];
  end;{while}
  writeln(fout,s[0]);
  for i:=s[0] downto 1 do writeln(fout,s[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
8ş Extraer Subsecuencia.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se tiene una secuencia de N números enteros positivos. Se quiere
extraer una subsecuencia  del tal forma que en la subsecuencia
extraída cada número sea divisible por cada uno de los anteriores a él
en la subsecuencia.

Ejemplo:

Para la lista original:  8  3  2  4  6   6  8  10  15  9  25  12  13
                                         -            -    -                               ---

Los elementos marcados forman la subsecuencia y cumplen
la propiedad de divisibilidad, o sea, el 6 es divisible por 3 y el
próximo 6 es divisible por 6 y por 3, el 12 es divisible por los
dos 6 y por 3.

Usted debe encontrar  la subsecuencia que cumpla los requisitos de
divisibilidad expresados anteriormente y que la cantidad de elementos
de la misma sea máxima.

Tarea

Hacer un programa que permita:
- Leer desde fichero de entrada SUB.IN  la secuencia dada.

- Encontrar la mayor subsecuencia, según la definición anteriormente
  explicada.

- Escribir hacia el fichero de salida SUB.OUT la cantidad de elementos
  de la mayor subsecuencia encontrada y los elementos que la conforman.

Entrada

El fichero de entrada SUB.IN contiene:
Línea 1: N (1 <= N <= 2000), cantidad de elementos de la
   secuencia.
Línea 2..N+1: En la línea i+1 se escribirá un valor Mi(0 <=Mi <=10000)
  el cual representa al i-ésimo elemento de la secuencia.

Salida

El fichero de salida SUB.OUT contiene:
Línea 1: S, el cual representa la  cantidad de elementos de la
  subsecuencia encontrada.
Línea 2..S+1: En cada una de estas se escribirán un elemento de la
  subsecuencia encontrada en el mismo orden en que estos aparecen en
  la secuencia original.


Ejemplo de Entrada y Salida

SUB.IN                 SUB.OUT

13                     4
8                      3
3                      3
2                      6
4                      12
6
6
8
10
15
9
25
12
13
}