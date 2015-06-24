{koder: A^2P}{9 - 5 - 2007}
{PSN 2005 #90 "Campos inundados"}
{ Sexy Max-Flow }
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50;
  MaxLen = 627;
  oo = 1 shl 29;
  source = 626;
  sink = 627;
var
  fin,fout        : text;
  N,M,i,j,k,p,
  a,b,sol,
  cantH,cantV     : longint;
  size            : array[0..1] of longint;
  len,last,f      : array[0..MaxLen] of longint;
  mat             : array[0..MaxN,0..MaxN] of char;
  queue           : array[0..1,0..MaxLen] of longint;
  V,H             : array[0..MaxN,0..MaxN] of longint;
  cap,flow,list   : array[0..MaxLen,0..MaxLen] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    for j:=1 to M do read(fin,mat[i,j]);
    readln(fin);
  end;{for}

  {init}
  for i:=1 to N do
    for j:=1 to M do
      if mat[i,j] = '*' then
        if H[i,j - 1] = 0 then
        begin
          inc(cantH);
          H[i,j] := cantH;
        end{then ->}
        else H[i,j] := H[i,j - 1];

  cantV := cantH;
  for j:=1 to M do
    for i:=1 to N do
      if mat[i,j] = '*' then
        if V[i - 1,j] = 0 then
        begin
          inc(cantV);
          V[i,j] := cantV;
        end{then ->}
        else V[i,j] := V[i - 1,j];

  {connect}
  for i:=1 to N do
    for j:=1 to M do
      if mat[i,j] = '*' then
      begin
        inc(len[H[i,j]]);
        list[H[i,j],len[H[i,j]]] := V[i,j];
        cap[H[i,j],V[i,j]] := 1;
        inc(len[V[i,j]]);
        list[V[i,j],len[V[i,j]]] := H[i,j];
      end;{then}

  len[source] := cantH;
  for i:=1 to cantH do
  begin
    list[source,i] := i;
    cap[source,i] := 1;
  end;{for}

  for i:=cantH + 1 to cantV do
  begin
    inc(len[i]);
    list[i,len[i]] := sink;
    cap[i,sink] := 1;
  end;{for}

  {solve}
  repeat
    a := 1; b := 0;
    size[a] := 1; queue[a,size[a]] := source;
    fillchar(f,sizeof(f),0);
    fillchar(last,sizeof(last),0);
    f[source] := oo;

    {BFS}
    repeat
      a := a xor 1; b := b xor 1;
      size[a] := 0;

      for i:=1 to size[b] do
        for j:=1 to len[queue[b,i]] do
          if last[list[queue[b,i],j]] = 0 then
          begin

            k := queue[b,i];
            p := list[k,j];

            if cap[k,p] > flow[k,p] then
            begin
              f[p] := min(f[k],cap[k,p] - flow[k,p]);
              last[p] := k;
            end;{then}

            if flow[p,k] > 0 then
            begin
              f[p] := min(f[k],flow[p,k]);
              last[p] := -k;
            end;{then}

            if last[p] <> 0 then
            begin
              inc(size[a]);
              queue[a,size[a]] := p;
            end;{then}

          end;{then}

    until (last[sink] <> 0) or (size[a] = 0);

    {fix}
    i := sink;
    inc(sol,f[sink]);
    if f[sink] <> 0 then
      repeat
        if last[i] > 0
          then inc(flow[last[i],i],f[sink])
          else dec(flow[i,-last[i]],f[sink]);
        i := abs(last[i]);
      until i = source;

  until f[sink] = 0;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
90ş Campos inundados.                                     Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La lluvia ha ca¡do sobre el campo de las vacas, un arreglo rectangular
de R filas y C columnas (1 <= R <= 50, 1 <= C <= 50). Aunque la lluvia
es buena para el pasto, la lluvia hace que algunos pedazos de tierra
pelada se vuelvan lodosos. Las vacas, que son meticulosamente limpias,
no quieren tener sus pezu¤as sucias cuando ellas comen.

Para evitar que las pezu¤as de las vacas se enloden. El Granjero Juan
(GJ) colocar  tableros de madera sobre las partes enlodadas del campo
de las vacas. Cada uno de los tableros es de una unidad de ancho, y
puede tener cualquier longitud de largo. Cada tablero debe estar
al¡neado paralelo a uno de los ejes del campo.

El Granjero Juan quiere minimizar el n£mero de tableros necesarios
para cubrir las partes enlodadas, algunas de las cuales podr¡an
requerir mas de un tablero para ser cubiertas. Los tableros no deben
cubrir ninguna parte con pasto y privar a las vacas de lugares de
pasteo, pero pueden sobreponerse entre ellos.

Calcule el m¡nimo n£mero de tableros que GJ necesita para cubrir todas
las partes enlodadas en el campo.

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacios: R y C

- L¡neas 2..R+1: Cada l¡nea contiene una cadena de C caracteres, con ?*?
         representando un pedazo enlodado, y ?.? representando un pedazo
         con pasto. No hay espacios en blanco.

ENTRADA EJEMPLO (archivo cover.in):

4 4
*.*.
.***
***.
..*.

FORMATO DE SALIDA:

- L¡nea 1: Un solo entero representando el n£mero de tableros que GJ
         necesita.

SALIDA EJEMPLO (archivo cover.out):

4

DETALLES DE LA SALIDA:

Los tableros 1, 2, 3 y 4 son colocados como se muestra a continuaci¢n:
1.2.
.333
444.
..2.
el tablero 2 est  sobrepuesto por los tableros 3 y 4.
}
