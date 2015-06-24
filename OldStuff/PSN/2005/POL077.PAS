{koder: A^2P}
{PSN 2005 #77 "Suma de conjuntos"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j           : longint;
  c               : array[0..500000] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  c[0] := 1; N := N div 2;
  for i:=1 to N do
  begin
    c[i] := (c[i-1] + c[j]) mod 1000000000;
    if odd(i) then inc(j);
  end;{for}

  {dprint}
  write(fout,c[N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
77ş Suma de conjuntos.                                    Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan (GJ) ha pedido a sus vacas que busquen diferentes
conjuntos de n£meros que sumen un n£mero dado. Las vacas usan
solamente n£meros que sean potencias enteras de 2. Aqu¡ est n los
conjuntos posibles de n£meros que suman 7:

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4

Ayude a GJ a contar todas las representaciones posibles para un entero
N dado (1 <= N <= 1,000,000).

NOMBRE DEL PROBLEMA: sumset

FORMATO DE ENTRADA:

Una sola l¡nea con un solo entero, N.

ENTRADA EJEMPLO (archivo sumset.in):

7

FORMATO DE SALIDA:

El n£mero de maneras de representar a N como la suma indicada. Debido
a lo potencialmente grande que puede ser este n£mero, imprima
solamente los £ltimos 9 d¡gitos (en representaci¢n base 10).

SALIDA EJEMPLO (arhivo sumset.out):

6
}