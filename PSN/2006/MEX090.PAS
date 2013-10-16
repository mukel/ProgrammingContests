{koder: A^2P}{30 - 4 - 2007}
{PSN 2006 #90 "Apagar las Luces"}
{ ¨Es la unica solucion? SUSPC.. }
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  ch              : char;
  stcase          : string;
  N,i,j,k,sol     : longint;
  res             : array[0..MaxN] of byte;
  Eq              : array[0..MaxN,0..MaxN + 1] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  N := 100;
  readln(fin,stcase);
  repeat
    {build}
    fillchar(Eq,sizeof(Eq),0);
    for i:=1 to N do
    begin
      read(fin,ch);
      Eq[i,N + 1] := byte(ch = 'O');
      if i mod 10 = 0 then readln(fin);

      Eq[i,i] := 1;
      if i mod 10 <> 1 then Eq[i,i - 1] := 1;
      if i mod 10 <> 0 then Eq[i,i + 1] := 1;
      if i - 10 >= 1 then Eq[i,i - 10] := 1;
      if i + 10 <= N then Eq[i,i + 10] := 1;
    end;{for}

    {triangulate}
    for i:=1 to N do
    begin 
      for j:=i to N do
        if Eq[j,i] = 1 then
        begin
          Eq[0] := Eq[i]; Eq[i] := Eq[j]; Eq[j] := Eq[0];
          break;
        end;{then}
      for j:=j + 1 to N do
        if Eq[j,i] = 1 then
          for k:=1 to N + 1 do
            Eq[j,k] := Eq[j,k] xor Eq[i,k];
    end;{for}

    {solve}
    sol := 0;
    for i:=N downto 1 do
    begin
      res[i] := Eq[i,N + 1];
      for j:=N downto i + 1 do
        if Eq[i,j] = 1 then res[i] := res[i] xor res[j];
      inc(sol,res[i]);
    end;{for}

    {dprint}
    write(fout,stcase,' ');
    if Eq[N,N] = 1
      then writeln(fout,sol)
      else writeln(fout,-1);

    readln(fin,stcase);
  until (stcase = 'end');

  {fclose}
  close(fin); close(fout);
end.{main}

{
90þ Apagar las Luces.                                      M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Usted esta ahora  frente  a  una importantisima tarea, que consiste en
ahorrar  energia  apagando luces.  Un  amigo  suyo  tiene el siguiente
problema en el trabajo. Hay una grilla de tama¤o 10 X 10 la cual tiene
un  bombillo en cada cuadricula.  Cada  bombillo  tiene  dos  posibles
estados, apagado y encendido.Nosotros definimos cambiar el estado como
pasar de un estado al otro. Por  desgracia  estas  luces  no funcionan
como se supone que lo hagan, ya  que  cuando  se le cambia el estado a
una tambien cambian  de  estado  las luces adyacentes, (arriba, abajo,
derecha, izquierda).  Por  supuesto que  las luces de los extremos les
cambian  el  estado  a  menos luces ya  que tienen  menos  adyacentes.

Para que quede mas claro como  funciona esto, abajo estan dos ejemplos
en  los cuales aparece una figura  antes y despues de que se le cambie
el estado al boton del medio.

###      #O#
###  ->  OOO
###      #O#

###      #O#
OOO  ->  ###
###      #O#

Tus amigos adoran ahorrar energia  y  te  han pedido que les  hagas un
programa  que  los  ayude  a saber si es posible o no apagar todas las
luces  y  en  caso  de  que sea posible decirles la minima cantidad de
pasos.

Entrada: (LIGTHS.IN)

La  entrada  consiste  de  varios casos de prueba. Cada caso de prueba
esta encabezado por una palabra que le da un nombre al mismo.  Despues
siguen  10  l¡neas  cada  una  con 10 caracteres '#' o 'O', donde  '#'
significa apagado y 'O' encendido.  La  entrada termina con la palabra
'end'.

Salida: (LIGTHS.OUT)

Para cada caso de prueba imprime una l¡nea de el nombre de dicho caso,
seguido  por  un  caracter  espacio  y  un entero que indica la minima
cantidad de pasos para apagar todas las luces. Si no es posible apagar
todas  las  luces o se requieren mas de 100 pasos, entonces escriba el
nombre del caso de prueba seguido por un espacio en blanco y un -1.

Ejemplo de Entrada:

all_off
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
all_on
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
simple
#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
########O#
#######OOO
########O#
end

Ejemplo de Salida:

all_off 0
all_on 44
simple 4
}