{koder: A^2P}
{PSN 2005 #24 "Potencias de Dos"}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,r,t,s     : word;
  d               : array[1..80] of byte;

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
      t := (d[j] shl 1 + r) div 10;
      d[j] := (d[j] shl 1 + r) mod 10;
      r := t;
    end;{for}
    if r > 0 then
    begin
      inc(s); d[s] := r; r := 0;
    end;{then}
  end;{for}

  {dprint}
  for i:=s downto 1 do write(fout,d[i]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
24ş Potencias de Dos                                      Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dado un entero N (0 <= N <= 265), imprima exactamente el valor de 2  a
la  eN‚sima  potencia  (sin  ceros  a  la  izquierda  o  espacios, por
supuesto).

NOMBRE DEL PROBLEMA: ptwo

FORMATO DE ENTRADA:
- L¡nea 1: El entero N

ENTRADA EJEMPLO (archivo ptwo.in):
100

FORMATO DE SALIDA:
- L¡nea 1: Una sola l¡nea que contiene 2 a la eN‚sima potencia.

SALIDA EJEMPLO (archivo ptwo.out):
1267650600228229401496703205376
}
