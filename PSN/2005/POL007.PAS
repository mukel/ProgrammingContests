{koder: A^2P}{2 - 3 - 2007}
{PSN 2005 #7 "Escalera del acr¢bata"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,escalon     : longint;

    function gcd(a,b: longint): longint;
    begin
      repeat
        a := a mod b; if a = 0 then exit(b);
        b := b mod a; if b = 0 then exit(a);
      until false;
    end;{gcd}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {dprint}
  writeln(fout,N + M - gcd(N,M));
  repeat
    repeat
      inc(escalon,N); write(fout,'+');
    until escalon >= M;
    repeat
      dec(escalon,M); write(fout,'-');
    until escalon < M;
  until escalon = 0;

  {fclose}
  close(fin); close(fout);
end.{main}

{
7þ Escalera del acr¢bata.                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Colgada de lo  m s alto de  la carpa de  un circo hay  una escalera de
pelda¤os. Un  acr¢bata del  circo siempre  asciende y  desciende de la
siguiente manera: cuando ‚l asciende  en cada paso sube N  pelda¤os de
la escalera  y cuando  desciende en  cada paso  baja M  pelda¤os de la
escalera,  donde N  y M   son enteros  positivos fijos.  Mediante una
secuencia de pasos de ascenso y descenso el acr¢bata puede realizar su
presentaci¢n, que consiste en subir  desde lo m s bajo de  la escalera
hasta el £ltimo pelda¤o y despu‚s bajar desde el £ltimo pelda¤o  hasta
lo m s bajo  de la escalera.  Determinar el n£mero  m¡nimo de pelda¤os
que debe tener  la escalera para  que el acr¢bata  pueda  mediante una
secuencia de pasos realizar su presentaci¢n. El acr¢bata puede arribar
m s de una vez a un mismo escal¢n.

Tarea

Escriba un programa que:
- lea del fichero de entrada ACROBAT.IN los n£meros N y M
- calcule el n£mero m¡nimo de pelda¤os que debe tener la escalera para
  que el acr¢bata pueda hacer su presentaci¢n, y la secuencia de pasos
  que debe seguir para esto.
- escriba el resultado para el fichero de salida ACROBAT.OUT

Entrada

El  fichero  de entrada  ACROBAT.IN  contiene en  su  £nica l¡nea  los
enteros N y M separados por un espacio. 1 <= N, M <= 1000000000 Salida

El  fichero de  salida ACROBAT.OUT  contiene en  la primera  l¡nea  el
n£mero m¡nimo de pelda¤os que debe tener la escalera del acr¢bata.  En
la segunda l¡nea aparecer  la secuencia de pasos descrita mediante una
cadena de  caracteres. Un  car cter '+'  indica que  el acr¢bata  debe
subir y un car cter '-' indica que el acr¢bata debe bajar.

Evaluaci¢n

En el 50% de los casos de prueba con que ser  evaluado su programa  se
tiene que  1 <= N, M <= 10000


Ejemplo de Entrada Salida

ACROBAT.IN     ACROBAT.OUT
4 7            10
               ++-++-++-+-
}
