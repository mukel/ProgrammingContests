{koder: A^2P}{24 - 3 - 2007}
{PSN 2006 #91 "Dividiendo monedas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  MaxM = 50000;
var
  fin,fout        : text;
  D,N,M,i,j,k,sol : longint;
  v               : array[0..MaxN] of word;
  mark            : array[0..MaxM] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  readln(fin,D);
  mark[0] := true;
  for i:=1 to D do
  begin
    readln(fin,N); M := 0;
    for j:=1 to N do
    begin
      read(fin,v[j]); inc(M,v[j]);
    end;{for}
    for j:=1 to M do mark[j] := false;

    for j:=1 to N do
      for k:=M downto v[j] do
        if mark[k - v[j]] then mark[k] := true;

    for j:=M div 2 downto 0 do if mark[j] then break;
    for k:=M div 2 + 1 to M do if mark[k] then break;

    if M - 2 * j <= 2 * k - M
      then sol := M - 2 * j else sol := 2 * k - M;

    writeln(fout,sol);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
91þ Dividiendo monedas.                                    M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Es comunmente  conocido  que los holandeses  inventaron el alambre  de
cobre. Dos holandeses estaban peleando por una moneda de cobre.  Ambos
estaban  tan ansiosos  de obtenerla  y la  pelea fue  tan fuerte   que
estiraron demasiado la  moneda y asi  crearon el alambre  de cobre. Lo
que no es comunmente conocido es  que la pelea  comenz¢ luego  de  que
dos  holandeses trataron de dividir una bolsa con monedas entre  ellos
dos.  El  contenido  de  la  bolsa  parec¡a  no  ser   equitativamente
divisible.  Los  holandeses  del  pasado  no  pod¡an resistir el hecho
de que una divisi¢n favoreciera a uno de ellos y siempre buscaban  una
distribuci¢n justa  hasta el ultimo centavo. Hoy en d¡a no se ven  mas
peleas por un simple centavo, pero ser capaz de hacer una divisi¢n tan
justa como sea  posible es algo  que es siempre  importante. Acerca de
esto es  este  problema. No todos  son capaces de  ver al instante  la
m s justa divisi¢n de una bolsa de monedas entre dos persona.  Pedimos
tu ayuda para dar  soluci¢n a  este problema.  Dada una  bolsa con  un
m ximo de  100 monedas,   determina  la   divisi¢n  mas   justa  entre
dos  personas.  Esto  significa  que la   diferencia entre lo   que le
corresponde  a  cada  presona debe  ser minimizada.  El valor  de  una
moneda   var¡a de  1 a  500 centavos.  No se  puede picar  una  simple
moneda.

Entrada:

Una  l¡nea con el  n£mero  N  que es la cantidad de problemas. Seguido por n
veces :

- Una l¡nea con un entero  no negativo M (M <= 100)  indicando el n£mero de
  monedas en la bolsa.
- Una l¡nea con M n£meros separados por un espacio, cada n£mero indica el
  valor de una moneda.

Salida:

La  salida  consiste  de  M  l¡neas.  Cada  l¡nea  contiene  la m¡nima
diferencia positiva entre las cantidades de las dos personas obtenidas
cuando ellas dividen las monedas de la bolsa correspondiente.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿              ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³  COINS.IN ³              ³ COINS.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´              ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 2         ³              ³ 0         ³
³ 3         ³              ³ 1         ³
³ 2 3 5     ³              ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4         ³
³ 1 2 4 6   ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}