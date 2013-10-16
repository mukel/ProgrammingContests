{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #89 "Conjeturas de Goldbach"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000000;
  MaxP = 78498;
var
  fin,fout        : text;
  N,P,i,j         : longint;
  mark            : array[0..MaxN] of boolean;
  list            : array[0..MaxP] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {prime sieve}
  for i:=2 to 1000 do
    if not mark[i] then
    begin
      j := sqr(i);
      repeat
        mark[j] := true;
        inc(j,i);
      until j > MaxN;
    end;{then}

  for i:=2 to MaxN do
    if not mark[i] then
    begin
      inc(P); list[P] := i;
    end;{then}

  {solve}
  readln(fin,N);
  repeat
    if N <> 6 then
    begin
      i := 1;
      while mark[N - list[i]] do inc(i);
      writeln(fout,N,' = ',list[i],' + ',N - list[i]);
    end{then ->}
    else writeln(fout,'Goldbach''s conjecture is wrong');
    readln(fin,N);
  until N = 0;

  {fclose}
  close(fin); close(fout);
end.{main}

{
89ş Conjeturas de Goldbach.                                M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En 1742, Christian Goldbach, un  matematico aleman, envia una carta  a
Leonhard Euler en la cual el planteaba la siquiente conjetura:

Todo numero  par mayor  que 4  puede ser  escrito como  la suma de dos
numeros primos impares

Por ejemplo
 * 8  = 3 + 5 .
 * 20 = 3 + 17.
 * 42 = 5+37 = 11+31 = 13+29 = 19+23.

Hoy en  dia esta  conjetura no  esta comprobada.(Espera,  yo tengo  la
prueba pero es muy larga para escribirla al margen de esta  pagina).De
cualquier manera tu tarea ahora es verificar la conjetura de  Goldbach
para todo numero par menor que un mill¢n.

Entrada

La entrada contiene uno o  mas casos de prueba. Cada caso  consiste de
un entero n par con 6 <= n < 1000000. La entrada temina con un 0.

Salida

Por cada caso  de prueba, imprimir  una linea de  la forma n  = a + b,
donde a y  b son primos  impares. Los numeros  y los operadores  seran
separados por un espacio en blanco. Si existe mas de un par de  primos
impares que sumen n, debe elegir el par donde la diferencia b - a  sea
maxima. Si  no existe  tal par,  imprimir una  linea con  la siquiente
frase: '' Goldbach's conjecture is wrong ''.

Ejemplo de entrada

8
20
42
0

Ejemplo de salida

8 = 3 + 5
20 = 3 + 17
42 = 5 + 37
}
