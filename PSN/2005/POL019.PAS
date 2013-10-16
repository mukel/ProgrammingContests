{koder: A^2P}{26 - 4 - 2007}
{PSN 2005 #19 "Arreglando la Elecci¢n Bovina"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxC = 25;
var
  fin,fout        : text;
  J,H,i,k,sol     : longint;
  mat             : array[0..MaxC] of char;
  mark,mark1      : array[0..MaxC] of boolean;

    function check(i: longint): boolean;
    begin
      mark1[i] := false;
      if mat[i] = 'H' then inc(H) else inc(J);
      if (i - 5 > 0) and (mark1[i - 5]) then check(i - 5);
      if (i + 5 <= MaxC) and (mark1[i + 5]) then check(i + 5);
      if (i mod 5 <> 1) and (mark1[i - 1]) then check(i - 1);
      if (i mod 5 <> 0) and (mark1[i + 1]) then check(i + 1);
      check := (J + H = 7) and (J > H);
    end;{check}

    procedure comb(i,level: longint);
    begin
      if level = 0 then
      begin
        J := 0; H := 0;
        mark1 := mark;
        if check(i - 1) then inc(sol);
        exit;
      end;{then}
      for i:=i to MaxC - level + 1 do
      begin
        mark[i] := true;
        comb(i + 1,level - 1);
        mark[i] := false;
      end;{for}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  for i:=1 to 5 do
  begin
    for k:=1 to 5 do read(fin,mat[(i - 1) * 5 + k]);
    readln(fin);
  end;{for}

  {solve}
  comb(1,7);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
19ş Arreglando la Elecci¢n Bovina                         Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Es tiempo de elecciones. La granja  est  partida en una matriz 5x5  de
ubicaciones de  vacas, cada  una de  ellas tiene  o una  vaca Holstein
(‘H’) o una vaca Jersey  (‘J’). Las Jerseys quieren crear  un distrito
de votaci¢n de 7 vacas  contiguas (vertical u horizontalmente) de  tal
manera que el n£mero de Jerseys sobrepase a las Holsteins. ¿De cu ntas
maneras se puede hacer esto para la matriz dada?

NOMBRE DEL PROBLEMA: cowrig

FORMATO  DE ENTRADA:

- L¡neas 1..5:  Cada  una   de   las  cinco  l¡neas  contienen   cinco
  caracteres    por   l¡nea,    cada  una   ‘H’   o    ‘J’.  No    hay
  espacios presentes.

ENTRADA EJEMPLO (archivo cowrig.in):

HHHHH
JHJHJ
HHHHH
HJHHJ
HHHHH

FORMATO DE SALIDA:

- L¡nea 1: El n£mero de distritos diferentes de 7 vacas conectadas  de
  tal  manera  que  las  Jerseys  sobrepasen  a  las  Holsteins  en el
  distrito.

SALIDA EJEMPLO (archivo cowrig.out):
2

DETALLES DE SALIDA:

Los dos distritos posibles son:

.....                .....
JHJHJ                JHJHJ
....H        y       .H...
....J                .J...
.....                .....

Cualquier otro distrito posible con siete vacas tiene menos de 4
Jerseys.
}