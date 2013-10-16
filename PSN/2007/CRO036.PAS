{koder: A^2P}{31 - 3 - 2007}
{
 IOI 2002 Day 1 Task 1
 PSN 2007 #36 "La Rana Problem tica"
}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 5000;
type
  point = record
    X,Y : integer;
  end;{point}
var
  fin,fout        : text;
  N,F,C,i,j,k,sol,
  X,Y,dx,dy,cant  : longint;
  list            : array[0..MaxN] of point;
  mark            : array[0..MaxN,0..MaxN] of boolean;

    function inbox(x,y: longint): boolean;
    begin
      inbox := ((x > 0) and (x <= F)) and
               ((y > 0) and (y <= C));
    end;{inbox}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,F,C);
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,list[i].X,list[i].Y);
    mark[list[i].X,list[i].Y] := true;
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=1 to N do
    begin
      X := list[j].X; Y := list[j].Y;
      dx := X - list[i].X; dy := Y - list[i].Y;
      if inbox(X - 2 * dx,Y - 2 * dy) then continue;
      cant := 1;
      repeat
        inc(cant);
        inc(X,dx); inc(Y,dy);
      until (not inbox(X,Y)) or (not mark[X,Y]);
      if (not inbox(X,Y)) and (cant > sol)
        then sol := cant;
    end;{for}

  {dprint}
  if sol < 3
    then writeln(fout,0)
    else writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
36þ La Rana Problem tica.                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En  Korea,  las  travesuras  de la chenggaeguri, una peque¤a rana, son
legendarias.  Ella tiene una bien merecida reputaci¢n, porque la  rana
salta  a  trav‚s  de  tu  campo  de  arroz en la noche, aplastando las
plantas  de  arroz.  En la ma¤ana, despu‚s de notar cuales plantas han
sido  aplastadas,  t£ quieres identificar el camino de la rana el cual
hizo el mayor da¤o. Una rana siempre salta a trav‚s del campo de arroz
en l¡nea recta, con cada salto de la misma longitud:

 (Ver Anexo 1)

Tu  campo  de  arroz  tiene  plantas  ubicadas  en      los  puntos de
intersecci¢n de una grilla como se muestra en la Figura - 1, y la rana
problem tica  salta  completamente  a  trav‚s  de  tu  campo de arroz,
comenzando  fuera del campo de arroz en  un lado de este y finalizando
fuera del campo en el otro lado como se muestra en la Figura - 2.

( Ver anexo 2 Figuras 1 y 2)

Muchas  ranas  pueden  saltar a trav‚s del campo de arroz, saltando de
planta  de  arroz  a    planta  de arroz. En cada salto se posa en una
planta  y  la aplasta, como en la Figura - 3. Note que algunas plantas
pueden   posadar m s de una rana durante la noche. Por supuesto, usted
no  puede  ver  las  l¡neas  mostrando  los  caminos  de  las  ranas o
cualquiera  de  sus  saltos  fuera  de  su  campo  de  arroz - para la
situaci¢n  en la Figura - 3, que tu puedes ver se muestra en la figura
- 4:

( Ver anexo 2 figuras 3 y 4)

De  la  figura  4, usted puede reconstruir todos los caminos posibles,
los cuales las ranas pueden haber seguido al cruzar tu campo de arroz.
Tu  solamente  estas interesado en las ranas  las cuales se han posado
en al menos 3 de tus plantas de arroz en su viaje a trav‚s de tu campo
de  arroz.  Uno  de  tales caminos es un camino de rana. En este caso,
significa  que los tres caminos mostrados en la Figura - 3 son caminos
de  rana  (hay  tambi‚n  otros  posibles  caminos  de rana). El camino
vertical  debajo  de  la columna 1 podr¡a haber sido un camino de rana
con salto de longitud 4 excepto hay solo 2 plantas de arroz aplastadas
por  lo  que  nosotros  no  estamos  interesados; y el camino diagonal
incluyendo  las  plantas  en la fila 2 col. 3, fila 3, col. 4 y fila 6
col.  7  tiene tres plantas  aplastadas pero no hay longitud de saltos
regular el cual pueda tener espaciados los saltos en esta v¡a mientras
todav¡a  se  est   posando en al menos 3 plantas, y por tanto no es un
camino  de  rana. Note tambi‚n que a lo largo de la l¡nea de un camino
que  la  rana  sigue puede haber plantas adicionales aplastadas en las
cuales  no  necesita  posarse la rana en ese camino, (ver la planta en
(2,  6)  en  el camino horizontal a trav‚s de la fila 2 en la Figura –
4); y en efecto algunas  plantas aplastadas no pueden ser justificadas
en alg£n camino de rana.

Tu  tarea  es  escribir  un programa para determinar la longitud de un
camino  de  rana  el  cual,  de  todos  los posibles caminos de  rana,
posadas  en la  mayor cantidad de plantas (causando el mayor da¤o a tu
cosecha  de  arroz). En la figura - 4 estar¡a el camino a trav‚s de la
fila 6, produciendo como respuesta el valor 7.

Entrada

Tu  programa  tiene  que  realizar la   lectura  desde  el  la entrada
standard. La primera l¡nea contiene dos enteros R y C, respectivamente
el n£mero de  filas  y  columnas  en tu campo de arroz,  1<=R,C<=5000.
La segunda l¡nea  contiene el entero N, el n£mero de plantas de  arroz
aplastadas, 3  <=  N  <=  5000.  Cada  una  de las restantes N  l¡neas
contiene dos enteros, el n£mero de la fila (1<=n£mero de fila<=R) y el
n£mero de  la columna.   (1<=  n£mero   de  columna   <=  C)   de  una
planta  de arroz aplastada,  separados  por un espacio en blanco. Cada
planta aplastada aparece solamente una vez.

Salida

Tu  programa  tiene  que  escribir hacia la salida standard. La salida
contiene  una  l¡nea  con  un  entero  simple,  el  n£mero  de plantas
aplastadas  a lo largo de un camino de rana la cual hizo el mayor da¤o
si  existe al menos un camino de la rana, de lo contrario, escribir un
0.

Ejemplo 1: (El ejemplo de la Figura - 4)

ÚÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄ¿
³ INPUT ³  ³ OUTPUT ³
ÃÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄ´
³ 6 7   ³  ³ 7      ³
³ 14    ³  ÀÄÄÄÄÄÄÄÄÙ
³ 2 1   ³
³ 6 6   ³
³ 4 2   ³
³ 2 5   ³
³ 2 6   ³
³ 2 7   ³
³ 3 4   ³
³ 6 1   ³
³ 6 2   ³
³ 2 3   ³
³ 6 3   ³
³ 6 4   ³
³ 6 5   ³
³ 6 7   ³
ÀÄÄÄÄÄÄÄÙ

Ejemplo 2: (el ejemplo de la Figura - 5)
ÚÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄ¿
³ INPUT ³  ³ OUTPUT ³
ÃÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄ´
³ 6 7   ³  ³ 4      ³
³ 18    ³  ÀÄÄÄÄÄÄÄÄÙ
³ 1 1   ³
³ 6 2   ³
³ 3 5   ³
³ 1 5   ³
³ 4 7   ³
³ 1 2   ³
³ 1 4   ³
³ 1 6   ³
³ 1 7   ³
³ 2 1   ³
³ 2 3   ³
³ 2 6   ³
³ 4 2   ³
³ 4 4   ³
³ 4 5   ³
³ 5 4   ³
³ 5 5   ³
³ 6 6   ³
ÀÄÄÄÄÄÄÄÙ
}
