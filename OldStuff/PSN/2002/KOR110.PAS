{koder: A^2P}{7 - 5 - 2007}
{PSN 2002 #110 "Fiesta de A¤o Nuevo"}
{
  Hoy cumple a¤os la mejor de las madres
  ... creo que es la mia.
}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 302;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,C,M,i,j,k,
  a,b,sol,
  sink,source     : longint;
  size            : array[0..1] of longint;
  f,last          : array[0..MaxN] of longint;
  queue           : array[0..1,0..MaxN] of longint;
  cap,flow        : array[0..MaxN,0..MaxN] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,C,M);
  source := N + M + 1;
  sink := N + M + 2;
  for i:=N + 1 to N + M do read(fin,cap[i,sink]);
  for i:=1 to N do
  begin
    cap[source,i] := C;
    read(fin,j);
    for j:=1 to j do
    begin
      read(fin,k);
      cap[i,N + k] := 1;
    end;{for}
    readln(fin);
  end;{for}

  {solve}
  repeat
    a := 1; b := 0;
    size[a] := 1; queue[a,size[a]] := source;
    fillchar(f,sizeof(f),0);
    fillchar(last,sizeof(last),0);
    f[source] := oo;

    {BFS}
    repeat
      a := a xor 1; b := b xor 1;
      size[a] := 0;
      for i:=1 to size[b] do
        for j:=1 to N + M + 2 do
          if last[j] = 0 then
          begin
            k := queue[b,i];

            if cap[k,j] > flow[k,j] then
            begin
              f[j] := min(f[k],cap[k,j] - flow[k,j]);
              last[j] := k;
            end;{then}

            if flow[j,k] > 0 then
            begin
              f[j] := min(f[k],flow[j,k]);
              last[j] := -k;
            end;{then}

            if last[j] <> 0 then
            begin
              inc(size[a]);
              queue[a,size[a]] := j;
            end;{then}

          end;{then}
    until (last[sink] <> 0) or (size[a] = 0);

    {fix}
    i := sink;
    inc(sol,f[sink]);
    if f[sink] <> 0 then
      repeat
        if last[i] > 0
          then inc(flow[last[i],i],f[sink])
          else dec(flow[i,-last[i]],f[sink]);
        i := abs(last[i]);
      until i = source;

  until f[sink] = 0;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
110ş Fiesta de A¤o Nuevo                                    Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  grupo  de  N (3 <= N <= 200) personas est n teniendo una fiesta de
a¤o nuevo. Cada persona es capaz de cocinar varios tipos diferentes de
comida  (llamado  tambi‚n "platos"). Hay un total de D (5 <= D <= 100)
diferentes  tipos  de  comida.  Cada tipo de comida es denotado por un
entero en el rango de 1..D.

El coordinador quiere maximizar el n£mero total de platos tra¡dos a la
fiesta,  pero tiene que especificar un l¡mite para el n£mero de platos
de  cada  tipo.  Cada persona puede traer K (1 <= K <= 5) platos, pero
ellos  deben ser diferentes uno del otro (una persona no puede traer 3
pasteles  de  chocolate,  por  ejemplo,  pero  puede  traer un pastel,
panesillos,  y  una  sabrosa alfalfa en salsa de naranja). ¨Cu l es la
m xima      cantidad    de    comida    que    puede    ser    tra¡da?

Entrada

El  fichero  de  entrada  ser   PARTY.IN  el  cual tendr  el siguiente
formato:
- l¡nea 1: Tres enteros N, K y D.
- l¡nea 2: D n£meros enteros no negativos que reprentan el n£mero total
           de cada plato que puede ser tra¡dos a la fiesta.
- l¡nea 3..N+2: Cada l¡nea contiene un entero inicial Z (1 <= Z <= D)
           denotando  el  n£mero de diferentes platos que cada persona
           puede preparar; el resto de la l¡nea contiene Z enteros que
           identifica cada comida, comida tipo 1 primero, comida tipo 2
           segundo, etc..

Salida

La salida ser  a trav‚s del fichero PARTY.OUT con una simple l¡nea con
un  simple  entero    que  es el m ximo n£mero de platos que puede ser
tra¡dos para la fiesta.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PARTY.IN  ³ ³ PARTY.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 3 5     ³ ³ 9         ³
³ 2 2 2 2 3 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4 1 2 3 4 ³
³ 4 2 3 4 5 ³
³ 3 1 2 4   ³
³ 3 1 2 3   ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}