{koder: A^2P}
{PSN 1999 #61 "Barcos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 5000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  a,b,c           : array[0..MaxN] of longint;

    var p,tmp : longint;
    procedure qsort(d,h: integer);
    var i,j : integer;
    begin
      i := d; j := h; p := a[(d + h) shr 1];
      repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then
        begin
          tmp := a[i]; a[i] := a[j]; a[j] := tmp;
          tmp := b[i]; b[i] := b[j]; b[j] := tmp;
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
  readln(fin);
  readln(fin,N);
  for i:=1 to N do
    readln(fin,a[i],b[i]);

  {solve}
  qsort(1,N);
  for i:=1 to N do
    for j:=1 to i-1 do
      if (b[j] < b[i]) and (c[j] + 1 > c[i])
        then c[i] := c[j] + 1;

  for i:=1 to N do
    if c[i] > sol then sol := c[i];

  {dprint}
  writeln(fout,sol + 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 61ş Barcos                                               Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  pa¡s  Palmia  est   dividido  por  un  rio  en las riveras norte y
sur.  Hay  N  pueblos en ambas riveras. Cada pueblo en la rivera norte
tiene  un  £nico  pueblo amigo en la rivera sur. Dos pueblos no tienen
el mismo amigo.

A  cada  par  de  pueblos amigos le gustar¡a tener una l¡nea de barcos
que  los  conecte  a  ellos.  Ellos  solictar n  permiso  al gobierno,
porque  muchas  veces  hay  neblina  en  el  rio y el gobierno decidi¢
prohibir  intersecciones  de  l¡neas  de  barcos  (si  dos  l¡neas  se
intersectan hay una alta probabilidad de choques de barcos).

Tarea

Escribir  un programa que ayude a los oficiales del gobierno decidir a
cuales  l¡neas  de barcos ellos deben conceder permiso para obtener un
n£mero m ximo de l¡neas de barcos sin intersecci¢n.

Entrada

El  fichero  de  entrada contiene en la primera l¡nea dos enteros X, Y
separados  por un espacio, X (10 ó X ó 6000) representa la longitud de
la  rivera  del  Rio  de Palmia , Y (10 ó Y ó 100) representa el ancho
del  rio.  La segunda l¡nea contiene al entero N, el n£mero de pueblos
situados  en  ambas riveras norte y sur (1 ó N ó 5000). En cada una de
las pr¢ximas N l¡neas hay dos enteros no negativos C y D separados por
un  espacio  (C,  D ó X), representando la distancia de pueblos amigos
del  borde  oeste  (al  este) de Palmia medido a lo largo de la rivera
del  rio (C para el pueblo de la rivera norte y D para el pueblo de la
rivera  Sur).  No  hay  dos  pueblos  en la misma posici¢n en la misma
rivera. Ver figura 1 para el ejemplo de entrada.

Salida

El  ficheo  de  salida tiene que contener el n£mero m ximo de posibles
l¡neas de barcos que satisfagan la condici¢n de arriba.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de Entrada ³³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 30 4               ³³ 4                 ³
³ 7                  ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 22 4               ³
³ 2 6                ³                     Norte
³ 10 3               ³        2     4        9  10     15 17  22
³ 15 12              ³     ÄÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÄÅÄÄÅÄÄÄÅÄÄÄ
³ 9 8                ³
³ 17 17              ³  Oeste                                    Este
³ 4 2                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ     ÄÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄÄÅÄÄÄÅÄÄÄÄÄÄ
                              2  3  4  6  8     12        17
                                           Sur
                                         Figura 1
}