{koder: A^2P}{16 - 3 - 2007}
{PSN 2000 #10 "Tri ngulo triangulado"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  N,i,j,k,sol     : longint;
  buff            : array[0..$ffff] of byte;
  c               : array[0..MaxN,1..3] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  settextbuf(fin,buff);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  inc(N);
  for i:=1 to N do
    for j:=1 to i do
    begin
      read(fin,k);
      if k = 1 then
      begin
        inc(c[j,1]);         //col
        inc(c[N - i + 1,2]); //fil
        inc(c[i - j + 1,3]); //diag
      end;{then}
    end;{for}

  for i:=1 to N + 1 do
    for j:=1 to 3 do
      sol := sol + (c[i,j] * ((N - i + 1) - c[i,j]));

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 10ş Tri ngulo triangulado                                  China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Se tiene la  triangulaci¢n de un tri ngulo, obtenida como sigue: cada
 lado del tri ngulo se ha dividido en M partes iguales (M es un n£mero
 natural  cualquiera) y por cada punto divisorio se han trazado rectas
 paralelas a los  otros dos  lados. Cada v‚rtice se ha pintado con uno
 de  los  colores: blanco o negro. Determine  el  n£mero de aristas de
 cuyos v‚rtices tienen color diferente.

 En  la  figura  esta  representada  una triangulaci¢n para M = 5, los
 v‚rtices  pintados de blanco tienen un cero al lado y los pintados de
 negro  tienen  un  uno.  El  n£mero  de aristas con v‚rtices de color
 diferente es 54.

 Entrada

 El  archivo  de  entrada  contiene  en la primera l¡nea el valor de M
 (1 < M < 10000). Las pr¢ximas M+1 l¡neas contienen la descripci¢n  de
 los v‚rtices  de  la  triangulaci¢n,  un cero indica que  el  v‚rtice
 esta pintado de  blanco  y  un  uno  que  esta pintado de negro. Cada
 n£mero se separa  por  un  espacio. Las  filas  del tri ngulo estar n
 alineadas por la izquierda desde el v‚rtice superior hasta la base.

  Salida

  El archivo de salida deber  contener solamente el n£mero de  aristas
  con v‚rtices de color diferente.

  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
  ³ Archivo de Entrada ³ ³ Archivo de Salida ³
  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
  ³ 5                  ³ ³ 54                ³
  ³ 0                  ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
  ³ 1 0                ³
  ³ 1 1 1              ³
  ³ 1 0 1 0            ³
  ³ 0 1 0 1 1          ³
  ³ 0 1 0 0 1 0        ³
  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
