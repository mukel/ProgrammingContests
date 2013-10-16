{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #85 "El Prom Bovino"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  MaxM = 50000;
type
  edge = record
    A,B : longint;
  end;{edge}
var
  fin,fout        : text;
  N,M,S,i,sol,last : longint;
  list            : array[0..MaxM] of edge;
  P,F,dfsnum,low,
  stack           : array[0..MaxN] of longint;
  mark            : array[0..MaxN] of boolean;

    var pv,tmp : edge;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; pv := list[(d + h) shr 1];
      repeat
        while list[i].A < pv.A do inc(i);
        while list[j].A > pv.A do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    procedure dfs(v: longint);
    var i,j : longint;
    begin
      inc(last);
      low[v] := last;
      dfsnum[v] := last;
      inc(S); stack[S] := v;
      mark[v] := true;

      if P[v] <> 0 then
        for i:=P[v] to F[v] do
          if not mark[list[i].B] then
          begin
            dfs(list[i].B);
            if low[list[i].B] < low[v]
              then low[v] := low[list[i].B];
          end{then ->}
          else if dfsnum[list[i].B] < low[v]
               then low[v] := dfsnum[list[i].B];

      if dfsnum[v] = low[v] then
      begin
        if stack[S] <> v then inc(sol);
        repeat
          j := stack[S]; dec(S);
          mark[j] := false;
        until j = v;
      end;{then}

    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
    readln(fin,list[i].A,list[i].B);

  {solve}
  qsort(1,M);
  i := 1;
  repeat
    P[list[i].A] := i;
    while list[i + 1].A = list[i].A do inc(i);
    F[list[i].A] := i;
    inc(i);
  until i > M;

  {strong components}
  for i:=1 to N do
    if dfsnum[i] = 0 then dfs(i);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
85ş El Prom Bovino.                                        M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N (2  <= N <=  10,000) vacas est n  excitadas: ¡es la  noche de su
prom!  Ellas  est n vestidas  con  sus vestidos  de  etiqueta con  sus
ramilletes y zapatos  nuevos. Ellas saben  que esta noche  trataran de
ejecutar el Baile Circular.

Unicamente las vacas pueden ejecutar el Baile Circular el cual tambi‚n
requiere un conjunto  de cuerdas. Para  comenzar, las vacas  rodean el
tanque de agua circular y se numeran consecutivamente en orden horario
de 1  a N.  Luego ellas  adquieren un  total de  M (2  <= M <= 50,000)
cuerdas, todas  las cuales  son distribuidas  a las  vacas quienes las
tienen  con sus  pezu¤as. Cada  vaca espera  que le  den cuerdas  para
tenerlas tanto en su pezu¤a  izquierda como en la derecha;  algunas de
ellas ocasionalmente quedan disconformes.

Para que el Baile Circular sea un ‚xito para cualquier vaca dada  (por
ejemplo, Bessie), las cuerdas que ella tiene deben ser configuradas de
la manera correcta. El baile  requiere que uno examine el  conjunto de
vacas que tiene los otros extremos de sus cuerdas, junto con las vacas
que tengan los otros extremos de cualquier cuerda tenida por cualquier
vaca  del  conjunto,  etc.  Cuando  Bessie  baila  en  sentido horario
alrededor del tanque, ella jalar  instant neamente todas las vacas  en
su grupo alrededor de manera horaria, tambi‚n. De la misma manera,  si
ella baila en  el otro sentido,  ella instant neamente jalar   todo el
grupo de manera antihoraria.

Por  supuesto,  si  las cuerdas  no  est n  distribuidas adecuadamente
entonces un conjunto  de vacas podr¡an  no formar un  grupo adecuado y
esto no producir¡a un  ‚xito en el Baile  Circular. Una manera en  que
esto podr¡a  pasar es  cuando solo  una cuerda  conecta dos vacas. Una
vaca podr¡a jalar la otra en una direcci¢n, pero no podr¡a jalarla  en
la otra (desde que  es un hecho bien  conocido que empujar cuerdas  no
tiene sentido). Note que las vacas deben bailar en pasos cerrados: una
vaca colgada (tal vez con solo una cuerda) que es jalada eventualmente
descalifica un  grupo de  ejecutar el  Baile Circular  desde que no es
jalada inmediatamente en pasos cerrados con el resto.

Dadas las cuerdas  y  su distribuci¢n  a las vacas,  Cu ntos grupos de
vacas  pueden ejecutar  apropiadamente el  Baile Circular?  La  cuerda
podr¡a  envolver  muchas  veces  alrededor  del  tanque  de  agua, por
supuesto.

NOMBRE DEL PROBLEMA: prom

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio N y M.

- L¡neas 2..M+1: Cada l¡nea contiene dos enteros separados por espacio
  A y B  que  describen  una cuerda  de  la  vaca  A  a la  vaca B  en
direcci¢n horaria.

ENTRADA EJEMPLO (archivo PROM.IN):

5 4
2 4
3 5
1 2
4 1

DETALLES DE LA ENTRADA:

La representaci¢n en ASCII para  un Baile Circular es desafiante.  Sin
embargo, aqu¡ hay una representaci¢n de las vacas alrededor del tanque
de agua:

       _1___
      /**** \
   5 /****** 2
  / /*TANQUE*|
  \ \********/
   \ \******/  3
    \ 4____/  /
     \_______/


FORMATO DE LA SALIDA:

- L¡nea  1:   Una  sola l¡nea  con un  solo entero  que es el n£mero de
grupos que bailan exitosamente el Baile Circular.

SALIDA EJEMPLO (archivo PROM.OUT):

1

DETALLES DE LA SALIDA:

Las vacas 1, 2, y 4 est n conectadas apropiadamente y forman un  grupo
completo de  Baile Circular.  Las vacas  3 y  5 no  tienen la  segunda
cuerda que  ellas necesitan  para jalar  en ambas  direcciones, por lo
tanto ellas no pueden ejecutar apropiadamente el Baile Circular.
}