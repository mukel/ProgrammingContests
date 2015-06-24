{koder: A^2P}
{PSN 2005 #41 "Cadenas DNA"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,k,h,sol   : byte;
  s               : array[1..100] of string[50];

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,s[i]);

  {solve}
  for i:=1 to N do
    for j:=1 to N do if i <> j then
        for k:=1 to length(s[i]) - 1 do
          if pos(copy(s[i],k,length(s[i]) - k + 1),s[j]) = 1 then
          begin
            h := length(s[i]) - k + 1;
            if h > sol then sol := h;
            break;
          end;{then}

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
41ş Cadenas DNA.                                          Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  ha encontrado la  secuencia DNA de  su vaca premiada
como productora  de leche,  Bessie. Las  secuencias de  DNA son listas
ordenadas (cadenas) conteniendo uno o m s de las letras 'A', 'C', 'G',
y  'T'..

Como es usual para secuencias  DNA, los resultados son un  conjunto de
cadenas que son secuencias  de DNA. Un par  de cadenas como 'GATTA'  y
'TACA' muy  probablemente representan  la cadena  'GATTACA' donde  los
caracteres superpuestos  est n mezclados,  ya que  probablemente ellos
fueron  duplicados  en  el  proceso  de  secuenciaci¢n.  Generalmente,
mezclar un  par de cadenas involucra remover la parte superpuesta  m s
grande  entre las  dos cuando  ellas son  concatenadas. Note  que las
superposiciones son entre el final de una cadena y el comienzo de otra
cadena, no en la mitad de una cadena. La cadena 'GATTACA' superpone  a
'TTACA' completamente, mientras que  las cadenas 'GATTACA' y  'TTA' no
tienen ninguna superposici¢n.

Dado un  conjunto de  N (2  <= N  <= 100)  secuencias DNA, todas cuyas
longitudes est n en el rango 1..50, encuentre e imprima la longitud de
la superposici¢n m s grande entre cualquier par de cadenas.

NOMBRE DEL PROBLEMA: dna

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero N
- L¡neas 2..N+1: Cada l¡nea contiene una sola subsecuencia DNA

ENTRADA EJEMPLO (archivo dna.in):

4
CGCCAC
TGTCGC
GAATGA
GAGGCGA

DETALLES DE LA ENTRADA:

Cuatro cadenas; cada una de longitudes seis y siete.

FORMATO DE SALIDA:

- L¡nea 1: Una sola l¡nea que contiene la longitud de la superposici¢n
m s grande entre cualesquiera par de cadenas (en cualquier orden)

SALIDA EJEMPLO (archivo dna.out):

3

DETALLES DE LA SALIDA:

CGC comienza la primera cadena y termina la segunda:
   CGCCAC
TGTCGC
Por lo tanto la superposici¢n m s grande es 3
}