{koder: A^2P}{3 - 2 - 2007}
{PSN 2005 #89 "Suma y multiplica que eso da"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,M             : qword;
  C,i             : longint;
  sol             : array[1..4] of longint;
  cand            : array[0..MaxN] of longint;

    procedure comb(depth,index,S: longint; P: qword);
    var i : longint;
    begin
      if depth = 4 then
      begin
        if (S = N) and (P = M) then
        begin
          for i:=1 to 4 do write(fout,sol[i],' ');
          close(fout); halt;
        end;{then}
        exit;
      end;{then}
      for i:=index to C do
        if (S + cand[i] <= N) and
           (M mod (P * cand[i]) = 0) then
        begin
          sol[depth + 1] := cand[i];
          comb(depth + 1,i,S + cand[i],P * cand[i]);
        end;{then}
    end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {solve}
  for i:=1 to N do
    if M mod i = 0 then
    begin
      inc(C); cand[C] := i;
    end;{then}

  comb(0,1,0,1);

  {...}
  writeln(fout,-1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
89þ Suma y multiplica que eso da.                         Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se quiere  hacer un programa que encuentre  cuatro  enteros positivos,
los cuales  sumados  den como  resultado  un entero N y multiplicados
un entero M. Por ejemplo suponga que N = 19 y M = 288, una posible
soluci¢n ser¡a (2,8,3,6). Puede  haber  m s  de  una soluci¢n,  por
ejemplo otra soluci¢n al caso anterior ser¡a (4,4,2,9).

Tarea

Determinar si existen los cuatro n£meros que sumados  y  multiplicados
dan como resultado N y M respectivamente.

Entrada

El fichero  de  entrada SYM.IN consta de solamente una linea  con  dos
enteros N (1 <= N <= 10000) y M (1 <= M <=100 000 000 000 000)
separados por un espacio.

Salida

El fichero  de  salida  SYM.OUT  constar   de una sola linea  con  los
cuatro  n£meros  encontrados separados por un espacio. Podr n  estar
en cualquier orden y de haber m s de una  soluci¢n bastar   con
cualquiera de ellas. En caso de no haber soluci¢n imprimir "-1".

Ejemplo de Entrada y Salida:

 ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ SYM.IN   ³ ³ SYM.OUT   ³
 ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 19 288   ³ ³ 2 8 3 6   ³
 ÀÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}