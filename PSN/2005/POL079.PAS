{koder: A^2P}
{PSN 2005 #79 "Volumen Moo"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  sol             : qword;
  N,i,j,k,p,tmp   : longint;
  c               : array[0..MaxN] of longint;

    procedure qsort(d,h: integer);
    var i,j : integer;
    begin
      i := d; j := h; p := c[(d + h) shr 1];
      repeat
        while c[i] < p do inc(i);
        while c[j] > p do dec(j);
        if i <= j then
        begin
          tmp := c[i]; c[i] := c[j]; c[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,c[i]);

  {solve}
  qsort(1,N);

  for i:=2 to N do
    inc(sol,qword(c[i] - c[i-1])
            * (i - 1) * (N - i + 1));

  {dprint}
  writeln(fout,sol shl 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
79ş Volumen Moo.                                          Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan ha recibido una queja de su vecino, el granjero Rob,
diciendo que sus vacas estan haciendo mucha bulla.

Las N vacas de GJ (1 <= N <= 10,000) todas pastan en diferentes
ubicaciones en un potrero largo uni-dimensional. Las vacas son
animales muy conversadores. Cada par de vacas llevan simult neamente
una conversaci¢n (por lo tanto cada vaca esta simult neamente mugiendo
con las otras N-1 vacas). Cuando la vaca i muge a la vaca j, el
volumen de su mugido debe ser igual a la distancia entre i y j, con el
prop¢sito que j sea capaz de escuchar el mugido. Por favor, ayude a GJ
a calcular el volumen total de sonido que esta siendo generado por
todas las N*(N-1) sesiones simultaneas de mugido.

TIEMPO LIMITE: 0.05 segundos

NOMBRE DEL PROBLEMA: volume

FORMATO DE ENTRADA:

- L¡nea 1: N

- L¡neas 2..N+1: La ubicaci¢n de cada vaca (en el rango
        0..1,000,000,000).

ENTRADA EJEMPLO (archivo volume.in):

5
1
5
3
2
4

DETALLES DE LA ENTRADA:

Hay cinco vacas en las ubicaciones 1, 5, 3, 2, y 4.

FORMATO DE SALIDA:

* L¡nea 1: Un solo entero, el volumen total de todos los mugidos.

SALIDA EJEMPLO (archivo volume.out):

40

DETALLE DE LA SALIDA:

La vaca en la ubicacion 1 contribuye con 1+2+3+4=10, la vaca en la 5
contribuye con 4+3+2+1=10, la vaca en la 3 contribuye con 2+1+1+2=6, la
vaca en la 2 contribuye con 1+1+2+3=7, y la vaca en la 4 contribuye con
3+2+1+1=7.  El volumen total es (10+10+6+7+7) = 40.
}
