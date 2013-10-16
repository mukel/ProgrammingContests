{koder: A^2P}
{PSN 2006 #16 "Asegurando el Establo"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,i,j,k       : word;
  c,tmp           : char;
  s               : string;
  let             : array[boolean] of byte;
  freq            : array['a'..'z'] of word;

    procedure comb(i: byte; d: char);
    var c : char;
    begin
      for c:=d to 'z' do
        if freq[c] > 0 then
        begin
          s[i] := c;
          inc(let[c in ['a','e','i','o','u']]);
          if i = N then
          begin
            if (let[true] > 0) and (let[false] > 1)
              then writeln(fout,s);
          end{then ->}
          else begin
            dec(freq[c]);
            comb(i+1,succ(c));
            inc(freq[c]);
          end;{else}
          dec(let[c in ['a','e','i','o','u']]);
        end;{then}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    read(fin,c,tmp); inc(freq[c]);
  end;{for}

  {solve}
  byte(s[0]) := N;
  comb(1,'a');

  {fclose}
  close(fin); close(fout);
end.{main}

{
16ş Asegurando el Establo.                                 M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan ha instalado un nuevo sistema de seguridad en el
establo y ahora deben dar un password v lido a las vacas en el reba¤o.
Un password v lido consiste de L (3 <= L <= 15) letras min£sculas (del
conjunto tradicional de caracteres latinos 'a'...'z'), que tenga al
menos una vocal ('a', 'e', 'i', 'o', o 'u'),al menos dos consonantes
(no-vocales), y tenga los caracteres en orden alfab‚tico ('abc'es
v lido; 'bac' no lo es).

Dada la longitud deseada L junto con C caracteres en min£scula,
escriba un programa que imprima todos los passwords v lidos de tama¤o
L que pueden ser formados a partir de esas letras. Los passwords deben
ser impresos en orden alfab‚tico, uno por l¡nea.

NOMBRE DEL PROBLEMA: passwd

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio, L y C

- L¡nea 2: C caracteres en min£scula separados por espacios que son el
        conjunto de caracteres a partir del cual se construir n los
        passwords.

ENTRADA EJEMPLO (archivo passwd.in):

4 6
a t c i s w

DETALLES DE LA ENTRADA:

Passwords de tama¤o 4 elegidos de seis caracteres dados.

FORMATO DE SALIDA:

- L¡neas 1..?: Cada l¡nea de salida contiene una palabra de tama¤o L
        (sin espacios). Las l¡neas de salida deben aparecer en orden
        alfab‚tico.

SALIDA EJEMPLO (archivo passwd.out):

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
}
