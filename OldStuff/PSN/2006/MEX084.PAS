{koder: A^2P}{11 - 3 - 2007}
{PSN 2006 #84 "Los Tazones de Agua"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 20 + 2;
var
  fin,fout        : text;
  N,i,sol1,sol2   : longint;
  t,s             : array[0..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  N := 20;
  read(fin,t[N]);
  for i:=1 to N - 1 do read(fin,t[i]);

  {solve}
  i := 1;
  repeat
    t[N] := t[N] xor t[i] xor t[i - 1];
    inc(i,3);
  until i > N;

  {sol1}
  t[N] := 0;
  for i:=N downto 1 do
  begin
    s[i] := t[i] xor s[i + 1] xor s[i + 2];
    inc(sol1,s[i]);
  end;{for}

  {sol2}
  t[N] := 1;
  for i:=N downto 1 do
  begin
    s[i] := t[i] xor s[i + 1] xor s[i + 2];
    inc(sol2,s[i]);
  end;{for}

  {dprint}
  if sol1 < sol2
    then writeln(fout,sol1)
    else writeln(fout,sol2);

  {fclose}
  close(fin); close(fout);
end.{main}

{
84þ Los Tazones de Agua.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las vacas tienen una l¡nea de 20 tazones de agua de donde ellas toman.
Los  tazones   pueden  estar   orientados  hacia   arriba  (orientados
apropiadamente para servir agua  fr¡a refrescante) o hacia  abajo (una
posici¢n en la cual no pueden  tener agua).  Ellas quieren que sus  20
tazones de agua  est‚n hacia arriba  y por lo  tanto usar sus  hocicos
anchos para voltear los tazones.

Sus hocicos, sin embargo, son  tan anchos que no solamente  voltean un
taz¢n sino los tazones en cualquier lado de ese taz¢n (un total tres ¢
en el caso de cualquier taz¢n de un extremo ¢ dos tazones).

Dado el estado inicial de los tazones (1=no tomable, 0=tomable)  ¨cu l
es  el m¡nimo  numero de  volteadas de  tazones para  poner todos  los
tazones hacia arriba?

NOMBRE DEL PROBLEMA: bowls

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero con 20 enteros separados por espacios


ENTRADA EJEMPLO (archivo bowls.in):

0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0

FORMATO DE SALIDA:

* L¡nea  1: El  n£mero m¡nimo  de volteadas  de tazones necesario para
poner todos  los tazones  hacia arriba  (esto es,  a 0).  Para las las
entradas dadas  siempre ser   posible encontrar  alguna combinaci¢n de
volteadas que manipularan los tazones a 20 0s.



SALIDA EJEMPLO (archivo bowls.out):

3

DETALLES DE LA SALIDA:

Voltear los tazones 4, 9, y 11 para hacer que se pueda tomar de todos:
0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [estado inicial]
0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [despu‚s de voltear el taz¢n 4]
0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 [despu‚s de voltear el taz¢n 9]
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 [despu‚s de voltear el taz¢n 11]
}