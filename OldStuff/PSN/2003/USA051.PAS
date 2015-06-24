{koder: A^2P}
{PSN 2003 #51 "Aislador"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  p,tmp           : word;
  N,i,sol         : longint;
  c               : array[1..MaxN] of word;

    procedure qsort(d,h: longint);
    var i,j   : longint;
    begin
      i := d; j := h; p := c[(d+h) div 2];
      repeat
        while c[i] > p do inc(i);
        while c[j] < p do dec(j);
        if i <= j then
        begin
          tmp := c[i]; c[i] := c[j]; c[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,c[i]);

  {solve}
  qsort(1,N);
  for i:=1 to N div 2 do
    inc(sol,c[i] shl 1);
  if odd(N) then inc(sol,c[i+1]);

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
51þ Aislador.                                                 USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  compa¤¡a  Insumax produce aisladores t‚rmicos multicapas. Cada una
de las i capas, i = 1, 2, ..., n de un aislador est  caracterizada por
un    coeficiente  de  aislamiento  a(i)  positivo.  Las  capas  est n
numeradas acorde a la direcci¢n de la fuga del calor.

      calor -> ³³a(1)³a(2)³...³a(i)³a(i+1)³a(n)³³->

El  coeficiente  de  aislamiento del aislador completo, A, es descrito
por  la  suma de los coeficientes de aislamiento de sus capas. Adem s,
el  coeficiente  A  se  eleva  si  una  capa,  con  un  coeficiente de
aislamiento  m s peque¤o es seguida por una capa con un coeficiente de
aislamiento m s grande, acorde a la f¢rmula:

    n         n-1
A = ä      a(i)    +    ä max (0,   a(i+1)  -  a(i))
    i=1       i=1

Por  ejemplo,  el  coeficiente de aislamiento del aislador de la forma

      -> ³³ 5 ³ 4 ³ 1 ³ 7 ³³ ->

es A = (5  +  4  +  1  +  7)  +  (7  -  1)  =  23

Tarea

Escriba  un  programa el cual, para el coeficiente de aislamiento dado
de  las  capas a(1), a(2), ..., a(n), determine un ordenamiento de las
capas  tal que el coeficiente de aislamiento del aislador completo sea
maximizado.

Entrada
En  la  primera l¡nea del fichero texto IZO.IN est  el n£mero de capas
N,  1  <=  N  <=  100,000. En las sucesivas  N l¡neas hay coeficientes
a(1), a(2), ..., a(n), uno por l¡nea. Estos  coeficientes  son enteros
que satisfacen la desigualdad 1 <= a(i) <= 10,000.

Salida

En la primera y £nica l¡nea del fichero texto IZO.OUT tu programa debe
escribir  un  entero igual al valor m s grande posible del coeficiente
de aislamiento A del aislador construido con las capas de coeficientes
dadas, puestas en un orden particular.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ IZO.IN ³  ³ IZO.OUT ³
ÃÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 4      ³  ³ 24      ³
³ 5      ³  ÀÄÄÄÄÄÄÄÄÄÙ
³ 4      ³
³ 1      ³
³ 7      ³
ÀÄÄÄÄÄÄÄÄÙ
}