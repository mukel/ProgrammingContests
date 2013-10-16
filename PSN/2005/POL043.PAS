{koder: A^2P}
{PSN 2005 #43 "Potencias Negativas de Dos"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,r,t,s     : byte;
  d               : array[1..250] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  s := 1; d[1] := 1;
  for i:=1 to N do
  begin
    for j:=1 to s do
    begin
      t := (d[j] * 5 + r) div 10;
      d[j] := (d[j] * 5 + r) mod 10;
      r := t;
    end;{for}
    if r > 0 then
    begin
      inc(s); d[s] := r; r := 0;
    end;{then}
  end;{for}

  {dprint}
  write(fout,'0.');
  for i:=N downto 1 do write(fout,d[i]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
43ş Potencias Negativas de Dos.                           Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dado un entero N (1 <= N <= 250), imprima el inverso exacto de 2 a  la
eN‚sima  potencia.  Impr¡malo  en   la  forma   "0.x..."   sin   ceros
sobrantes.

NOMBRE DEL PROBLEMA: nptwo

FORMATO DE ENTRADA:

- L¡nea 1: Un solo entero N.

ENTRADA EJEMPLO (archivo nptwo.in):

67

FORMATO DE SALIDA:

- L¡nea 1: La representaci¢n decimal de  1 / (2^N).

SALIDA EJEMPLO (archivo nptwo.out):

0.0000000000000000000067762635780344027125465800054371356964111328125
}
