{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #36 "Estantes"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,M,S,i,j,k     : longint;
  C,h             : array[-2..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  readln(fin,S);
  for i:=1 to S do
  begin
    read(fin,j,k);
    if k > h[j] then h[j] := k;
  end;{for}

  {slve}
  for i:=1 to N do
    C[i] := min( C[i - 1] + h[i],
                 min( C[i - 2] + max(h[i],h[i - 1]),
                      C[i - 3] + max(h[i],max(h[i - 1],h[i - 2]))));

  {dprint}
  writeln(fout,C[N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
36ş Estantes.                                              Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una estanteria en un departamento de policia consiste de estantes que
est n organizados en C columnas y R filas. Para alcanzar un objeto de
alg£n estante una escalera tiene que ser usada. Una escalera puede ser
recostada contra una columna de estantes solamente. Subiendo en la
escalera a cierta altura (fila) es posible tomar algun objeto de esa
columna hasta la altura ascendida incluyendo los objetos de las
columnas (izquierda y derecha) adyacentes.

Un policia necesita tomar ciertos objetos del estante. Para disminuir
el riesgo de lesi¢n en el trabajo es necesario encontrar una via para
tomar todos los objetos necesitados del estante tal que la altura
total de todas las subidas sea la minima posible. La altura total es
la suma de las alturas de todas las subidas. Los objetos en los
estantes son dados.

Escriba un programa que determine la minima altura posible de todas
las subidas necesarias para recoger todos los objetos de los estantes.

Entrada

La primera linea del fichero de entrada SHELVES.IN contien dos enteros
C y R, 1 <= C <= 100, 1 <= R <= 100, numero de columnas y numero de
filas, separados por un caracter espacio. La segunda linea contiene un
entero N, 1 <= N <= 100, numero de estantes que se necesitan alcanzar.
Cada uno de las pr¢ximas N lineas contienen dos enteros A y B, 1 <= A
<= C, 1 <= B <= R, separados por un caracter espacio, numero de
columna y fila del estante que necesita se alcanzado.

Salida

La primera y £nica linea del fichero de salida SHELVES.OUT debe
contener la posible altura total minima de subidas necesarias para
alcanzar todos los estantes dados.

Ejemplo de Entrada y Salida

 Ejemplo #1         Ejemplo #2        Ejemplo #3
ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ SHELVES.IN ³     ³ SHELVES.IN ³    ³ SHELVES.IN ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 5        ³     ³ 6 20       ³    ³ 10 10      ³
³ 3          ³     ³ 4          ³    ³ 5          ³
³ 2 3        ³     ³ 5 6        ³    ³ 9 1        ³
³ 3 4        ³     ³ 1 1        ³    ³ 7 6        ³
³ 4 4        ³     ³ 6 1        ³    ³ 5 8        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ     ³ 3 7        ³    ³ 4 1        ³
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿    ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ    ³ 3 2        ³
³ SHELVES.OUT ³    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿   ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´    ³ SHELVES.OUT ³   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ 4           ³    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´   ³ SHELVES.OUT ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ    ³ 9           ³   ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
                   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ   ³ 11          ³
                                     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
