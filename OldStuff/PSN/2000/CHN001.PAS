{koder: A^2P}
{PSN 2000 #1 "FLOWER" }
program flower;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   F,V,i,k      : byte;
   a            : array[1..100,1..100] of byte;
   m            : array[1..100,1..100] of integer;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,F,V);
     for i:=1 to F do
         for k:=1 to V do
             read(fin,m[i,k]);

     {solve}
     a[1,1] := 1;
     for i:=2 to V - F + 1 do
         if m[1,i-1] > m[1,i] then
         begin
            m[1,i] := m[1,i-1];
            a[1,i] := a[1,i-1];
         end{then}
         else a[1,i] := i;

     for i:=2 to F do
         for k:=i to V - F + i do
             if m[i-1,k-1] + m[i,k] > m[i,k-1] then
             begin
                  a[i,k] := k;
                  m[i,k] := m[i-1,k-1] + m[i,k];
             end{then}
             else
             begin
                  a[i,k] := a[i,k-1];
                  m[i,k] := m[i,k-1];
             end;{else}

     {dprint}
     k := a[F,V];
     writeln(fout,m[F,V]);
     for i:=F downto 1 do
     begin
          a[F,i] := k;
          k := a[i-1,k-1];
     end;{for}
     for i:=1 to F do write(fout,a[F,i],#32);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
 1ş Peque¤a Florer¡a                                        China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Usted  desea  arreglar  la  vidriera  de su florer¡a de manera tal que
quede lo m s est‚tico posible.

Usted  tiene  F  ramos  de  flores,  de cada uno de ellos de una clase
diferente de flores y al menos la misma cantidad de vasijas (floreros)
ordenados  en  una  fila.  Las  vasijas  est n fijadas en un estante y
numeradas  de izquierda a derecha en forma sucesiva de 1 a V, siendo V
la  cantidad  de  vasijas.  La  vasija  1 es la que est  en el extremo
izquierdo y la vasija V en la que est  en el extremo derecho.

Los  ramos  de flores se pueden colocar en cualquiera de las vasijas y
est n  identificados  por  los  n£meros  de  1  a  F. Estos n£meros de
identificaci¢n  tienen el siguiente sentido: Ellos determinan el orden
de  aparici¢n de los ramos de flores en las vasijas, o sea que el ramo
i  debe estar hacia la izquierda del ramo j siempre que i < j. Suponga
por ejemplo, que tenemos un ramo de azaleas identificado con el n£mero
1,  un  ramo  de  begonias  identificados con el n£mero 2 y un ramo de
claveles identificado con el n£mero 3. Ahora todos los ramos deben ser
puestos en las vasijas, pero conservando sus n£meros de identificaci¢n
en  orden.  El ramo de azaleas debe estar en una vasija a la izquierda
del  de las begonias, y el ramo de begonias debe estar en una vasija a
la  izquierda  de  la  de  los claveles. Si hay m s vasijas que ramos,
entonces  las  vasijas excedentes permanecer n vac¡as. Una vasija s¢lo
puede contener un ramo de flores.

Cada  vasija  tiene  diferentes  caracter¡sticas  (lo  mismo  que  las
flores).  Por lo tanto, poner un ramo de flores en una vasija tiene un
valor  de  est‚tica,  expresado  con  un entero. Los valores est‚ticos
est n  representados  en  una  tabla  como  se ilustra en el ejemplo a
continuaci¢n:


                ³      V A S I J A S      ³
                ³                         ³
                ³ 1    2    3    4     5  ³
   ÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
R  1 (azaleas)  ³ 7    23   -5   -24   16
a               ³
m  2 (begonias) ³ 5    21   -4   10    23
o               ³
s  3 (claveles) ³ -21  5    -4   -20   20


De acuerdo a esta tabla, las azaleas, por ejemplo, lucir¡an bien en la
vasija 2, pero se ver¡an feas en la vasija 4.

Dejando una vasija vac¡a tiene un valor est‚tico 0.

Para  conseguir  la distribuci¢n m s agradable usted debe maximizar la
suma  de  los valores est‚ticos utilizados en la misma, manteniendo el
orden  impuesto a los ramos. Si m s de una distribuci¢n tiene el valor
m ximo de la suma, cualquiera de ellas es aceptable. Su respuesta debe
contener solamente una de ellas.


Restricciones:

.  1 <= F <= 100, donde F es la cantidad de ramos de flores. Los ramos
                 est n numerados de 1 a F.

. F <= V <= 100, donde V es el n£mero de vasijas.

.  -50  <=  A(ij)  <=  50,  donde  A(ij) es el valor est‚tico obtenido
                 poniendo el ramo i en la vasija j.


Entrada

El archivo de entrada es un archivo de texto.

. La primera l¡nea contiene dos n£meros: F, V.
.  Las  siguientes  F  l¡neas:  Cada  una  de  estas l¡neas contiene V
  enteros, de tal manera que A(ij) est  dado como el j-‚simo n£mero de
  la (i+1)-‚sima l¡nea del archivo de entrada.

Salida

La salida debe ser hacia un archivo de texto conteniendo dos l¡neas:

.  La  primera  l¡nea  contiene la suma de los valores est‚ticos de su
  distribuci¢n.

.  La  segunda  l¡nea  contiene  la  distribuci¢n  como una lista de F
  n£meros,  de  tal  manera  que  el  k-‚simo  n£mero  de  esta  l¡nea
  identifica la vasija en la cual es puesto el ramo k.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo de Entrada³³Ejemplo de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3 5              ³³ 53              ³
³ 7 23 -5 -24 16   ³³ 2 4 5           ³
³ 5 21 -4 10 23    ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ -21 5 -4 -20 20  ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}