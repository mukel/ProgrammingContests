{koder: A^2P}
{PSN 2004 #73 "Plan de sacrificio"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 101 * 2;
var
  fin,fout        : text;
  N,M,C,S,i,j,k,h : integer;
  x,y,sol,p       : array[0..MaxN] of integer;

    function cross(o,c,m: byte): longint;
    begin
      cross := longint(x[c] - x[o]) * (y[m] - y[o])
             - longint(x[m] - x[o]) * (y[c] - y[o]);
    end;{cross}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=M + 1 to M + N do readln(fin,x[i],y[i]);
  for i:=1 to M do readln(fin,x[i],y[i]);

  {solve}{convex-hull.jarvis-march}
  k := 1;
  for i:=1 to M do
    if x[i] < x[k] then k := i;

  j := k;
  repeat
    h := byte(j = 1) + 1;
    for i:=1 to M do
      if cross(i,h,j) < 0 then h := i;
    inc(C); p[C] := j;
    j := h;
  until j = k;
  p[C + 1] := k;

  for i:=1 to N do
    for j:=1 to C do
      if cross(p[j],p[j + 1],M + i) >= 0 then
      begin
        inc(S); sol[S] := i;
        break;
      end;{then}

  {dprint}
  writeln(fout,S);
  for i:=1 to S do write(fout,sol[i],' ');

  {fclose}
  close(fin); close(fout);
end.{main}

{
73ş Plan de sacrificio.                                    Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mikol tiene en su finca instalado un sistema de aislamiento contra
plagas que consta de varios postes, cuando dos de ellos se conectan
crean una especie de pared magn‚tica que no deja pasar a ninguna
plaga. Al conectar varios postes se puede crear un area cerrada y
aislada. Mikol se entera que se aproxima un plaga maligna para su
ganado, el sabe la posici¢n de cada vaca. Como las vacas que no se
puedan aislar se infestar n, Mikol debe saber cu les son para
sacrificarlas, usted debe ayudarlo y decirle cuales son esas vacas.
Enti‚ndase las vacas que no puedan ser aisladas, o sea, aquellas que
siempre queden fuera de cualquier  rea aislada que se forme.

Tarea

- Leer del fichero de entrada "VACAS.IN" la ubicaci¢n de las vacas y
  la ubicaci¢n de los postes, ambos representados en un sistema de
  coordenadas.
- Encontar las vacas que deber n ser sacrificadas.
- Escribir hacia el fichero de salida "VACAS.OUT" el n£mero de las
  vacas que deber n ser sacrificadas.

Entrada

El fichero de entrada "VACAS.IN" contendr  en la primera l¡nea dos
enteros N (cantidad de vacas) y M (cantidad de postes) (3 <= N, M <=
100). En las siguientes N l¡neas, en la l¡nea i+1 (i=1..N) aparecer n
dos enteros A y B, fila y columna de la posici¢n de la i-‚sima vaca
(-10000 <= A, B <= 10000). En las £ltimas M l¡neas aparecer n, en la
l¡nea j+N+1 (j=1..M) dos enteros X y Y, fila y columna de la posici¢n
del j-‚simo poste (-10000<=X, Y<=10000). No habr n tres puntos en el
sistema que pertenezcan a una misma l¡nea.

Salida

El fichero de salida "VACAS.OUT" contendr  en la primera l¡nea un
entero K denotando la cantidad de vacas que hay que sacrificar. En la
segunda l¡nea del fichero aparecer n K enteros, representando los
n£meros de las K vacas.

 Ejemplo #1 de Entrada y Salida.

 ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
 ³VACAS.IN³  ³VACAS.OUT³
 ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
 ³ 4 4    ³  ³ 2       ³
 ³ 3 2    ³  ³ 3 4     ³
 ³ 3 4    ³  ÀÄÄÄÄÄÄÄÄÄÙ
 ³ 1 1    ³
 ³ 1 3    ³
 ³ 2 1    ³
 ³ 2 4    ³
 ³ 4 2    ³
 ³ 4 5    ³
 ÀÄÄÄÄÄÄÄÄÙ
}
