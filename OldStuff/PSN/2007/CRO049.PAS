{koder: A^2P}{31 - 3 - 2007}
{PSN 2007 # 49 "Tareas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  MaxM = 1000001;
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  work            : array[0..MaxM] of integer;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    readln(fin,j,k);
    inc(work[i]); dec(work[k + 1]);
  end;{for}

  {solve}
  sol := 1;
  for i:=2 to M do
  begin
    inc(work[i],work[i - 1]);
    if work[i] >{=} work[sol] then sol := i;
  end;{work}

  {dprint}
  writeln(fout,sol,' ',work[sol]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
49ş Tareas.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mario est  muy ocupado en su trabajo ,el SMA. Como ‚l es el £nico  que
trabaja en la computadora, simempre est  sobrecargado de tareas.

En la unidad Mario tiene N (1<=N<=10000) jefes. Cada jefe le da una  y
solo una  orden, es  decir el  recibir  N  tareas, estas  son dadas un
instante de M minutos, es decir que el recibir  tareas entre el minuto
1  y el  minuto M  (pueden existir  minutos el  los que  no tenga  que
trabajar).  Una   tarea  est    definida  por   dos  enteros   a  y  b
(1<=a<=b<=10^6),  donde  a  es  el   minuto  de  inicio  y  b   el  de
finalizaci¢n. Es decir Mario estar¡a realizando esa tarea entre a y b,
ambos inclusive.

Por suerte  Mario es  muy inteligente  y el  puede estar trabajando en
cualquier minuto en una infinita cantidad de tareas.

No obstante el est  muy cansado pues la noche anterior estuvo  jugando
StarCraft. Por eso el pidi¢  un descanso. Pero aqu¡ los  descansos son
muy cortos por lo que su descanso es de solo un minuto.

Ayude a Mario a saber cual es  el minuto donde el realice la mayor  de
tareas al mismo tiempo.

TAREA
 - Lea de la entrada la configuraci¢n de las tareas a realizar.
 - Calcule el minuto en el que se realizan la mayor cantidad de tareas.
 - Escriba el resultado en un fichero de salida.

ENTRADA

El  fichero de  entrada TAREAS.IN  contiene en  la primera  l¡nea  los
enteros N y M, qie representan la cantidad de jefes y el m ximo  valor
que  puede alcanzar  los minutos  respectivamente. En  las pr¢ximas  N
l¡neas  aparecen dos  enteros ai  y bi  describiendo cada  una de  las
tareas.

SALIDA

El  fichero de  salida TAREAS.OUT  contiene en  la primera  l¡nea  dos
enteros separados por un espacio que representan el minuto m s ocupado
y la cantidad de tareas que se realizan en este.

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ TAREAS.IN ³ ³ TAREAS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3 10      ³ ³ 5 3        ³
³ 1 5       ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 5 10      ³
³ 3 8       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}