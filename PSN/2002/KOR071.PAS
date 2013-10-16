{koder: A^2P}
{PSN 2002 #71 "Tuber¡a para el organop¢nico"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 350;
  MaxM = 100000;
  oo = MaxLongint;
var
  fin,fout        : text;
  N,M,i,j         : longint;
  c               : array[0..MaxM] of longint;
  l,v             : array[1..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M,N);
  for i:=1 to N do readln(fin,l[i],v[i]);

  {solve}
  c[0] := oo;
  for i:=1 to N do
    for j:=M downto l[i] do
      if (c[j - l[i]] <> 0) and (v[i] > c[j]) then
        if v[i] < c[j - l[i]] then c[j] := v[i]
          else if c[j - l[i]] > c[j] then c[j] := c[j - l[i]];

  {dprint}
  write(fout,c[M]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
71ş Tuber¡a para el organop¢nico.                           Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los  compa¤eros  de agricultura urbana quieren mover agua del estanque
municipal al organop¢nico situado a una distancia D (7<= D <=100000).
Ellos  tienen  un  conjunto  de  P  (1<=p<=350) tubos, cada uno con un
entero positivo Li, la longitud y, un entero positivo Ci, la capacidad
(ambos n£meros se pueden representar en 24 Bits).

Los  tubos  pueden  ser conectados en serie en un recorrido. Los tubos
conectados  tienen  la  capacidad de la menor de todas las capacidades
individuales    de    los  tubos.  Un  recorrido  tiene  que  alcanzar
precisamente  D unidades (es decir, la suma de Li para los tubos en un
recorrido tiene que ser igual a D)

Entrada

El fichero de entrada PLUMB.IN contiene:
- l¡nea 1: una l¡nea con dos entero: D y P
- l¡nea 2.. N+1 : cada l¡nea contiene dos enteros describiendo un
  tubo: Li y Ci.

Salida

El fichero de salida PLUMB.OUT contiene una l¡nea con un entero simple
que es el flujo m ximo posible legal.


Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PLUMB.IN ³  ³ PLUMB.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 7 6      ³  ³ 5         ³
³ 4 5      ³  ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 6      ³
³ 2 7      ³
³ 1 4      ³
³ 6 7      ³
³ 1 5      ³
ÀÄÄÄÄÄÄÄÄÄÄÙ
}
