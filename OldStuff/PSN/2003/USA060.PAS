{koder: A^2P}{1 - 5 - 2007}
{PSN 2003 #60 "Cerdos"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1102; { N + M + sink + source }
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,k,h,a,b,sol,
  source,sink     : longint;
  size            : array[0..1] of longint;
  len,last,f      : array[0..MaxN] of longint;
  queue           : array[0..1,0..MaxN] of longint;
  list,cap,flow   : array[0..MaxN,0..MaxN] of longint;

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
  source :=  N + M + 1;
  sink := N + M + 2;
  for i:=1 to N do
  begin
    inc(len[source]);
    list[source,len[source]] := i;
    read(fin,cap[source,i]);
  end;{for}
  for i:=N + 1 to N + M do
  begin
    read(fin,j);
    for j:=1 to j do
    begin
      read(fin,k);      
      inc(len[i]); list[i,len[i]] := sink;
      inc(len[i]); list[i,len[i]] := k;
      inc(len[k]); list[k,len[k]] := i;
      cap[k,i] := oo;
      for h:=1 to len[k] - 1 do
      begin        
        inc(len[i]); list[i,len[i]] := list[k,h];
        inc(len[list[k,h]]); list[list[k,h],len[list[k,h]]] := i;
        cap[list[k,h],i] := oo;        
      end;{for}
    end;{for}    
    readln(fin,cap[i,sink]);
  end;{for}

  {solve}
  repeat
    {BFS}
    a := 1; b := 0;
    size[a] := 1;
    queue[a,size[a]] := source;
    fillchar(last,sizeof(last),0);
    fillchar(f,sizeof(f),0);
    f[source] := oo; last[source] := -1;

    repeat
      a := a xor 1; b := b xor 1;
      size[a] := 0;
      for i:=1 to size[b] do
        for j:=1 to len[queue[b,i]] do
          if last[list[queue[b,i],j]] = 0 then
          begin
            h := queue[b,i];
            k := list[queue[b,i],j];

            if cap[h,k] > flow[h,k] then
            begin
              f[k] := min(f[h],cap[h,k] - flow[h,k]);
              last[k] := h;
            end;{then}

            if flow[k,h] > 0 then
            begin
              f[k] := min(f[h],flow[k,h]);
              last[k] := -h;
            end;{then}

            if last[k] <> 0 then
            begin
              inc(size[a]);
              queue[a,size[a]] := k;
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
60ş Cerdos.                                                   USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko  trabaja  en una granja de cerdos que consiste de M corrales con
cerradura  y  Mirko no puede abrir cualquier corral porque ‚l no tiene
las llaves. Los clientes vienen a la granja uno despu‚s del otro. Cada
uno  de  ellos tiene llaves para algunos corrales y quieren comprar un
cierto n£mero de cerdos.

Todos  los  datos  respecto  a  la  planificaci¢n de los clientes para
visitar  la  granja en ese d¡a particular est n disponibles para Mirko
temprano  en  la  ma¤ana  tal  que ‚l pueda hacer sus ventas-plan para
maximizar el n£mero de cerdos vendidos.

M s  exactamente,  el  procedimiento  es  como  sigue:  el usuario que
arriba,  abre  todos  los corrales de los cuales el tiene llave, Mirko
vende  un cierto n£mero de cerdos de todos los corrales abiertos a ‚l,
y,  si  Mirko  quiere,  el  puede  redistribuir los cerdos restantes a
trav‚s  de  los corrales abiertos. Un n£mero ilimitado de cerdos puede
ser  ubicado  en cada corral. Cuando Mirko termina de redistribuir los
cerdos  (si  fue  necesario)  y  por  ende  termina con un cliente los
corrales abiertos se cierran.

Tarea

Escriba  un  programa  que encuentre el n£mero m ximo de cerdos que ‚l
pueda vender en ese d¡a.

Entrada

La primera L¡nea del fichero de entrada PIGS.IN contiene dos enteros M
y N, 1 <= M <=100, 1 <= N <= 1000, representando el n£mero de corrales
y  el n£mero de clientes respectivamente. Los corrales est n numerados
de  1..M  y  los  clientes  est n numerados de 1 a N. La pr¢xima l¡nea
contiene  M  enteros,  representando  la  cantidad  de  cerdos en cada
corral.  El  n£mero  de cerdos en cada corral es mayor o igual que 0 y
menor  o  igual  que  1000.  Las pr¢ximas N l¡neas contienen registros
acerca  de  los  clientes  en la siguientes forma (registro acerca del
i-‚simo cliente en la (i+2)-‚sima l¡nea):
        a K1 K2 ... Ka B
Esto  significa  que  este  tiene llave para los corrales marcados con
n£meros  K1,k2,...Ka  (ordenados no decrecientemente) y que ‚l  quiere
comprar B cerdos. Los n£meros a y B pueden ser iguales a 0 (cero).

Salida

La primera y £nica l¡nea  del fichero de salida PIGS.OUT debe contener
el n£mero de cerdos vendidos.

Ejemplos de Entrada y Salida

Ejemplo # 1       Ejemplo # 2        Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PIGS.IN ³     ³ PIGS.IN     ³    ³ PIGS.IN               ³
ÃÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3 3     ³     ³ 6 6         ³    ³ 11 5                  ³
³ 3 1 10  ³     ³ 6 3 2 0 1 3 ³    ³ 1 2 2 1 0 2 4 1 1 1 2 ³
³ 2 1 2 2 ³     ³ 2 1 2 0     ³    ³ 5 1 2 3 4 5 3         ³
³ 2 1 3 3 ³     ³ 1 3 3       ³    ³ 4 1 2 6 7 5           ³
³ 1 2 6   ³     ³ 1 1 1       ³    ³ 2 3 8 1               ³
ÀÄÄÄÄÄÄÄÄÄÙ     ³ 2 2 3 8     ³    ³ 3 3 6 11 5            ³
ÚÄÄÄÄÄÄÄÄÄÄ¿    ³ 2 4 5 2     ³    ³ 3 8 9 10 3            ³
³ PIGS.OUT ³    ³ 2 4 6 6     ³    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄ´    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ    ÚÄÄÄÄÄÄÄÄÄÄ¿
³ 7        ³    ÚÄÄÄÄÄÄÄÄÄÄ¿       ³ PIGS.OUT ³
ÀÄÄÄÄÄÄÄÄÄÄÙ    ³ PIGS.OUT ³       ÃÄÄÄÄÄÄÄÄÄÄ´
                ÃÄÄÄÄÄÄÄÄÄÄ´       ³ 17       ³
                ³ 15       ³       ÀÄÄÄÄÄÄÄÄÄÄÙ
                ÀÄÄÄÄÄÄÄÄÄÄÙ
}