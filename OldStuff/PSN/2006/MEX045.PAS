{koder: A^2P}{11 - 3 - 2007}
{PSN 2006 #45 "Suma M xima"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,i,j,k,h,sol   : longint;
  t               : array[0..MaxN] of longint;
  c               : array[0..MaxN,0..MaxN] of shortint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    for j:=1 to N do read(fin,c[i,j]);

  {solve}
  sol := -MaxLongint;
  for i:=1 to N do
  begin
    fillchar(t,sizeof(t),0);
    for j:=i to N do
    begin
      h := 0;
      for k:=1 to N do
      begin
        inc(t[k],c[j,k]);
        if h < 0 then h := t[k] else inc(h,t[k]);
        if h > sol then sol := h;
      end;{for}
    end;{for}
  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
45ş Suma M xima.                                           M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dado un arreglo de dos  dimensiones de enteros negativos y  positivos,
encuentre  el subrectangulo  con la  suma m s  grande. La  suma de  un
rectangulo es  la suma  de todos  los elementos  en ese rectangulo. En
este problema el  sub-rectangulo con la  mas grande suma  se refiere a
como el subrectangulo maximo. Un subrectangulo es cualquier subarreglo
localizado  dentro   del  arreglo   completo.  Como   un  ejemplo,  el
subrectangulo maximo del arreglo:

    0 -2 -7  0
    9  2 -6  2
   -4  1 -4  1
   -1  8  0 -2

esta en la esquina inferior izquierda:

    9 2
   -4 1
   -1 8

y tiene como suma 15.

Entrada

El fichero de entrada SUBMTX.IN consiste de un arreglo de enteros.  La
entrada comienza   con un   entero positivo   simple N   en una  l¡nea
indicando  el tama¤o  del cuadrado de dos dimensiones. Esto es seguido
por N  filas de  N  enteros  cada  uno   separados  entre   si por  un
espacio  en  blanco. N  puede se  tan largo como 100. Los  numeros  en
el arreglo estaran en  el rango [-127, 127].

Salida

La primera y £nica l¡nea del  fichero de  salida SUBMTX.OUT  contiene un
entero el cual representa la suma del subrect ngulo m ximo.

Ejemplo de entrada y salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ SUBMTX.IN  ³  ³ SUBMTX.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4          ³  ³ 15         ³
³ 0 -2 -7 0  ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 9 2 -6 2   ³
³ -4 1 -4  1 ³
³ -1 8 0 -2  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
