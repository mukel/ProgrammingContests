{koder: A^2P}
{PSN 2001 #70 "Comprando Frutas"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50;
  MaxM = 1000;
var
  fin,fout        : text;
  N,i,j           : word;
  f               : array[1..MaxN] of word;
  last            : array[1..MaxM] of byte;
  mark            : array[0..MaxM] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,f[i]);

  {solve}
  mark[0] := true;
  for i:=1 to N do
    for j:=MaxM downto f[i] do
      if (not mark[j]) and (mark[j - f[i]]) then
      begin
        mark[j] := true; last[j] := i;
      end;{then}

  {dprint}
  i := MaxM;
  if mark[MaxM] then
    repeat
      writeln(fout,f[last[i]]);
      dec(i,f[last[i]]);
    until i = 0
  else write(fout,'NO');

  {fclose}
  close(fin); close(fout);
end.{main}

{
70ş Comprando Frutas.                                   Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un eminente profesor de matem ticas ten¡a la siguiente costumbre:
cuando  iba  de compras (comprando frutas, por ejemplo naranjas), a ‚l
le  gustaba  comprar exactamente 1 kg si esto fuera posible. Un alumno
suyo  decidi¢  hacer  lo  mismo.  El  profesor  pod¡a  hacer todos los
c lculos  necesarios  en  la  mente, pero el estudiante debe llevar su
computadora.

Cuando el estudiante va a comprar, ‚l puede pesar todas las frutas.
Crear  un programa en el cual el estudiante debe introducir el peso de
las  frutas pesadas en gramos. El programa debe terminar si es posible
que  el  estudiante compre 1 kg exacto de frutas y si puede determinar
una  combinaci¢n  de  los  pesos  de  las  frutas,  que  cumpla con la
condici¢n.

Entrada

En  la  primera  fila del archivo de entrada FRUITS.IN est  escrito el
n£mero N de frutas, donde 1 <= N <= 50. En las siguientes N filas est 
escrito  un  n£mero entero (el peso de cada fruta), cada uno entre 1 y
1000.

Salida

Se escribir  en el archivo de salida FRUITS.OUT:
La  cadena  "No",  si  es  imposible comprar exactamente 1 kg. En caso
contrario  escriba  los pesos de la combinaci£n determinada (cuya suma
es igual a 1000), escribiendo un n£mero por fila.

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ FRUITS.IN ³ ³ FRUITS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5         ³ ³ 500        ³
³ 200       ³ ³ 200        ³
³ 300       ³ ³ 300        ³
³ 200       ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 400       ³
³ 500       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}