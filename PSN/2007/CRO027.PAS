{koder: A^2P}{5 - 3 - 2007}
{PSN 2007 #27 "Kola"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxB = 100;
  MaxN = 1000;
  oo = 1 shl 7;
var
  fin,fout        : text;
  N,B,C,i,j,k     : longint;
  choice          : array[0..MaxN] of char;
  target,actual   : array[0..MaxB] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,B,C);
  for i:=1 to N do read(fin,choice[i]);
  for i:=1 to B do read(fin,target[i]);

  {solve}
  fillchar(actual,sizeof(actual),C);
  for i:=1 to N do
  begin
    k := 0;
    if choice[i] = 'S' then
    begin
      actual[k] := oo;
      for j:=1 to B do if actual[j] > 0 then
        if (actual[j] < actual[k]) or
           ((actual[j] = actual[k]) and (target[j] < target[k]))
           then k := j;
    end{then ->}
    else begin
      actual[k] := 0;
      for j:=1 to B do if actual[j] > 0 then
        if (actual[j] > actual[k]) or
           ((actual[j] = actual[k]) and (target[j] < target[k]))
           then k := j;
    end;{for}
    dec(actual[k]);
    write(fout,k,' ');
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

(*
27þ Kola.                                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En  un  cuarto  hay    M    botellas rellenas con una bebida sumamente
popular y de  buen gusto,  llamada Kola. Cada una de las botellas est 
marcada  por uno de los n£meros 1, 2, 3, ... M, y no hay ning£n par de
botellas marcadas con el mismo n£mero.

Una    cola  (muy  popular  en  nuestro  pa¡s)  consiste en N personas
sedientas  que forman en la puerta  de entrada al cuarto. Cada persona
tiene asignado un de n£mero 1,  2,  3, ...  N,  y de nuevo, ning£n par
de  ellas  tiene el mismo n£mero.  Todos ellos esperan para beber Kola
de una de las botellas en el cuarto. Uno por  uno, organizados por sus
n£meros  (la  persona  que  se le asign¢  el n£mero 1 es el primero en
entrar,  el  pr¢ximo  es  la  persona  que  se  le asign¢ el n£mero 2,
etc.),  entran en el cuarto, beben un decilitro  de Kola de una de las
botellas  en el cuarto y entonces se marchan. No m s de una persona se
permite  estar  en  el cuarto en cualquier momento. Hay dos  tipos  de
personas:    malgastadoras y  econ¢micas.  Las  personas malgastadoras
siempre  beben  de  una  de las botellas  m s  llenas.  Los econ¢micos
siempre    beben de una de las botellas  menos  llenas  (por supuesto,
las botellas vac¡as son ignoradas). Es conocido cu nta  Kola permanece
en  cada botella despu‚s de que la £ltima persona  dej¢  el cuarto.

Tarea

Usted    necesita escribir un programa que determine qu‚ persona bebi¢
de cada botella.

Entrada

La  primera l¡nea del fichero de entrada COLA.IN contiene tres enteros
N,  M  y K,  1  <=  N  <= 1000, 1 <= M <= 100, 1 <= K <= 20, el n£mero
de   las personas  en  la  cola, el n£mero de botellas en el cuarto  y
cu ntos  decilitros      de   Kola   estaban  inicialmente   en   cada
botella,  respectivamente. Se asignan a las personas los n£meros del 1
al    N  y las  botellas  se  marcan por n£meros del 1 al  M  como  se
describi¢  anteriormente.  La   segunda  l¡nea  del fichero de entrada
contiene   una  sucesi¢n  de caracteres  'R'  y  'S' de longitud N. El
car cter de  la  posici¢n  i describe a la persona i-esima: 'R' denota
a  la  persona  malgastadora   y 'S' denota a la persona econ¢mica. La
tercera (y £ltima l¡nea) del fichero de entrada contiene M enteros que
denotan    los    vol£menes (en decilitros) que  quedaron de  Kola  en
las    botellas  correspondientes:  el k-‚simo n£mero corresponde a la
botella    k-‚sima.  Los    n£meros  adyacentes  son  separados por un
espacio. Cada uno de esos M enteros son del conjunto {0, 1, 2... K}.

Salida

La    primera    y  £nica  l¡nea del fichero de  salida  COLA.OUT debe
contener   N enteros;  el i-esimo n£mero es el n£mero de botella de la
persona    i-  esima  que bebi¢ Kola. Dos n£meros adyacentes deben ser
separados  por un espacio.

Ejemplos de Entrada y Salida:

     Ejemplo  #  1         Ejemplo # 2             Ejemplo # 3
ÚÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³COLA.IN³³ COLA.OUT ³ ³COLA.IN³³ COLA.OUT ³ ³ COLA.IN   ³³ COLA.OUT  ³
ÃÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 3 3 ³³ 2 2 2 3  ³ ³ 4 3 3 ³³ 2 2 3 2  ³ ³ 5 5 2     ³³ 3 3 5 1 5 ³
³ SSSS  ³ÀÄÄÄÄÄÄÄÄÄÄÙ ³ SSRS  ³ÀÄÄÄÄÄÄÄÄÄÄÙ ³ SSRRS     ³ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 0 2 ³             ³ 3 0 2 ³             ³ 1 2 0 2 0 ³
ÀÄÄÄÄÄÄÄÙ             ÀÄÄÄÄÄÄÄÙ             ÀÄÄÄÄÄÄÄÄÄÄÄÙ

Nota:  Habr  siempre una soluci¢n, no necesariamente £nica, para todos
los juegos de datos de prueba.
*)