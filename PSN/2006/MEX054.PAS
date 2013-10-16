{koder: A^2P}
{PSN 2006 #54 "Alcanc¡as"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  next,mark       : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,next[i]);

  {solve}  
  for i:=1 to N do
    if mark[i] = 0 then
    begin
      j := i;
      repeat
        mark[j] := i; j := next[j];
      until mark[j] <> 0;
      if mark[j] = i then inc(sol);
    end;{then}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
54ş Alcanc¡as.                                             M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Byteazar el Drag¢n tiene N alcanc¡as. Cada alcanc¡a puede ser  abierta
con su  correspondiente llave  o rompi‚ndola.  Byteazar ha  puesto las
llaves en alguna  de las alcancias  - ‚l recuerda  cual llave ha  sido
localizada en cual alcanc¡a. Byteazar tiene la intenci¢n de comprar un
carro y necesita un paso de acceso a todas las alcanc¡as. No obstante,
el   quiere  destruir   la menor   cantidad   de  alcanc¡as como   sea
posible.  Ayude  a Byteazar a determinar cu ntas alcancias tienen  que
ser rotas.

Task

Escriba un programa el cual:

-  lea del  fichero de  entrada SKA.IN  el n£mero  de alcancias  y la
   ubicaci¢n de sus correspondientes llaves,

-	encuentre el n£mero  m¡nimo de alcancias que ser n rotas  para tener
  acceso a todas,

- escriba el resultado hacia SKA.OUT.

Entrada

En la primera l¡nea del  fichero de entrada SKA.IN contiene  un entero
simple  N (1  <= N  <= 1.000.000)  - este  es el  n£mero de  alcancias
propiedad del  drag¢n. Las  alcancias (asi  como sus  correspondientes
llaves) est n numeradas desde 1 hasta N. A continuaci¢n, hay N l¡neas:
la  (i+1)-‚sima  l¡nea  contiene  un  entero  simple  -  el  n£mero de
la alcancia en la cuales la i-‚sima llave ha sido localizada.

Salida

La primera  l¡nea del  fichero de  salida SKA.OUT  contiene un  entero
simple -  el n£mero  m¡nimo de  alcancias que  ser n rotas  para tener
acceso  a todas las alcanc¡as.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
³ SKA.IN  ³ ³ SKA.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
³ 4       ³ ³ 2       ³
³ 2       ³ ÀÄÄÄÄÄÄÄÄÄÙ
³ 1       ³
³ 2       ³
³ 4       ³
ÀÄÄÄÄÄÄÄÄÄÙ

En el ejemplo anterior las alcancias 1 y 4 han sido rotas.
}