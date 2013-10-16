{koder: A^2P}{3 - 3 - 2007}
{PSN 2004 #81 "Palin"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 200;
var
  fin,fout        : text;
  N,i,j,k,h       : longint;
  s               : string[MaxN];
  c               : array[0..MaxN,0..MaxN] of byte;

    function pal(a,b: byte): boolean;
    begin
      while (a <= b) and (s[a] = s[b]) do
      begin
        inc(a); dec(b)
      end;{while}
      pal := (a > b);
    end;{pal}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,s);

  {solve}{dp}
  N := byte(s[0]);
  for h:=0 to N - 1 do
    for i:=1 to N - h do
    begin
      j := i + h;
      if pal(i,j) then c[i,j] := 1
      else begin
        c[i,j] := oo;
        for k:=i to j - 1 do
          if c[i,k] + c[k + 1,j] < c[i,j]
            then c[i,j] := c[i,k] + c[k + 1,j];
      end;{else}
    end;{for}

  {dprint}
  writeln(fout,c[1,N]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
81þ Palin.                                                 Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una pal¡ndrome es  una palabra que  se lee lo  mismo adelante o  hacia
atr s. Si  una palabra  no es  pal¡ndrome, esta  puede ser  cortada en
partes pal¡ndromes. Escriba un programa que calcule el menor n£mero de
partes pal¡ndromes que puede  ser cortada una secuencia  de caracteres
dada.

Entrada (PALIN.IN)

La primera y £nica l¡nea del fichero de entrada contiene una secuencia
de caracteres. Los caracteres  usados como entrada ser n  del conjunto
de letras min£sculas  del alfabeto ingl‚s  (a-z). La longitud  de cada
secuencia de entrada ser  cuando m s 100.

Salida (PALIN.OUT)

La primera y £nica l¡nea del fichero de salida debe contener el n£mero
de pal¡ndromes.

Ejemplos de Entrada y Salida

Ejemplo #1         Ejemplo #2        Ejemplo #3
ÚÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³PALIN.IN³        ³PALIN.IN³        ³PALIN.IN     ³
ÃÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³anaban  ³        ³abaccbcb³        ³anavolimilana³
ÀÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄ¿
³PALIN.OUT³       ³PALIN.OUT ³      ³PALIN.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄ´
³2        ³       ³3         ³      ³5         ³
ÀÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄÄÄÄÄÄÄÙ

Explicaciones:

#1  a_naban
#2  aba_cc_bcb
#3  ana_v_o_limil_ana
}