{koder: A^2P}{30 - 4 - 2007}
{PSN 2006 #86 "D¡as de D¢lar"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
  MaxLen = 40;
var
  fin,fout        : text;
  N,M,i,j,k,r,t   : longint;
  len             : array[0..MaxN] of longint;
  C               : array[0..MaxN,0..MaxLen] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  len[0] := 1; C[0,1] := 1;
  for i:=1 to M do
    for j:=i to N do if len[j - i] <> 0 then
    begin
      if len[j - i] > len[j] then len[j] := len[j - i];
      for k:=1 to len[j] do
      begin
        t := c[j,k] + c[j - i,k] + r;
        c[j,k] := t mod 10;
        r := t div 10;
      end;{for}
      if r > 0 then
      begin
        inc(len[j]);
        c[j,len[j]] := r;
        r := 0;
      end;{then}
    end;{for}

  {dprint}
  for i:=len[N] downto 1 do
    write(fout,C[N,i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
86ş D¡as de D¢lar.                                         M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  (GJ) va a  los D¡as de  D¢lar en la  Tienda Vacuna y
descubre  un n£mero ilimitado de herramientas en promoci¢n. Durante su
primera visita, las herramientas  se est n vendiendo variadamente  por
$1, $2, y $3.  El Granjero Juan tiene  exactamente $5 para gastar.  El
puede comprar 5 herramientas  de $1 cada una  o 1 herramienta de  $3 y
adicionalmente  1   herramienta  de   $2.  Por   supuesto,  hay  otras
combinaciones para un total de  5 maneras diferentes en las  cuales GJ
puede gastar todo su dinero en herramientas. Aqu¡ est n las maneras:

        1 @ US$3 + 1 @ US$2
        1 @ US$3 + 2 @ US$1
        1 @ US$2 + 3 @ US$1
        2 @ US$2 + 1 @ US$1
        5 @ US$1

Escriba un programa que calcular  el n£mero de maneras en que GJ puede
gastar  N  d¢lares  (1  <=  N  <=  1000)  en  la  Tienda  Vacuna  para
herramientas en promoci¢n con un costo de $1..$K (1 <= K <= 100).

NOMBRE DEL PROBLEMA: ddayz


FORMATO DE ENTRADA:

Una sola l¡nea con dos enteros separados por espacio: N y K.


ENTRADA EJEMPLO (archivo DDAYZ.IN):

5 3

FORMATO DE SALIDA:

Una sola l¡nea con un solo  entero que es el n£mero de  maneras £nicas
en que GJ puede gastar su dinero.

SALIDA EJEMPLO (archivo DDAYZ.OUT):

5
}
