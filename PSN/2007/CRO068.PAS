{koder: A^2P}{4 - 4 - 2007}
{PSN 2007 #68 "Pa¡ses"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  inf             : double;
  N,i,j           : longint;
  X,Y,S,sol       : array[0..MaxN] of longint;

    function influence(i,j: longint): double;
    begin
      influence := S[i] / (sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));
    end;{influence}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,X[i],Y[i],S[i]);

  {solve}
  for i:=1 to N do
  begin
    inf := -1;
    for j:=1 to N do
      if (S[j] > S[i]) and
         (influence(j,i) >= inf) and (influence(j,i) > S[i]) then
      begin
        if influence(j,i) = inf then sol[i] := -1 else sol[i] := j;
        inf := influence(j,i);
      end;{for}
  end;{for}

  {dprint}
  for i:=1 to N do
  begin
    while sol[sol[i]] > 0 do sol[i] := sol[sol[i]];
    case sol[i] of
     -1 :  writeln(fout,'D');
      0 :  writeln(fout,'K');
      else writeln(fout,sol[i]);
    end;{case}
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
68ş Pa¡ses.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El   problema    considera   como    muchos   pa¡ses    poderosos   se
levantan humildemente desde  el principio.  Considere un  mapa de  dos
dimensiones. En este  mapa existen n  ciudades. Cada ciudad  i est  en
una localizaci¢n distinta con  coordenadas (xi,  yi) en   el mapa.  La
ciudad tienen  tambi‚n un  n£mero  Si   de soldados  bajo el  mando de
un general.

La influencia que ejerce la ciudad i hacia otra localizaci¢n (x,y)  es
calculada como la division de Si por  la distancia al cuadrado   entre
ella  y (x,y).  Esto  es   como si   los soldados   en la   ciudad   i
ejercen  una atracci¢n gravitacional  en todas las localizaciones  del
mapa alrededor de esta. La  ciudad i es  amenazada por otra  ciudad  j
si  la  influencia ejercida  por  ciudad  j  en  la  localizaci¢n (xi,
yi) de  la ciudad   i excede el n£mero   de soldados Si:  entonces  la
ciudad  j puede enviar suficientes  soldados para vencer  a todos  los
soldados   que  defienden la   ciudad   i. Si   la  ciudad  i  no   es
amenazada  por alguna otra ciudad  j,  entonces  estos  ciudadanos
le  agradecen  a  su  elegido invencible general como su Rey, y  ponen
la ciudad como la capital de  su reino.

Por otra parte, si  alguna  ciudad j  amenaza  a la   ciudad  i ejerce
estrictamente   mas  influencia  en  esta  localizaci¢n  (xi,  yi) que
cualquier otra  ciudad k,  entonces los  ciudadanos de  la ciudad i no
tienen elecci¢n:  la ciudad  i tiene  que rendirse  a la  ciudad j. De
ahora en adelante la  ciudad i  debe obedecer a la misma capital  como
la  ciudad j la obedec¡a; sin  embargo, los Si soldados  en la  ciudad
i  no deben  unirse al ej‚rcito  de la ciudad  j  o de  la capital. De
otra manera  la ciudad  i  es  salvada  por  una  desconfianza   mutua
de   igualmente amenazadas  por las ciudades  j y k:  Si una de  ellas
ataca y  vence a   la ciudad  i, entonces  las otras  pueden  en turno
atacar y vencer los  que est n  cansados en la batalla a los  primeros
que atacaron.  Sin embargo,  los ciudadanos  de la  ciudad i no pueden
luego elegir a su general como  su rey,  porque ‚l  le ha   fallado en
su deber  de mantener la ciudad segura  de  amenazas. De  esta  manera
ellos  pueden  poner  esta  ciudad  dentro  de  la  capital  como  una
democracia.

Tu tarea es  escribir un programa  el cual tome la  informaci¢n acerca
de las ciudades en el mapa como entrada, y escriba para cada ciudad  i
una de los tres resultados:

- si es la capital de un reino.
- si es la capital de una  democracia.
- si la  ciudad j se conserva como la capital.

Entrada

La entrada  es a  trav‚s del  fichero texto  COUNTRIES.IN. La  primera
l¡nea consiste de un entero 1 <= n <= 1000, el n£mero de ciudades.  En
las  n siguientes l¡neas se dan informaci¢n  de las  n ciudades,  Cada
ciudad  en   su propia   l¡nea.  La  l¡nea  i+1   se  da la  siguiente
informaci¢n  de la ciudad i con  tres enteros xi, yi,  Si  los  cuales
est n  separados por un  simple caracter espacio. Todos  estos n£meros
est n el en  rango 0 <= xi, yi, Si <= 1000.

Salida

La  salida ser  hacia el  fichero texto COUNTRIES.OUT. Consiste  de  n
l¡neas, donde  la l¡nea  i consiste  del siguiente  resultado para  la
ciudad i:

- El caracter K si la ciudad i es la capital de un reino.
- El caracter D si la ciudad i es la capital de una  democracia.
- El n£mero 1 <= j <= n de la ciudad la cual la ciudad i cumple
  como una capital si la ciudad i tuvo que rendirse.

EJEMPLO

Considere el siguiente mapa, donde cada punto representa una ciudad y
los n£mero de soldados es mencionado arriba:

                        14
           5 ÄÄÅÄÄÄÅÄÄÄşÄÄÄÅÄÄÄÅÄÄÄÅÄÄ
               ³   ³   ³   ³   ³   ³
           4 ÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄ
               ³   ³   ³2  ³   ³   ³
           3 ÄÄÅÄÄÄÅÄÄÄşÄÄÄÅÄÄÄÅÄÄÄÅÄÄ
               ³   ³   ³   ³7  ³   ³
           2 ÄÄÅÄÄÄÅÄÄÄÅÄÄÄşÄÄÄÅÄÄÄÅÄÄ
               ³   ³2  ³ 3 ³   ³   ³
           1 ÄÄÅÄÄÄşÄÄÄşÄÄÄÅÄÄÄÅÄÄÄÅÄÄ
               ³   ³   ³   ³   ³   ³
           0 ÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄÄÅÄÄ
               0   1   2   3   4   5

Asumiendo  que estas 5 ciudades son  numeradas de abajo hacia arriba y
de izquierda a derecha, entonces los correspondientes ficheros de
Entrada y Salida  son los siguientes:

COUNTRIES.IN       COUNTRIES.OUT

5                  K
2 5 14             D
2 3 2              K
3 2 7              3
1 1 2              3
2 1 3

Es decir, la  ciudad 3 en  la localizaci¢n (3,2)  es la capital  de un
reino, la  cual tambi‚n  contiene las   ciudades 4  en la localizaci¢n
(1,1) y la 5 en la localizaci¢n (2,1). En el otro paso, la ciudad 1 en
la  localizaci¢n (2,5) forma todo un reino por as¡ misma, mientras  la
ciudad 2 en la  localizaci¢n (2,3) forma toda una democracia por  ella
misma.
}
