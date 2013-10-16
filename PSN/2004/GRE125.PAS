{koder: A^2P}{3 - 5 - 2007}
{PSN 2004 #125 "Red de energ¡a"}
{ Los JDs tienen si tienen espacios(dice que no) }
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 102; { D + source + sink }
  oo = 1 shl 29;
var
  fin,fout        : text;
  s               : string;
  len             : byte absolute s;
  D,N,M,C,i,j,k,
  sol,a,b,
  source,sink     : longint;
  size            : array[0..1] of longint;
  last,f          : array[0..MaxN] of longint;
  queue           : array[0..1,0..MaxN] of longint;
  cap,flow        : array[0..MaxN,0..MaxN] of longint;

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
  readln(fin,D,N,M,C);
  source := D + 1; sink := D + 2;
  for i:=1 to C do
  begin
    readln(fin,s);
    while s[len] = ' ' do dec(len);
    val(copy(s,2,pos(',',s) - 2),j);
    val(copy(s,pos(',',s) + 1,pos(')',s) - pos(',',s) - 1),k);
    val(copy(s,pos(')',s) + 1,len - pos(')',s)),cap[j + 1,k + 1]);
  end;{for}
  for i:=1 to N do
  begin
    readln(fin,s);
    while s[len] = ' ' do dec(len);
    val(copy(s,2,pos(')',s) - 2),j);
    val(copy(s,pos(')',s) + 1,len - pos(')',s)),cap[source,j + 1]);
  end;{for}
  for i:=1 to M do
  begin
    readln(fin,s);
    while s[len] = ' ' do dec(len);
    val(copy(s,2,pos(')',s) - 2),j);
    val(copy(s,pos(')',s) + 1,len - pos(')',s)),cap[j + 1,sink]);
  end;{for}

  {solve}
  repeat
    a := 1; b := 0;
    size[a] := 1;
    queue[a,size[a]] := source;
    fillchar(f,sizeof(f),0);
    fillchar(last,sizeof(last),0);
    f[source] := oo;

    {BFS}
    repeat
      a := a xor 1; b := b xor 1;
      size[a] := 0;
      for i:=1 to size[b] do
        for j:=1 to D + 2 do if last[j] = 0 then
        begin
          k := queue[b,i];

          if cap[k,j] > flow[k,j] then
          begin
            f[j] := min(f[k],cap[k,j] - flow[k,j]);
            last[j] := k;
          end;{then}

          if flow[j,k] > 0 then
          begin
            f[j] := min(f[k],flow[j,k]);
            last[j] := -k;
          end;{flow}

          if last[j] <> 0 then
          begin
            inc(size[a]);
            queue[a,size[a]] := j;
          end;{then}

        end;{for}
    until (last[sink] <> 0) or (size[a] = 0);

    {fix}
    inc(sol,f[sink]);
    i := sink;
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
125þ Red de energ¡a.                                       Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una red de energ¡a consiste de nodos (estaciones de energ¡a,
consumidores y expedidores) conectados por l¡neas que transportan la
energ¡a. Un nodo u se puede abastecer con una cantidad s(u)>=0 de
energ¡a, puede producir una cantidad 0<=p(u)<=pmax(u) de energ¡a,
puede consumir una cantidad 0<=c(u)<=min(s(u),cmax(u)) de energ¡a y
puede enviar una cantidad d(u)=s(u)+p(u)-c(u) de energ¡a. Se aplican
las siguientes restricciones: c(u)=0 para cualquier estaci¢n de
energ¡a, p(u)=0 para cualquier consumidor, y p(u)=c(u)=0 para
cualquier expedidor. Hay a lo sumo una l¡nea de trasporte de energ¡a
(u,v) desde un nodo u a un nodo v de la red; esta transporta una
cantidad 0<=l(u,v)<=lmax(u,v) de energ¡a enviada por u a v. Sea
Con=Suma(c(u))) la energ¡a consumida en la red. El problema es
calcular el m ximo valor de Con.

Un ejemplo est  en la figura 1 (powernet.gif). La marca x/y de la
estaci¢n de energ¡a u muestra que p(u)=x y pmax(u)=y. La marca x/y del
consumidor u muestra que c(u)=x y cmax(u)=y. La marca x/y de la l¡nea
de transporte de energ¡a (u,v) muestra que l(u,v)=x y lmax(u,v)=y. La
energ¡a consumida es Con=6. Observe que que hay otros estados posibles
de la red pero el valor de Con no puede exceder a 6.

Entrada: (powernet.in)

La primera l¡nea del fichero de entrada contiene cuatro enteros,
0<=n<=100 (nodos), 0<=np<=n (estaciones de energ¡a), 0<=nc<=n
(consumidores), y 0<=m<=n*n (l¡neas de transporte de energ¡a). Cada
una de las pr¢ximas m l¡neas contiene un triplo (u,v)z, donde u y v
son identificadores de nodo (iniciando de 0) y 0<=z<=1000 es el valor
de lmax(u,v). Luego np l¡neas con duplos (u)z, donde u es el
identificador de una estaci¢n de energ¡a y 0<=z<=10000 es el valor de
pmax(u). Las £ltimas nc l¡neas son duplos (u)z, donde u es el
identificador de un consumidor y 0<=z<=10000 es el valor de cmax(u).
todos los n£meros en la entrada son enteros. Los triplos (u,v)z y los
duplos (u)z no contendr n espacios.

Salida: (powernet.out)

El fichero de salida debe contener la mayor cantidad de energ¡a que
puede consumir la red correspondiente.

Ejemplos de entrada y salida

Ejemplo #1             Ejemplo #2
ÚÄÄÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³powernet.in³          ³powernet.in³
ÃÄÄÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄÄÄ´
³2 1 1 2    ³          ³7 2 3 13   ³
³(0,1)20    ³          ³(0,0)1     ³
³(1,0)10    ³          ³(0,1)2     ³
³(0)15      ³          ³(0,2)5     ³
³(1)20      ³          ³(1,0)1     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ          ³(1,2)8     ³
ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿         ³(2,3)1     ³
³powernet.out³         ³(2,4)7     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´         ³(3,5)2     ³
³15          ³         ³(3,6)5     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ         ³(4,2)7     ³
                       ³(4,3)5     ³
                       ³(4,5)1     ³
                       ³(6,0)5     ³
                       ³(0)5       ³
                       ³(1)2       ³
                       ³(3)2       ³
                       ³(4)1       ³
                       ³(5)4       ³
                       ÀÄÄÄÄÄÄÄÄÄÄÄÙ
                       ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
                       ³powernet.out³
                       ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
                       ³6           ³
                       ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ

El ejemplo #1, codifica una red con dos nodos, la estaci¢n de energ¡a
0 con pmax(0)=15 y el consumidor 1 con cmax(1)=20, y con dos l¡neas de
transporte con lmax(0,1)=20 y lmax(1,0)=10. El m ximo valor de Con es
15. El ejemplo #2 codifica la red de la figura 1 (powernet.gif).
}
