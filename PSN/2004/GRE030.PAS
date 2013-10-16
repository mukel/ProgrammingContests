{koder: A^2P}
{PSN 2004 #30 "Nave Espacial"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 41;
  MaxM = 440;
  MaxLen = 60;
var
  fin,fout        : text;
  N,M,i,j,k,r,t   : longint;
  c               : array[0..MaxN,0..MaxM,0..MaxLen] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M,N);

  {solve}
  c[1,0,0] := 1; c[1,0,1] := 1;
  for i:=1 to N + 1 do
  begin
    for j:=i to i * M do
    begin
      if c[i,j-1,0] >= c[i-1,j-1,0] then c[i,j,0] := c[i,j-1,0]
        else c[i,j,0] := c[i-1,j-1,0];
      for k:=1 to c[i,j,0] do
      begin
        t := c[i-1,j-1,k] + c[i,j-1,k] + r;
        c[i,j,k] := t mod 10;
        r := t div 10;
      end;{for}
      if r > 0 then
      begin
        inc(c[i,j,0]);
        c[i,j,c[i,j,0]] := r; r := 0;
      end;{then}
    end{then ->}
  end;{for}

  {dprint}
  for j:=c[N + 1,N * M + 1,0] downto 1 do
    write(fout,c[N + 1,N * M + 1,j]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
30ş Nave Espacial.                                           Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La Asociaci¢n Espacial Rumana (RSA) descubri¢ un nuevo asteroide, al
cual ellos lo llamaron BOI2003. RSA tiene un gran inter‚s en explorar
el asteroide BOI2003, as¡ que ellos construyeron una Nave Espacial para
llevar a los cient¡ficos al asteroide. La Nave Espacial construida por
ellos tiene algunos rasgos peculiares. Cuando la  Nave Espacial sale
de la Tierra por primera vez debe llevar exactamente S cient¡ficos.
Cuando la Nave Espacial llega al asteroide BOI2003, solo un cient¡fico
aterriza y La  Nave Espacial retorna  para  recoger otros S
cient¡ficos.

El primer cient¡fico que aterriz¢ en BOI2003 sospecha la existencia de
un peligroso Virus en el asteroide. De este modo ‚l sugiere que, hasta
que no se investigue, no viaje ning£n cient¡fico para la BOI2003 y no
debe salir de la Nave Espacial cuando ellos lleguen a tierra.

Par ser m s espec¡fico, asumimos  que los cient¡ficos son denotados
por enteros comenzando por el 1. La Nave Espacial trabaja de la
siguiente forma:

- la primera vez sale de la tierra, la Nave Espacial lleva los
  cient¡ficos 1, 2, ..., S; uno de estos cient¡ficos aterriza en el
  asteroide y los otros S-1 cient¡ficos retornan hacia la  tierra
  (pero no se bajan de la nave);

- la segunda vez la Nave Espacial sale de la tierra con los
  cient¡ficos S+1, S+2, ..., 2S acumulando los S-1 cient¡ficos que
  retornaron, y la Nave Espacial lleva estos 2S-1 cient¡ficos para la
  BOI2003; uno de ellos aterriza en el asteroide y la  Nave Espacial
  retorna hacia la tierra con 2S-2 cient¡ficos (otra vez ellos no se
  bajan de la nave);

- la tercera vez, los cient¡ficos 2S+1, 2S+2, ..., 3S conjuntamente
  con los otros 2S-2 cient¡ficos quienes ya est n en la Nave Espacial,
  viajan hacia BOI2003 y uno de ellos aterrizan en el asteroide;

- y as¡ sucesivamente.

Despu‚s de N viajes  un equipo de cient¡ficos consistente de N
cient¡ficos hab¡an sido llevado m s y est n trabajado en el asteroide
BOI2003.

Tarea

Escriba un programa que determine el n£mero de posibilidades para
formar el equipo de investigaci¢n.

Entrada

El fichero de entrada SHIP.IN presenta una simple l¡nea que contiene
los enteros S y N, separados por un espacio en blanco.

Salida

El fichero de salida SHIP.OUT debe tener una simple l¡nea que contiene
un entero K, representando el n£mero de posibilidades para formar el
equipo de investigaci¢n.

Restricciones:

ú 1 <= S <= 10
ú 1 <= N <= 40
ú La Nave Espacial tiene ilimitada capacidad.
ú El orden el cual los miembros del equipo llega al asteroide
  no importa.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄ¿
³ SHIP.IN ³  ³ SHIP.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄ´
³ 2 3     ³  ³ 14       ³
ÀÄÄÄÄÄÄÄÄÄÙ  ÀÄÄÄÄÄÄÄÄÄÄÙ
}
