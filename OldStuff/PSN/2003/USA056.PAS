{koder: A^2P}{6 - 5 - 2007}
{PSN 2003 #56 "Codo"}
{ Easy, but sexy }
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 150;
var
  fin,fout        : text;
  A,B             : string;
  i,j             : longint;
  st              : array[1..MaxN * 2] of char;
  d               : array[-1..MaxN,-1..MaxN] of byte;

    procedure print(i,j: longint);
    begin
      if d[i,j] = 3 then exit;
      if d[i,j] = 1
        then print(i - 1,j)
        else print(i,j - 1);
      write(fout,d[i,j]);
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,A); readln(fin,B);
  readln(fin,st);

  {solve}
  d[0,0] := 3;
  for i:=0 to length(A) do
    for j:=0 to length(b) do
    begin
      if (d[i - 1,j] <> 0) and (st[i + j] = A[i]) then d[i,j] := 1;
      if (d[i,j - 1] <> 0) and (st[i + j] = B[j]) then d[i,j] := 2;
    end;{for}

  {dprint}
  print(length(A),length(B));

  {fclose}
  close(fin); close(fout);
end.{main}

{
56ş Codo.                                                     USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko y Slavko est n jugando un juego muy interesante.
Cada  uno de ellos imagina una palabra, entonces ellos se sientan a la
misma  computadora  y peg ndose el uno al otro con el codo teclean sus
palabras en el teclado.
Despu‚s de eso, ellos miran a la pantalla y ellos ven que sus palabras
est n  tan  mezcladas  que  ellos  no  pueden  encontrar cuales letras
pertenecen a uno y cuales al otro.

Tarea

Escriba  un programa que decidir  para cada letra en la pantalla si le
pertenece a la palabra de Mirko o la palabra de Slavko.
Nota: la soluci¢n no tiene que ser £nica.

Entrada

En  la  primera  y segunda l¡nea del archivo de entrada ELBOW.IN est n
las  palabras    de  Mirko  y de Slavko. Cada palabra contiene s¢lo de
letras  min£sculas  del  alfabeto  ingl‚s (a-z), y el n£mero de letras
de  cada  palabra  ser   menor  o  igual  que  150. En la tercera fila
est n  las  palabras  en  la  pantalla. Habr  siempre soluci¢n para el
juego de datos de entrada.

Salida

En la primera y £nica l¡nea del archivo de salida ELBOW.OUT usted debe
para  cada  letra  de  la  tercera palabra escribir el n£mero '1' o el
n£mero  '2', de esta manera si nosotros ley‚ramos letras de la tercera
palabra  en    las    posiciones  denotadas por el n£mero '1' nosotros
obtenemos  la  primera   palabra, y si nosotros ley‚ramos letras de la
tercera  palabra  en    las    posiciones  denotadas por el n£mero '2'
nosotros obtenemos la segunda palabra.


Ejemplos de Entrada y Salida:

  Ejemplo  #  1                 Ejemplo # 2          Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄ¿
³ELBOW.IN   ³³ELBOW.OUT  ³ ³ELBOW.IN³³ELBOW.OUT³ ³ELBOW.IN³³ELBOW.OUT³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄ´
³novine     ³³11222111122³ ³tata    ³³21112212 ³ ³hsin    ³³12222111 ³
³vesna      ³ÀÄÄÄÄÄÄÄÄÄÄÄÙ ³mama    ³ÀÄÄÄÄÄÄÄÄÄÙ ³sinh    ³ÀÄÄÄÄÄÄÄÄÄÙ
³novesvinena³              ³mtatamaa³            ³hsinhsin³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ              ÀÄÄÄÄÄÄÄÄÙ            ÀÄÄÄÄÄÄÄÄÙ
}
