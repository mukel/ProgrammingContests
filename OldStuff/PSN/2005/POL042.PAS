{koder: A^2P}
{PSN 2005 #42 "PAL"}
program pal;
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   i,k,m        : byte;
   s            : string[75];
   len          : byte absolute s;

     procedure pl(a,b: byte);
     begin
          while (s[a] = s[b]) and (a > 0) do
          begin inc(b); dec(a); end;{while}
          if b - a > m then
          begin m := b - a; k := a; end;{then}
     end;{pl}

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     read(fin,s);

     {solve}
     for i:=2 to len - 1 do pl(i,i);
     for i:=1 to len - 1 do pl(i,i+1);

     {dprint}
     for i:=k+1 to m+k-1 do write(fout,s[i]);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
42þ Pal¡ndrome.                                           Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un palindrome es una serie de  d¡gitos (o de letras, si usted  quiere)
que se leen lo mismo hacia  delante y hacia atr s. El n£mero  12344321
es  un  pal¡ndrome, as¡  como  12321 y  3.  El n£mero  2468  no es  un
pal¡ndrome.

Lea un n£mero de hasta 75  d¡gitos del archivo de entrada y  encuentre
el pal¡ndrome  m s grande  que ocurre  en este  n£mero. El  pal¡ndrome
estar  en  cualquier parte  y podr  ser  de dos  d¡gitos hasta   todos
los d¡gitos del n£mero y se garantiza que ser  £nico.

NOMBRE DEL PROBLEMA: pal

FORMATO DE ENTRADA:

- L¡nea 1: Un solo n£mero de hasta 75 d¡gitos de longitud

ENTRADA EJEMPLO (archivo pal.in):

82910341234565432158735

FORMATO DE SALIDA

- L¡nea 1: El pal¡ndrome mas grande que se encuentre en cualquier
  lugar en el n£mero.

SALIDA EJEMPLO (archivo pal.out):

12345654321

DETALLES DE LA SALIDA:

8291034-->12345654321<--58735
}