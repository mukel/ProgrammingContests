{koder: A^2P}
{PSN 2005 #20 "Contabilidad de Comida"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxD = 2000;
var
  fin,fout        : text;
  N,F,E,M,h,i,j,k : word;
  c               : array[0..MaxD] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,F,E,M);
  for i:=1 to N do
  begin
    readln(fin,j,k);
    if M < k then k := M;
    for h:=j to k do inc(c[h]);
  end;{for}

  {solve}
  j := 0;
  for i:=M downto 0 do
    if j = F - E then break
      else inc(j,c[i]);

  {dprint}
  write(fout,i+1);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
20þ Contabilidad de Comida                                Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero  Juan est   tratando de  averiguar cuando  lleg¢ su £ltimo
cargamento de comida. Comenzando con  un dep¢sito vac¡o de comida,  ‚l
orden¢  y recibi¢  F1 (1  <= F1  <= 1,000,000)  kilogramos de  comida.
Desafortunadamente,  ‚l  no  est  seguro  de  cuando  lleg¢ la  comida
exactamente. De los F1  kilogramos, F2 (1 <=  F2 <= F1) kilogramos  de
comida permanecen en el d¡a D (1 <= D <= 2,000). El debe determinar el
d¡a m s reciente en que su cargamento podr¡a haber llegado.

Cada una de sus C (1 <=  C <= 100) vacas come exactamente 1  kilogramo
de comida cada d¡a. Por diferentes razones, las vacas llegan un d¡a  y
se  van  en otro,  por  lo tanto  los  d¡as podr¡an  tener  diferentes
consumos de comida. Los datos de  entrada dicen en que d¡as cada  vaca
estaba presente. Cada vaca comi¢ comida del dep¢sito del Granjero Juan
el d¡a en que ella lleg¢ y tambi‚n el d¡a en que ella se fue.

Dado que hoy es el d¡a D, determine el m¡nimo n£mero de d¡as que deben
de haber pasado  desde su £ltimo  cargamento. Las vacas  ya han comido
hoy, y el cargamento lleg¢ antes de que las vacas comenzaran a comer.

NOMBRE DEL PROBLEMA: fcount

FORMATO DE ENTRADA:

- L¡nea 1: Cuatro enteros seprados por espacios: C, F1, F2 y D.
- L¡neas 2..C+1: La l¡nea i+1 contiene dos enteros separados por
  espacio describiendo la presencia de una vaca. El primer entero dice
  el primer d¡a en que la vaca estuvo en la granja; el segundo dice el
  d¡a final de su presencia. Cada d¡a est  en el rango 0..2,000.

ENTRADA EJEMPLO (archivo fcount.in):

3 14 4 10
1 9
5 8
8 12

DETALLES DE LA ENTRADA:

El  cargamento m s  reciente fue  de 14  kilogramos de  comida, y  el
Granjero Juan  tiene 4  kilogramos sobrantes.  El tuvo  tres vacas que
comieron comida por alguna cantidad  de tiempo durante los £ltimos  10
d¡as.

FORMATO DE SALIDA:

El £ltimo d¡a en que el cargamento podr¡a haber llegado, un entero que
ser  siempre positivo.

SALIDA EJEMPLO (archivo fcount.out):

6

DETALLES DE LA SALIDA:

Si el Granjero Juan comenz¢ con 14 kg de comida en el d¡a 6,  entonces
en los d¡as 6 y 7, se  hubieran comido dos kilogramos cada d¡a. En  el
d¡a 8, se hubieran  comido tres kilogramos. En  el d¡a 9, se  hubieran
comido dos kilogramos. En el  d¡a 10, se hubiera comido  un kilogramo.
Por lo tanto, el  total comido hubiera sido  2 + 2 +  3 + 2 +  1 = 10,
dej ndo lo con 4 kilogramos
}
