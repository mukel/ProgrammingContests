{koder: A^2P}
{PSN 2005 #113 "El banco cochinito"}
{01-09-06}
{O(n * (f - e))}
{$I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 500;
  MaxF = 10000;
  oo = 1 shl 30;
var
  fin,fout        : text;
  E,F,N,M,i,j     : word;
  p,v,cant        : array[1..MaxN] of word;
  ant             : array[0..MaxF] of word;
  c               : array[0..MaxF] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,E,F);
  readln(fin,N);
  for i:=1 to N do readln(fin,v[i],p[i]);

  {solve}{knapsack}
  M := F - E;{peso real}
  for i:=1 to M do c[i] := oo;
  {c[0] := 0;}
  for i:=1 to N do
    for j:=p[i] to M do
      if c[j - p[i]] + v[i] < c[j] then
      begin
        c[j] := c[j - p[i]] + v[i];
        ant[j] := i;
      end;{then}

  {dprint}
  if c[M] = oo then write(fout,'Imposible')
  else begin
    i := M;
    while ant[i] <> 0 do
    begin
      inc(cant[ant[i]]);
      i := i - p[ant[i]];
    end;{while}
    writeln(fout,c[M]);
    for i:=1 to N do writeln(fout,cant[i]);
  end;{else}

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
113ş El banco cochinito.                                    Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Antes que los concursantes puedan viajar a la IOI, un presupuesto debe
prepararse,  con  el  apoyo  de  los  patrocinadores.  Para esto se ha
propuesto  un  nuevo tipo de banco : Piggy - Bank ( Banco cochinito ),
la  idea  fundamental  de  este  banco  es igual a la de una alcanc¡a,
cuando  echas  una  moneda,  no  la  puedes  sacar hasta que rompas la
alcanc¡a.  Cuando  halla  suficientes monedas para pagar los viajes se
puede romper el banco.

El  encargado  de esta tarea, un irresponsable sin duda, ha perdido la
lista con la cantidad de dinero  que se ha echado en el Banco, y ahora
no  se  sabe  cuanto dinero hay en el Piggy-Bank. Como £nico se podr¡a
saber  la  cantidad de dinero que hay en el Piggy-Bank es rompi‚ndolo,
pero si no hay suficientes monedas en el banco no podremos competir en
la IOI.

Es  necesario  que  ustedes  ayuden al irresponsable, que ha puesto en
juego  su  participaci¢n  en  la  IOI,  a  determinar cual es la menor
cantidad de dinero que puede haber en el Piggy-Bank.

Para eso se te dar  como datos:

E  y  F  (1 <= E , F <= 10000). E es el peso del Piggy-Bank vac¡o, y F
el de el Piggy-Bank lleno.

N  (1  <=  N  <= 500). N es la cantidad de tipos de monedas que se han
echado en el Banco.

Para  cada  i (1 <= i <= N) representando el tipo de moneda se te dar 
P  (1 <= P <=10000) y W (1 <= W <= 10000), donde P representa el valor
de  una moneda de ese tipo y W representa el peso de una moneda de ese
tipo.

Entrada

En  la primera l¡nea del  archivo PIG.IN est n E y F, separados por un
espacio.  En  la  segunda  l¡nea  aparecer   el valor de N, y en las N
siguientes l¡neas P(i) y W(i) para 1 <= i <= N.

Salida

En    la  primera  l¡nea  del  archivo  PIG.OUT  escribir s  X, que es
la  m¡nima  cantidad    de    dinero  que puede  haberse reunido en el
Piggy-Bank  usando  las  monedas    con    el    peso   dado, en las N
siguientes    l¡neas    un entero C(i), que representa la  cantidad de
monedas    del  tipo  i  que est n en el Piggy-Bank para  obtener X; o
la   sentencia  Imposible  si  es  que  no  puede alcanzar exactamente
el peso del banco.

Ejemplo # 1 de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ PIG.IN  ³  ³ PIG.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 10 110  ³  ³ 60      ³
³ 2       ³  ³ 0       ³
³ 1 1     ³  ³ 2       ³
³ 30 50   ³  ÀÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÙ

Ejemplo # 2 de Entrada y Salida

ÚÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄ¿
³ PIG.IN ³   ³ PIG.OUT ³
ÃÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄ´
³ 10 110 ³   ³ 100     ³
³ 2      ³   ³ 100     ³
³ 1 1    ³   ³ 0       ³
³ 50 30  ³   ÀÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÙ

Ejemplo 3 de Entrada y Salida

ÚÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ PIG.IN ³   ³ PIG.OUT   ³
ÃÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 1 6    ³   ³ Imposible ³
³ 2      ³   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 10 3   ³
³ 10 4   ³
ÀÄÄÄÄÄÄÄÄÙ
}
