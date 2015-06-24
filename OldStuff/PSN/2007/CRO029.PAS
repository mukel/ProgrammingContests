{koder: A^2P}{22 - 3 - 2007}
{PSN 2007 #29 "Cubierta de K-caminos"}
{
  Greedy (no da la solucion optima)
}
{$B-,I-,Q-,R-,S-}
const
  TiempoLimite = 1;
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  MaxM = 1000000;
  MaxE = 100;
type
  edge = record
    A,B : longint;
  end;{edge}
var
  fin,fout        : text;
  N,M,E,T,i,j,sol : longint;
  list            : array[0..MaxM] of edge;
  c               : array[0..MaxN] of longint;
  P,F             : array[0..MaxN] of boolean;
  sed             : array[0..MaxE] of longint;

    var tmp : edge; pv : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h;
      pv := c[list[(d + h) shr 1].A] +
            c[list[(d + h) shr 1].B];
      repeat
        while c[list[i].A] + c[list[i].B] < pv do inc(i);
        while c[list[j].A] + c[list[j].B] > pv do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
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
  readln(fin,T);

  {solve}
  for T:=1 to T do
  begin
    fillchar(P,N + 1,false);
    fillchar(F,N + 1,false);

    readln(fin,E,N,M); sol := 0;
    for i:=1 to N do readln(fin,c[i]);
    for i:=1 to M do
      readln(fin,list[i].A,list[i].B);

    qsort(1,M);

    i := 1; j := 1;
    repeat
      if (not P[list[i].A]) and (not F[list[i].A]) then
      begin
        inc(sol,c[list[i].A] + c[list[i].B]);
        P[list[i].A] := true; F[list[i].A] := true;
        sed[j] := i; inc(j);
      end;{then}
      inc(i);
    until (j = E + 1) or (i > M);

    {dprint}
    if i > M then writeln(fout,'NINGUNO')
    else begin
      writeln(fout,sol);
      for i:=1 to E do
        writeln(fout,list[sed[i]].A,' ',list[sed[i]].B);
    end;{else}

  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
29ş Cubierta de K-caminos.                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  cubierta de  K-caminos (k-path  cover) de  un grafo  orientado  es
un conjunto   de exactamente   k   de   sus arcos   seleccionados   de
tal    manera   que  cualquiera   dos   de  ellos   tengan  diferentes
v‚rtices   iniciales    y  cualquiera     dos    de     ellos   tengan
diferente   v‚rtices   finales.  Asumiendo  que   para   cada  v‚rtice
conocemos  su    costo   nosotros  podemos definir   el costo   de  el
arco como una suma  de los costos  de  su  comienzo y  final.  Tambi‚n
podemos definir el costo de  una cubierta de k-caminos como  una  suma
de  los   costos  de  sus   arcos.   Tu    tarea  es encontrar  la m s
barata cubierta  de  K-caminos para un  grafo orientado conociendo  el
costo de los v‚rtices.

        4            6            2

       (2) <ÄÄÄÄÄÄÄ (3) <Ä¿   ÚÄÄ (5)
        ^ º          ^    ³   ³   ^ º
        º ÈÍÍÍÍÍ»    ³    ³   ³   º º
        º       º    ³ÚÄÄÄÅÄÄÄÙ   º º
        º       ÈÍ>  ³v   ³       º v
       (1) ÄÄÄÄÄÄÄ> (4)   ÀÄÄÄÄÄÄ (6)

        5           10           3
     Un grafo y su m s barata cubierta de 4-caminos.

Entrada

La primera linea del fichero de entrada COVER.IN contiene el n£mero de
casos de  prueba  c  (1 <= c <= 20).  Cada uno de los  casos de prueba
comienza  con k,  el n£mero  de v‚rtices  n  y  el n£mero  de arcos  m
(1 <= k <= 100,  1 <= n <= 10000,  0 <= m <= 1000000). Las proximas  n
lineas contienen los costos de los v‚rtices,  cada uno de ellos es  un
entero  desde  [-100000,100000]. Entonces  m  lineas describiendo  los
arcos  como sigue,  cada  uno de  ellas  conteniendo exactamente   dos
n£meros  que  representan   sus  v‚rtices   inicial    y   final.  Los
v‚rtices   estan numerados desde 1 hasta n.

Salida

Para cada caso de prueba escribir hacia el fichero de salida COVER.OUT
el   costo de  la m s barata cubierta de K-caminos. En las proximas  k
lineas en cada una se escribiran cada uno de los arcos de la cubierta.
Cuando un grafo dado no tiene cubierta de K-caminos escribir  NINGUNO.
A continuacion la proxima solucion igual que se explic¢ anteriormente.

Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ COVER.IN ³  ³ COVER.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 1        ³  ³ 33        ³
 ³ 4 6 9    ³  ³ 1 2       ³
 ³ 5        ³  ³ 2 4       ³
 ³ 4        ³  ³ 5 6       ³
 ³ 6        ³  ³ 6 5       ³
 ³ 10       ³  ÀÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 2        ³
 ³ 3        ³
 ³ 1 2      ³
 ³ 1 4      ³
 ³ 2 4      ³
 ³ 3 2      ³
 ³ 4 3      ³
 ³ 5 4      ³
 ³ 6 3      ³
 ³ 5 6      ³
 ³ 6 5      ³
 ÀÄÄÄÄÄÄÄÄÄÄÙ
}