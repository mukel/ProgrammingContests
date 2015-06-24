{koder: A^2P}{3 - 4 - 2007}
{PSN 2007 #44 "Ordenamiento de Vacas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,i,j,cant,sol  : longint;
  list,next       : array[0..MaxN] of longint;
  mark            : array[0..MaxN] of boolean;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := list[(d + h) shr 1];
      repeat
        while list[i] < p do inc(i);
        while list[j] > p do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          tmp := next[i]; next[i] := next[j]; next[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

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
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,list[i]); next[i] := i;
  end;{for}

  {solve}
  qsort(1,N);
  for i:=1 to N do
    if (not mark[i]) and (next[i] <> i) then
    begin
      j := i; cant := 0;
      while next[j] <> i do
      begin
        j := next[j];
        mark[j] := true;
        inc(sol,list[j]); inc(cant);
      end;{while}
      sol := sol + min(list[i] * cant,
                list[1] * cant + 2 * (list[1] + list[i]))
    end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
44ş Ordenamiento de Vacas.                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N (1 <= N <= 10,000) vacas del Granjero Juan est n alineadas  para
ser orde¤adas en la tarde. Cada vaca tiene un nivel de “mal humor”  en
el rango 1...100,000.  Debido a que  las vacas con  mal humor son  m s
propensas a da¤ar el equipo de orde¤o de GJ, GJ quisiera reordenar las
vacas  en  la  l¡nea  de  tal  manera  que  est‚n  alineadas  en orden
ascendente de  mal humor.  Durante este  proceso, los  lugares de  dos
vacas   cualesquiera   (no  necesariamente   adyacentes)   pueden  ser
intercambiados. Desde que las vacas mal humoradas son m s dif¡ciles de
mover, le  toma a  GJ X+Y  unidades de  tiempo intercambiar  dos vacas
cuyos niveles de mal humor sean X y Y.

Ayude a GJ  a calcular el tiempo m¡nimo requerido para reordenar a las
vacas.

NOMBRE DEL PROBLEMA: csort

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero : N.

- L¡neas 2..N+1: Cada l¡nea contiene un solo entero: la l¡nea i+1
      describe el mal humor de la vaca i.

ENTRADA EJEMPLO (archivo csort.in)

3
2
3
1

DETALLES DE LA ENTRADA:

Tres vacas est n en la l¡nea con niveles de mal humor de
respectivamente 2, 3, y 1.

FORMATO DE SALIDA:

- L¡nea 1: Una sola l¡nea con el tiempo m¡nimo requerido para
      reordenar las vacas en orden creciente de mal humor.

EJEMPLO DE SALIDA (archivo csort.out):

7

DETALLES DE LA SALIDA:

2 3 1 : Orden inicial.
2 1 3 : Despu‚s de intercambiar las vacas con mal humor 3 y 1
        (tiempo=1+3=4).
1 2 3 : Despu‚s de intercambiar las vacas con mal humor 1 y 2
        (tiempo=2+1=3).
}
