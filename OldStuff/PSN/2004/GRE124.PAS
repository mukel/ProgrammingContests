{koder: A^2P}
{PSN 2003 #124 "Contrase¤a oculta"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  s               : array[0..MaxN] of char;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=0 to N-1 do read(fin,s[i]);

  {solve}
  for i:=1 to N do if j = N then break
  else
    for j:=1 to N do
      if s[(i+j) mod N] < s[(sol+j - 1) mod N] then
      begin
        sol := i; break;
      end else if s[(i+j) mod N] > s[(sol+j - 1) mod N] then break;

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
124ş Contrase¤a oculta.                                    Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Algunas veces los programadores tienen v¡as muy extra¤as para esconder
sus contrase¤as. Ver por ejemplo como Billy "Hacker" Geits esconde su
contrase¤a. Billy selecciona una cadena S compuesta de letras
min£sculas del Lat¡n con longitud L. Entonces hace todos los L-1
desplazamientos c¡clicos de una letra a la izquierda de la cadena y
toma como contrase¤a un prefijo de la primera cadena obteniada
lexicogr ficamente (incluyendo a S). Por ejemplo, considere la cadena
alabala. Los desplazamientos c¡clicos de una letra a la izquierda son:

                alabala
                labalaa
                abalaal
                balaala
                alaalab
                laalaba
                aalabal

y la primera de ellas (lexicogr ficamente) es la cadena aalabal. La
primera letra de esta cadena est  en la posici¢n 6 en la cadena
inicial (las posiciones en la cadena se cuentan desde 0).

Escriba un programa que para una cadena S dada encuentre la posici¢n
inicial del menor (lexicogr ficamente) desplazamiento c¡clico de una
letra a la izquierda de esta cadena. Si aparece el menor
(lexicogr ficamente) desplazamiento a la izquierda m s de una vez
entonces tu programa tiene que imprimir la posici¢n inicial m s
peque¤a.

Entrada (hidden.in)

La primera l¡nea del fichero de entrada contiene La longitud L de la
cadena (5<=L<=100000) y la pr¢xima l¡nea contiene la cadena S.

Salida (hidden.out)

El fichero de salida debe contener un simple n£mero el cual es la
posici¢n inicial encontrada por su programa.


Ejemplos de entrada y salida

Ejemplo #1             Ejemplo #2
ÚÄÄÄÄÄÄÄÄÄ¿            ÚÄÄÄÄÄÄÄÄÄ¿
³hidden.in³            ³hidden.in³
ÃÄÄÄÄÄÄÄÄÄ´            ÃÄÄÄÄÄÄÄÄÄ´
³6        ³            ³7        ³
³baabaa   ³            ³alabala  ³
ÀÄÄÄÄÄÄÄÄÄÙ            ÀÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄ¿           ÚÄÄÄÄÄÄÄÄÄÄ¿
³hidden.out³           ³hidden.out³
ÃÄÄÄÄÄÄÄÄÄÄ´           ÃÄÄÄÄÄÄÄÄÄÄ´
³1         ³           ³6         ³
ÀÄÄÄÄÄÄÄÄÄÄÙ           ÀÄÄÄÄÄÄÄÄÄÄÙ
}
