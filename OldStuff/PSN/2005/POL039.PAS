{koder: A^2P}{2 - 3 - 2007}
{PSN 2005 #39 "Secuencia regular"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,i,j,k,h       : longint;
  seq             : array[0..MaxN] of char;
  c,last          : array[0..MaxN,0..MaxN] of longint;

    function union(i,j: longint): longint;
    begin
      if ((seq[i] = '(') and (seq[j] = ')')) or
         ((seq[i] = '[') and (seq[j] = ']'))
           then union := 0 else union := 2;
    end;{union}

    procedure print(i,j: longint);
    begin
      if i = j then
        if seq[i] in ['(',')'] then write(fout,'()')
          else write(fout,'[]');
      if i >= j then exit;
      if last[i,j] = 0 then
      begin
        write(fout,seq[i]);
        print(i + 1,j - 1);
        write(fout,seq[j]);
      end{then ->}
      else begin
        print(i,last[i,j]);
        print(last[i,j] + 1,j);
      end;{else}
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  while not seekeoln(fin) do
  begin
    inc(N);
    read(fin,seq[N]);
  end;{while}

  {solve}
  for i:=1 to N do c[i,i] := 1;
  for h:=1 to N - 1 do
    for i:=1 to N - h do
    begin
      j := i + h;
      {indent}
      c[i,j] := c[i + 1,j - 1] + union(i,j);
      for k:=i to j - 1 do
        if c[i,k] + c[k + 1,j] <= c[i,j] then
        begin
          c[i,j] := c[i,k] + c[k + 1,j];
          last[i,j] := k;
        end;{for}
    end;{for}

  {dprint}
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
39þ Secuencia regular.                                    Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Definimos  una  secuencia  regular de  corchetes  y  parentesis de  la
siguiente manera:

1. La secuencia vacia es una secuencia regular.
2. Si S es  una secuencia regular, entonces  (S) y [S] son  secuencias
   regulares.
3. Si  A y  B son  secuencias regulares,  entoces AB  es una secuencia
   regular.

Por  ejemplo,  todas  las  siguientes  secuencias  de  caracteres  son
secuencias (de corchetes  y parentesis) regular:  (), [], (()),  ([]),
()[], ()[()]

Y todas las siguientes secuencias de caracteres no lo son:
(, [, ), )(, ([)], ([(]

A usted se le dan algunas  secuencias  de  caracteres  '(',  ')', '[',
y  ']'  y tiene  que encontrar  la posible  secuencia (de  corchetes y
parentesis)    regular mas   corta  que   contenga  la   secuencia de
caracteres dada como una subsecuencia.

Aqui, una cadena  a1a2...an es llamada  una subsecuencia de  la cadena
b1b2...bm, si en esta existe tales ¡ndices 1 <= i1 < i2 < ... < in <= m,
tal que aj=bij para todo 1 <= j <= n.

Entrada

El fichero  de entrada  BRACKET.IN contiene  a lo  sumo 100 caracteres
'(', ')', '['  y  ']'  que  est n situados  en  una l¡nea simple   sin
alg£n otro caracter entre ellos.

Output

Escriba hacia el  fichero de salida  BRACKET.OUT una linea  simple que
contiene alguna  subsecuencia (de corchetes y par‚ntesis) regular  que
tiene la longitud m¡nima posible y contiene la secuencia dada como una
subsecuencia.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ BRACKET.IN ³ ³ BRACKET.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³([(]        ³ ³ ()[()]      ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
