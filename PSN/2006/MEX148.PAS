{koder: A^2P}{5 - 3 - 2007}
{PSN 2006 #148 "Squint"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,d,h,m         : qword;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}{binary search}
  d := 0; h := MaxLongint * 2;
  repeat
    m := (d + h) shr 1;
    if sqr(m) < N then d := m + 1
      else h := m;
  until d = h;

  {dprint}
  writeln(fout,d);

  {fclose}
  close(fin); close(fout);
end.{main}

{
141þ Squint.                                               M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Tarea

Escriba un programa que calcule la ra¡z de un n£mero entero.

Entrada

El fichero de entrada SQUINT.IN, solamente contiene un n£mero entero n
0 <= n < 2^63.

Salida

Escriba hacia el fichero de salida SQUINT.OUT. en su £nica l¡nea el
m s peque¤o entero no negativo q tal que q^2 >= n

Ejemplo de Entrada y Salida:

SQUINT.IN               SQUINT.OUT

122333444455555         11060446

        _______________
Porque û122333444455555 ÷ 11060445.038765619

Nota: No puede utlizar la funci¢n del Pascal SQRT.
}