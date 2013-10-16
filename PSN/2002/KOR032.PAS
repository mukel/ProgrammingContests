{koder: A^2P}{13 - 3 - 2007}
{PSN 2002 #32 "Des¢rdenes"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j,k,
  a,b,tmp,sol     : longint;
  cant            : array[1..2] of longint;
  pos,ciclo       : array[0..MaxN] of longint;
  mark            : array[0..MaxN] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,pos[i]);

  {solve}
  {find dsords}
  for i:=1 to N do
    if not mark[i] then
    begin
      j := i; k := 0;
      repeat
        mark[j] := true;
        j := pos[j]; inc(k);
      until j = i;
      inc(cant[1],k div 2);
      inc(cant[2],(k - 1) div 2)
    end;{then}

  if cant[1] > 0 then inc(sol);
  if cant[2] > 0 then inc(sol);
  writeln(fout,sol);

  {solve dsords}
  for i:=1 to 2 do
    if cant[i] > 0 then
    begin
      fillchar(mark,sizeof(mark),false);
      write(fout,cant[i]);
      for j:=1 to N do
        if not mark[j] then
        begin
          k := j; M := 0;
          repeat
            inc(M); ciclo[M] := k;
            mark[k] := true;
            k := pos[k];
          until k = j;

          {swaps}
          for k:=1 to M div 2 do
          begin
            a := ciclo[k]; b := ciclo[M - k + 1];
            write(fout,' ',a,' ',b);
            tmp := pos[a]; pos[a] := pos[b]; pos[b] := tmp;
          end;{for}

        end;{for}
        writeln(fout);
    end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
32ş Des¢rdenes                                              Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una  permutaci¢n de los n£meros del 1 al N es una secuencia de n£meros
a1,  a2,...,  aN  en el cual apararece exactamente una vez cada uno de
los n£meros del 1 al N.

Un desorden de una permutaci¢n es una nueva permutaci¢n que se obtiene
al  realizar  un  conjunto  de  intercambios de pares de n£meros en la
primera tal que cada n£mero sea intercambiado a lo m s una sola vez.

Comenzando  con la permutaci¢n 1, 2,..., N se desea encontrar la menor
cantidad  de  des¢rdenes que se le deben de aplicar sucesivamente para
obtener ua permutaci¢n dada.

Por ejemplo, para N=5 se desea obtener la permutaci¢n 3, 4, 1, 5, 2.
Esto se logra con dos des¢rdenes, primero intercambiando el 1 por el 3
y el 2 por el 5 para posteriormente intercambiar el 5 por el 4.

Escriba un programa que encuentre:

- la cantidad D de des¢rdenes (subtarea A) y
- los intercambios (subtarea B) que se deben de efectuar en cada uno
  de los  una permutaci¢n dada.

Entrada

El  fichero texto DESORD.IN contiene en la primera l¡nea el valor de N
(1 <= N <= 1000) y en la segunda l¡nea una lista de N enteros del 1 a
N,

Salida

El  fichero  texto  DESORD.OUT  deber  contener en la primera l¡nea el
valor  de  D  y  en  cada una de las siguientes D l¡neas la cantidad K
de  intercambios seguida de K parajas de enteros indicando los n£meros
intercambiados.  Las parajas podr n estar escritas en cualquier orden,
pero  los  des¢rdenes  deber n  escribirse  en  el  orden  que  fueron
aplicados.

Ejemplos de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ DESORD.IN ³  ³ DESORD.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5         ³  ³ 2          ³
³ 3 4 1 5 2 ³  ³ 2 1 3 2 5  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ  ³ 1 5 4      ³
               ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ DESORD.IN     ³ ³ DESORD.OUT    ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7             ³ ³ 1             ³
³ 3 2 1 7 6 5 4 ³ ³ 3 1 3 4 7 5 6 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}