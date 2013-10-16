{koder: A^2P}{12 - 3 - 2007}
{PSN 2006 #46 "Entregando tareas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1002;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;
  time,pos        : array[0..MaxN] of longint;
  L,R             : array[-1..MaxN,-1..MaxN] of longint;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    begin
      i := d; j := h; p := pos[(d + h) shr 1];
      repeat
        while pos[i] < p do inc(i);
        while pos[j] > p do dec(j);
        if i <= j then
        begin
          tmp := time[i]; time[i] := time[j]; time[j] := tmp;
          tmp := pos[i]; pos[i] := pos[j]; pos[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M); readln(fin,M);
  for i:=1 to N do
    readln(fin,pos[i],time[i]);

  {solve}
  sol := oo;
  qsort(1,N);
  for i:=0 to N do
  begin
    for j:=N + 1 downto i do
    begin

      L[i,j]  := min(
        max(L[i - 1,j] + pos[i] - pos[i - 1] ,time[i]),
        max(R[i - 1,j] + pos[j] - pos[i] ,time[i]) );

      R[i,j] := min(
        max(L[i,j + 1] + pos[j] - pos[i] ,time[j]),
        max(R[i,j + 1] + pos[j + 1] - pos[j] ,time[j]) );

      if j = N + 1 then R[i,j] := oo
        else if i = 0 then L[i,j] := oo;

    end;{for}

    {L[i,i] = R[i,i]}
    j := L[i,i] + abs(M - pos[i]);
    if j < sol then sol := j;

  end;{for}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
46þ Entregando tareas.                                     M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Bessie tiene  que entregar  sus tareas  para sus  C clases  (1 <= C <=
1,000) en Moo U de tal manera que aun tenga tiempo para rumiar con sus
compa¤eros de  clases cuando  ellos esperan  por el  ¢mnibus para ir a
casa.

Los profesores aceptan las entregas  de tareas solo despu‚s que  ellos
han finalizado sus clases y   tambien limpiaron la pizarra,  guardaron
los instrumentos de  laboratorio, y asi  sucesivamente.  Los datos  de
entrada contienen el tiempo m s  temprano en que un profesor  aceptar 
la tarea.

Bessie comienza en un extremo (distancia 0) de un hallway H (1 <= H <=
1,000) metros  de largo  y camina  a razon  de un  metro por segundo a
varia aulas (en un orden que ella elige) para entregar su tarea.  Cada
aula  esta  localizada  a  lo   largo  de  este  halladay al igual que
la  puerta  al   area  de  espera   para  los  omnibus.

Dada la ubicaci¢n del  aula de la salida  y de las aulas  y tambien el
horario  de  los profesores,  determine  el tiempo  mas  tempreano que
Bessie puede  salir por  la puerta  que da  al area  de espera  de los
omnibus. Bessie tiene que entregar todas sus tareas antes de salir.  A
proposito el acto de entregar la tarea no toma ningun tiempo.

Entrada

El fichero de entrada TURNIN.IN  contiene:

- l¡nea 1: tres enteros: C, H, y B.  B (0  <= B <= H) es  la distancia
  de la entrada  del sal¢n al  rea de espera de los ¢mnibus.

- l¡neas 2..C+1:  cada una de  estas l¡neas contienen  dos enteros que
  describen un  aula   donde  la  tarea   ser   entregada.  El  primer
  entero (0..H) es el n£mero de  metros  al aula desde  la entrada del
  vestibulo. El segundo  entero  (0..10,000) es  el primer tiempo  (en
  segundos) que el profesor para ese curso aceptar  la tarea.

Salida

El  fichero de  salida TURNIN.OUT   contiene en  la primera  l¡nea  un
entero  simple: the  earliest second  que Bessie  puede salir  por  la
puerta al area de espera de ¢mnibus.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ TURNIN.IN ³ ³ TURNIN.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 10 3    ³ ³ 22         ³
³ 8 9       ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4 21      ³
³ 3 16      ³
³ 8 12      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ

Detalles de la salida

Tiempo  Acci¢n
  0 Bessie camina al aula que esta a 8 metros.
  8 Bessie espera 1 segundo.
  9 Bessie entrega la primera tarea.
  9 Bessie espera 5 segundos, pensando en el heno frio en el verano.
 12 Bessie entrega la tarea para esta localizaci¢n.
 12 Bessie camina hacia atras atras 4 metrs hasta el aula que esta a 4
    metros de la entrada.
 16 Bessie espera 5 segundos, pensando en un toro buen mozo que una
    vez conoci¢.
 21 Bessie entrega su tarea
 21 Bessie camina hacia atras 1 metro hasta el aula que esta a 3
    metros de la entrada.
 22 Bessie entrega su tarea.
 22 Bessie sale, ya que esta es tambien la localizacion de la salida
    del omnibus.

Asi,  Bessie  puede  salir  en  el  tiempo  22.  No  existe  un  mejor
itinerario.
}
