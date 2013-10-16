{koder: A^2P}{2 - 5 - 2007}
{PSN 2003 #62 "T£nel"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,i,j,sol       : longint;
  pos             : array[0..MaxN] of longint;
  list            : array[0..MaxN * 2] of string[8];

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to 2 * N do readln(fin,list[i]);

  {solve}
  for i:=1 to N do
  begin
    j := N + 1;
    while list[j] <> list[i] do inc(j);
    pos[i] := j;
  end;{for}

  for i:=1 to N do
    for j:=i - 1 downto 1 do
      if pos[i] < pos[j] then
      begin
        inc(sol);
        break;
      end;{then}

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
62þ T£nel.                                                    USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mirko est  posicionado  en la entrada y Slavko est  posicionado en la
salida de un t£nel. Ellos anotan el registro de matr¡cula (las chapas)
de los autom¢viles que pasan por ellos y proporcionan esa informaci¢n
a la patrulla de policia que est  a unas millas de ellos en la
carretera.

Usando la informaci¢n que Mirko y Slavko les dieron, la polic¡a puede
determinar, sin cometer error, que algunos choferes se adelantaron
mientras manejaban a trav‚s del t£nel y esto est  estrictamente
prohibido Escriba un programa que determine el n£mero de choferes para
los cuales la polic¡a puede alegar que ellos se adelantaron. Nosotros
asumimos que el tr fico a trav‚s del t£nel no tiene ninguna parada.

Entrada

El archivo de la entrada TUNNEL.IN consiste en 2N+1 l¡neas. En primera
l¡nea hay un entero N, 1 <= N <= 1000, n£mero de autom¢viles. En las
pr¢ximas N l¡neas hay registros de matr¡cula de esos autom¢viles, en
el orden en que ellos entraron en el t£nel. En las pr¢ximas N l¡neas
est n los registros de matr¡culas de esos autom¢viles, en el orden en
que ellos salieron del t£nel. El registro de matr¡cula de un autom¢vil
consiste en por lo menos seis y a lo sumo ocho car cteres y s¢lo ser n
permitidos los caracteres del alfabeto ingl‚s (A-Z) y los d¡gitos del
sistema decimal (0-9).

Salida

En la primera y £nica l¡nea del fichero de salida TUNNEL.OUT aparecer 
el n£mero de choferes que polic¡a puede castigar ciertamente por
adelantarse en el t£nel.

Ejemplos de Entrada y Salida:

  Ejemplo #1           Ejemplo # 2             Ejemplo #3

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄÄÄ¿           ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ TUNNEL.IN ³        ³ TUNNEL.IN ³           ³ TUNNEL.IN  ³
 ÃÄÄÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄÄÄ´           ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 4         ³        ³ 5         ³           ³ 5          ³
 ³ ZG431SN   ³        ³ ZG508OK   ³           ³ ZG206A     ³
 ³ ZG5080K   ³        ³ PU305A    ³           ³ PU234Q     ³
 ³ ST123D    ³        ³ RI604B    ³           ³ OS945CK    ³
 ³ ZG206A    ³        ³ ZG206A    ³           ³ ZG431SN    ³
 ³ ZG206A    ³        ³ ZG232ZF   ³           ³ ZG5962J    ³
 ³ ZG431SN   ³        ³ PU305A    ³           ³ ZG5962J    ³
 ³ ZG5080K   ³        ³ ZG232ZF   ³           ³ OS945CK    ³
 ³ ST123D    ³        ³ ZG206A    ³           ³ ZG206A     ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ        ³ ZG508OK   ³           ³ PU234Q     ³
                      ³ RI604B    ³           ³ ZG431SN    ³
                      ÀÄÄÄÄÄÄÄÄÄÄÄÙ           ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ TUNNEL.OUT ³       ³ TUNNEL.OUT ³          ³ TUNNEL.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 1          ³       ³ 3          ³          ³ 2          ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ          ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
