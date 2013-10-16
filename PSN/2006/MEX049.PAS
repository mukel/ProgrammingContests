{koder: A^2P}
{PSN 2006 #49 "Las Torres Gemelas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j         : word;
  b               : boolean;
  s1,s2           : array[1..MaxN] of word;
  c               : array[boolean,0..MaxN] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do read(fin,s1[i]);
  for i:=1 to M do read(fin,s2[i]);

  {solve}{lcs}
  for i:=1 to N do
  begin
    b := not b;
    for j:=1 to M do
      if s1[i] = s2[j] then c[b,j] := c[not b,j-1] + 1
        else if c[not b,j] >= c[b,j-1] then c[b,j] := c[not b,j]
               else c[b,j] := c[b,j-1];
  end;{for}

  {dprint}
  writeln(fout,c[b,M]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
49ş Las Torres Gemelas.                                    M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Habia una vez, en un antiguo Imperio, dos  torres de formas  similares
en dos ciudades diferentes.  Las torres estaban construidas  por losas
circulares puestas unas sobre las otras. Cada una de las losas era  de
la  misma  altura  y  tenian  radio  completo.  Sin  embargo,  no   es
sorprendente  que  las dos  torres  fueran de  forma  diferente, ellas
ten¡an muchas losas en comun.

Sin embargo,  mas de  mil a¤os  despu‚s que ellas  fueron construidas,
el Emperador orden¢  a sus arquitectos  eliminar algunas de  las losas
de las dos torres tal que ellas tengan la misma forma y tama¤o,  y  al
mismo tiempo  permanezcan  tal altas  como  sea posible.  El  orden de
las losas en la nueva torre tiene que ser el mismo que ellas tenian en
la torre  original. El  emperador pens¢  que, de  esta manera  las dos
torres ser¡an el simbolo de armonia e igualdad entre las dos ciudades.
El decidi¢ nombrarlas a ellas las Torres Gemelas

Ahora, alrededor  de dos  mil a¤os  despu‚s, a usted  se le  reta  con
un  simple  problema  de aplanamiento:  dada  la  descripci¢n  de  dos
torres diferentes a usted se  le pide  solamente  encontrar el  n£mero
de   losas  en  la  m s  alta  de  las torres  gemelas  que  puede ser
construida desde ellas.

Entrada

El  fichero  de entrada  TOWER.IN  contiene en  la  primera l¡nea  dos
enteros N1  y  N2  (1  <=   N1, N2  <=  1000)  indicando el  numero de
losas  respectivamente   en   las   dos   torres.  La   segunda  linea
contiene   N1 enteros  positivos  los  que  representan   el  radio de
las losas  (de arriba hacia  debajo) en  la primera  torre. La tercera
linea  contiene  N2  enteros positivos   los   que    representan   el
radio de las  losas (de arriba hacia  debajo) en   la segunda torre.

Salida

El fichero de entrada TOWER.OUT el n£mero de losas en la torre (en una
torre) en la posible torre gemela m s alta que puede ser construida
de ella.

Ejemplo de Entrada y de Salida

Ejemplo # 1

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ TOWER.IN             ³ ³ TOWER.OUT  ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 7 6                  ³ ³ 4          ³
³ 20 15 10 15 25 20 15 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 15 25 10 20 15 20    ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Ejemplo # 2

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ TOWER.IN                   ³ ³ TOWER.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 8 9                        ³ ³ 6         ³
³ 10 20 20 10 20 10 20 10    ³ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 20 10 20 10 10 20 10 10 20 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}