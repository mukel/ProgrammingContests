{koder: A^2P}{23 - 3 - 2007}
{PSN 2007 #31 "Ataque de ratas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxSize = 1025;
var
  fin,fout        : text;
  N,D,X,Y,i,j,k,sol : longint;
  t,c             : array[-51..MaxSize,-51..MaxSize] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,D); readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,j,k);
    readln(fin,c[j,k]);
  end;{for}

  {solve}
  for i:=0 to MaxSize do
    for j:=0 to MaxSize do
      t[i,j] := t[i - 1,j] + t[i,j - 1] -
                t[i - 1,j - 1] + c[i,j];

  D := 2 * D + 1;
  for i:=D div 2 to MaxSize do
    for j:=D div 2 to MaxSize do
      if t[i,j] - t[i - D,j] - t[i,j - D] + t[i - D,j - D] > sol
      then begin
        sol := t[i,j] - t[i - D,j] - t[i,j - D] + t[i - D,j - D];

        if i - D div 2 > 0
          then X := i - D div 2
          else X := 0;

        if j - D div 2 > 0
          then Y := j - D div 2
          else Y := 0;

      end;{then}

  {dprint}
  writeln(fout,X,' ',Y,' ',sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
31ş Ataque de ratas.                                      Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Baaaam!!!! Otra bomba  de gas mortal  explota en las  alcantarillas de
Manhattan. Las ratas han tomado los  alcantarillados y el gobierno  de
la ciudad hace todo lo que  puede para mantener la poblaci¢n de  ratas
bajo control.

Como  sabes,  Manhattan  esta organizada de modo regular con calles  y
avenidas formando  una red rectangular. El agua  desechada  corre bajo
las calles en el mismo  arreglo y las ratas siempre instalan sus nidos
en las intersecciones de las   calles.  El £nico  m‚todo  viable  para
extinguirlas es usar  bombas de gas  como la que   acaba de  explotar.
Sin  embargo,  las  bombas  de  gas  no son  s¢lo peligrosas  para las
ratas. Los rascacielos sobre la explosi¢n tienen que ser evacuados  de
antemano y por eso se debe escoger el punto de ataque a las ratas  muy
cuidadosamente.

Las  bombas  de  gas  que  se usar n  son construidas por una compa¤¡a
llamada American   Catastrophe  Management  (ACM)  y   se venden  bajo
el t¡tulo de "gas inteligente  para  ratas",  son  inteligentes porque
cuando explotan el gas se  extiende  en  una  secci¢n rectangular  por
los  canales  del alcantarillado.  La fuerza   de una  bomba de gas es
dada por un n£mero d  que especifica  el "radio" rectangular  del  rea
de la difusi¢n  del gas. Por  ejemplo, la Figura  muestra lo que  pasa
cuando una bomba con d=1 explota.

Problema

El  rea de inter‚s  consta  de  un reticulado discreto  de   1025*1025
campos. Exploradores  del  grupo de  exterminio  de ratas han  dado un
detallado informe,  que  muestra   donde  las   poblaciones  de  ratas
de   tama¤os  diferentes   han construido   sus nidos.  Se te  da una
bomba de gas  con  fuerza d y tu   tarea es encontrarle  una  posici¢n
para la  explosi¢n, donde por efecto  de esta bomba de gas se  elimine
el n£mero m s grande de ratas.

La posici¢n mejor es determinada por los criterios siguientes:

- La  suma de  toda  poblaci¢n de ratas clasificada seg£n sus  tama¤os
dentro del  rea de  la explosi¢n de la  bomba de gas (dado  por d) sea
m xima.

- Si hay  m s de una  de estas  posiciones entonces la posici¢n con la
menor  coordenada   ser    escogida.   Se   ordenan  las   coordenadas
primero por su x y despu‚s por su y.

Dada una situaci¢n (x1, y1) en la reja, un punto (x2, y2) est   dentro
del  rea  de  difusi¢n   de una   bomba de  gas  con  fuerza  d  si la
ecuaci¢n siguiente es verdadera:

 max(abs(x2- x1),abs(y2- y1))<= d

Entrada

La  primera  l¡nea del fichero de entrada RATS.IN contiene la fuerza d
de la bomba de  gas  (1 <= d  <= 50).  La segunda   l¡nea contiene  el
n£mero  n (1  <= n  <=  20000)  de poblaciones de ratas. Entonces  por
cada poblaci¢n  de ratas  sigue   una   l¡nea   que    contiene   tres
enteros    separados   por  espacios  para  la posici¢n  (x, y)  y  el
"tama¤o" i de  la poblaci¢n  (1  <= i <=  255).  Se garantiza  que las
coordenadas son v lidas (i.e.,  en el rango entre 0 y 1024) y no se da
una misma posici¢n m s de una vez.

Salida

El fichero de salida RATS.OUT contiene una sola l¡nea la cual contiene
las coordenadas  X y  Y de  la  situaci¢n   escogida para    lanzar la
bomba   de gas,   seguida por   la  suma   de los   tama¤os  de    las
poblaciones  de   ratas  que  se extinguir n.  Los tres  n£meros deben
estar separados por un espacio.

>Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄ¿
 ³ RATS.IN ³  ³ RATS.OUT ³
 ÃÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄ´
 ³ 1       ³  ³ 5 5 30   ³
 ³ 2       ³  ÀÄÄÄÄÄÄÄÄÄÄÙ
 ³ 4 4 10  ³
 ³ 6 6 20  ³
 ÀÄÄÄÄÄÄÄÄÄÙ
}