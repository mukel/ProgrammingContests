{koder: A^2P}{10 - 5 - 2007}
{PSN 2003 #39 "El llenado de barriles"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  EPSILON = 1e-9; { -> Los reales son una mier... }
var
  fin,fout        : text;
  op              : char;
  sum,solA,solB   : real;
  N,M,i,j,k,cant  : longint;
  liq             : array[0..MaxN] of real;
  mark            : array[0..MaxN] of longint;
  reach           : array[0..MaxN,0..MaxN] of boolean;

    procedure dfs(barrel: byte);
    var j : byte;
    begin
      inc(cant);
      mark[barrel] := i;
      sum := sum + liq[barrel];
      for j:=1 to N do
        if (reach[barrel,j]) and (mark[j] <> i)
          then dfs(j)
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {solve}
  for i:=1 to M do
  begin
    readln(fin,op,j,k);
    if op = 'P' then liq[j] := liq[j] + k;
    if op = 'V' then
    begin
      reach[j,k] := not reach[j,k];
      reach[k,j] := not reach[k,j];
    end;{then}

    cant := 0; sum := 0;
    dfs(j);

    if sum / cant - 100 > EPSILON then
    begin
      writeln(fout,'DESBORDAMIENTO ',i);
      close(fout); halt;
    end;{then}

    for j:=1 to N do
      if mark[j] = i then liq[j] := sum / cant;
  end;{for}

  solA := 100.0;
  for i:=1 to N do
  begin
    if liq[i] < solA then solA := liq[i];
    if liq[i] > solB then solB := liq[i];
  end;{for}

  {dprint}
  writeln(fout,'OK ',solA:0:2,' ',solB:0:2);

  {fclose}
  close(fin); close(fout);
end.{main}

{
39ş El llenado de barriles.                                   USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Existen  N  (1 < N <= 100) barriles iguales y vac¡os en una superficie
horizontal.  El volumen de cada barril es de 100 unidades. Cada dos de
ellos  est n  conectados  a  una tuber¡a. Cada tuber¡a es conectada al
fondo de dos barriles y esta tiene su propia v lvula las cuales pueden
estar  solo  en  dos  posiciones:  "ABIERTO" o "CERRADO". Al principio
todas las v lvulas est n cerradas. Si una v lvula es abierta, entonces
el  l¡quido  de  un  barril  conectado    a otro barril puede r pida y
libremente  fluir  al  otro  de  modo que el nivel de l¡quido en estos
barriles  ser   igual (el principio de los vasos comunicantes). Si una
v lvula es cerrada, el fluido a trav‚s de esta tuber¡a es imposible.
Dos tipos de operaciones son permitidas:

1) "P" (para echar) cuando alguna cantidad de l¡quido es vertida en el
   barril prescrito. La descripci¢n de la operaci¢n es: "P A M", donde
   A  es  el  barril y M es la cantidad de l¡quido (en unidades) a ser
   vertida  en  el  barril  (A  y M son enteros, (0 < A <= N, 0 < M <=
   1000).

2)  "V"  (para una v lvula) cuando una v lvula prescrita es cambiada a
   la  posici¢n  contraria  (por ejemplo, esta v lvula se cierra s¡ ha
   sido  abierta  y  se abre s¡ ha sido cerrada). La descripci¢n de la
   operaci¢n  es  "V  n1  n2",  donde  n1  y n2 son los n£meros de los
   barriles  que  est n  conectados  con  una  tuber¡a  que tiene esta
   v lvula (n1 y n2 son enteros, 0 < n1 <= N, 0 < n2 <= N, n1 <> n2).
   Dos descripciones diferentes "V n1 n2" y "V n2 n1" se refieren a la
   misma v lvula.

Tarea

Su tarea es ejecutar una secuencia de operaciones dadas. No tendr s en
cuenta  la cantidad de l¡quido en las tuber¡as. Si alguna operaci¢n de
echar  ("P")  no puede ser ejecutada debido al derrame del l¡quido, la
ejecuci¢n  de  esta  secuencia de la operaci¢n debe ser detenida y dar
una salida apropiada.

Entrada

El  fichero de entrada BARRIL.IN contiene los n£meros N y K (n£mero de
operaciones  0 < K < 1000) en la primera l¡nea y la descripci¢n de las
operaciones en las siguientes K l¡neas, una descripci¢n por l¡nea.

Salida

El fichero de salida BARRIL.OUT contiene la palabra "OK" y los valores
de  un m¡nimo y un m ximo nivel de l¡quido entre todos los barriles al
finalizar,  si la secuencia de operaciones fue completamente ejecutada
o  la  palabra "DESBORDAMIENTO" y el n£mero de la operaci¢n durante la
cual  el  desbordamiento del l¡quido sucedi¢. Los valores del nivel de
l¡quido  deben  ser  escritos  como  n£meros  reales  con  dos lugares
decimales.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ BARRIL.IN ³ ³ BARRIL.OUT     ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 2 6       ³ ³ OK 75.00 95.00 ³
³ P 1 63    ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ P 2 37    ³
³ V 1 2     ³
³ P 1 50    ³
³ V 2 1     ³
³ P 1 20    ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
