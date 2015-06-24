{koder: A^2P}
{PSN 2002 #28 "Diga Cheese"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 102;
  oo = 1 shl 30;
var
  fin,fout        : text;
  N,i,j,k         : word;
  d,x,y,z,r       : array[0..MaxN] of real;
  mark            : array[1..MaxN] of boolean;
  c               : array[0..MaxN,0..MaxN] of real;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=2 to N+1 do
    readln(fin,x[i],y[i],z[i],r[i]);
  readln(fin,x[1],y[1],z[1]);
  readln(fin,x[N+2],y[N+2],z[N+2]);

  {solve}
  for i:=1 to N+1 do
    for j:=i+1 to N+2 do
    begin
      c[i,j] := sqrt(sqr(x[j] - x[i])
      + sqr(y[j] - y[i]) + sqr(z[j] - z[i])) - r[i] - r[j];
      if c[i,j] < 0 then c[i,j] := 0;
      c[j,i] := c[i,j];
    end;{for}

  {dijkstra}
  d := c[1];  //for i:=1 to N+2 do d[i] := c[1,i];
  d[0] := oo;
  for i:=1 to N+1 do
  begin
    k := 0;
    for j:=2 to N+2 do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    for j:=2 to N+2 do
      if (not mark[j]) and (c[k,j] + d[k] < d[j])
        then d[j] := c[k,j] + d[k];
  end;{for}

  {dprint}
  write(fout,round(d[N+2] * 10));

  {fclose}
  close(fin); close(fout);
end.{main}

{
28ş Diga Cheese                                             Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Hab¡a  una  vez    un pedazo grande de queso, viv¡a en ‚l un  caro del
queso llamada Amelia Acaro del Queso. Amelia estaba realmente contenta
porque ella estaba rodeada por los m s deliciosos quesos que ella pudo
haber comido. Sin embargo, ella sent¡a que hab¡a algo que le faltaba a
su vida.

Una  ma¤ana,  meintras so¤aba con quesos fue interrumpida por un ruido
que  jam s  hab¡a oido. Pero ella inmediatamente se da cuenta que esto
era  el  sonido de un  caro de queso macho rullendo en el mismo pedazo
de  queso!  (determinando  el  g‚nero del  caro del queso justo por el
sonido  de esta rodeadura no es un m‚todo f cil, pero todos los  caros
de queso lo pueden hacer. Esto es porque sus padres lo hacen).

Nada  puede  detener  a  Amelia  ahora.  Ella ten¡a que conocer lo m s
pronto  posible  al   caro.  Por  lo tanto ella tiene que encontrar el
camino  m s  r pido  para  llegar  al  otro   caro. Amelia puede roer
complemante  un  1  mm de queso en diez segundos. Para reunirse con el
otro   caro por el camino directo puede no ser r pido. El queso en que
Amelia  vive  est   lleno  de  huecos.  Estos  huecos,  los cuales son
burbujas  de  aire  atrapados  en el queso son esf‚ricos para la mayor
parte.  Pero  ocasionalmente  estos  huecos  esf‚ricos  se superponen,
creando  huecos  compuestos de todos los tipos. Pasando a trav‚s de un
hueco  en  el queso Amelia toma un tiempo esencialmente cero, dado que
ella  puede  volar desde un extremo al otro inst ntaneamente. As¡ ella
puede  aprovechar  viajar a trav‚s de huecos para llegar al otro  caro
r pidamente.

Para    este  problema,  usted  escribir   un  programa  que  dado  la
localizaci¢n  de  ambos  caros y los huecos en el queso, determinar el
menor  tiempo  que  se  toma  Amelia para alcanzar al otro  caro. Para
resolver este problema, usted puede asumir que el queso tiene un largo
infinito.  Esto es porque el queso es tan largo como nunca permita que
Amelia  abandone  el  queso  al  alcanzar el otro  caro (especialmente
puesto  que  el   caro de queso comil¢n pueda comersela a ella). Usted
tambi‚n  puede  asumir que el otro  caro espera ansiosamente el arribo
de Amelia y no se mover  mientras que Amelia est  en el camino.

Entrada

La  entrada  es  mediante el fichero texto ACARO.IN con la descripci¢n
siguiente:

. La  primera  l¡nea contiene un  simple entero N (0 <= N <= 100) , el
  n£mero  de  huecos  en  el  queso.  En las siguientes N l¡neas hay 4
  enteros separados por un espacio en blanco cada uno Xi, Yi, Zi y Ri.
  Estos describen el centro (Xi, Yi, Zi) y el radio Ri (Ri > 0) de los
  huecos.  Todos  los  valores  est n  expresados  en  mil¡metros.  La
  descripci¢n concluye con dos l¡neas conteniendo 3 enteros cada una.
  La  primera  l¡nea  contiene los valores Xa, Ya y Za; la posici¢m de
  Amelia  en  el queso, la segunda l¡nea contiene los valores Xb, Yb y
  Zb las posiciones del otro  caro.

Salida

La  salida  es hacia el fichero texto ACARO.OUT con una sola l¡nea con
un  solo  valor  entero que representa el menor tiempo en segundos que
toma Amelia en llegar al otro  caro, redondeado al entero cercano.

Ejemplos de Entrada y Salida:

  Ejemplo #1                      Ejemplo  #2
 ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿    ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ ACARO.IN   ³ ³ ACARO.OUT ³    ³ ACARO.IN ³ ³ ACARO.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´    ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 1          ³ ³ 100       ³    ³ 1        ³ ³ 20        ³
 ³ 20 20 20 1 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ    ³ 5 0 0 4  ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 0 0 0      ³                  ³ 0 0 0    ³
 ³ 0 0 10     ³                  ³ 10 0 0   ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ                  ÀÄÄÄÄÄÄÄÄÄÄÙ
}