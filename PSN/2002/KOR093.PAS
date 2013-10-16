{koder: A^2P}{FPC}
{PSN 2005 #93 "Vagabundeo por Expo Cuba"}
{O(N)}
{$I+,Q+,R+,S+}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 30000;
var
  fin,fout        : text;
  N,i,j,k,sol     : integer;
  next,val        : array[1..MaxN] of word;
  mark            : array[1..MaxN] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,next[i]);

  {solve}
  for i:=1 to N do
    if not mark[i] then
    begin
      j := i; k := 0;
      repeat
        val[j] := k; inc(k);
        mark[j] := true; j := next[j];
      until mark[j];
      if k - val[j] > sol then sol := k - val[j];
    end;{then}

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
93ş  Vagabundeo por Expo Cuba.                              Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

A  los  estudiantes de la Preselecci¢n Nacional cuando van de visita a
Expo  Cuba  les  gusta  pasear  los N (1 <= N <= 30,000) pabellones de
exposiciones.

Para  que  una  experiencia  de  vagabundeo sea valida los estudiantes
pueden  comenzar en alguna pabell¢n y tienen que finalizar en el mismo
pabell¢n   sin  visitar  algun  otro  pabell¢n  dos  veces.  Dada  una
descripci¢n  de  los  caminos entre los pabellones, deduzca el posible
mas largo paseo v lido que los estudiantes pueden realizar.

Entrada

El fichero de entrada STROLL.IN contiene:
- l¡nea 1: un entero: N.
- l¡nea 2..N+1: la l¡nea M representa el n£mero de la pabell¢n que el
  pabell¢n  M-1  conecta  (asi  la  l¡nea  2  muestra cual pabell¢n es
  accesible desde la pabell¢n 1, etc.

Salida

El fichero de  salida STROLL.OUT contiene  en una l¡nea simple cual es
el n£mero m s grande de pabellones  que  pueden  ser  visitados  en un
vagabundeo legal.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ STROLL.IN ³ ³ STROLL.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5         ³ ³ 3          ³
³ 2         ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 4         ³
³ 5         ³  como resultado de visitar la pabell¢n 2, luego el 4,
³ 5         ³  entonces el 5.
³ 2         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
