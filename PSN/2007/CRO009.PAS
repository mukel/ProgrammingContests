{koder: A^2P}{...}
{PSN 2007 #9 "Secuencias Musicales"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,M,T,i,j       : longint;
  seq,pat,sol     : array[0..MaxN] of integer;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M,T);
  for i:=1 to N do read(fin,seq[i]);
  for i:=1 to M do read(fin,pat[i]);

  {solve}
  for i:=1 to N - M + 1 do
  begin
    for j:=1 to M do
      if abs(pat[j] - seq[j+i-1]) > T then break;
    if abs(pat[j] - seq[j+i-1]) <= T then
    begin
      inc(sol[0]); sol[sol[0]] := i;
    end;{then}
  end;{for}

  {dprint}
  for i:=0 to sol[0] do
    writeln(fout,sol[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
9ş Secuencias Musicales.                                  Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las  secuencias  musicales  pueden  ser  vistas  esquem ticamente como
secuencias de  n£meros enteros,  representando las  notas en  notaci¢n
crom tica o diat¢nica (codificaci¢n absoluta del tono, CAT)

Por ejemplo, la figura muestra una representaci¢n del acorde   C-menor
en codificaci¢n absoluta del tono

Note  que  de esta  forma  puede representarse  una  secuencia musical
usando un alfabeto cuyos s¡mbolos son n£meros enteros.

En  ocasiones  se  necesita buscar  una  ocurrencia  similar, pero  no
necesariamente id‚ntica, de una peque¤a melod¡a dada en una  secuencia
musical.

Dos   melod¡as    de  la   misma   longitud  concuerdan   si   en  sus
correspondientes representaciones   cada  uno  de los  n£meros (tonos)
difiere cuando m s en un valor l¡mite d, previamente definido.

Por ejemplo, dada la secuencia musical:
34, 61, 64, 59, 64, 66, 71, 73, 10, 94

Si se fija un valor de tolerancia  d = 1 entonces la melod¡a (60,  63,
67, 72) concuerda con la melod¡a (59, 64, 66, 71) que aparece a partir
del 4to  tono de la secuencia original.

El problema consiste en que dada una secuencia musical, una melod¡a, y
un  valor  de  tolerancia  d,  determinar  todas  las  melod¡as  en la
secuencia musical que concuerdan con la melod¡a dada seg£n el valor de
tolerancia d

Tarea

Hacer un programa que permita:

-	Leer desde fichero de  entrada MUSICA.IN una secuencia musical,  una
  melod¡a, y un valor de tolerancia d.
- Determinar todas las melod¡as en la secuencia musical que concuerdan
  con la melod¡a dada seg£n el valor de tolerancia d.
-	Escribir hacia el fichero de salida MUSICA.OUT todos los tonos donde
  comienza la melod¡a encontrada en la secuencia musical.

Entrada

El  fichero de  entrada MUSICA.IN  contiene:

L¡nea  1: N   (1 <=  N  <= 10000), M  (1 <= M  <= 100) y  d (1 <= d <=
1000)  separados  entre si   por  un espacio  en  blanco, los   cuales
representan la cantidad de  tonos de la secuencia musical, la cantidad
de tonos de la melod¡a a buscar y el valor de tolerancia d.
L¡nea 2: aparecen los N valores enteros positivos entre 0 y 10000  los
cuales representan a los tonos de la secuencia musical.
Linea 3: aparecen los M valores enteros positivos entre 0 y 10000  los
cuales representan a los tonos de la melod¡a a buscar.

Salida

El fichero de salida MUSICA.OUT contiene:
L¡nea 1: V cantidad de veces que apareci¢ la melod¡a en la secuencia.
L¡nea 2..V+1: en cada l¡nea aparecer  un entero que representa cada una
 de las posiciones de los tonos en la secuencia musical original donde
 comienza a concordar la melod¡a.

Ejemplo de Entrada y Salida

Musica.in                                 Musica.out

10 4 1                                    1
34 61 64 59 64 66 71 73 10 94             4
59 64 66 71

Musica.in                                 Musica.out

8 3 2                                     2
2 8 3 1 1 2 6 5                           3
1 3 1                                     4
}