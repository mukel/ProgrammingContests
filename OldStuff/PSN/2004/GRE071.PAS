{koder: A^2P}{27 - 4 - 2007}
{PSN 2004 #71 "Inversiones"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,i,sol         : longint;
  list,tmp        : array[0..MaxN] of longint;

    procedure sort(d,h: longint);
    var i,j,k,p : longint;
    begin
      if d = h then exit;
      p := (d + h) shr 1;
      sort(d,p); sort(p + 1,h);

      {merge}
      i := d; j := p + 1;
      for k:=1 to h - d + 1 do
        if (i <= p) and ((j > h) or (list[i] < list[j])) then
        begin
          tmp[k] := list[i];
          inc(i);
        end{then ->}
        else begin
          tmp[k] := list[j];
          inc(j); inc(sol,p - i + 1);
        end;{else}

      {copy}
      for k:=1 to h - d + 1 do
        list[d + k - 1] := tmp[k];
    end;{sort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,list[i]);

  {solve}
  sort(1,N);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
71ş Inversiones.                                           Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Sea A[1..N] un arreglo de n£meros enteros positivos. Si i < j y A[i] >
A[j], entonces el par (i, j) es considerado una inversion de A. A no
contendr  n£meros repetidos.

Tarea

Dado un arreglo A, determinar la cantidad de inversiones en A.

Entrada

En la primera l¡nea de INVER.IN, est  el n£mero 1 <= N <= 10000, en
las l¡neas 2..N+1 est n los elementos de A.

Salida

En el fichero INVER.OUT solo estar  un £nico n£mero, denotando el
n£mero de inversions de A.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
³INVER.IN³ ³INVER.OUT³
ÃÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
³ 5      ³ ³ 5       ³
³ 2      ³ ÀÄÄÄÄÄÄÄÄÄÙ
³ 3      ³
³ 8      ³
³ 6      ³
³ 1      ³
ÀÄÄÄÄÄÄÄÄÙ
}
