{koder: A^2P}
{PSN 2005 #18 "Adquisici¢n de Partes"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j,k       : word;
  b               : boolean;
  last,sol        : array[0..MaxN] of word;{mark}
  c               : array[1..MaxN,0..MaxN] of word;
  d               : array[boolean,0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    readln(fin,j,k);
    inc(c[j,0]);
    c[j,c[j,0]] := k;
  end;{for}

  {solve}{bfs}
  sol[0] := 1; d[b,0] := 1; d[b,1] := 1;
  repeat
    inc(sol[0]); b := not b; d[b,0] := 0;
    for i:=1 to d[not b,0] do
      for j:=1 to c[d[not b,i],0] do
        if last[c[d[not b,i],j]] = 0 then
        begin
          inc(d[b,0]);
          d[b,d[b,0]] := c[d[not b,i],j];
          last[c[d[not b,i],j]] := d[not b,i];
        end;{begin}
  until (last[M] <> 0) or (d[b,0] = 0);

  {dprint}
  if last[M] <> 0 then
  begin
    sol[sol[0]] := M;
    for i:=sol[0]-1 downto 1  do
      sol[i] := last[sol[i+1]];
    for i:=0 to sol[0] do writeln(fout,sol[i]);
  end{then}
  else write(fout,-1);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
18ş Adquisici¢n de Partes                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las vacas  han sido  enviadas en  una misi¢n  a trav‚s delespacio para
adquirir una  nueva m quina  orde¤adora para  su establo.  Ellas est n
viajando a trav‚s de un conglomerado de estrellas conteniendo N (1  <=
N <= 50,000) planetas, cada uno con una tienda.

Las vacas  han determinado  cu les de  K (1  <= K  <= 1,000)  tipos de
objetos (numerados 1..K) de cada planeta en el conglomerado desean,  y
cu les  productos  deben  comerciar.  Ning£n  planeta  ha desarrollado
dinero, por lo  tanto ellos trabajan  con el sistema  de trueque: todo
los intercambios consisten de que cada parte da exactamente un  objeto
(presumiblemente de tipos diferentes).

Las vacas parten de la Tierra  con un paquete de heno de  alta calidad
(¡tem  1),  y ellas  desean  una nueva  m quina  orde¤adora (¡tem  K).
Ay£delas  a  encontrar  la  mejor   manera  de  hacer  una  serie   de
intercambios en los planetas del conglomerado para obtener el ¡tem  K.
Si esta tarea es imposible, d‚ como salida -1.

NOMBRE DEL PROBLEMA: acquire

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacios, N y K.
- L¡neas 2..N+1:  La L¡nea  i+1  contiene  dos enteros   separados por
  espacio,  a_i  y  b_i   respectivamente,  que  son  los    productos
  de intercambio   del   planeta  i.  El   planeta dar    el  ¡tem b_i
  con  el prop¢sito de recibir el ¡tem a_i.

ENTRADA EJEMPLO (archivo acquire.in):

6 5
1 3
3 2
2 3
3 1
2 5
5 4

FORMATO DE SALIDA:

* L¡nea 1: El m¡nimo n£mero de intercambios T requeridos para obtener
  la m quina orde¤adora, la cual es el ¡tem K (o -1 si las vacas no
  pueden obtener el ¡tem K).

* L¡neas 2..T+1: La lista ordenada de objetos que las vacas poseen
  durante la secuencia de intercambios.

SALIDA EJEMPLO (archivo acquiere.out):

4
1
3
2
5

DETALLES DE LA SALIDA

Las vacas  poseen 4  objetos en  total: primero  ellas intercambian el
objeto 1 por el objeto 3, luego  el objeto 3 por el objeto 2,  y luego
el objeto 2 por el objeto 5.
}
