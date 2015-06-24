{koder: A^2P}
{PSN 2005 #45 "Verificando una coartada"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxV = 100;
  MaxN = 500;
  oo = 100000000;
var
  fin,fout        : text;
  N,P,V,M,i,j,k,h : longint;
  s               : array[1..MaxV] of word;
  d               : array[0..MaxN] of longint;
  mark            : array[1..MaxN] of boolean;
  c               : array[1..MaxN,1..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,P,V,M);
  for i:=1 to N do
    for j:=1 to N do c[i,j] := oo;
  for i:=1 to N do c[i,i] := 0;
  for i:=1 to P do
  begin
    readln(fin,j,k,h);
    if h < c[j,k] then
    begin
      c[j,k] := h; c[k,j] := h;
    end;{then}
  end;{for}

  {solve}{dijsktra}
  d[0] := MaxLongint;
  mark[1] := true;
  for i:=1 to N do
    d[i] := c[1,i];
  for i:=1 to N-1 do
  begin
    k := 0;
    for j:=1 to N do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    for j:=1 to N do
      if (not mark[j]) and (d[k] + c[k,j] < d[j])
        then d[j] := d[k] + c[k,j];
  end;{for}

  {dprint}
  k := 0;
  for i:=1 to V do
  begin
    readln(fin,j);
    if d[j] <= M then
    begin
      inc(k); s[k] := i;
    end;{then}
  end;{for}
  writeln(fout,k);
  for i:=1 to k do writeln(fout,s[i]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
45Ý Verificando una coartada.                             Polonia 2005
----------------------------------------------------------------------

Un crimen  ha sido  cometido: una  carga de  grano ha  sido tomada del
establo por una  de las vacas  de GJ. GJ  est  tratando de  determinar
cual de sus C (1 <=  C <= 100) vacas es la  culpable. Afortunadamente,
un sat‚lite que pasaba por la zona  tom¢ una imagen de su granja M  (1
<= M <= 70000)  segundos antes que el  crimen tuviera lugar, dando  la
ubicaci¢n de  todas las  vacas. El  quiere saber  cuales vacas  ten¡an
tiempo para llegar al establo y robar el grano.

La  granja  del Granjero  Juan  comprende F  (1  <= F  <=  500) campos
numerados 1..F que est n  conectados por P (1  <= P <= 1,000)  caminos
bidireccionales cuyo  tiempo de  recorrido est   en el  rango 1..70000
segundos (las  vacas caminan  muy despacio).  El campo  1 contiene  al
establo. No toma ning£n tiempo desplazarse dentro de un campo.

Dada la distribuci¢n de la granja del Granjero Juan y la ubicaci¢n  de
cada vaca cuando el sat‚lite pas¢ por encima, determine el conjunto de
vacas que podr¡an ser culpables.

NOMBRE DEL PROLEMA: alibi

FORMATO DE ENTRADA:

- L¡nea 1: Cuatro enteros separados por espacios: F, P, C y M

- L¡neas 2..P+1: Tres  enteros separados por espacios  describiendo un
  camino:  F1, F2  y T.  El camino  conecta F1  y F2 y se requieren  T
  segundos para recorrerlo.
- L¡neas P+2..P+C+1: Un entero por l¡nea, la ubicaci¢n de una vaca. La
  primera  l¡nea da  el n£mero  del campo  donde  est   la vaca  1, la
  segunda de la vaca 2, etc.

ENTRADA EJEMPLO (archivo alibi.in):

7 6 5 8
1 4 2
1 2 1
2 3 6
3 5 5
5 4 6
1 7 9
1
4
5
3
7


DETALLES DE LA ENTRADA:

Campos/distancias como esto:
          6
      4------5
      |      |
     2|      |
      |      |
7-----1      |5
     |      |
     1|      |
      |      |
      2------3
          6

FORMATO DE SALIDA

- L¡nea 1:  Un solo  entero  N,  el numero  de vacas  que podr¡an  ser
  culpables del crimen.

- L¡neas 2..N+1: Un  solo n£mero de vaca  en cada l¡nea que  es una de
  las vacas que podr¡an ser culpables del crimen. La lista debe  estar
  en orden ascendente.

SALIDA EJEMPLO (archivo alibi.out):

4
1
2
3
4

DETALLES DE LA SALIDA:

Cualquier vaca,  excepto la  5 podr¡a  haberlo hecho.  A la  vaca 5 le
hubiera tomado 9 segundos llegar al establo.
}
