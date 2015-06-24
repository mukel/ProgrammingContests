{koder: A^2P}{9 - 5 - 2007}
{PSN 2005 #76 "Caminar charlando"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  filedata = 'dict.txt';
  MaxN = 30;
var
  fin,fout,dic    : text;
  st              : string;
  N,M,i,j,k,sol   : longint;
  len             : byte absolute st;
  mat             : array[0..MaxN,0..MaxN] of char;
  C               : array[0..4,0..MaxN,0..MaxN] of longint;

begin
  {fload}
  assign(dic,filedata); reset(dic);
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=N downto 1 do
  begin
    for j:=1 to M do read(fin,mat[i,j]);
    readln(fin);
  end;{for}

  {init}
  for i:=0 to N do
    for j:=0 to M do C[0,i,j] := 1;

  {solve}
  repeat
    readln(dic,st);
    for i:=1 to len do
      for j:=1 to N do
        for k:=1 to M do
        begin
          C[i,j,k] := C[i,j - 1,k] + C[i,j,k - 1] - C[i,j - 1,k - 1];
          if st[i] = mat[j,k] then
            C[i,j,k] := C[i,j,k] +
              C[i - 1,j - 1,k] + C[i - 1,j,k - 1] - C[i - 1,j - 1,k - 1];
        end;{for}
    inc(sol,C[len,N,M]);
  until seekeof(dic);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(dic); close(fout);
end.{main}

{
76ş Caminar charlando.                                    Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El campesino John le ha puesto un puzzle a sus vacas para  resolverlo.
En  una   entrada  al  granero, el tiene colocado una grilla de WxH
(1 <= W <=  30,  1 <=  H  <= 30)  letras.  Cuando una vaca  entra   al
granero, ella tiene que deletrear una  palabra  en  ingl‚s  movi‚ndose
entre  las casillas. Ella  puede  comenzar  en cualquier letra y puede
solamente moverse a la derecha y/o arriva en la grilla para obtener la
pr¢xima letra. La pr¢xima   letra podr¡a  estar  a   alguna  distancia
de la actual: las vacas son saltadoras de clase mundial!. Dos vacas no
pueden tomar  el mismo  camino, aunque  dos vacas  pueden deletrear la
misma palabra.

Como un ejemplo, considere esta  grilla (presumiendo `TO' y  `OX'  son
palabras):

  T X X O
  T X Q T
  X T X Q

Cuatro  caminos  son  validos,  todos  deletreando  'TO'  (un deletreo
requiere una 'T' de la fila de abajo y una 'O' de la fila de  arriba).
`OX',  mientras  una  palabra  v lida, requerir¡a  ir  debajo  o  a la
izquierda en la grilla.

Dada la grila y  una lista de palabras  v lidas, calcule el n£mero  de
vacas que pueden entrar  en el granero sin  que alguna vaca repita  un
camino. El fichero ïdict.txtï  contiene la lista de  palabras v lidas,
una por l¡nea.

Entrada

El fichero de entrada TWALK.IN contiene
- L¡nea 1: dos enteros: H y W.
- Pr¢ximas  H l¡neas:  cada linea contiene W caracteres, sin espacios,
  dando una fila en la grilla. La primra fila es la fila del tope.  El
  primer  caracter  en  cada   fila  es  el  caracter  de  m s  a   la
  izquierda.

Salida

El fichero de salida TWALK.OUT contiene en la primera y £nica l¡nea el
n£mero de vacas que pueden entrar al granero sin repetir un camino.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ TWALK.IN ³ ³ TWALK.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 3 4      ³ ³ 4         ³
³ TXXO     ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ TXQT     ³
³ XTXQ     ³
ÀÄÄÄÄÄÄÄÄÄÄÙ
}
