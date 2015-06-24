{koder: A^2P}{30 - 3 - 2007}
{PSN 2006 #48 "La alineaci¢n de vacas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
  MaxM = 10000;
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;
  seq             : array[0..MaxN] of longint;
  mark            : array[0..MaxM] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
    readln(fin,seq[i]);

  {solve}
  sol := 1;
  for i:=1 to N do
  begin
    if not mark[seq[i]] then inc(j);
    mark[seq[i]] := true;
    if j = M then
    begin
      inc(sol); j := 0;
      fillchar(mark,M + 1,false);
    end;{then}
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
48ş La alineaci¢n de vacas.                                M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N  (1 <= N <=  100,000) vacas  del campesino John est n  alineadas
en una fila.  Cada vaca est   identificada con un  n£mero en el  rango
1...K (1 <= K <= 10,000) identificando su raza. Por ejemplo, una l¡nea
de 14 vacas pudiera tener estas razas:

    1 5 3 2 5 1 3 4 4 2 5 1 2 3

El campesino  John que  es un  matematico ingenioso  prest¢ atenci¢n a
todos los ordenamientos  de las propiedades  de secuencias de  n£meros
similar a la de arriba. Por ejemplo, el not¢ que la secuencia 3 4 1  3
es  una  secuencia (no  necesariamente  contigua) de  la  secuencia de
identificadores de raza de arriba.  El campesino quiere saber cual  es
la longitud de la posible  secuencia m s corta que el  pueda construir
de los  n£meros en  el rango  1..K que  NO es  una subsecuencia de los
identificadores de  raza de  sus vacas.  Ay£delo a  ‚l a resolver este
problema.

Entrada


El fichero de entrada LINEUP.IN contiene
- L¡nea 1: Dos enteros, N y K
- L¡neas 2..N+1: Cada l¡nea contiene un entero simple que es el ID de
  la raza de una vaca. La l¡nea 2 describe a la vaca 1; la l¡nea 3
  describe a la vaca 2; y asi sucesivamente.

Salida

El fichero de salida LINEUP.OUT contiene el la linea 1 la longitud de
la secuencia mas corta que no es una subsecuencia de la entrada.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ lineup.in ³ ³ lineup.out ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 14 5      ³ ³ 3          ³
³ 1         ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 5         ³
³ 3         ³ Detalles de la Salida
³ 2         ³
³ 5         ³ Todas las secuencias de d¡gitos simples
³ 1         ³ aparecen. Cada una de las 25
³ 3         ³ secuencias de dos d¡gitos tambi‚n
³ 4         ³ aparecen. De las secuencias de tres
³ 4         ³ digitos, la secuencia 2, 2, 4 no aparece.
³ 2         ³
³ 5         ³
³ 1         ³
³ 2         ³
³ 3         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}