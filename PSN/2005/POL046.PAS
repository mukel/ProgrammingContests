{koder: A^2P}{FPC}
{PSN 2005 #46 "Sin Heno"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
  oo = MaxLongint;
var
  fin,fout        : text;
  N,M,i,j,k,h,sol : longint;
  mark            : array[1..MaxN] of boolean;
  d               : array[0..MaxN] of longint;
  c               : array[1..MaxN,1..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  	for j:=1 to N do c[i,j] := oo;
  for i:=1 to N do c[i,i] := 0;
  for i:=1 to M do
  begin
    readln(fin,j,k,h);
    if h < c[j,k] then
    begin
      c[j,k] := h; c[k,j] := h;
    end;{then}
  end;{for}

  {solve}{prim}
  d[0] := oo;
  mark[1] := true;
  for i:=1 to N do
    d[i] := c[1,i];
  for i:=1 to N-1 do
  begin
    k := 0;
    for j:=1 to N do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    if d[k] > sol then sol := d[k];
    for j:=1 to N do
      if (not mark[j]) and (c[k,j] < d[j])
        then d[j] := c[k,j];
  end;{for}

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
46þ Sin Heno.                                             Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las vacas se  han quedado sin  heno, un suceso  horrible que debe  ser
remediado inmediatamente. Bessie quiere  recorrer algunas de las  N (2
<=  N <=  2,000) otras  granjas (numeradas  1..N) para  investigar su
situaci¢n de heno. Ella  recorrer  algunos de todos  los M (1 <=  M <=
10,000) caminos  de doble  v¡a cuya  longitud no  excede 1,000,000,000
que  conectan las  granjas. Algunas  granjas pueden  estar conectadas
m£ltiplemente con caminos de diferentes longitudes.

Bessie est  tratando de decidir  el tama¤o de la cantimplora  que ella
necesitar . Ella sabe que necesita una onza de agua por cada unidad de
distancia de un camino. Dado que  ella puede obtener m s agua en  cada
granja, ella £nicamente est  preocupada por la longitud del camino m s
largo. Por supuesto, ella planea  su ruta entre granjas de  tal manera
que ella minimice la cantidad de agua que ella debe cargar.

Ayude a que Bessie sepa la cantidad m s grande de agua que ella tendr 
que cargar: ¨cu l es la longitud del camino m s largo que ella  tendr 
que  recorrer entre  cualesquiera dos  granjas, presumiendo  que  ella
elija rutas que minimicen ese n£mero?

NOMBRE DEL PROBLEMA: outofhay

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio, N y M.

- L¡neas  2..1+M: La  l¡nea i+1  contiene tres  enteros separados  por
  espacios, A_i,  B_i, y  L_i, describiendo  un camino  de A_i  a  B_i
  de longitud L_i.

ENTRADA EJEMPLO (archivo outofhay.in):

3 3
1 2 23
2 3 1000
1 3 43


FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es la longitud del camino m s largo que
  necesita ser recorrido.

SALIDA EJEMPLO (archivo outofhay.out):

43

DETALLES DE LA SALIDA:

Con el prop¢sito de llegar a  la granja 2, Bessie viaja por  un camino
de longitud 23. Para llegar a la granja 3, Bessie viaja por un  camino
de longitud 43. Con una capacidad de 43, ella puede viajar a lo  largo
de estos  caminos dado  que ella  recarga su  cantimplora a  capacidad
m xima antes de comenzar un nuevo camino.
}
